/********************************************************************************
** Form generated from reading UI file 'employmentstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYMENTSTATISTICS_H
#define UI_EMPLOYMENTSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmploymentStatistics
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tbn_major;
    QToolButton *tbn_class;
    QToolButton *tbn_city;
    QToolButton *tbn_company;
    QToolButton *tbn_post;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget_stastics;

    void setupUi(QWidget *EmploymentStatistics)
    {
        if (EmploymentStatistics->objectName().isEmpty())
            EmploymentStatistics->setObjectName(QStringLiteral("EmploymentStatistics"));
        EmploymentStatistics->resize(1700, 950);
        gridLayout = new QGridLayout(EmploymentStatistics);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(EmploymentStatistics);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tbn_major = new QToolButton(frame_2);
        tbn_major->setObjectName(QStringLiteral("tbn_major"));
        tbn_major->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_major->setAutoRaise(false);

        horizontalLayout_2->addWidget(tbn_major);

        tbn_class = new QToolButton(frame_2);
        tbn_class->setObjectName(QStringLiteral("tbn_class"));
        tbn_class->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_class->setAutoRaise(false);

        horizontalLayout_2->addWidget(tbn_class);

        tbn_city = new QToolButton(frame_2);
        tbn_city->setObjectName(QStringLiteral("tbn_city"));

        horizontalLayout_2->addWidget(tbn_city);

        tbn_company = new QToolButton(frame_2);
        tbn_company->setObjectName(QStringLiteral("tbn_company"));
        tbn_company->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_company->setAutoRaise(false);

        horizontalLayout_2->addWidget(tbn_company);

        tbn_post = new QToolButton(frame_2);
        tbn_post->setObjectName(QStringLiteral("tbn_post"));
        tbn_post->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_post->setAutoRaise(false);

        horizontalLayout_2->addWidget(tbn_post);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget_stastics = new QTableWidget(frame_2);
        tableWidget_stastics->setObjectName(QStringLiteral("tableWidget_stastics"));

        verticalLayout->addWidget(tableWidget_stastics);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(EmploymentStatistics);

        QMetaObject::connectSlotsByName(EmploymentStatistics);
    } // setupUi

    void retranslateUi(QWidget *EmploymentStatistics)
    {
        EmploymentStatistics->setWindowTitle(QApplication::translate("EmploymentStatistics", "Form", Q_NULLPTR));
        tbn_major->setText(QApplication::translate("EmploymentStatistics", "\346\214\211\344\270\223\344\270\232\347\273\237\350\256\241", Q_NULLPTR));
        tbn_class->setText(QApplication::translate("EmploymentStatistics", "\346\214\211\347\217\255\347\272\247\347\273\237\350\256\241", Q_NULLPTR));
        tbn_city->setText(QApplication::translate("EmploymentStatistics", "\346\214\211\345\237\216\345\270\202\347\273\237\350\256\241", Q_NULLPTR));
        tbn_company->setText(QApplication::translate("EmploymentStatistics", "\346\214\211\344\274\201\344\270\232\347\273\237\350\256\241", Q_NULLPTR));
        tbn_post->setText(QApplication::translate("EmploymentStatistics", "\346\214\211\345\262\227\344\275\215\347\273\237\350\256\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EmploymentStatistics: public Ui_EmploymentStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYMENTSTATISTICS_H
