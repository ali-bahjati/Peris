#include "drawingform.h"
#include "ui_drawingform.h"

DrawingForm::DrawingForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawingForm)
{
    ui->setupUi(this);
<<<<<<< HEAD
=======

>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
}

DrawingForm::~DrawingForm()
{
    delete ui;
}

<<<<<<< HEAD
void DrawingForm::on_closeButton_clicked()
{
    this->close();
}
=======
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482
