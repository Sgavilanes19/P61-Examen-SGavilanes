#ifndef JUEGO_H
#define JUEGO_H
#include "configuracion.h"
#include "circulo.h"


#include <QMainWindow>
#include <QDebug>
#include <QPoint>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>


QT_BEGIN_NAMESPACE
namespace Ui { class Juego; }
QT_END_NAMESPACE

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    ~Juego();
protected:
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_btnArriba_released();

    void on_btnAbajo_released();

    void on_btnIzqueirda_released();

    void on_btnDerecha_released();

    void on_actionConfigraci0n_triggered();

    void on_actionSalir_triggered();

    void on_marco_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Juego *ui;
    Circulo *m_circulo;
    void dibujar();
    QImage *m_lienzo;
    QPainter *m_Painter;
};
#endif // JUEGO_H
