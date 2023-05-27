
#include <cstdlib>
#include <iostream>
#include <string>
#include <zmq.hpp>
#include <QString>
#include <calculate.h>
#include <data.h>

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

    subscriber.setsockopt(ZMQ_SUBSCRIBE, "IndyPenders>", 12);   //socket to receive from

    zmq::message_t *msg = new zmq::message_t();
    int i = 0; //counter
    int valueReceived = 0;
    data name;
    data Savingthrow;
    int DieCalc = 15;
    std::string SavingthrowValue = "15";
    while(true){
    while (subscriber.connected()){
      std::string message;
      subscriber.recv(msg);



      //filter the dice (1D20)
      std::string Die = msg->to_string().substr(15, 19);
      Calculate calc;
      DieCalc = calc.Die(Die);
      std::string buffer(static_cast<char*>(msg->data()), msg->size());
      //std::cout << "Received : [" << buffer << "]" << std::endl;

      //check if player name is saved in data.cpp or needs to be added.
      std::string player = name.names(buffer);


      SavingthrowValue = Savingthrow.DMSavingthrow(buffer,DieCalc);
      std::cout << "Dm: " << SavingthrowValue.c_str() << std::endl;
      std::cout << "Rolled (no mod): " << DieCalc << std::endl;
      DieCalc = DieCalc + std::stoi(name.modifier(buffer));
      std::cout << "Total: " << DieCalc << std::endl;

      //put this in a savingthrow.cpp
      if (DieCalc != 0) {
        if (DieCalc < std::stoi( SavingthrowValue)) {
          std::string str1 = "!IndyPenders>DND>";
          std::string str2 = "You Failed the saving throw, you needed: ";
          int Total = std::stoi( SavingthrowValue) ;
          std::string TotalSend = std::to_string(Total);
          std::string str3 = TotalSend.c_str() ;
          std::string str4 = "\n You rolled a: " ;
          std::string str5 = std::to_string(DieCalc).c_str() ;
          message = str1 + str2 + str3 + str4 + str5;
           std::cout << "Test "<< std::endl;
          sleep(1000);
          ventilator.send(message.c_str(), message.length());
        } else {
          std::string str1 = "!IndyPenders>DND>";
          std::string str2 = "You succeeded the saving throw, you needed: ";
          int Total = std::stoi( SavingthrowValue);
          std::string TotalSend = std::to_string(Total);
          std::string str3 = TotalSend.c_str() ;
          std::string str4 = "\n You rolled a: " ;
          std::string str5 = std::to_string(DieCalc).c_str() ;

          message = str1 + str2 + str3 + str4 + str5;
          sleep(1000);
          ventilator.send(message.c_str(), message.length());
        }
      }
    }
      //make duel.cpp

}
  } catch (zmq::error_t &ex) {
    std::cerr << "Caught an exception : " << ex.what();
  }

  return 0;
}
