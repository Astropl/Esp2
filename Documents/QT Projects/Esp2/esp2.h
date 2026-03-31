#ifndef ESP2_H
#define ESP2_H

#include <QMainWindow>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class Esp2;
}
QT_END_NAMESPACE

class Esp2 : public QMainWindow
{
    Q_OBJECT

public:
    Esp2(QWidget *parent = nullptr);
    ~Esp2();


    void getDateText();
    void settinggs();

    string rokNaHiszpanski(int rok);
private slots:
    void on_btnExit_clicked();

private:
    Ui::Esp2 *ui;
};
#endif // ESP2_H
