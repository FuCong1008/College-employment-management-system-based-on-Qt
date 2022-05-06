/********************************************************************************
** Form generated from reading UI file 'registeruser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterUser
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *le_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_account;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *le_pwd;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *le_pwdAct;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbtn_stu;
    QRadioButton *rbtn_teacher;
    QRadioButton *rbtn_admin;
    QPushButton *btn_ack;
    QPushButton *btn_back;

    void setupUi(QWidget *RegisterUser)
    {
        if (RegisterUser->objectName().isEmpty())
            RegisterUser->setObjectName(QStringLiteral("RegisterUser"));
        RegisterUser->resize(300, 222);
        RegisterUser->setMaximumSize(QSize(300, 300));
        gridLayout_2 = new QGridLayout(RegisterUser);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(RegisterUser);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        le_name = new QLineEdit(frame);
        le_name->setObjectName(QStringLiteral("le_name"));

        horizontalLayout_5->addWidget(le_name);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        le_account = new QLineEdit(frame);
        le_account->setObjectName(QStringLiteral("le_account"));

        horizontalLayout_2->addWidget(le_account);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        le_pwd = new QLineEdit(frame);
        le_pwd->setObjectName(QStringLiteral("le_pwd"));

        horizontalLayout_3->addWidget(le_pwd);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        le_pwdAct = new QLineEdit(frame);
        le_pwdAct->setObjectName(QStringLiteral("le_pwdAct"));

        horizontalLayout_4->addWidget(le_pwdAct);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rbtn_stu = new QRadioButton(frame);
        rbtn_stu->setObjectName(QStringLiteral("rbtn_stu"));
        rbtn_stu->setChecked(true);

        horizontalLayout->addWidget(rbtn_stu);

        rbtn_teacher = new QRadioButton(frame);
        rbtn_teacher->setObjectName(QStringLiteral("rbtn_teacher"));

        horizontalLayout->addWidget(rbtn_teacher);

        rbtn_admin = new QRadioButton(frame);
        rbtn_admin->setObjectName(QStringLiteral("rbtn_admin"));

        horizontalLayout->addWidget(rbtn_admin);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        btn_ack = new QPushButton(frame);
        btn_ack->setObjectName(QStringLiteral("btn_ack"));

        gridLayout->addWidget(btn_ack, 5, 0, 1, 1);

        btn_back = new QPushButton(frame);
        btn_back->setObjectName(QStringLiteral("btn_back"));

        gridLayout->addWidget(btn_back, 5, 1, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(RegisterUser);

        QMetaObject::connectSlotsByName(RegisterUser);
    } // setupUi

    void retranslateUi(QWidget *RegisterUser)
    {
        RegisterUser->setWindowTitle(QApplication::translate("RegisterUser", "\346\263\250\345\206\214", Q_NULLPTR));
        label_5->setText(QApplication::translate("RegisterUser", "\350\276\223\345\205\245\345\247\223\345\220\215", Q_NULLPTR));
        le_name->setPlaceholderText(QApplication::translate("RegisterUser", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegisterUser", "\350\276\223\345\205\245\350\264\246\345\217\267", Q_NULLPTR));
        le_account->setPlaceholderText(QApplication::translate("RegisterUser", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterUser", "\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        le_pwd->setPlaceholderText(QApplication::translate("RegisterUser", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterUser", "\347\241\256\345\256\232\345\257\206\347\240\201", Q_NULLPTR));
        le_pwdAct->setPlaceholderText(QApplication::translate("RegisterUser", "\350\257\267\347\241\256\345\256\232\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        rbtn_stu->setText(QApplication::translate("RegisterUser", "\345\255\246\347\224\237", Q_NULLPTR));
        rbtn_teacher->setText(QApplication::translate("RegisterUser", "\346\225\231\345\270\210", Q_NULLPTR));
        rbtn_admin->setText(QApplication::translate("RegisterUser", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        btn_ack->setText(QApplication::translate("RegisterUser", "\347\241\256\345\256\232", Q_NULLPTR));
        btn_back->setText(QApplication::translate("RegisterUser", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterUser: public Ui_RegisterUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
