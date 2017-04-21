/*
 * File:   mainForm.cpp
 * Author: pmg
 *
 * Created on den 9 december 2014, 18:40
 */

#include <QDir>
#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QProcess>
#include <QByteArray>
#include <QMessageBox>
#include <QVariant>
#include <QDebug>


#include "mainForm.h"
#include "aboutForm.h"
#include "Def.h"

 void mainForm::testTerminal() {
     widget.textEdit->setTextColor(Qt::red);
     widget.textEdit->append("Kalle");
}

 
 
mainForm::mainForm() {
    widget.setupUi(this);
   
    qDebug() << "OmTerm Startup";
    
    QCoreApplication::setOrganizationName("MudderverkSoftware");
    QCoreApplication::setApplicationName(APP_NAME);

    this->setWindowTitle(APP_NAME);

    settings = new QSettings(this);
    serial   = new QSerialPort(this);
        
    connect(widget.actionDuplicate_session, SIGNAL(triggered()), this, SLOT(newSession()));
    connect(widget.actionExit,    SIGNAL(triggered()), this, SLOT(exit()));
    connect(widget.actionAbout,   SIGNAL(triggered()), this, SLOT(about()));
    connect(widget.connectButton, SIGNAL(clicked()),   this, SLOT(connectPort()));
    connect(this->serial,         SIGNAL(readyRead()), this, SLOT(serialRead()));
    
    connect(widget.console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
    
    // debug events
    connect(widget.dbgAddChar,  SIGNAL(clicked()), this, SLOT(debugHandler()));
    connect(widget.dbgANSItest, SIGNAL(clicked()), this, SLOT(debugHandler()));
    connect(widget.dbgSendData, SIGNAL(clicked()), this, SLOT(debugHandler()));
    
    
    connect(widget.displayCombo, SIGNAL(currentIndexChanged(qint32)), this, SLOT(changeHandler(qint32)));
    
//    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
//        QString s =   QObject::tr("Port: ") + info.portName() + "\n"
//                    + QObject::tr("Location: ") + info.systemLocation() + "\n"
//                    + QObject::tr("Description: ") + info.description() + "\n"
//                    + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
//                  //  + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
//                    + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
//                    + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
//                    + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
//        widget.textEdit->append(s);
//        widget.portsCombo->addItem(info.portName());
//    }
    
    updatePorts();
    
    //widget.comboBox->addItems(QSerialPortInfo::standardBaudRates());
    widget.statusbar->showMessage("Disconnected");
    
    // Fill all comboboxes with data
    widget.parityCombo->addItem("NoParity", QVariant(QSerialPort::NoParity));
    widget.parityCombo->addItem("Even",     QVariant(QSerialPort::EvenParity));
    widget.parityCombo->addItem("Odd",      QVariant(QSerialPort::OddParity));
    
    widget.stopBitsCombo->addItem("1",   QVariant(QSerialPort::OneStop));
    widget.stopBitsCombo->addItem("1.5", QVariant(QSerialPort::OneAndHalfStop));
    widget.stopBitsCombo->addItem("2",   QVariant(QSerialPort::TwoStop));
    
    widget.dataBitsCombo->addItem("5",   QVariant(QSerialPort::Data5));
    widget.dataBitsCombo->addItem("6",   QVariant(QSerialPort::Data6));
    widget.dataBitsCombo->addItem("7",   QVariant(QSerialPort::Data7));
    widget.dataBitsCombo->addItem("8",   QVariant(QSerialPort::Data8));
    
    widget.flowControlCombo->addItem("No",       QVariant(QSerialPort::NoFlowControl));
    widget.flowControlCombo->addItem("Hardware", QVariant(QSerialPort::HardwareControl));
    widget.flowControlCombo->addItem("Software", QVariant(QSerialPort::SoftwareControl));
    
    widget.bitrateCombo->addItem("300",    QVariant(300));
    widget.bitrateCombo->addItem("1200",   QVariant(1200));
    widget.bitrateCombo->addItem("2400",   QVariant(2400));
    widget.bitrateCombo->addItem("4800",   QVariant(4800));
    widget.bitrateCombo->addItem("9600",   QVariant(9600));
    widget.bitrateCombo->addItem("14400",  QVariant(14400));
    widget.bitrateCombo->addItem("19200",  QVariant(19200));
    widget.bitrateCombo->addItem("28800",  QVariant(28800));
    widget.bitrateCombo->addItem("38400",  QVariant(38400));
    widget.bitrateCombo->addItem("57600",  QVariant(57600));
    widget.bitrateCombo->addItem("115200", QVariant(115200));
        
    widget.displayCombo->addItem("Ascii",     QVariant(mode_ascii));
    widget.displayCombo->addItem("Hex",       QVariant(mode_hex));
    widget.displayCombo->addItem("Hex+ASCII", QVariant(mode_hexAscii));
    
    // Debug function
#ifndef DDEBUG
    widget.groupDebug->hide();
#endif
    
    // load application settings 
    loadSettings();
    
    rxCount = new QLabel(this);
    txCount = new QLabel(this);
    
    
    widget.statusbar->addPermanentWidget(rxCount);
    widget.statusbar->addPermanentWidget(txCount);
    
    rxCnt=0;
    txCnt=0;
    
    dispMode = mode_ascii;
    frameCnt=0;
    frameLen=8;
    
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    
    updateStatusBar();
    
    testTerminal();
}


void mainForm::debugHandler() {
    QObject *obj = QObject::sender();
    
    if (obj == (QObject*)widget.dbgAddChar) {
      widget.console->putData("OmTerm test characters");    
    }
    if (obj == (QObject*)widget.dbgANSItest) {
      //widget.console->putData("OmTerm test characters");
      widget.console->putData(E_MAGENTA "Magenta" E_END "\n");
      widget.console->putData(E_RED     "Red"     E_END "\n");
      widget.console->putData(E_YELLOW  "Yellow"  E_END "\n");
      widget.console->putData(E_GREEN   "Green"   E_END "\n");
      widget.console->putData(E_BLUE    "Blue"    E_END "\n");
      widget.console->putData(E_CYAN    "Cyan"    E_END "\n");
      widget.console->putData(E_BR_MAGENTA "Magenta" E_END "\n");
      widget.console->putData(E_BR_RED     "Red"     E_END "\n");
      widget.console->putData(E_BR_YELLOW  "Yellow"  E_END "\n");
      widget.console->putData(E_BR_GREEN   "Green"   E_END "\n");
      widget.console->putData(E_BR_BLUE    "Blue"    E_END "\n"); 
    }
    if (obj == (QObject*)widget.dbgSendData) {
      serial->write("OmTerm test characters");    
    }

}

void mainForm::updateContex() {
  switch (dispMode) {
      case mode_ascii:widget.frameSize->hide();    break;
      case mode_hex:widget.frameSize->show();      break;
      case mode_hexAscii:widget.frameSize->show(); break;
  }   
}

void mainForm::changeHandler(qint32 i) {
    QObject *obj = QObject::sender();  
    qDebug() <<  "Change handler" ;  
    if (obj == (QObject*)widget.displayCombo) {
      //dispMode = (displayMode) widget.displayCombo->currentData().toInt(); 
      dispMode = (displayMode) widget.displayCombo->currentData().toInt();      
    }
    if (obj == (QObject*)widget.frameSize) {
      frameLen = widget.frameSize->value(); 
      dispMode = (displayMode) widget.displayCombo->currentData().toInt();      
    }
    
    
    updateContex();
}

mainForm::~mainForm() {
}

void mainForm::writeData(const QByteArray &data) {
    serial->write(data);
    txCnt += data.size();
    updateStatusBar();
}

void mainForm::serialRead() {
    int i;
    
    QByteArray data = serial->readAll();
    qDebug() << "DispMode " << dispMode;
    switch (dispMode) {
        case mode_hexAscii: break;
        case mode_hex:      
        for(i=0;i<data.size();i++) {
            
            widget.console->insertPlainText(QString::number(data.at(i),16));
            widget.console->insertPlainText(" ");
            frameCnt++;
            if (frameCnt>frameLen) {
                widget.console->putData("\n");
                frameCnt=0;
            }
        }
        break;
        case mode_ascii:       
          widget.console->putData(data);
        break ;
    }
    rxCnt += data.size();
    updateStatusBar();
}

void mainForm::newSession() {
    QStringList arguments;
    QString program = QApplication::applicationDirPath() + "/" + QApplication::applicationName() + ".exe";
    //widget.textEdit->append(program);
    arguments << "" ;

    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, arguments);
    
    updateStatusBar();
}

