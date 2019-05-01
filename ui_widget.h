/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *chatNameLabel;
    QLabel *nameLabel;
    QTextEdit *textEditRead;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *textEditWrite;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *connectPushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(431, 426);
        Widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(257, 110));
        tabWidget->setMaximumSize(QSize(499493, 434343));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setIconSize(QSize(16, 8));
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        chatNameLabel = new QLabel(tab);
        chatNameLabel->setObjectName(QStringLiteral("chatNameLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chatNameLabel->sizePolicy().hasHeightForWidth());
        chatNameLabel->setSizePolicy(sizePolicy1);
        chatNameLabel->setMinimumSize(QSize(0, 55));
        chatNameLabel->setMaximumSize(QSize(16777215, 49));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(36);
        chatNameLabel->setFont(font);

        horizontalLayout_3->addWidget(chatNameLabel);

        nameLabel = new QLabel(tab);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy2);
        nameLabel->setMinimumSize(QSize(0, 50));
        nameLabel->setFont(font);

        horizontalLayout_3->addWidget(nameLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEditRead = new QTextEdit(tab);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\273\277\345\256\213"));
        font1.setPointSize(14);
        textEditRead->setFont(font1);
        textEditRead->setStyleSheet(QStringLiteral(""));
        textEditRead->setReadOnly(true);

        verticalLayout_2->addWidget(textEditRead);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        textEditWrite = new QTextEdit(tab);
        textEditWrite->setObjectName(QStringLiteral("textEditWrite"));
        textEditWrite->setMaximumSize(QSize(16777215, 250));
        textEditWrite->setFont(font1);

        horizontalLayout_6->addWidget(textEditWrite);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        pushButton_2->setMinimumSize(QSize(200, 40));
        pushButton_2->setMaximumSize(QSize(500, 230));

        horizontalLayout_6->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 40));
        pushButton_3->setMaximumSize(QSize(100, 40));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 209, 74));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        connectPushButton = new QPushButton(layoutWidget);
        connectPushButton->setObjectName(QStringLiteral("connectPushButton"));

        horizontalLayout_2->addWidget(connectPushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_5->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>\351\205\215\347\275\256</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chatNameLabel->setText(QApplication::translate("Widget", "\350\256\276\345\244\207", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        textEditWrite->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\273\277\345\256\213'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "Reply", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\345\205\263\351\227\255", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "IP  \357\274\232", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Widget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("Widget", "8888", Q_NULLPTR));
        connectPushButton->setText(QApplication::translate("Widget", "\346\234\252\350\277\236\346\216\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\351\205\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
