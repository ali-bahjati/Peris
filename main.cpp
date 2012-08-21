#include <QtGui/QApplication>
#include "drawingform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawingForm w;
    w.show();

    
    return a.exec();
}
