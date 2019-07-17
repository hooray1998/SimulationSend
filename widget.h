#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QTemporaryFile>
#include <QFileIconProvider>
#include <QtDebug>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTimer>
#include <QWidget>
#include <QTcpSocket>  //通信套接字
#include <QKeyEvent>
#include <QLineEdit>
#include <QStringListModel>
#include <QListView>
#include <QFile>
#include <QUdpSocket>
#include <QTableWidget>
#define MAX_USER 100

namespace Ui {
class Widget;
}

class Record{
public:
    bool die;
    bool isread;
    QString name;
    QStringList msgList;
    Record(){
        isread = true;
        die = true;
    }
};


class FileInfo{
public:
    QString filename;
    QString filetype;
    QString filesize;
    QString sizecount;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void showLoginWidget();
    void showLoginWidget(bool autoLogin, char *argv);
    void test();
private slots:
    void on_connectPushButton_clicked();

    void on_pushButton_2_clicked();

    void Disconnect();

    void chatWith(QModelIndex index);

    void addUser(QString user);
    void delUser(QString user);

    void analyzeData();
    //void SendText();

    void changeChatWith();

    int findOrCreate(QString);
    void recordMsg(QString send, QString msg);
    void showMsg();

    void initUdpSocket();
    void sendData();
    void readPendingDatagrams();

    void startReplyTimer();
    void stopReplyTimer();

    void connectslot();
    void loginslot();
protected:
    //bool eventFilter(QObject *target, QEvent *event);
    void closeEvent(QCloseEvent*e);

private:
    Ui::Widget *ui;
    QTcpSocket *pTcpSocket;
    int mode;
    bool connected;
    QTimer *connectTimer;

    QString id;
    QWidget *loginWidget;
    //QWidget *fileWidget;
    QStringListModel *model;
    QListView *list;
    QStringList userList;
    int userNum;
    QString curChat;

    Record *record[MAX_USER];//切换窗口，
    int maxUserNum;

    QLineEdit *name ;

    QUdpSocket *udpSocket;
    int udpPort;
    QFile file;
    int i;

    QString lastMsg;


    QTableWidget *fileWidget;
    FileInfo    fileinfo[100];
    int fileNum;
    bool receiving;

    int all_pianShu;
     QPixmap *mBackPic;

    QTimer *replyTimer;
};

#endif // WIDGET_H
