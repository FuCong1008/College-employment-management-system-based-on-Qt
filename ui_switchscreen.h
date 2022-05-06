/********************************************************************************
** Form generated from reading UI file 'switchscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHSCREEN_H
#define UI_SWITCHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchScreen
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QFrame *frame_body;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QFrame *frame_head;
    QGridLayout *gridLayout;
    QToolButton *tbn_userId;
    QLabel *le_showTime;
    QToolButton *tbn_exit;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbn_stuInfo;
    QToolButton *tbn_company;
    QToolButton *tbn_info;
    QToolButton *tbn_count;
    QToolButton *tbn_userManagement;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *SwitchScreen)
    {
        if (SwitchScreen->objectName().isEmpty())
            SwitchScreen->setObjectName(QStringLiteral("SwitchScreen"));
        SwitchScreen->resize(1700, 950);
        verticalLayout = new QVBoxLayout(SwitchScreen);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(SwitchScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_body = new QFrame(frame);
        frame_body->setObjectName(QStringLiteral("frame_body"));
        frame_body->setFrameShape(QFrame::StyledPanel);
        frame_body->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_body);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(frame_body);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_body, 1, 0, 1, 1);

        frame_head = new QFrame(frame);
        frame_head->setObjectName(QStringLiteral("frame_head"));
        frame_head->setStyleSheet(QStringLiteral(""));
        frame_head->setFrameShape(QFrame::StyledPanel);
        frame_head->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_head);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 11);
        tbn_userId = new QToolButton(frame_head);
        tbn_userId->setObjectName(QStringLiteral("tbn_userId"));
        tbn_userId->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_userId->setAutoRaise(false);

        gridLayout->addWidget(tbn_userId, 0, 3, 1, 1);

        le_showTime = new QLabel(frame_head);
        le_showTime->setObjectName(QStringLiteral("le_showTime"));
        le_showTime->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(le_showTime, 0, 0, 1, 1);

        tbn_exit = new QToolButton(frame_head);
        tbn_exit->setObjectName(QStringLiteral("tbn_exit"));
        tbn_exit->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_exit->setAutoRaise(false);

        gridLayout->addWidget(tbn_exit, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(100, -1, -1, -1);
        tbn_stuInfo = new QToolButton(frame_head);
        tbn_stuInfo->setObjectName(QStringLiteral("tbn_stuInfo"));

        horizontalLayout->addWidget(tbn_stuInfo);

        tbn_company = new QToolButton(frame_head);
        tbn_company->setObjectName(QStringLiteral("tbn_company"));

        horizontalLayout->addWidget(tbn_company);

        tbn_info = new QToolButton(frame_head);
        tbn_info->setObjectName(QStringLiteral("tbn_info"));
        tbn_info->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_info->setAutoRaise(false);

        horizontalLayout->addWidget(tbn_info);

        tbn_count = new QToolButton(frame_head);
        tbn_count->setObjectName(QStringLiteral("tbn_count"));
        tbn_count->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_count->setAutoRaise(false);

        horizontalLayout->addWidget(tbn_count);

        tbn_userManagement = new QToolButton(frame_head);
        tbn_userManagement->setObjectName(QStringLiteral("tbn_userManagement"));
        tbn_userManagement->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbn_userManagement->setAutoRaise(false);

        horizontalLayout->addWidget(tbn_userManagement);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(1156, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_3->addWidget(frame_head, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);


        retranslateUi(SwitchScreen);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SwitchScreen);
    } // setupUi

    void retranslateUi(QWidget *SwitchScreen)
    {
        SwitchScreen->setWindowTitle(QApplication::translate("SwitchScreen", "SEMS", Q_NULLPTR));
        tbn_userId->setText(QApplication::translate("SwitchScreen", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        le_showTime->setText(QApplication::translate("SwitchScreen", "SEMS", Q_NULLPTR));
        tbn_exit->setText(QApplication::translate("SwitchScreen", "\351\200\200\345\207\272", Q_NULLPTR));
        tbn_stuInfo->setText(QApplication::translate("SwitchScreen", "\345\255\246\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
        tbn_company->setText(QApplication::translate("SwitchScreen", "\345\205\254\345\217\270\344\277\241\346\201\257", Q_NULLPTR));
        tbn_info->setText(QApplication::translate("SwitchScreen", "\345\260\261\344\270\232\344\277\241\346\201\257", Q_NULLPTR));
        tbn_count->setText(QApplication::translate("SwitchScreen", "\345\260\261\344\270\232\347\273\237\350\256\241", Q_NULLPTR));
        tbn_userManagement->setText(QApplication::translate("SwitchScreen", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SwitchScreen: public Ui_SwitchScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHSCREEN_H
