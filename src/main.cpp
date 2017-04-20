/*
 * File:   main.cpp
 * Author: pmg
 *
 * Created on den 21 april 2014, 12:04
 */

#include <QApplication>

#include <mainForm.h>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    mainForm *mf = new mainForm();
    mf->show();

    
    return app.exec();
}
