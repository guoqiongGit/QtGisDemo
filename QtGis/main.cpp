#include "QtGis.h"
#include <QtWidgets/QApplication>
#include "qgsapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //可执行程序的当前目录
    QString appDir = QCoreApplication::applicationDirPath();
    //设置QSetting环境
    QCoreApplication::setOrganizationName("QtQgis");
    QCoreApplication::setApplicationName("QtQgis Application");

    //初始化QGIS环境
    QgsApplication::init(appDir);
    QgsApplication::initQgis();
    QgsApplication::setMaxThreads(8);
    //QApplication::setStyle(new WhiteStyle());

    QtGis w;
    w.showMaximized();
    return a.exec();
}
