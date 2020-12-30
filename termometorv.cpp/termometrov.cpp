#include "termometrov.h"
#include "ui_termometrov.h"
#include <QDebug>

TermometroV::TermometroV(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TermometroV)
{
    ui->setupUi(this);

    connect(ui->dialCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));

    connect(ui->dialFahr, SIGNAL(valueChanged(int)),
            this, SLOT(Fahr2cent(int)));

    connect(ui->dialKelvin, SIGNAL(valueChanged(int)),
            this, SLOT(Kelvin2centi(int)));

    connect (ui->dialCent,SIGNAL(valueChanged(int)),
             this,SLOT(Cent2kelvin(int)));

    connect(ui->dialKelvin,SIGNAL(valueChanged(int)),
            this, SLOT(Kelvin2fahr(int)));

    connect(ui->dialFahr, SIGNAL(valueChanged(int)),
            this, SLOT(Fahr2kelvin(int)));

    connect(ui->dialCent, SIGNAL(sliderPressed()),
            this, SLOT(cambiarCursor()));

    connect(ui->dialCent, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));

    ui->dialFahr->setValue(32);
    ui->dialKelvin->setValue(273);
}

TermometroV::~TermometroV()
{
    delete ui;
}

float TermometroV::cent2Fahr(int valor)
{
    if(ui->dialCent->hasFocus()){
        float f = valor * 9.0/5 + 32;
        //ESTO ES PARA COMPROBAR LOS VALORES
        //qDebug() << "C = " << valor << ", F = " << f;
        ui->dialFahr->setValue(f);
        //DEPURACION ... mirar que pasa para corregir el error
        //XqDebug() << "En cent2fahr";
        return f;
    }
    return 0;
}

float TermometroV::Fahr2cent(int valor)
{
    if(ui->dialFahr->hasFocus()){   //hasfocus cuando selecciono el contro para mover el dial
        float c = (valor-32) * 5.0/9;
        ui->dialCent->setValue(c);
        //DEPUERACION  qDebug() << "En fahr2cent";
        return c;
    }
    return 0;
}

float TermometroV::Kelvin2centi(int valor)
{
    if(ui->dialKelvin->hasFocus()){
        float k = valor - 273.15;
        ui->dialCent->setValue(k);
        return k;
    }
    return 0;
}

float TermometroV::Kelvin2fahr(int valor)
{
    if(ui->dialKelvin->hasFocus()){
        float kf = (valor - 273.15) * 9.0/5 + 32;
        ui->dialFahr->setValue(kf);
        return kf;
    }
    return 0;
}

float TermometroV::Cent2kelvin(int valor)
{
    if(ui->dialCent->hasFocus()){
        float ck = valor + 273.15;
        ui->dialKelvin->setValue(ck);
        return ck;
    }
    return 0;
}

float TermometroV::Fahr2kelvin(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float fk = (valor-32)* 5.0/9 + 273.15;
        ui->dialKelvin->setValue(fk);
        return fk;
    }
    return 0;
}

void TermometroV::cambiarCursor()
{
    // if(ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::ClosedHandCursor);
    // }else{
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);
    // }
}

void TermometroV::dialRelajado()
{
    // if(ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::OpenHandCursor);
    // }else{
        ui->dialFahr->setCursor(Qt::OpenHandCursor);
   // }
}





























