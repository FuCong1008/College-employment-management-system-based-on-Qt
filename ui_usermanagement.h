/********************************************************************************
** Form generated from reading UI file 'usermanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENT_H
#define UI_USERMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManagement
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_userManage;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *le_account;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_query;
    QPushButton *btn_reset;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *le_userName;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QComboBox *combox_identity;
    QSpacerItem *horizontalSpacer_19;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_userInfo;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_save;
    QTableWidget *tableWidget_userInfo;

    void setupUi(QWidget *UserManagement)
    {
        if (UserManagement->objectName().isEmpty())
            UserManagement->setObjectName(QStringLiteral("UserManagement"));
        UserManagement->resize(1700, 950);
        gridLayout = new QGridLayout(UserManagement);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_userManage = new QFrame(UserManagement);
        frame_userManage->setObjectName(QStringLiteral("frame_userManage"));
        frame_userManage->setFrameShape(QFrame::StyledPanel);
        frame_userManage->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_userManage);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(frame_userManage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 19, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        le_account = new QLineEdit(groupBox);
        le_account->setObjectName(QStringLiteral("le_account"));

        horizontalLayout_3->addWidget(le_account);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 18, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 20, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btn_query = new QPushButton(groupBox);
        btn_query->setObjectName(QStringLiteral("btn_query"));

        horizontalLayout_5->addWidget(btn_query);

        btn_reset = new QPushButton(groupBox);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));

        horizontalLayout_5->addWidget(btn_reset);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 21, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 14, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 0, 16, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 0, 15, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 0, 7, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 0, 13, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_13, 0, 9, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 0, 11, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 0, 17, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_18, 0, 12, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 0, 8, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_17, 0, 10, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        le_userName = new QLineEdit(groupBox);
        le_userName->setObjectName(QStringLiteral("le_userName"));

        horizontalLayout_4->addWidget(le_userName);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        combox_identity = new QComboBox(groupBox);
        combox_identity->setObjectName(QStringLiteral("combox_identity"));

        horizontalLayout->addWidget(combox_identity);


        gridLayout_2->addLayout(horizontalLayout, 0, 4, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_19, 0, 6, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        frame_2 = new QFrame(frame_userManage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_userInfo = new QPushButton(frame_2);
        btn_userInfo->setObjectName(QStringLiteral("btn_userInfo"));

        horizontalLayout_2->addWidget(btn_userInfo);

        horizontalSpacer_3 = new QSpacerItem(828, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_save = new QPushButton(frame_2);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout_2->addWidget(btn_save);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget_userInfo = new QTableWidget(frame_2);
        tableWidget_userInfo->setObjectName(QStringLiteral("tableWidget_userInfo"));

        verticalLayout->addWidget(tableWidget_userInfo);


        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);


        gridLayout->addWidget(frame_userManage, 0, 0, 1, 1);


        retranslateUi(UserManagement);

        QMetaObject::connectSlotsByName(UserManagement);
    } // setupUi

    void retranslateUi(QWidget *UserManagement)
    {
        UserManagement->setWindowTitle(QApplication::translate("UserManagement", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserManagement", "\346\220\234\347\264\242\346\235\241\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("UserManagement", "\347\224\250\346\210\267\350\264\246\345\217\267:", Q_NULLPTR));
        le_account->setPlaceholderText(QApplication::translate("UserManagement", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", Q_NULLPTR));
        btn_query->setText(QApplication::translate("UserManagement", "\346\237\245\350\257\242", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("UserManagement", "\351\207\215\347\275\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserManagement", "\347\224\250\346\210\267\345\247\223\345\220\215:", Q_NULLPTR));
        le_userName->setPlaceholderText(QApplication::translate("UserManagement", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("UserManagement", "\347\224\250\346\210\267\350\272\253\344\273\275:", Q_NULLPTR));
        combox_identity->clear();
        combox_identity->insertItems(0, QStringList()
         << QApplication::translate("UserManagement", "\345\255\246\347\224\237", Q_NULLPTR)
         << QApplication::translate("UserManagement", "\346\225\231\345\270\210", Q_NULLPTR)
         << QApplication::translate("UserManagement", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR)
        );
        btn_userInfo->setText(QApplication::translate("UserManagement", "\346\267\273\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        btn_save->setText(QApplication::translate("UserManagement", "\346\233\264\346\226\260\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserManagement: public Ui_UserManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENT_H
