/********************************************************************************
** Form generated from reading UI file 'companyinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYINFO_H
#define UI_COMPANYINFO_H

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

class Ui_CompanyInfo
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_com1;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_addCompany;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_saveToExcel;
    QTableWidget *tableWidget_companyInfo;
    QLabel *label;

    void setupUi(QWidget *CompanyInfo)
    {
        if (CompanyInfo->objectName().isEmpty())
            CompanyInfo->setObjectName(QStringLiteral("CompanyInfo"));
        CompanyInfo->resize(1700, 950);
        gridLayout = new QGridLayout(CompanyInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_com1 = new QFrame(CompanyInfo);
        frame_com1->setObjectName(QStringLiteral("frame_com1"));
        frame_com1->setFrameShape(QFrame::StyledPanel);
        frame_com1->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_com1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_addCompany = new QPushButton(frame_com1);
        btn_addCompany->setObjectName(QStringLiteral("btn_addCompany"));

        horizontalLayout->addWidget(btn_addCompany);

        horizontalSpacer_2 = new QSpacerItem(918, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_saveToExcel = new QPushButton(frame_com1);
        btn_saveToExcel->setObjectName(QStringLiteral("btn_saveToExcel"));

        horizontalLayout->addWidget(btn_saveToExcel);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget_companyInfo = new QTableWidget(frame_com1);
        tableWidget_companyInfo->setObjectName(QStringLiteral("tableWidget_companyInfo"));

        gridLayout_2->addWidget(tableWidget_companyInfo, 1, 0, 1, 1);

        label = new QLabel(frame_com1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);


        gridLayout->addWidget(frame_com1, 0, 0, 1, 1);


        retranslateUi(CompanyInfo);

        QMetaObject::connectSlotsByName(CompanyInfo);
    } // setupUi

    void retranslateUi(QWidget *CompanyInfo)
    {
        CompanyInfo->setWindowTitle(QApplication::translate("CompanyInfo", "Form", Q_NULLPTR));
        btn_addCompany->setText(QApplication::translate("CompanyInfo", "\346\267\273\345\212\240\345\205\254\345\217\270\344\277\241\346\201\257", Q_NULLPTR));
        btn_saveToExcel->setText(QApplication::translate("CompanyInfo", "\345\257\274\345\207\272Excel", Q_NULLPTR));
        label->setText(QApplication::translate("CompanyInfo", "\350\256\260\345\275\225\346\225\260\345\205\261 N \350\241\214\357\274\214\345\275\223\345\211\215\347\254\254 N \350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CompanyInfo: public Ui_CompanyInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYINFO_H
