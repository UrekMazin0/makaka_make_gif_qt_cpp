#include "widgets/widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
                    "QPushButton{"
                    "background-color: rgb(60, 60, 120);"
                    "border-radius: 4px;"
                    "border-bottom: 3px transparent;"
                    "border-right: 2px transparent;"
                    "border-left: 2px transparent;}"
                    "QPushButton:hover{"
                    "background-color: rgb(255,130,00);} "
                    "QPushButton:pressed  {"
                    "background-color: rgb(232,95,76); } "
                    );
    Widget w;
    w.show();
    return a.exec();
}
