#include "esp2.h"
#include "./ui_esp2.h"

//#include <windows.h>
#include <string>
#include <ctime>
#include <QMessageBox>

using namespace std;

string dni[] = {
    "domingo", "lunes", "martes", "miércoles",
    "jueves", "viernes", "sábado"
};

string miesiace[] = {
    "enero", "febrero", "marzo", "abril", "mayo", "junio",
    "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
};

string liczby[] = {
    "", "uno", "dos", "tres", "cuatro", "cinco", "seis",
    "siete", "ocho", "nueve", "diez", "once", "doce",
    "trece", "catorce", "quince", "dieciséis", "diecisiete",
    "dieciocho", "diecinueve", "veinte", "veintiuno",
    "veintidós", "veintitrés", "veinticuatro", "veinticinco",
    "veintiséis", "veintisiete", "veintiocho", "veintinueve", "treinta", "treinta y uno"
};




Esp2::Esp2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Esp2)
{
    ui->setupUi(this);
    getDateText();
    settinggs();
}

void Esp2::settinggs()
{

    //ui->labelDate->setFixedSize(320,120);
    this->setWindowTitle("Hoy");
    ui->labelDate->setWordWrap(true);
    ui->labelDate->setStyleSheet("font-size: 16px; font-weight: bold;");
    ui->labelDate->setFixedWidth(450);

    //this->setFixedSize(320,120);

    //this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground); //Przezroczytse tło
    //ui->labelDate->setAlignment(Qt::AlignCenter);

    //ui->labelDate->adjustSize();
    // ui->labelDate->setAlignment(Qt::AlignCenter);
    // ui->labelDate->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);


    //this->setFixedSize(320,120);
    //ui->labelDate->setAlignment(Qt::AlignCenter);
    //this->adjustSize();
    //this->setWindowFlags(Qt::Tool |
    //                   Qt::FramelessWindowHint |
    //                   Qt::WindowStaysOnTopHint);

    //     this->setStyleSheet(R"(
    //     background-color: #1f1f1f;
    //     color: white;
    //     border-radius: 12px;
    // )");
}


void Esp2::getDateText()

{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int dzien_tyg = now->tm_wday;   // 0-6 (niedziela = 0)
    int dzien = now->tm_mday;       // 1-31
    int miesiac = now->tm_mon;      // 0-11
    int rok = now->tm_year + 1900;

    string tekst = "Hoy es ";
    tekst += dni[dzien_tyg] + ", ";
    //tekst += std::to_string(dzien) + " de ";
    tekst += liczby[dzien] + " de ";
    tekst += miesiace[miesiac] + " de ";
    //tekst += std::to_string(rok);// dodac
    tekst += rokNaHiszpanski(rok);


    //QMessageBox::information(this, "Fecha", QString::fromStdString(tekst));
    ui->labelDate->setText(QString::fromStdString(tekst));

}

Esp2::~Esp2()
{
    delete ui;
}
string Esp2::rokNaHiszpanski(int rok)
{
    int tys = rok / 1000;          // 2
    int reszta = rok % 1000;       // 026

    string wynik = "";

    if (tys == 2) wynik += "dos mil";

    if (reszta > 0)
    {
        wynik += " ";

        if (reszta <= 30)
        {
            wynik += liczby[reszta];
        }
        else
        {
            int dzies = reszta / 10;
            int jedn = reszta % 10;

            if (reszta < 40) wynik += "treinta";
            else if (reszta < 50) wynik += "cuarenta";
            else if (reszta < 60) wynik += "cincuenta";
            else if (reszta < 70) wynik += "sesenta";
            else if (reszta < 80) wynik += "setenta";
            else if (reszta < 90) wynik += "ochenta";
            else wynik += "noventa";

            if (jedn != 0)
                wynik += " y " + liczby[jedn];
        }
    }

    return wynik;
}