void mainForm::about() {
    //static aboutForm af;
    //af.show();
    widget.textEdit->hide();
    QMessageBox::about(this, tr("OmTerm"), tr("<b>OmTerm</b><br>" 
                                              "A simple QT serial terminal<br>"
                                              "Peter Malmberg <peter.malmberg@gmail.com>"));
    
}
void mainForm::exit() {
    saveSettings();
    QApplication::exit(EXIT_SUCCESS);
}

void mainForm::connectPort() {
//    QSerialPort::DataBits db;
//    QVariant v;
    if (serial->isOpen()) {
        serial->close();
    } else {
        serial->setPortName(widget.portsCombo->currentText());
        //serial->setFlowControl((QSerialPort::FlowControl)widget.flowControlCombo->currentData().toInt());
        qDebug() << widget.portsCombo->currentText();
        //serial->setFlowControl(QSerialPort::NoFlowControl);
        //serial->setBaudRate(widget.bitrateCombo->currentData().toInt(), QSerialPort::AllDirections);        
        //serial->setDataBits((QSerialPort::DataBits)widget.dataBitsCombo->currentData().toInt());
        //serial->setStopBits((QSerialPort::StopBits)widget.stopBitsCombo->currentData().toInt());
        //serial->setParity((QSerialPort::Parity)widget.parityCombo->currentData().toInt());
              
//        serial->setStopBits(widget.stopBitsCombo->currentData().toInt());
//        serial->setParity(widget.parityCombo->currentData().toInt());
//        serial->setFlowControl(widget.flowControlCombo->currentData().toInt());
        
        
        if (serial->open(QIODevice::ReadWrite)) {
            serial->setFlowControl(QSerialPort::NoFlowControl);
            serial->setBaudRate(widget.bitrateCombo->currentData().toInt(), QSerialPort::AllDirections);  
        } else {
            
        }
        
        widget.textEdit->append(serial->errorString());
    }
    //widget.textEdit->append("Connecting");
    
    updateStatusBar();
}

