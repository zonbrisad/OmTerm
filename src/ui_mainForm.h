/********************************************************************************
** Form generated from reading UI file 'mainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "console.h"

QT_BEGIN_NAMESPACE

class Ui_mainForm
{
public:
    QAction *actionDuplicate_session;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionReset_Terminal;
    QAction *actionClear;
    QAction *actionSend_Break;
    QAction *actionSend_CTRL_C;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    QComboBox *comboBox_5;
    QPushButton *pushButton_10;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *portsCombo;
    QLabel *label_2;
    QComboBox *bitrateCombo;
    QLabel *label_6;
    QComboBox *dataBitsCombo;
    QLabel *label_3;
    QComboBox *parityCombo;
    QLabel *label_4;
    QComboBox *stopBitsCombo;
    QLabel *label_5;
    QComboBox *flowControlCombo;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QComboBox *displayCombo;
    QLabel *label_8;
    QSpinBox *frameSize;
    QLabel *label_9;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QComboBox *comboBox_2;
    QSpinBox *spinBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QGroupBox *groupDebug;
    QVBoxLayout *verticalLayout_5;
    QPushButton *dbgAddChar;
    QPushButton *dbgANSItest;
    QPushButton *dbgSendData;
    QPushButton *pushButton_6;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit;
    Console *console;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuControl;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainForm)
    {
        if (mainForm->objectName().isEmpty())
            mainForm->setObjectName(QStringLiteral("mainForm"));
        mainForm->resize(915, 854);
        actionDuplicate_session = new QAction(mainForm);
        actionDuplicate_session->setObjectName(QStringLiteral("actionDuplicate_session"));
        actionAbout = new QAction(mainForm);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionExit = new QAction(mainForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionReset_Terminal = new QAction(mainForm);
        actionReset_Terminal->setObjectName(QStringLiteral("actionReset_Terminal"));
        actionClear = new QAction(mainForm);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionSend_Break = new QAction(mainForm);
        actionSend_Break->setObjectName(QStringLiteral("actionSend_Break"));
        actionSend_CTRL_C = new QAction(mainForm);
        actionSend_CTRL_C->setObjectName(QStringLiteral("actionSend_CTRL_C"));
        centralwidget = new QWidget(mainForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        verticalLayout->addWidget(connectButton);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 3, -1, 3);
        comboBox_5 = new QComboBox(groupBox_6);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        verticalLayout_8->addWidget(comboBox_5);

        pushButton_10 = new QPushButton(groupBox_6);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout_8->addWidget(pushButton_10);


        verticalLayout->addWidget(groupBox_6);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAutoFillBackground(false);
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(2);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        portsCombo = new QComboBox(groupBox_2);
        portsCombo->setObjectName(QStringLiteral("portsCombo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, portsCombo);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        bitrateCombo = new QComboBox(groupBox_2);
        bitrateCombo->setObjectName(QStringLiteral("bitrateCombo"));

        formLayout->setWidget(1, QFormLayout::FieldRole, bitrateCombo);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        dataBitsCombo = new QComboBox(groupBox_2);
        dataBitsCombo->setObjectName(QStringLiteral("dataBitsCombo"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dataBitsCombo);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        parityCombo = new QComboBox(groupBox_2);
        parityCombo->setObjectName(QStringLiteral("parityCombo"));

        formLayout->setWidget(3, QFormLayout::FieldRole, parityCombo);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        stopBitsCombo = new QComboBox(groupBox_2);
        stopBitsCombo->setObjectName(QStringLiteral("stopBitsCombo"));

        formLayout->setWidget(4, QFormLayout::FieldRole, stopBitsCombo);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        flowControlCombo = new QComboBox(groupBox_2);
        flowControlCombo->setObjectName(QStringLiteral("flowControlCombo"));

        formLayout->setWidget(5, QFormLayout::FieldRole, flowControlCombo);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        displayCombo = new QComboBox(groupBox);
        displayCombo->setObjectName(QStringLiteral("displayCombo"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, displayCombo);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        frameSize = new QSpinBox(groupBox);
        frameSize->setObjectName(QStringLiteral("frameSize"));
        frameSize->setValue(16);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, frameSize);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pushButton);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_4->addWidget(pushButton_2);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_4->addWidget(checkBox_2);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_4->addWidget(checkBox);

        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_4->addWidget(comboBox_2);

        spinBox_2 = new QSpinBox(groupBox_3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        verticalLayout_4->addWidget(spinBox_2);

        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        verticalLayout_4->addWidget(comboBox_3);

        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        verticalLayout_4->addWidget(comboBox_4);


        verticalLayout->addWidget(groupBox_3);

        groupDebug = new QGroupBox(centralwidget);
        groupDebug->setObjectName(QStringLiteral("groupDebug"));
        verticalLayout_5 = new QVBoxLayout(groupDebug);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        dbgAddChar = new QPushButton(groupDebug);
        dbgAddChar->setObjectName(QStringLiteral("dbgAddChar"));

        verticalLayout_5->addWidget(dbgAddChar);

        dbgANSItest = new QPushButton(groupDebug);
        dbgANSItest->setObjectName(QStringLiteral("dbgANSItest"));

        verticalLayout_5->addWidget(dbgANSItest);

        dbgSendData = new QPushButton(groupDebug);
        dbgSendData->setObjectName(QStringLiteral("dbgSendData"));

        verticalLayout_5->addWidget(dbgSendData);

        pushButton_6 = new QPushButton(groupDebug);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_5->addWidget(pushButton_6);

        doubleSpinBox = new QDoubleSpinBox(groupDebug);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        verticalLayout_5->addWidget(doubleSpinBox);

        spinBox = new QSpinBox(groupDebug);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        verticalLayout_5->addWidget(spinBox);


        verticalLayout->addWidget(groupDebug);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        textEdit->setFont(font);

        verticalLayout_3->addWidget(textEdit);

        console = new Console(centralwidget);
        console->setObjectName(QStringLiteral("console"));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        font1.setPointSize(10);
        console->setFont(font1);

        verticalLayout_3->addWidget(console);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_9 = new QPushButton(groupBox_5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout_7->addWidget(pushButton_9);

        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setFrame(true);

        verticalLayout_7->addWidget(lineEdit);


        verticalLayout_6->addWidget(groupBox_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_6);

        mainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 915, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuControl = new QMenu(menubar);
        menuControl->setObjectName(QStringLiteral("menuControl"));
        mainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(mainForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainForm->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuControl->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionDuplicate_session);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuControl->addAction(actionReset_Terminal);
        menuControl->addAction(actionClear);
        menuControl->addSeparator();
        menuControl->addAction(actionSend_CTRL_C);
        menuControl->addAction(actionSend_Break);

        retranslateUi(mainForm);

        QMetaObject::connectSlotsByName(mainForm);
    } // setupUi

    void retranslateUi(QMainWindow *mainForm)
    {
        mainForm->setWindowTitle(QApplication::translate("mainForm", "mainForm", 0));
        actionDuplicate_session->setText(QApplication::translate("mainForm", "New Session...", 0));
        actionAbout->setText(QApplication::translate("mainForm", "About", 0));
        actionExit->setText(QApplication::translate("mainForm", "Quit", 0));
        actionReset_Terminal->setText(QApplication::translate("mainForm", "Reset Terminal", 0));
        actionClear->setText(QApplication::translate("mainForm", "Clear", 0));
        actionSend_Break->setText(QApplication::translate("mainForm", "Send Break", 0));
        actionSend_CTRL_C->setText(QApplication::translate("mainForm", "Send CTRL-C", 0));
        connectButton->setText(QApplication::translate("mainForm", "Connect", 0));
        groupBox_6->setTitle(QApplication::translate("mainForm", "Profiles", 0));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("mainForm", "Default", 0)
         << QApplication::translate("mainForm", "New profile", 0)
        );
        pushButton_10->setText(QApplication::translate("mainForm", "Save Profile", 0));
        groupBox_2->setTitle(QApplication::translate("mainForm", "Port settings", 0));
        label->setText(QApplication::translate("mainForm", "Port:", 0));
        label_2->setText(QApplication::translate("mainForm", "Bitrate:", 0));
        label_6->setText(QApplication::translate("mainForm", "DataBits", 0));
        label_3->setText(QApplication::translate("mainForm", "Parity", 0));
        label_4->setText(QApplication::translate("mainForm", "Stop bits:", 0));
        label_5->setText(QApplication::translate("mainForm", "Flow Control:", 0));
        groupBox->setTitle(QApplication::translate("mainForm", "Display", 0));
        label_7->setText(QApplication::translate("mainForm", "Display", 0));
        label_8->setText(QApplication::translate("mainForm", "Frame size", 0));
        label_9->setText(QApplication::translate("mainForm", "sd", 0));
        pushButton->setText(QApplication::translate("mainForm", "aaa", 0));
        groupBox_3->setTitle(QApplication::translate("mainForm", "Capture", 0));
        pushButton_2->setText(QApplication::translate("mainForm", "Start", 0));
        checkBox_2->setText(QApplication::translate("mainForm", "CheckBox", 0));
        checkBox->setText(QApplication::translate("mainForm", "CheckBox", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("mainForm", "Unix timestamp", 0)
        );
        groupDebug->setTitle(QApplication::translate("mainForm", "Debug", 0));
        dbgAddChar->setText(QApplication::translate("mainForm", "Add some characters", 0));
        dbgANSItest->setText(QApplication::translate("mainForm", "ANSI Color Test", 0));
        dbgSendData->setText(QApplication::translate("mainForm", "Send Data", 0));
        pushButton_6->setText(QApplication::translate("mainForm", "PushButton", 0));
        groupBox_5->setTitle(QApplication::translate("mainForm", "GroupBox", 0));
        pushButton_9->setText(QApplication::translate("mainForm", "Send file", 0));
        menuFile->setTitle(QApplication::translate("mainForm", "File", 0));
        menuHelp->setTitle(QApplication::translate("mainForm", "Help", 0));
        menuControl->setTitle(QApplication::translate("mainForm", "Control", 0));
    } // retranslateUi

};

namespace Ui {
    class mainForm: public Ui_mainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
