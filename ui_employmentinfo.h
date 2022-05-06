/********************************************************************************
** Form generated from reading UI file 'employmentinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYMENTINFO_H
#define UI_EMPLOYMENTINFO_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmploymentInfo
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_setShow;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_query;
    QPushButton *btn_reset;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *combox_faculty;
    QComboBox *combox_major;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *combox_province;
    QComboBox *combox_city;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QRadioButton *rbtn_male;
    QRadioButton *rbtn_female;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *le_post;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *le_company;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *le_class;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_addEmploymentInfo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_saveToExcel;
    QTableWidget *tableWidget_workInfo;
    QLabel *label_showRow;

    void setupUi(QWidget *EmploymentInfo)
    {
        if (EmploymentInfo->objectName().isEmpty())
            EmploymentInfo->setObjectName(QStringLiteral("EmploymentInfo"));
        EmploymentInfo->resize(1700, 950);
        gridLayout = new QGridLayout(EmploymentInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_setShow = new QFrame(EmploymentInfo);
        frame_setShow->setObjectName(QStringLiteral("frame_setShow"));
        frame_setShow->setFrameShape(QFrame::StyledPanel);
        frame_setShow->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_setShow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(frame_setShow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_query = new QPushButton(groupBox);
        btn_query->setObjectName(QStringLiteral("btn_query"));

        verticalLayout->addWidget(btn_query);

        btn_reset = new QPushButton(groupBox);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));

        verticalLayout->addWidget(btn_reset);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 2, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        combox_faculty = new QComboBox(groupBox);
        combox_faculty->setObjectName(QStringLiteral("combox_faculty"));

        horizontalLayout_2->addWidget(combox_faculty);

        combox_major = new QComboBox(groupBox);
        combox_major->setObjectName(QStringLiteral("combox_major"));

        horizontalLayout_2->addWidget(combox_major);


        horizontalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        combox_province = new QComboBox(groupBox);
        combox_province->setObjectName(QStringLiteral("combox_province"));

        horizontalLayout_5->addWidget(combox_province);

        combox_city = new QComboBox(groupBox);
        combox_city->setObjectName(QStringLiteral("combox_city"));

        horizontalLayout_5->addWidget(combox_city);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        rbtn_male = new QRadioButton(groupBox);
        rbtn_male->setObjectName(QStringLiteral("rbtn_male"));
        rbtn_male->setChecked(true);

        horizontalLayout->addWidget(rbtn_male);

        rbtn_female = new QRadioButton(groupBox);
        rbtn_female->setObjectName(QStringLiteral("rbtn_female"));

        horizontalLayout->addWidget(rbtn_female);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_7->addLayout(horizontalLayout);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        le_post = new QLineEdit(groupBox);
        le_post->setObjectName(QStringLiteral("le_post"));

        horizontalLayout_3->addWidget(le_post);


        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_5);

        le_company = new QLineEdit(groupBox);
        le_company->setObjectName(QStringLiteral("le_company"));

        horizontalLayout_6->addWidget(le_company);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        le_class = new QLineEdit(groupBox);
        le_class->setObjectName(QStringLiteral("le_class"));

        horizontalLayout_4->addWidget(le_class);


        horizontalLayout_8->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(380, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 1, 2, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        frame_2 = new QFrame(frame_setShow);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        btn_addEmploymentInfo = new QPushButton(frame_2);
        btn_addEmploymentInfo->setObjectName(QStringLiteral("btn_addEmploymentInfo"));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        btn_addEmploymentInfo->setFont(font);

        horizontalLayout_9->addWidget(btn_addEmploymentInfo);

        horizontalSpacer_2 = new QSpacerItem(778, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        btn_saveToExcel = new QPushButton(frame_2);
        btn_saveToExcel->setObjectName(QStringLiteral("btn_saveToExcel"));

        horizontalLayout_9->addWidget(btn_saveToExcel);


        gridLayout_4->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        tableWidget_workInfo = new QTableWidget(frame_2);
        tableWidget_workInfo->setObjectName(QStringLiteral("tableWidget_workInfo"));

        gridLayout_4->addWidget(tableWidget_workInfo, 1, 0, 1, 1);

        label_showRow = new QLabel(frame_2);
        label_showRow->setObjectName(QStringLiteral("label_showRow"));

        gridLayout_4->addWidget(label_showRow, 2, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);


        gridLayout->addWidget(frame_setShow, 0, 0, 1, 1);


        retranslateUi(EmploymentInfo);

        QMetaObject::connectSlotsByName(EmploymentInfo);
    } // setupUi

    void retranslateUi(QWidget *EmploymentInfo)
    {
        EmploymentInfo->setWindowTitle(QApplication::translate("EmploymentInfo", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("EmploymentInfo", "\346\220\234\347\264\242\346\235\241\344\273\266", Q_NULLPTR));
        btn_query->setText(QApplication::translate("EmploymentInfo", "\346\237\245\350\257\242", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("EmploymentInfo", "\351\207\215\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("EmploymentInfo", "\344\270\223\344\270\232:", Q_NULLPTR));
        label_6->setText(QApplication::translate("EmploymentInfo", "\345\237\216\345\270\202:", Q_NULLPTR));
        label_4->setText(QApplication::translate("EmploymentInfo", "\346\200\247\345\210\253:", Q_NULLPTR));
        rbtn_male->setText(QApplication::translate("EmploymentInfo", "\347\224\267", Q_NULLPTR));
        rbtn_female->setText(QApplication::translate("EmploymentInfo", "\345\245\263", Q_NULLPTR));
        label_2->setText(QApplication::translate("EmploymentInfo", "\345\262\227\344\275\215:", Q_NULLPTR));
        le_post->setPlaceholderText(QApplication::translate("EmploymentInfo", "\350\257\267\350\276\223\345\205\245\345\262\227\344\275\215\345\220\215\347\247\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("EmploymentInfo", "\344\274\201\344\270\232:", Q_NULLPTR));
        le_company->setPlaceholderText(QApplication::translate("EmploymentInfo", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\345\220\215\347\247\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("EmploymentInfo", "\347\217\255\347\272\247:", Q_NULLPTR));
        le_class->setPlaceholderText(QApplication::translate("EmploymentInfo", "\350\257\267\350\276\223\345\205\245\347\217\255\347\272\247\345\220\215\347\247\260", Q_NULLPTR));
        btn_addEmploymentInfo->setText(QApplication::translate("EmploymentInfo", "\346\267\273\345\212\240\345\260\261\344\270\232\344\277\241\346\201\257", Q_NULLPTR));
        btn_saveToExcel->setText(QApplication::translate("EmploymentInfo", "\345\257\274\345\207\272Excel", Q_NULLPTR));
        label_showRow->setText(QApplication::translate("EmploymentInfo", "\350\256\260\345\275\225\346\225\260\345\205\261 N \350\241\214\357\274\214\345\275\223\345\211\215\347\254\254 N \350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EmploymentInfo: public Ui_EmploymentInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYMENTINFO_H
