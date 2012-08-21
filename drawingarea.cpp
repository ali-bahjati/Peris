#include "drawingarea.h"
#include "ui_drawingform.h"


DrawingArea::DrawingArea(QWidget *parent) :
    QWidget(parent)
{

}

void DrawingArea::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),*(DrawingArea::pixmap));
}

void DrawingArea::mouseMoveEvent(QMouseEvent *e)
{
    if ( e->x() < width() && e->y() < height())
    {
        if (DrawingArea::lastx == 0 && DrawingArea::lasty == 0)
        {
            DrawingArea::lastx = e->x();
            DrawingArea::lasty = e->y();
        }
        QPainter painter(DrawingArea::pixmap);
        painter.setPen(Qt::black);
        painter.drawLine( DrawingArea::lastx , DrawingArea::lasty , e->x() , e->y() );


        DrawingArea::pointsX.push_back(e->x());
        DrawingArea::pointsY.push_back(e->y());


        DrawingArea::lastx = e->x();
        DrawingArea::lasty = e->y();
        update();
    }
    else
    {
        DrawingArea::lastx = 0;
        DrawingArea::lasty = 0;
    }
}
void DrawingArea::mouseReleaseEvent(QMouseEvent *)
{
    DrawingArea::lastx = 0;
    DrawingArea::lasty = 0;

    //just for testing, we will have a tester class later ;)

    PreProcessing::Scale scale;
    scale.scaleWidth = 300;
    scale.squareScale(DrawingArea::pointsX, DrawingArea::pointsY);


    DrawingArea::pointsX = scale.getPointsX();
    DrawingArea::pointsY = scale.getPointsY();

    QPainter painter(DrawingArea::pixmap);
    painter.setPen(Qt::red);
    painter.drawRect(0,0,300,300);

    for (unsigned int i = 0; i < DrawingArea::pointsX.size() ; i++)
    {
        painter.drawEllipse(DrawingArea::pointsX[i] - 2, DrawingArea::pointsY[i] - 2,4,4);
    }


    update();
}

void DrawingArea::showEvent(QShowEvent *)
{
    DrawingArea::lastx = 0;
    DrawingArea::lasty = 0;

    DrawingArea::pixmap =  new QPixmap(width(),height());
    QPainter painter(DrawingArea::pixmap);

    painter.fillRect(0,0,width(),height(),Qt::white);
    update();
}

void DrawingArea::on_resetButton_clicked()
{
    DrawingArea::pointsX.clear();
    DrawingArea::pointsY.clear();

    QPainter painter(DrawingArea::pixmap);
    painter.fillRect(0,0,width(),height(),Qt::white);
    update();
}
