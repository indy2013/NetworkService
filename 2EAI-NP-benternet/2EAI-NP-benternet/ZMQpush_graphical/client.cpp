
#include "client.h"

#include <QMessageBox>
#include <string>

Client::Client() : QObject()
{

}

Client::~Client() {
    delete msg;
}

void Client::setupConnection() {
    // Initialize msg flow variable
    msg = new zmq::message_t{};

    try {
        // Create connection
        context = zmq::context_t{ 1 };

        // Outgoing message go out through here
        subscriber = zmq::socket_t(context, ZMQ_SUB);
        subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");
        subscriber.setsockopt(ZMQ_SUBSCRIBE, "!IndyPenders>DND>", 17);  //socket to receive answer from ZMQsub

        ventilator = zmq::socket_t(context, ZMQ_PUSH);
        ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

        // Get ready for the first command
        emit waitingForCommand();
    }

    catch (zmq::error_t &ex) {
        QString errorMsg = "Caught an exception while connecting to the server : ";
        errorMsg += ex.what();

        emit error(errorMsg);
    }
}

void Client::sendCommand(std::string& command) {
    // Cannot send command if it isn't connected to the server
    if (!ventilator.connected()) return;

    try {
        // Otherwise send the command
        ventilator.send(command.c_str(), command.length()); //message gets send

        // Let the GUI know a msg has been send
        std::string sendedMsg{ "SENDED: " };
        sendedMsg += command.c_str();
        sendedMsg += '\n';
        emit sendMessage(sendedMsg);

        // Start waiting for a reply from the server
        emit waitingForMessage();
        waitForMessage();
    }

    catch (zmq::error_t &ex) {
        QString errorMsg = "Caught an exception while sending a message : ";
        errorMsg += ex.what();

        emit error(errorMsg);
    }
}

void Client::waitForMessage() {
    // Cannot receive msg if it isn't connected to the server
    if (!subscriber.connected()) return;

    try {
        // Otherwise receive the msg
        subscriber.recv(msg); //answer received

        // Let the GUI know a msg has been received
        std::string str0 = msg->to_string().substr(17, 78);
        emit receivedMessage(str0 + '\n');

        // Start waiting for a command
        emit waitingForCommand();
    }

    catch (zmq::error_t &ex) {
        QString errorMsg = "Caught an exception while receiving a message : ";
        errorMsg += ex.what();

        emit error(errorMsg);
    }
}
