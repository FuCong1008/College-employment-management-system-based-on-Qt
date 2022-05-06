/********************************************************************************
** Form generated from reading UI file 'addcompany.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPANY_H
#define UI_ADDCOMPANY_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCompany
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_addCom;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_company;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *le_post;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLineEdit *le_salary;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *le_ability;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *le_contacterName;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QLineEdit *le_contacterPhone;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_7;
    QComboBox *combox_showProvince;
    QComboBox *combox_showCity;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_submit;
    QPushButton *btn_reset;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AddCompany)
    {
        if (AddCompany->objectName().isEmpty())
            AddCompany->setObjectName(QStringLiteral("AddCompany"));
        AddCompany->resize(292, 274);
        gridLayout = new QGridLayout(AddCompany);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_addCom = new QFrame(AddCompany);
        frame_addCom->setObjectName(QStringLiteral("frame_addCom"));
        frame_addCom->setFrameShape(QFrame::StyledPanel);
        frame_addCom->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_addCom);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_addCom);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        le_company = new QLineEdit(frame_addCom);
        le_company->setObjectName(QStringLiteral("le_company"));

        horizontalLayout_2->addWidget(le_company);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_addCom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        le_post = new QLineEdit(frame_addCom);
        le_post->setObjectName(QStringLiteral("le_post"));

        horizontalLayout_3->addWidget(le_post);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_13 = new QLabel(frame_addCom);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_13);

        le_salary = new QLineEdit(frame_addCom);
        le_salary->setObjectName(QStringLiteral("le_salary"));

        horizontalLayout_4->addWidget(le_salary);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(frame_addCom);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        le_ability = new QLineEdit(frame_addCom);
        le_ability->setObjectName(QStringLiteral("le_ability"));

        horizontalLayout_5->addWidget(le_ability);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(frame_addCom);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_11);

        le_contacterName = new QLineEdit(frame_addCom);
        le_contacterName->setObjectName(QStringLiteral("le_contacterName"));

        horizontalLayout_11->addWidget(le_contacterName);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(frame_addCom);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_16);

        le_contacterPhone = new QLineEdit(frame_addCom);
        le_contacterPhone->setObjectName(QStringLiteral("le_contacterPhone"));

        horizontalLayout_12->addWidget(le_contacterPhone);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_7 = new QLabel(frame_addCom);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(68, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_7);

        combox_showProvince = new QComboBox(frame_addCom);
        combox_showProvince->setObjectName(QStringLiteral("combox_showProvince"));

        horizontalLayout_17->addWidget(combox_showProvince);

        combox_showCity = new QComboBox(frame_addCom);
        combox_showCity->setObjectName(QStringLiteral("combox_showCity"));

        horizontalLayout_17->addWidget(combox_showCity);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        btn_submit = new QPushButton(frame_addCom);
        btn_submit->setObjectName(QStringLiteral("btn_submit"));

        horizontalLayout_14->addWidget(btn_submit);

        btn_reset = new QPushButton(frame_addCom);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));

        horizontalLayout_14->addWidget(btn_reset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_14);


        gridLayout->addWidget(frame_addCom, 0, 0, 1, 1);


        retranslateUi(AddCompany);

        QMetaObject::connectSlotsByName(AddCompany);
    } // setupUi

    void retranslateUi(QWidget *AddCompany)
    {
        AddCompany->setWindowTitle(QApplication::translate("AddCompany", "\346\267\273\345\212\240\345\205\254\345\217\270\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddCompany", "\345\260\261\344\270\232\345\215\225\344\275\215:", Q_NULLPTR));
        le_company->setPlaceholderText(QApplication::translate("AddCompany", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\345\215\225\344\275\215\345\220\215\347\247\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddCompany", "\345\260\261\344\270\232\345\262\227\344\275\215:", Q_NULLPTR));
        le_post->setPlaceholderText(QApplication::translate("AddCompany", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\345\262\227\344\275\215", Q_NULLPTR));
        label_13->setText(QApplication::translate("AddCompany", "\345\260\261\344\270\232\350\226\252\350\265\204:", Q_NULLPTR));
        le_salary->setPlaceholderText(QApplication::translate("AddCompany", "\350\257\267\350\276\223\345\205\245\345\260\261\344\270\232\350\226\252\350\265\204", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddCompany", "\350\203\275\345\212\233\350\246\201\346\261\202:", Q_NULLPTR));
        le_ability->setPlaceholderText(QApplication::translate("AddCompany", "\350\257\267\350\276\223\345\205\245\350\203\275\345\212\233\350\246\201\346\261\202", Q_NULLPTR));
        label_11->setText(QApplication::translate("AddCompany", "\345\215\225\344\275\215\350\201\224\347\263\273\344\272\272:", Q_NULLPTR));
        le_contacterName->setPlaceholderText(QApplication::translate("AddCompany", "\350\257\267\350\276\223\345\205\245\345\215\225\344\275\215\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        label_16->setText(QApplication::translate("AddCompany", "\350\201\224\347\263\273\344\272\272\347\224\265\350\257\235:", Q_NULLPTR));
        le_contacterPhone->setPlaceholderText(QApplication::translate("AddCompany", "\350\257\267\350\276\223\345\205\245\345\215\225\344\275\215\350\201\224\347\263\273\344\272\272\347\224\265\350\257\235", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddCompany", "\345\215\225\344\275\215\345\234\260\347\202\271:", Q_NULLPTR));
        btn_submit->setText(QApplication::translate("AddCompany", "\346\217\220\344\272\244", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("AddCompany", "\351\207\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddCompany: public Ui_AddCompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPANY_H
