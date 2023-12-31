#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("蓝牙终端信息后台");

    url = "http://192.168.3.111/gap/nodes/?event=1";

    ui->le_url->setText(url);
    ui->le_url->setEnabled(false);
    ui->le_url->setToolTip("请在设置中修改");

    ui->lw_device->setToolTip("选中后在设备信息查看详情");

    connect(ui->pb_get, &QPushButton::clicked, this, &MainWindow::HandleApiRequest);
    connect(ui->menu->actions().at(0), &QAction::triggered, [&]() {
        bool ok;
        QString newUrl = QInputDialog::getText(this, "修改URL", "请输入新的URL:", QLineEdit::Normal, url, &ok);
        if (ok) {
            url = newUrl;
            QMessageBox::information(this, "提示", "URL已更新为：" + url);
        }
    });
    connect(ui->menu_2->actions().at(0), &QAction::triggered, [&]() {
        this->ui->tb_msg->clear();
        QMessageBox::information(this, "提示", "清除成功");
    });
    connect(ui->menu_2->actions().at(1), &QAction::triggered, [&]() {
        this->ui->lw_device->clear();
        QMessageBox::information(this, "提示", "清除成功");
    });


//    DataFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DataFromFile()
{
    QFile file("./data.txt");
    file.open(QIODevice::ReadWrite);
    QByteArray myByteArray = file.readAll();
    int size = myByteArray.size();
    for (int i = 0; i < size; i += 1024) {
        QByteArray subByteArray = myByteArray.mid(i, 1024);
        qDebug() << "#####" << subByteArray;
        qDebug() << "";
        handleDataChunk(subByteArray);
    }
    file.close();
}

void MainWindow::HandleApiRequest()
{
    // url params
    url = "http://192.168.3.111/gap/nodes/?event=1" + CheckFilterName() + CheckFilterMac();

    // "get" request stream data
    reply = manager.get(QNetworkRequest(QUrl(url)));
    reply->setReadBufferSize(1024);
    connect(reply, &QNetworkReply::readyRead, this, &MainWindow::checkoutReplyBuffer);
    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

    // loop start
    eventLoop.exec();

    // handle with http error
    if (reply->error() != QNetworkReply::NoError) {
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug( "request protobufHttp found error ....code: %d %d\n", statusCodeV.toInt(), reply->error());
        qDebug(qPrintable(reply->errorString()));
    }

    QByteArray responseByte = reply->readAll();
    qDebug() << responseByte;
}

void MainWindow::checkoutReplyBuffer()
{
    qint64 buffer_size = reply->bytesAvailable();
    if (buffer_size >= 1024){
        QByteArray byte1024 = reply->readAll();
//        handleDataChunk(byte1024);

//        dataStr.append(QString::fromUtf8(byte1024));
//        qDebug().noquote() << byte1024;
    }
}

void MainWindow::handleDataChunk(QByteArray chunk)
{
    QByteArray buffer;
    // add playload to buffer
    buffer.append(QString::fromUtf8(chunk));

    // Match all JSON string
    int openBraces = 0;
    int closeBraces = 0;
    int lastClosingBrace = -1;

    for(int index = 0; index < buffer.size(); index++){
      if(buffer[index] == '{') {
         openBraces++;
      } else if (buffer[index] == '}') {
         closeBraces++;
         if (openBraces == closeBraces) { lastClosingBrace = index; }
      }
    }
    if (lastClosingBrace != -1) {
//        qDebug() << "Find a piece of new Data";
        QByteArray jsonString = buffer.left(lastClosingBrace+1);
        qDebug() <<  jsonString;
        qDebug() << "";

        // remove data first of buffer
        buffer.remove(0, lastClosingBrace+1);

        // QByteArray to JSON
        QJsonDocument doc = QJsonDocument::fromJson(MatchJsonObj(jsonString).data());
        QJsonObject data = doc.object();
        if (doc.isNull()){
            qDebug() << "ERROR: Data is Null";
        }

        // handle value
        QString name = data["name"].toString();
        QString evt_type = data["evt_type"].toString();
        QString rssi = data["rssi"].toString();
        QString adData = data["adData"].toString();
        QJsonObject bdaddrs = data["bdaddrs"].toObject();
        QString bdaddr = bdaddrs["bdaddr"].toString();
        QString bdaddrType = bdaddrs["bdaddrType"].toString();

        QStringList msg;
        msg << bdaddr << rssi << adData;
        // show data
        HandleLwDevice(name);
        HandleTbMsg(msg);
    }
}

QByteArray MainWindow::MatchJsonObj(QByteArray byteArray)
{
    QRegularExpression regex("\\{(.*)\\}");
    QRegularExpressionMatch match = regex.match(byteArray);
    if (match.hasMatch()){
//      qDebug() << "Match values in new Data";
      QString matchedText = match.captured(0);
      byteArray = matchedText.toUtf8();
      return byteArray;
    }
    return "";
}

void MainWindow::HandleTbMsg(QStringList msg)
{
    // insert tb_msg
    QString msgLine = "设备地址：" + msg[0] + "信号强度：" + msg[1] + " 接收数据：" + msg[2] + "\r";
    ui->tb_msg->append(msgLine);

    QString content = ui->tb_msg->toPlainText();
    int lineCount = ui->tb_msg->document()->lineCount();

    if (lineCount > 100) {
        ui->tb_msg->clear();
    }
}

void MainWindow::HandleLwDevice(QString name)
{
    // Check for existence before insertion
    QList<QListWidgetItem *> items = ui->lw_device->findItems(name, Qt::MatchExactly);
    if (items.isEmpty()) {
        ui->lw_device->addItem(name);
    }
}

QString MainWindow::CheckFilterName()
{
    if(ui->cb_name->isChecked()){
        QString device_name = ui->le_name->text();
        return "&filter_name=" + device_name;
    } else {
        return "";
    }
}

QString MainWindow::CheckFilterMac()
{
    if(ui->cb_mac->isChecked()){
        QString device_mac = ui->le_mac->text();
        return "&filter_mac=" + device_mac;
    } else {
        return "";
    }
}


