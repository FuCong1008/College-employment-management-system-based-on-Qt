/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_exit;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *combox_account;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *le_pwd;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *rBtn_isRemPwd;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_login;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(600, 342);
        gridLayout = new QGridLayout(Login);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        frame = new QFrame(Login);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        btn_exit = new QPushButton(frame);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout_6->addWidget(btn_exit);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 4);

        verticalSpacer_3 = new QSpacerItem(20, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 2, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(frame_2);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setPointSize(20);
        label_title->setFont(font);
        label_title->setContextMenuPolicy(Qt::CustomContextMenu);
        label_title->setLayoutDirection(Qt::LeftToRight);
        label_title->setTextFormat(Qt::AutoText);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setIndent(-1);

        verticalLayout->addWidget(label_title);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(38, 21));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        combox_account = new QComboBox(frame_2);
        combox_account->setObjectName(QStringLiteral("combox_account"));
        combox_account->setEditable(true);

        horizontalLayout_2->addWidget(combox_account);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(38, 21));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        le_pwd = new QLineEdit(frame_2);
        le_pwd->setObjectName(QStringLiteral("le_pwd"));

        horizontalLayout_3->addWidget(le_pwd);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        rBtn_isRemPwd = new QRadioButton(frame_2);
        rBtn_isRemPwd->setObjectName(QStringLiteral("rBtn_isRemPwd"));
        rBtn_isRemPwd->setChecked(true);

        horizontalLayout_4->addWidget(rBtn_isRemPwd);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_8 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_login = new QPushButton(frame_2);
        btn_login->setObjectName(QStringLiteral("btn_login"));

        horizontalLayout->addWidget(btn_login);

        btn_register = new QPushButton(frame_2);
        btn_register->setObjectName(QStringLiteral("btn_register"));

        horizontalLayout->addWidget(btn_register);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addWidget(frame_2, 2, 1, 2, 2);

        horizontalSpacer_4 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 1, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "SEMS", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("Login", "\303\227", Q_NULLPTR));
        label_title->setText(QApplication::translate("Login", "\351\253\230\346\240\241\345\260\261\344\270\232\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\350\264\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "\345\257\206\347\240\201", Q_NULLPTR));
        rBtn_isRemPwd->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        btn_login->setText(QApplication::translate("Login", "\347\231\273\345\205\245", Q_NULLPTR));
        btn_register->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
