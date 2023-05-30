#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new Client{};

    createConnections();

    client->setupConnection();
}

MainWindow::~MainWindow()
{
    delete client;
    delete ui;
}

void MainWindow::createConnections() {
    connect(client, &Client::error, this, &MainWindow::on_errorMsg);
    connect(client, &Client::waitingForCommand, this, &MainWindow::enableCommands);
    connect(client, &Client::waitingForCommand, ui->command, &QLineEdit::clear);
    connect(client, &Client::waitingForMessage, this, &MainWindow::disableCommands);
    connect(client, &Client::receivedMessage, this, &MainWindow::addReceivedMsgToChat);
    connect(client, &Client::sendMessage, this, &MainWindow::addSendMsgToChat);
}

void MainWindow::on_submit_pressed()
{
    std::string command{ ui->command->text().toStdString() };
    client->sendCommand(command);
}

void MainWindow::enableCommands() {
    ui->command->setEnabled(true);
    ui->submit->setEnabled(true);
}

void MainWindow::disableCommands() {
    ui->command->setEnabled(false);
    ui->submit->setEnabled(false);
}

void MainWindow::addReceivedMsgToChat(const std::string& msg) {
    ui->chat->setPlainText(ui->chat->toPlainText() + QString::fromStdString(msg));
}

void MainWindow::addSendMsgToChat(const std::string& msg) {
    ui->chat->setPlainText(ui->chat->toPlainText() + QString::fromStdString(msg));
}

void MainWindow::on_errorMsg(const QString& errorMsg) {
    QMessageBox errorBox = QMessageBox{};
    errorBox.setText(errorMsg);
    errorBox.setIcon(QMessageBox::Critical);
    errorBox.exec();
}
