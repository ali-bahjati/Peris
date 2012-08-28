#ifndef DRAWINGFORM_H
#define DRAWINGFORM_H

#include <QMainWindow>

namespace Ui {
class DrawingForm;
}

class DrawingForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DrawingForm(QWidget *parent = 0);
    ~DrawingForm();

private slots:
    void on_closeButton_clicked();

private:
    Ui::DrawingForm *ui;
};

#endif // DRAWINGFORM_H
