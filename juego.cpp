#include "juego.h"
#include "ui_juego.h"


#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    QPoint centro = ui->marco->geometry().center();
    m_circulo = new Circulo();
    m_circulo->setX(centro.x());
    m_circulo->setY(centro.y());
    m_lienzo = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    m_lienzo->fill(Qt::white);
    m_Painter = new QPainter(m_lienzo);
    m_Painter->setRenderHint(QPainter::Antialiasing);
    dibujar();
}

Juego::~Juego()
{

    delete ui;
    delete m_lienzo;
    delete m_Painter;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *m_lienzo);
}




void Juego::on_btnArriba_released()
{
    m_lienzo->fill(Qt::white);
    m_circulo->setAncho(m_circulo->getAncho()-1);
    if (m_circulo->getAncho()==30){
        QMessageBox::information(this,"No es posible","Fuera de rango");
                return;
    }
    dibujar();

}


void Juego::on_btnAbajo_released()
{
    m_lienzo->fill(Qt::white);
    m_circulo->setAncho(m_circulo->getAncho()+1);
    dibujar();
}


void Juego::on_btnIzqueirda_released()
{
   m_lienzo->fill(Qt::white);
    m_circulo->setAnchx(m_circulo->getAnchx()-1);
    dibujar();
}


void Juego::on_btnDerecha_released()
{
    m_lienzo->fill(Qt::white);
    m_circulo->setAnchx(m_circulo->getAnchx()+1);

    dibujar();
}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{

    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::black);
    pincel.setJoinStyle(Qt::MiterJoin);

    pincel.setColor(Qt::black);
    pincel.setWidth(5);
    m_Painter->setPen(pincel);
    m_Painter->drawEllipse(m_circulo->getAnchx(), m_circulo->getAncho(), m_circulo->getTalla(), m_circulo->getTalla());
    update();
}


void Juego::on_marco_customContextMenuRequested(const QPoint &pos)
{

}

