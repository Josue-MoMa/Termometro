#ifndef TERMOMETROV_H
#define TERMOMETROV_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TermometroV; }
QT_END_NAMESPACE

class TermometroV : public QMainWindow
{
    Q_OBJECT

public:
    TermometroV(QWidget *parent = nullptr);
    ~TermometroV();

public slots:
    float cent2Fahr(int);
    float Fahr2cent(int);

    float Kelvin2centi(int);
    float Kelvin2fahr(int);

    float Cent2kelvin(int);
    float Fahr2kelvin(int);

    void cambiarCursor();
    void dialRelajado();

private:
    Ui::TermometroV *ui;

};
#endif // TERMOMETROV_H