void mainForm::updateStatusBar() {
    
    rxCount->setText(QString("RX %1").arg(rxCnt,7));
    txCount->setText(QString("TX %1").arg(txCnt,7));
   
    if (serial->isOpen()) {
        widget.connectButton->setText("Disconnect");
    } else {
        widget.connectButton->setText("Connect");
    }
}



 void mainForm::loadSettings() {
     int index;
     
     index = widget.portsCombo->findText(settings->value("port/port").toString());
     if (index != -1) {
       widget.portsCombo->setCurrentIndex(index);
     }
     index = widget.bitrateCombo->findData(settings->value("port/bitRate").toInt());
     if (index != -1) {
       widget.bitrateCombo->setCurrentIndex(index);
     }
     index = widget.dataBitsCombo->findData(settings->value("port/dataBits").toInt());
     if (index != -1) {
       widget.dataBitsCombo->setCurrentIndex(index);
     }
     index = widget.stopBitsCombo->findData(settings->value("port/stopBits").toInt());
     if (index != -1) {
       widget.stopBitsCombo->setCurrentIndex(index);
     }
     index = widget.parityCombo->findData(settings->value("port/parity").toInt());
     if (index != -1) {
       widget.parityCombo->setCurrentIndex(index);
     }
     index = widget.flowControlCombo->findData(settings->value("port/flowcontrol").toInt());
     if (index != -1) {
       widget.flowControlCombo->setCurrentIndex(index);
     }
     
     
 }
 
 void mainForm::saveSettings() {
     settings->setValue("port/port",        widget.portsCombo->currentText());
     settings->setValue("port/bitRate",     widget.bitrateCombo->currentData().toInt());
     settings->setValue("port/dataBits",    widget.dataBitsCombo->currentData().toInt());
     settings->setValue("port/stopBits",    widget.stopBitsCombo->currentData().toInt());
     settings->setValue("port/parity",      widget.parityCombo->currentData().toInt());
     settings->setValue("port/flowcontrol", widget.flowControlCombo->currentData().toInt());
     
     settings->sync();
 }
 
 void mainForm::update() {
     //widget.textEdit->append("timer");
 }
 
 void mainForm::updateBitrate() {
     
//     for(int i=0; i<QSerialPortInfo::standardBaudRates().count(); i++) {
//        
//     }
        
 }
 
void mainForm::updatePorts() {
    widget.portsCombo->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {   
        widget.portsCombo->addItem(info.portName());
    }
 }
