
#include <QString>
#include <Send.h>
#include <calculate.h>
#include <cstdlib>
#include <data.h>
#include "duel.h"
#include <iostream>
#include <string>
#include <zmq.hpp>

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n) Sleep(n)
#endif

int main(void) {
  srand(time(NULL));
  try {

    zmq::context_t context(1);

    // Incoming messages come in here
    zmq::socket_t ventilator(context, ZMQ_PUSH);
    ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

    subscriber.setsockopt(ZMQ_SUBSCRIBE, "IndyPenders>",12); // socket to receive from

    zmq::message_t *msg = new zmq::message_t();
    data name;
    data Savingthrow;
    Calculate calc;
    Send editMsg;
    int DieCalc = 15;
    std::string SavingthrowValue = "15";
    while (true) {
      while (subscriber.connected()) {
        std::string message;
        subscriber.recv(msg);
         std::string buffer(static_cast<char *>(msg->data()), msg->size());
        QList<QString> List = QString::fromStdString(buffer).split('>');

        // filter the dice (1D20)
        if (List[1].toStdString() == "Duel" || List[1].toStdString() == "duel") {}
        else{
        std::string Die = msg->to_string().substr(15, 19);

        DieCalc = calc.Die(Die);
        }





        // check if player name is saved in data.cpp or needs to be added.
        std::string player = name.names(buffer);


        if (List[1].toStdString() == "Duel" || List[1].toStdString() == "duel") {
            std::cout<< "before entered DuelFight" << std::endl;
          Duel fight(name, calc);

          message = fight.DuelFight(buffer);
          std::cout<< message << std::endl;
          sleep(1500);
          ventilator.send(message.c_str(), message.length());

          }else{
        SavingthrowValue = Savingthrow.DMSavingthrow(buffer, DieCalc);


        std::cout << "Dm: " << SavingthrowValue.c_str() << std::endl;
        std::cout << "Rolled (no mod): " << DieCalc << std::endl;

        DieCalc = DieCalc + std::stoi(name.modifier(buffer));

        std::cout << "Total: " << DieCalc << std::endl;

        //puts message togather and sees if savingthrow is bigger or smaller then needed.
        message = editMsg.MsgContruct(buffer, DieCalc, SavingthrowValue);
        // put this in a savingthrow.cpp
        std::cout<< message << std::endl;
        sleep(1500);
        ventilator.send(message.c_str(), message.length());
        }
      }
    }
  } catch (zmq::error_t &ex) {
    std::cerr << "Caught an exception : " << ex.what();
  }

  return 0;
}
