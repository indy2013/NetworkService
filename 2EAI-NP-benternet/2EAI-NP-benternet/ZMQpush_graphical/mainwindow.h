#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submit_pressed();
    void on_errorMsg(const QString& errorMsg);
    void enableCommands();
    void disableCommands();
    void addReceivedMsgToChat(const std::string& msg);
    void addSendMsgToChat(const std::string& msg);

private:
    Ui::MainWindow *ui;

    Client* client{};

    void createConnections();
};

#endif // MAINWINDOW_H
