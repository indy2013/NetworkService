
#ifndef CLIENT_H
#define CLIENT_H


#include "zmq.hpp"
#include <QObject>


class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    ~Client();

    void setupConnection();

    void sendCommand(std::string& command);
    void waitForMessage();

signals:
    void waitingForCommand();
    void waitingForMessage();
    void sendMessage(const std::string& msg);
    void receivedMessage(const std::string& msg);
    void error(const QString& errorMsg);

private:
    zmq::context_t context;
    zmq::message_t* msg{};

    zmq::socket_t subscriber;
    zmq::socket_t ventilator;

};

#endif // CLIENT_H
