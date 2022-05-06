/********************************************************************************
** Form generated from reading UI file 'studentinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTINFO_H
#define UI_STUDENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentInfo
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_stu;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_addStu;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_saveToExcel;
    QTableWidget *tableWidget_studentInfo;
    QLabel *label;

    void setupUi(QWidget *StudentInfo)
    {
        if (StudentInfo->objectName().isEmpty())
            StudentInfo->setObjectName(QStringLiteral("StudentInfo"));
        StudentInfo->resize(1700, 950);
        gridLayout = new QGridLayout(StudentInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_stu = new QFrame(StudentInfo);
        frame_stu->setObjectName(QStringLiteral("frame_stu"));
        frame_stu->setFrameShape(QFrame::StyledPanel);
        frame_stu->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_stu);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_addStu = new QPushButton(frame_stu);
        btn_addStu->setObjectName(QStringLiteral("btn_addStu"));

        horizontalLayout->addWidget(btn_addStu);

        horizontalSpacer_2 = new QSpacerItem(918, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_saveToExcel = new QPushButton(frame_stu);
        btn_saveToExcel->setObjectName(QStringLiteral("btn_saveToExcel"));

        horizontalLayout->addWidget(btn_saveToExcel);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget_studentInfo = new QTableWidget(frame_stu);
        tableWidget_studentInfo->setObjectName(QStringLiteral("tableWidget_studentInfo"));

        gridLayout_2->addWidget(tableWidget_studentInfo, 1, 0, 1, 1);

        label = new QLabel(frame_stu);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);


        gridLayout->addWidget(frame_stu, 0, 0, 1, 1);


        retranslateUi(StudentInfo);

        QMetaObject::connectSlotsByName(StudentInfo);
    } // setupUi

    void retranslateUi(QWidget *StudentInfo)
    {
        StudentInfo->setWindowTitle(QApplication::translate("StudentInfo", "Form", Q_NULLPTR));
        btn_addStu->setText(QApplication::translate("StudentInfo", "\346\267\273\345\212\240\345\255\246\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
        btn_saveToExcel->setText(QApplication::translate("StudentInfo", "\345\257\274\345\207\272Excel", Q_NULLPTR));
        label->setText(QApplication::translate("StudentInfo", "\350\256\260\345\275\225\346\225\260\345\205\261 N \350\241\214\357\274\214\345\275\223\345\211\215\347\254\254 N \350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StudentInfo: public Ui_StudentInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTINFO_H
