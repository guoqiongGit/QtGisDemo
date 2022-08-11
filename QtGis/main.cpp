#include "QtGis.h"
#include <QtWidgets/QApplication>
#include "qgsapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //��ִ�г���ĵ�ǰĿ¼
    QString appDir = QCoreApplication::applicationDirPath();
    //����QSetting����
    QCoreApplication::setOrganizationName("QtQgis");
    QCoreApplication::setApplicationName("QtQgis Application");

    //��ʼ��QGIS����
    QgsApplication::init(appDir);
    QgsApplication::initQgis();
    QgsApplication::setMaxThreads(8);
    //QApplication::setStyle(new WhiteStyle());

    QtGis w;
    w.showMaximized();
    return a.exec();
}
