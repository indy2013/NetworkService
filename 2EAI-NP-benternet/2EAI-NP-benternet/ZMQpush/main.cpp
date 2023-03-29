#include <cstdlib>
#include <iostream>
#include <zmq.hpp>
#include "dice.h"
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n) Sleep(n)
#endif

int main(int argc, char *argv[]) {

  Dice *dice = new Dice();
  // generate a random integer
  std::string sentence;
  std::cin >> sentence;
  int i = 0;
  int Die = dice->D4();


  std::cout << "Random number send: " << Die << std::endl;
  std::string str1 = "indyPenders>DND>";
  std::string str2 = std::to_string(Die).c_str();
  std::string message = str1 + str2;
  zmq::message_t *msg = new zmq::message_t();

  try {
    zmq::context_t context(1);
    // zmq::context_t rec(1);

    // Outgoing message go out through here
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "!IndyPenders>DND>", 17);
    zmq::socket_t ventilator(context, ZMQ_PUSH);
    ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

    //		ventilator.connect( "tcp://192.168.1.8:24041" );
    //		ventilator.connect( "tcp://localhost:24041" );

    while (ventilator.connected() && i != 10 /*&& subscriber.connected()*/) {
      sleep(1000);
      ventilator.send(message.c_str(), message.length());
      std::cout << "SENDED: " << std::to_string(Die).c_str() << std::endl;
      i++;
    }
    while (subscriber.connected()) {
      subscriber.recv(msg);
      std::string str0 = msg->to_string().substr(17, 78);
      std::cout << str0 << std::endl;
    }
  } catch (zmq::error_t &ex) {
    std::cerr << "Caught an exception : " << ex.what();
  }

  return 0;
}


