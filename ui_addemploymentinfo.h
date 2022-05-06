/********************************************************************************
** Form generated from reading UI file 'addemploymentinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEMPLOYMENTINFO_H
#define UI_ADDEMPLOYMENTINFO_H

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

class Ui_AddEmploymentInfo
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_addEmploy;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLineEdit *le_stuName;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *le_stuPhone;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_company;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QLineEdit *le_stuJiuYeDate;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLineEdit *le_salary;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_18;
    QLineEdit *le_stuClass;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_6;
    QLineEdit *le_stuNumber;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *le_post;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *le_ability;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QComboBox *combox_subProvince;
    QComboBox *combox_subCity;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *le_contacterName;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QLineEdit *le_contacterPhone;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_17;
    QRadioButton *rbtn_man;
    QRadioButton *rbtn_woman;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_8;
    QComboBox *combox_faculty;
    QComboBox *combox_stuMajor;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_submit;
    QPushButton *btn_reset;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AddEmploymentInfo)
    {
        if (AddEmploymentInfo->objectName().isEmpty())
            AddEmploymentInfo->setObjectName(QStringLiteral("AddEmploymentInfo"));
        AddEmploymentInfo->resize(618, 268);
        gridLayout = new QGridLayout(AddEmploymentInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_addEmploy = new QFrame(AddEmploymentInfo);
        frame_addEmploy->setObjectName(QStringLiteral("frame_addEmploy"));
        frame_addEmploy->setFrameShape(QFrame::StyledPanel);
        frame_addEmploy->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_addEmploy);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_14 = new QLabel(frame_addEmploy);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_14);

        le_stuName = new QLineEdit(frame_addEmploy);
        le_stuName->setObjectName(QStringLiteral("le_stuName"));

        horizontalLayout_6->addWidget(le_stuName);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(frame_addEmploy);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_5);

        le_stuPhone = new QLineEdit(frame_addEmploy);
        le_stuPhone->setObjectName(QStringLiteral("le_stuPhone"));

        horizontalLayout_9->addWidget(le_stuPhone);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_addEmploy);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        le_company = new QLineEdit(frame_addEmploy);
        le_company->setObjectName(QStringLiteral("le_company"));

        horizontalLayout->addWidget(le_company);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_15 = new QLabel(frame_addEmploy);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_15);

        le_stuJiuYeDate = new QLineEdit(frame_addEmploy);
        le_stuJiuYeDate->setObjectName(QStringLiteral("le_stuJiuYeDate"));

        horizontalLayout_10->addWidget(le_stuJiuYeDate);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_13 = new QLabel(frame_addEmploy);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_13);

        le_salary = new QLineEdit(frame_addEmploy);
        le_salary->setObjectName(QStringLiteral("le_salary"));

        horizontalLayout_4->addWidget(le_salary);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 5, 2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_18 = new QLabel(frame_addEmploy);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_18);

        le_stuClass = new QLineEdit(frame_addEmploy);
        le_stuClass->setObjectName(QStringLiteral("le_stuClass"));

        horizontalLayout_13->addWidget(le_stuClass);


        gridLayout_2->addLayout(horizontalLayout_13, 0, 2, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_6 = new QLabel(frame_addEmploy);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_16->addWidget(label_6);

        le_stuNumber = new QLineEdit(frame_addEmploy);
        le_stuNumber->setObjectName(QStringLiteral("le_stuNumber"));

        horizontalLayout_16->addWidget(le_stuNumber);


        gridLayout_2->addLayout(horizontalLayout_16, 1, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(frame_addEmploy);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        le_post = new QLineEdit(frame_addEmploy);
        le_post->setObjectName(QStringLiteral("le_post"));

        horizontalLayout_3->addWidget(le_post);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(frame_addEmploy);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_3);

        le_ability = new QLineEdit(frame_addEmploy);
        le_ability->setObjectName(QStringLiteral("le_ability"));

        horizontalLayout_5->addWidget(le_ability);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(frame_addEmploy);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(68, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        combox_subProvince = new QComboBox(frame_addEmploy);
        combox_subProvince->setObjectName(QStringLiteral("combox_subProvince"));

        horizontalLayout_2->addWidget(combox_subProvince);

        combox_subCity = new QComboBox(frame_addEmploy);
        combox_subCity->setObjectName(QStringLiteral("combox_subCity"));

        horizontalLayout_2->addWidget(combox_subCity);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_2, 4, 2, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(frame_addEmploy);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_11);

        le_contacterName = new QLineEdit(frame_addEmploy);
        le_contacterName->setObjectName(QStringLiteral("le_contacterName"));

        horizontalLayout_11->addWidget(le_contacterName);


        horizontalLayout_15->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(frame_addEmploy);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_16);

        le_contacterPhone = new QLineEdit(frame_addEmploy);
        le_contacterPhone->setObjectName(QStringLiteral("le_contacterPhone"));

        horizontalLayout_12->addWidget(le_contacterPhone);


        horizontalLayout_15->addLayout(horizontalLayout_12);


        gridLayout_2->addLayout(horizontalLayout_15, 5, 0, 1, 3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_17 = new QLabel(frame_addEmploy);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_17);

        rbtn_man = new QRadioButton(frame_addEmploy);
        rbtn_man->setObjectName(QStringLiteral("rbtn_man"));
        rbtn_man->setChecked(true);

        horizontalLayout_8->addWidget(rbtn_man);

        rbtn_woman = new QRadioButton(frame_addEmploy);
        rbtn_woman->setObjectName(QStringLiteral("rbtn_woman"));

        horizontalLayout_8->addWidget(rbtn_woman);


        gridLayout_2->addLayout(horizontalLayout_8, 6, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_8 = new QLabel(frame_addEmploy);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(68, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_8);

        combox_faculty = new QComboBox(frame_addEmploy);
        combox_faculty->setObjectName(QStringLiteral("combox_faculty"));

        horizontalLayout_18->addWidget(combox_faculty);

        combox_stuMajor = new QComboBox(frame_addEmploy);
        combox_stuMajor->setObjectName(QStringLiteral("combox_stuMajor"));

        horizontalLayout_18->addWidget(combox_stuMajor);


        gridLayout_2->addLayout(horizontalLayout_18, 6, 1, 1, 2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        btn_submit = new QPushButton(frame_addEmploy);
        btn_submit->setObjectName(QStringLiteral("btn_submit"));

        horizontalLayout_7->addWidget(btn_submit);

        btn_reset = new QPushButton(frame_addEmploy);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));

        horizontalLayout_7->addWidget(btn_reset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_7, 7, 0, 1, 3);


        gridLayout->addWidget(frame_addEmploy, 0, 0, 1, 1);


        retranslateUi(AddEmploymentInfo);

        QMetaObject::connectSlotsByName(AddEmploymentInfo);
    } // setupUi

    void retranslateUi(QWidget *AddEmploymentInfo)
    {
        AddEmploymentInfo->setWindowTitle(QApplication::translate("AddEmploymentInfo", "\346\267\273\345\212\240\345\260\261\344\270\232\344\277\241\346\201\257", Q_NULLPTR));
        label_14->setText(QApplication::translate("AddEmploymentInfo", "\345\255\246\347\224\237\345\247\223\345\220\215:", Q_NULLPTR));
        le_stuName->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\247\223\345\220\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddEmploymentInfo", "\345\255\246\347\224\237\347\224\265\350\257\235:", Q_NULLPTR));
        le_stuPhone->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\347\224\265\350\257\235", Q_NULLPTR));
        label->setText(QApplication::translate("AddEmploymentInfo", "\345\260\261\344\270\232\345\215\225\344\275\215:", Q_NULLPTR));
        le_company->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\345\215\225\344\275\215\345\220\215\347\247\260", Q_NULLPTR));
        label_15->setText(QApplication::translate("AddEmploymentInfo", "\345\260\261\344\270\232\346\227\266\351\227\264:", Q_NULLPTR));
        le_stuJiuYeDate->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\260\261\344\270\232\346\227\266\351\227\264", Q_NULLPTR));
        label_13->setText(QApplication::translate("AddEmploymentInfo", "\345\260\261\344\270\232\350\226\252\350\265\204:", Q_NULLPTR));
        le_salary->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\350\226\252\350\265\204", Q_NULLPTR));
        label_18->setText(QApplication::translate("AddEmploymentInfo", "\345\255\246\347\224\237\347\217\255\347\272\247:", Q_NULLPTR));
        le_stuClass->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\347\217\255\347\272\247", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddEmploymentInfo", "\345\255\246\347\224\237\345\255\246\345\217\267:", Q_NULLPTR));
        le_stuNumber->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\255\246\347\224\237\345\255\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddEmploymentInfo", "\345\260\261\344\270\232\345\262\227\344\275\215:", Q_NULLPTR));
        le_post->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\345\262\227\344\275\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddEmploymentInfo", "\350\203\275\345\212\233\350\246\201\346\261\202:", Q_NULLPTR));
        le_ability->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\350\203\275\345\212\233\350\246\201\346\261\202", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddEmploymentInfo", "\345\260\261\344\270\232\345\237\216\345\270\202:", Q_NULLPTR));
        label_11->setText(QApplication::translate("AddEmploymentInfo", "\345\215\225\344\275\215\350\201\224\347\263\273\344\272\272:", Q_NULLPTR));
        le_contacterName->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\215\225\344\275\215\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        label_16->setText(QApplication::translate("AddEmploymentInfo", "\350\201\224\347\263\273\344\272\272\347\224\265\350\257\235:", Q_NULLPTR));
        le_contacterPhone->setPlaceholderText(QApplication::translate("AddEmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\215\225\344\275\215\350\201\224\347\263\273\344\272\272\347\224\265\350\257\235", Q_NULLPTR));
        label_17->setText(QApplication::translate("AddEmploymentInfo", "\345\255\246\347\224\237\346\200\247\345\210\253:", Q_NULLPTR));
        rbtn_man->setText(QApplication::translate("AddEmploymentInfo", "\347\224\267", Q_NULLPTR));
        rbtn_woman->setText(QApplication::translate("AddEmploymentInfo", "\345\245\263", Q_NULLPTR));
        label_8->setText(QApplication::translate("AddEmploymentInfo", "\345\255\246\347\224\237\344\270\223\344\270\232:", Q_NULLPTR));
        btn_submit->setText(QApplication::translate("AddEmploymentInfo", "\346\217\220\344\272\244", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("AddEmploymentInfo", "\351\207\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddEmploymentInfo: public Ui_AddEmploymentInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMPLOYMENTINFO_H
