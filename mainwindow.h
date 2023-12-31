#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QRegularExpression>
#include <QListWidgetItem>
#include <QInputDialog>

#include <QFile>


namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DataFromFile();

    void checkoutReplyBuffer();
    void handleDataChunk(QByteArray chunk);
    QByteArray MatchJsonObj(QByteArray byteArray);
    QString CheckFilterName();
    QString CheckFilterMac();
    void HandleTbMsg(QStringList msg);

    void HandleLwDevice(QString name);

public slots:
    void HandleApiRequest();

private:
    Ui::MainWindow *ui;
    QString url;
    QString search_url;
    QEventLoop eventLoop;
    QNetworkReply *reply;
    QNetworkAccessManager manager;
};

#endif // MAINWINDOW_H
