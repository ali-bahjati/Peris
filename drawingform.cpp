#include "drawingform.h"
#include "ui_drawingform.h"

DrawingForm::DrawingForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawingForm)
{
    ui->setupUi(this);

}

DrawingForm::~DrawingForm()
{
    delete ui;
}

