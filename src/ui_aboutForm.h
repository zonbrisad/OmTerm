/********************************************************************************
** Form generated from reading UI file 'aboutForm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORM_H
#define UI_ABOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aboutForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *aboutForm)
    {
        if (aboutForm->objectName().isEmpty())
            aboutForm->setObjectName(QStringLiteral("aboutForm"));
        aboutForm->resize(403, 303);
        verticalLayout = new QVBoxLayout(aboutForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(aboutForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(aboutForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), aboutForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), aboutForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(aboutForm);
    } // setupUi

    void retranslateUi(QDialog *aboutForm)
    {
        aboutForm->setWindowTitle(QApplication::translate("aboutForm", "aboutForm", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutForm: public Ui_aboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORM_H
