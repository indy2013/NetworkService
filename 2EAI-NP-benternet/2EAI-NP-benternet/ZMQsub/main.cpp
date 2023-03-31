
#include <cstdlib>
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
  try {

    zmq::context_t context(1);

    // zmq::context_t rec(1);

    // Incoming messages come in here
    zmq::socket_t ventilator(context, ZMQ_PUSH);
    ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");
    //		subscriber.connect( "tcp://192.168.1.8:24042" );
    //		subscriber.connect( "tcp://localhost:24042" );
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

    subscriber.setsockopt(ZMQ_SUBSCRIBE, "indyPenders>DND>", 16);

    zmq::message_t *msg = new zmq::message_t();
    int i = 0;
    srand(time(NULL));
    int Savingthrow = rand() % 20 + 1;
    int valueReceived = 0;

    while (subscriber.connected()){
      std::string message;
      subscriber.recv(msg);
      std::string str0 = msg->to_string().substr(16, 17);
      std::cout << "Received : [" << str0 << "]" << std::endl;
      valueReceived = std::stoi(str0);

      if (valueReceived != 0) {
        if (valueReceived < Savingthrow) {
          std::string str1 = "!IndyPenders>DND>";
          std::string str2 = "You Failed the saving throw, you needed: ";
          std::string str3 = std::to_string(Savingthrow).c_str();
          message = str1 + str2 + str3;
          sleep(1000);
          ventilator.send(message.c_str(), message.length());
        } else {
          std::string str1 = "!IndyPenders>DND>";
          std::string str2 = "You succeeded the saving throw, you needed: ";
          std::string str3 = std::to_string(Savingthrow).c_str();
          message = str1 + str2 + str3;
          sleep(1000);
          ventilator.send(message.c_str(), message.length());
        }
      }
    }

  } catch (zmq::error_t &ex) {
    std::cerr << "Caught an exception : " << ex.what();
  }

  return 0;
}
