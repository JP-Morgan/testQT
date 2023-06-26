
#include "hand_tappting.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hand_tappting w;
    w.show();
    return a.exec();
}
