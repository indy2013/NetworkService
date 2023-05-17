#include <cstdlib>
#include <iostream>
#include <zmq.hpp>

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n) Sleep(n)
#endif

int main(int argc, char *argv[]) {

  int i = 0;

  std::string str1 = "IndyPenders>DND>";
  int D20 = rand() % 20 + 1;
  std::string str2 =  std::to_string(D20).c_str();
  std::string message = str1 + str2;
  //std::cout << "Die send " << str2 << std::endl;   delete later

  zmq::message_t *msg = new zmq::message_t();

  try {
    zmq::context_t context(1);
    // zmq::context_t rec(1);

    // Outgoing message go out through here
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "!IndyPenders>DND>", 17);  //socket to receive answer from ZMQsub
    zmq::socket_t ventilator(context, ZMQ_PUSH);
    ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

    //		ventilator.connect( "tcp://192.168.1.8:24041" );
    //		ventilator.connect( "tcp://localhost:24041" );

    while (ventilator.connected() && i != 10 /*&& subscriber.connected()*/) {
      sleep(1000);
      ventilator.send(message.c_str(), message.length()); //message gets send
      std::cout << "SENDED: " << message.c_str() << std::endl;
      i++;
    }
    while (subscriber.connected()) {
      subscriber.recv(msg);   //answer received
      std::string str0 = msg->to_string().substr(17, 78);
      std::cout << str0 << std::endl;
    }
  } catch (zmq::error_t &ex) {
    std::cerr << "Caught an exception : " << ex.what();
  }

  return 0;
}


