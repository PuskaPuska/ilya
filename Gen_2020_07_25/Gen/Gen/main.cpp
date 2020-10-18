#include "gen.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	const QStringList arguments = a.arguments();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    Gen w;
    w.show();
	/*if (arguments.size() > 1 && QFile::exists(arguments.last())) {
      w.openOutside(arguments.last());
    }*/
    return a.exec();
}
