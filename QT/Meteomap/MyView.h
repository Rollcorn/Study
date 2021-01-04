#ifndef METEO_H
#define METEO_H
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsItem>
#include <QtMath>

class Meteo : public QWidget
{
    Q_OBJECT

public:
    Meteo();

private slots:
    void zoomIn();
    void zoomOut();


};

#endif // METEO_H
