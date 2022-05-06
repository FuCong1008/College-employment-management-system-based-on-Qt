/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUser
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_addUser;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_account;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *le_userPwd;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_userName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *rbtn_stu;
    QRadioButton *rbtn_teacher;
    QRadioButton *rbtn_admin;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_submit;
    QPushButton *btn_reset;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AddUser)
    {
        if (AddUser->objectName().isEmpty())
            AddUser->setObjectName(QStringLiteral("AddUser"));
        AddUser->resize(323, 194);
        gridLayout_2 = new QGridLayout(AddUser);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_addUser = new QFrame(AddUser);
        frame_addUser->setObjectName(QStringLiteral("frame_addUser"));
        frame_addUser->setFrameShape(QFrame::StyledPanel);
        frame_addUser->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_addUser);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_addUser);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        le_account = new QLineEdit(frame_addUser);
        le_account->setObjectName(QStringLiteral("le_account"));

        horizontalLayout->addWidget(le_account);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(frame_addUser);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        le_userPwd = new QLineEdit(frame_addUser);
        le_userPwd->setObjectName(QStringLiteral("le_userPwd"));

        horizontalLayout_5->addWidget(le_userPwd);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_addUser);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        le_userName = new QLineEdit(frame_addUser);
        le_userName->setObjectName(QStringLiteral("le_userName"));

        horizontalLayout_2->addWidget(le_userName);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_addUser);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        rbtn_stu = new QRadioButton(frame_addUser);
        rbtn_stu->setObjectName(QStringLiteral("rbtn_stu"));
        rbtn_stu->setChecked(true);

        horizontalLayout_3->addWidget(rbtn_stu);

        rbtn_teacher = new QRadioButton(frame_addUser);
        rbtn_teacher->setObjectName(QStringLiteral("rbtn_teacher"));

        horizontalLayout_3->addWidget(rbtn_teacher);

        rbtn_admin = new QRadioButton(frame_addUser);
        rbtn_admin->setObjectName(QStringLiteral("rbtn_admin"));

        horizontalLayout_3->addWidget(rbtn_admin);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_submit = new QPushButton(frame_addUser);
        btn_submit->setObjectName(QStringLiteral("btn_submit"));

        horizontalLayout_4->addWidget(btn_submit);

        btn_reset = new QPushButton(frame_addUser);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));

        horizontalLayout_4->addWidget(btn_reset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);


        gridLayout_2->addWidget(frame_addUser, 0, 0, 1, 1);


        retranslateUi(AddUser);

        QMetaObject::connectSlotsByName(AddUser);
    } // setupUi

    void retranslateUi(QWidget *AddUser)
    {
        AddUser->setWindowTitle(QApplication::translate("AddUser", "\346\267\273\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        label->setText(QApplication::translate("AddUser", "\347\224\250\346\210\267\350\264\246\345\217\267:", Q_NULLPTR));
        le_account->setPlaceholderText(QApplication::translate("AddUser", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\350\264\246\345\217\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddUser", "\347\224\250\346\210\267\345\257\206\347\240\201:", Q_NULLPTR));
        le_userPwd->setText(QApplication::translate("AddUser", "123456", Q_NULLPTR));
        le_userPwd->setPlaceholderText(QApplication::translate("AddUser", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddUser", "\347\224\250\346\210\267\345\247\223\345\220\215:", Q_NULLPTR));
        le_userName->setPlaceholderText(QApplication::translate("AddUser", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\247\223\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddUser", "\347\224\250\346\210\267\350\272\253\344\273\275:", Q_NULLPTR));
        rbtn_stu->setText(QApplication::translate("AddUser", "\345\255\246\347\224\237", Q_NULLPTR));
        rbtn_teacher->setText(QApplication::translate("AddUser", "\346\225\231\345\270\210", Q_NULLPTR));
        rbtn_admin->setText(QApplication::translate("AddUser", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        btn_submit->setText(QApplication::translate("AddUser", "\346\217\220\344\272\244", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("AddUser", "\351\207\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddUser: public Ui_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
