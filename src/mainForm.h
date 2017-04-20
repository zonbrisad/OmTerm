/* 
 * File:   mainForm.h
 * Author: pmg
 *
 * Created on den 9 december 2014, 18:40
 */

#ifndef _MAINFORM_H
#define	_MAINFORM_H

#include <QtSerialPort/QtSerialPort>
#include <QSettings>
#include <QTimer>
#include "ui_mainForm.h"

typedef enum displayMode {
    mode_ascii = 0,
    mode_hex,
    mode_hexAscii
} dsiplayMode;


class mainForm : public QMainWindow {
    Q_OBJECT
public:
    mainForm();
    virtual ~mainForm();
private:
    QSerialPort  *serial;
    Ui::mainForm widget;
    QSettings    *settings;
    QTimer       *timer;
    QLabel       *rxCount;
    QLabel       *txCount;
    int          rxCnt;
    int          txCnt;
    displayMode  dispMode;
    int          frameLen;
    int          frameCnt;
            
    void updateStatusBar();
    void loadSettings();
    void saveSettings();
    void updateBitrate();
    void updatePorts();
    void testTerminal();
    
    void updateContex();
    
private slots:
    void newSession();
    void exit();
    void about();
    void connectPort();
    void serialRead();
    void update();
    void writeData(const QByteArray &data);
    void debugHandler();
    void changeHandler(qint32 i);
    
};

#endif	/* _MAINFORM_H */
