#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <time.h>
#define ONE_SIZE 8000
#define DBG qDebug()<<__FILE__<<__FUNCTION__<<"():"<<__LINE__
/// 用户名居中显示
/// 自己的信息靠右显示
/// 服务器断开得有反应
///
/// 未读消息提醒
///
///
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(NULL));

    //读取配置文件
    lastMsg = "init";
    QFile *f_ip = new QFile("init_ip.txt");
    if(f_ip->open(QIODevice::ReadOnly))
    {
        ui->lineEdit->setText(f_ip->readAll());
        f_ip->close();
    }

    mode = -1;
    curChat = "设备";
    maxUserNum = 0;
    connected = false;

    this->setWindowTitle("fakeTim");

    pTcpSocket = NULL;

    //分配空间，指定父对象
    pTcpSocket = new QTcpSocket(this);


    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_connectPushButton_clicked()));

    //弹出来一个提示而已
    connect(pTcpSocket, SIGNAL(connected()),this,SLOT(connectslot()) );
    connect(pTcpSocket, SIGNAL(disconnected()), this, SLOT(slot_disconnect()));

    //显示来自服务器的消息
    connect(pTcpSocket, SIGNAL(readyRead()),this,SLOT(analyzeData()));

    on_connectPushButton_clicked();//开机连接

    ui->text1->hide();
    ui->text2->hide();
    ui->doubleSpinBox1->hide();
    ui->doubleSpinBox2->hide();

}

Widget::~Widget()
{
    delete ui;
}


//与服务器建立连接
void Widget::on_connectPushButton_clicked()
{
        if(connected)
        {
            qDebug()<<"请求断开。。。。。。。";
            userList.clear();
            userList<<"设备";
            model->setStringList(userList);


            ui->connectPushButton->setText("未连接");
            connected = false;

            pTcpSocket->disconnectFromHost();
            ui->textEditRead->append("断开连接");
        }
        else
        {
            //获得服务器的IP和端口
            QString ip = ui->lineEdit->text();
            qint16 port = ui->lineEdit_2->text().toInt();

            //主动和服务器将建立连接
            pTcpSocket->connectToHost(QHostAddress(ip), port);
        }
}


void Widget::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked()){
        ui->doubleSpinBox1->setValue(rand()%5000+500);
        ui->doubleSpinBox2->setValue(rand()%2000+1500);
    }
    char msg[25];

    if(lastMsg=="04"||lastMsg=="14"||lastMsg=="24"){//request a
        sprintf(msg,"%06d02%08.3f", id.toInt(),ui->doubleSpinBox1->value());
        pTcpSocket->write(QString(msg).toUtf8().data());
        QString str = "[ME][回复a值]: " + QString(msg);
        ui->textEditRead->append(str);
    }
    else if(lastMsg == "06"){
        sprintf(msg,"%06d03%08.3f%08.3f", id.toInt(),ui->doubleSpinBox1->value(),ui->doubleSpinBox2->value());
        pTcpSocket->write(QString(msg).toUtf8().data());
        QString str = "[ME][回复b值]: " + QString(msg);
        ui->textEditRead->append(str);
    }
    else if(lastMsg == "07"){
        sprintf(msg,"%06d02%08.3f", id.toInt(),ui->doubleSpinBox1->value());
        pTcpSocket->write(QString(msg).toUtf8().data());
        QString str = "[ME][回复r值]: " + QString(msg);
        ui->textEditRead->append(str);
    }

    ui->text1->hide();
    ui->text2->hide();
    ui->doubleSpinBox1->hide();
    ui->doubleSpinBox2->hide();


}

//断开连接
void Widget::Disconnect()
{
    userList.clear();
    userList<<"设备";
    model->setStringList(userList);

   ui->connectPushButton->setText("未连接");
   connected = false;

    pTcpSocket->disconnectFromHost();
    ui->textEditRead->append("断开连接");

    this->close();
}

void Widget::showLoginWidget()
{
    loginWidget = new QWidget();
    loginWidget->resize(QSize(400,300));

    name = new QLineEdit(loginWidget);
    name->setMaxLength(6);
    name->setPlaceholderText("用户名");
    name->setFont(QFont(NULL,25));

    QPushButton *loginButton = new QPushButton(loginWidget);
    loginButton->setText("登录");
    loginButton->setFont(QFont(NULL,25));

    name->setGeometry(50,50,300,50);

    loginButton->setGeometry(120,220,160,50);
    loginWidget->show();
    connect(name,SIGNAL(returnPressed()),this,SLOT(loginslot()) );
    connect(loginButton, SIGNAL(clicked()),this, SLOT(loginslot()));
}


void Widget::analyzeData()
{
       //从通信套接字中间取出内容
        lastMsg = (pTcpSocket->readAll());

        QString msg;
        if(lastMsg=="04"||lastMsg=="14"||lastMsg=="24"){
			msg = QString("[SR][请求a值]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
            ui->text1->show();
            ui->doubleSpinBox1->show();
            ui->text1->setText("请输入显示值:");
            if(ui->radioButton->isChecked())
                on_pushButton_2_clicked();
        }
        else if(lastMsg=="06"){
			msg = QString("[SR][请求b值]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
            ui->text1->show();
            ui->doubleSpinBox1->show();
            ui->text1->setText("请输入当前水量:");
            ui->text2->show();
            ui->doubleSpinBox2->show();
            ui->text2->setText("请输入原值:");
            if(ui->radioButton->isChecked())
                on_pushButton_2_clicked();
        }
        else if(lastMsg=="07"){
			msg = QString("[SR][请求r值]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
            ui->text1->show();
            ui->doubleSpinBox1->show();
            ui->text1->setText("请输入最终值:");
            if(ui->radioButton->isChecked())
                on_pushButton_2_clicked();
        }
        else if(lastMsg.left(2)=="35"||lastMsg.left(2)=="45"){
			msg = QString("[SR][补充指令]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
            pTcpSocket->write("80");
            QString str = "[ME][补充回复]: 80" ;
            ui->textEditRead->append(str);
        }
        else if(lastMsg.left(2)=="15"||lastMsg.left(2)=="25"||lastMsg.left(2)=="65"){
			msg = QString("[SR][调试通知]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
            pTcpSocket->write("55");
            QString str = "[ME][通知确认]: 55" ;
            ui->textEditRead->append(str);
        }
        else if(lastMsg.left(2)=="05"){
			msg = QString("[SR][VS终值返回]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
		}
        else if(lastMsg.left(2)=="08"){
			msg = QString("[SR][精度稳定返回]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
		}
        else if(lastMsg=="11"){
			msg = QString("[SR][切换精度]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
		}
        else if(lastMsg=="91"){
			msg = QString("[SR][中止调试]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
		}
        else if(lastMsg=="ok"){
			msg = QString("[SR][连接成功]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
		}
		else{
			msg = QString("[SR][暂未识别]: %2").arg(lastMsg);
			ui->textEditRead->append(msg); //在后面追加新的消息
		}


}


void Widget::closeEvent(QCloseEvent *e)
{
    Disconnect();
    e->accept();
}

void Widget::connectslot()
{
   ui->connectPushButton->setText("已连接");
   ui->textEditRead->append("连接成功");
   connected = true;
}

void  Widget::loginslot()
{
    id = name->text();
    this->show();
    //ui->textEditWrite->setFocus();
    ui->nameLabel->setText(id);
    loginWidget->close();
	while(id.size()!=6) id.append(" ");
    QString msg = id.append("01");
    pTcpSocket->write(msg.toUtf8().data());
}

void Widget::slot_disconnect(){
   ui->textEditRead->append("断开连接");
   connected = false;
}
