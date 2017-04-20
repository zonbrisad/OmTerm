/* 
 * File:   aboutForm.h
 * Author: pmg
 *
 * Created on den 10 december 2014, 20:05
 */

#ifndef _ABOUTFORM_H
#define	_ABOUTFORM_H

#include "ui_aboutForm.h"

class aboutForm : public QDialog {
    Q_OBJECT
public:
    aboutForm();
    virtual ~aboutForm();
private:
    Ui::aboutForm widget;
};

#endif	/* _ABOUTFORM_H */
