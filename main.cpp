#include <QApplication>
#include<start.h>
#include<QResource>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource("./plane.rcc");
    start s;
    s.show();

    return a.exec();
}
