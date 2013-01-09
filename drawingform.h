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
<<<<<<< HEAD
    
private slots:
    void on_closeButton_clicked();
=======
>>>>>>> 86676bede2834bec473bb363ac16819cedfbc482

private:
    Ui::DrawingForm *ui;
};

#endif // DRAWINGFORM_H
