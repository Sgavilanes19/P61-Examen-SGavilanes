#include "circulo.h"

int Circulo::getTalla() const
{
    return tal;
}

void Circulo::setTalla(int value)
{
    tal = value;
}

int Circulo::getAncho() const
{
    return alto;
}

void Circulo::setAncho(int value)
{
    alto= value;
}

int Circulo::getAnchx() const
{
    return alto;
}

void Circulo::setAnchx(int value)
{
    alto = value;
}

Circulo::Circulo()
{
    ancho=20;
    alto=200;
    tal=150;
}

Circulo::Circulo(int x, int y, int size)
{
    this->alto=x;
    this->ancho=y;
    this->tal=size;
}
