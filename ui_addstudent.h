/********************************************************************************
** Form generated from reading UI file 'addstudent.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENT_H
#define UI_ADDSTUDENT_H

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

class Ui_AddStudent
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_addStu;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_6;
    QLineEdit *le_stuNumber;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_18;
    QLineEdit *le_stuClass;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLineEdit *le_stuName;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *le_stuPhone;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *combox_faculty;
    QComboBox *combox_stuMajor;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_17;
    QRadioButton *rbtn_man;
    QRadioButton *rbtn_woman;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QLineEdit *le_stuJiuYeDate;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_company;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *le_post;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_submit;
    QPushButton *btn_reset;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AddStudent)
    {
        if (AddStudent->objectName().isEmpty())
            AddStudent->setObjectName(QStringLiteral("AddStudent"));
        AddStudent->resize(282, 322);
        gridLayout = new QGridLayout(AddStudent);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_addStu = new QFrame(AddStudent);
        frame_addStu->setObjectName(QStringLiteral("frame_addStu"));
        frame_addStu->setFrameShape(QFrame::StyledPanel);
        frame_addStu->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_addStu);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_6 = new QLabel(frame_addStu);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_16->addWidget(label_6);

        le_stuNumber = new QLineEdit(frame_addStu);
        le_stuNumber->setObjectName(QStringLiteral("le_stuNumber"));

        horizontalLayout_16->addWidget(le_stuNumber);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_18 = new QLabel(frame_addStu);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_18);

        le_stuClass = new QLineEdit(frame_addStu);
        le_stuClass->setObjectName(QStringLiteral("le_stuClass"));

        horizontalLayout_13->addWidget(le_stuClass);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_14 = new QLabel(frame_addStu);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_14);

        le_stuName = new QLineEdit(frame_addStu);
        le_stuName->setObjectName(QStringLiteral("le_stuName"));

        horizontalLayout_6->addWidget(le_stuName);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(frame_addStu);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_5);

        le_stuPhone = new QLineEdit(frame_addStu);
        le_stuPhone->setObjectName(QStringLiteral("le_stuPhone"));

        horizontalLayout_9->addWidget(le_stuPhone);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(frame_addStu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        combox_faculty = new QComboBox(frame_addStu);
        combox_faculty->setObjectName(QStringLiteral("combox_faculty"));

        horizontalLayout_2->addWidget(combox_faculty);

        combox_stuMajor = new QComboBox(frame_addStu);
        combox_stuMajor->setObjectName(QStringLiteral("combox_stuMajor"));

        horizontalLayout_2->addWidget(combox_stuMajor);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_17 = new QLabel(frame_addStu);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_17);

        rbtn_man = new QRadioButton(frame_addStu);
        rbtn_man->setObjectName(QStringLiteral("rbtn_man"));
        rbtn_man->setChecked(true);

        horizontalLayout_8->addWidget(rbtn_man);

        rbtn_woman = new QRadioButton(frame_addStu);
        rbtn_woman->setObjectName(QStringLiteral("rbtn_woman"));

        horizontalLayout_8->addWidget(rbtn_woman);

        horizontalSpacer_3 = new QSpacerItem(40, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_15 = new QLabel(frame_addStu);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_15);

        le_stuJiuYeDate = new QLineEdit(frame_addStu);
        le_stuJiuYeDate->setObjectName(QStringLiteral("le_stuJiuYeDate"));

        horizontalLayout_10->addWidget(le_stuJiuYeDate);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_addStu);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        le_company = new QLineEdit(frame_addStu);
        le_company->setObjectName(QStringLiteral("le_company"));

        horizontalLayout->addWidget(le_company);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(frame_addStu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        le_post = new QLineEdit(frame_addStu);
        le_post->setObjectName(QStringLiteral("le_post"));

        horizontalLayout_3->addWidget(le_post);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        btn_submit = new QPushButton(frame_addStu);
        btn_submit->setObjectName(QStringLiteral("btn_submit"));

        horizontalLayout_14->addWidget(btn_submit);

        btn_reset = new QPushButton(frame_addStu);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));

        horizontalLayout_14->addWidget(btn_reset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_14);


        gridLayout->addWidget(frame_addStu, 0, 0, 1, 1);


        retranslateUi(AddStudent);

        QMetaObject::connectSlotsByName(AddStudent);
    } // setupUi

    void retranslateUi(QWidget *AddStudent)
    {
        AddStudent->setWindowTitle(QApplication::translate("AddStudent", "\346\267\273\345\212\240\345\255\246\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddStudent", "\345\255\246\347\224\237\345\255\246\345\217\267:", Q_NULLPTR));
        le_stuNumber->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\255\246\345\217\267", Q_NULLPTR));
        label_18->setText(QApplication::translate("AddStudent", "\345\255\246\347\224\237\347\217\255\347\272\247:", Q_NULLPTR));
        le_stuClass->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\347\217\255\347\272\247", Q_NULLPTR));
        label_14->setText(QApplication::translate("AddStudent", "\345\255\246\347\224\237\345\247\223\345\220\215:", Q_NULLPTR));
        le_stuName->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\247\223\345\220\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddStudent", "\345\255\246\347\224\237\347\224\265\350\257\235:", Q_NULLPTR));
        le_stuPhone->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\347\224\265\350\257\235", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddStudent", "\345\255\246\347\224\237\344\270\223\344\270\232:", Q_NULLPTR));
        label_17->setText(QApplication::translate("AddStudent", "\345\255\246\347\224\237\346\200\247\345\210\253:", Q_NULLPTR));
        rbtn_man->setText(QApplication::translate("AddStudent", "\347\224\267", Q_NULLPTR));
        rbtn_woman->setText(QApplication::translate("AddStudent", "\345\245\263", Q_NULLPTR));
        label_15->setText(QApplication::translate("AddStudent", "\345\260\261\344\270\232\346\227\266\351\227\264:", Q_NULLPTR));
        le_stuJiuYeDate->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\260\261\344\270\232\346\227\266\351\227\264", Q_NULLPTR));
        label->setText(QApplication::translate("AddStudent", "\345\260\261\344\270\232\345\215\225\344\275\215:", Q_NULLPTR));
        le_company->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\345\215\225\344\275\215\345\220\215\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddStudent", "\345\260\261\344\270\232\345\262\227\344\275\215:", Q_NULLPTR));
        le_post->setPlaceholderText(QApplication::translate("AddStudent", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\345\262\227\344\275\215", Q_NULLPTR));
        btn_submit->setText(QApplication::translate("AddStudent", "\346\217\220\344\272\244", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("AddStudent", "\351\207\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddStudent: public Ui_AddStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENT_H
