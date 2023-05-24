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

  int i = 0; //counter

  zmq::message_t *msg = new zmq::message_t();

  try {
    zmq::context_t context(1);

    // Outgoing message go out through here
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "!IndyPenders>DND>", 17);  //socket to receive answer from ZMQsub
    zmq::socket_t ventilator(context, ZMQ_PUSH);
    ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");
    while(true){
    //write input here for DM or Player example "IndyPenders>DM>1D20, "IndyPenders>Pl>1D20>name>+5,+0,+0,+0,+0,+0>str"
    std::string message;
    std::cin >> message;

    while (ventilator.connected() && i != 1) {
      sleep(1000);
      ventilator.send(message.c_str(), message.length()); //message gets send
      std::cout << "SENDED: " << message.c_str() << std::endl;
      i++;
    }
    while (subscriber.connected() && i == 1) {
      subscriber.recv(msg);   //answer received
      std::string str0 = msg->to_string().substr(17, 78);
      std::cout << str0 << std::endl;
      i--;
    }
}
  } catch (zmq::error_t &ex) {
    std::cerr << "Caught an exception : " << ex.what();
  }

  return 0;
}


