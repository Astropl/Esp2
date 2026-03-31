#include "esp2.h"
#include "./ui_esp2.h"

//#include <windows.h>
#include <string>
#include <ctime>
#include <QMessageBox>
#include <QDate>

using namespace std;

string dni[] = {
    "lunes", "martes", "miércoles",
    "jueves", "viernes", "sábado", "domingo"
};

string miesiace[] = {
    "enero", "febrero", "marzo", "abril", "mayo", "junio",
    "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
};//miesiace


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
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ui->labelDate);
    layout->addWidget(ui->btnExit);
    layout->addWidget(ui->lblYesterday);
    layout->addWidget(ui->lblTomorrow);

    layout->setAlignment(ui->btnExit, Qt::AlignCenter);
    ui->centralwidget->setLayout(layout);

    layout->setSpacing(12);
    layout->setContentsMargins(10, 10, 10, 10);

    settinggs();
    getDateText();

}

void Esp2::settinggs()
{


    this->setWindowTitle("Hoy");

    ui->labelDate->setWordWrap(true);
    ui->labelDate->setStyleSheet("font-size: 16px; font-weight: bold;");
    ui->labelDate->setAlignment(Qt::AlignCenter);
    ui->labelDate->setFixedWidth(300);

    ui->btnExit->setText("Wyjście");
    ui->btnExit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //ui->labelDate->adjustSize();
    //this->adjustSize();
    ui->lblYesterday->setStyleSheet("color: #2E86C1;");
    ui->labelDate->setStyleSheet("font-weight: bold; font-size: 18px;");
    ui->lblTomorrow->setStyleSheet("color: #555555; font-style: italic;");


}


void Esp2::getDateText()

{

    QDate today = QDate::currentDate();
    QDate yesterday = today.addDays(-1);
    QDate tomorrow = today.addDays(1);

    auto buildText = [&](QDate d) -> QString {

        int dzien_tyg = d.dayOfWeek() - 1; // 0–6
        int dzien = d.day();
        int miesiac = d.month() - 1;
        int rok = d.year();

        string tekst = dni[dzien_tyg] + ", ";
        tekst += liczby[dzien] + " de ";
        tekst += miesiace[miesiac] + " de ";
        tekst += rokNaHiszpanski(rok)+ ".";

        return QString::fromStdString(tekst);
    };

    ui->lblYesterday->setText("Ayer es " + buildText(yesterday));
    ui->labelDate->setText("Hoy es " + buildText(today));
    ui->lblTomorrow->setText("Mañana es " + buildText(tomorrow));

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
            //int dzies = reszta / 10;
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

void Esp2::on_btnExit_clicked()
{
    qApp->quit();
}

