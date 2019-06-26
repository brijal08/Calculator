#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "calulatorresult.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QScopedPointer<CalulatorResult> caluculatorresult(new CalulatorResult);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    engine.rootContext()->setContextProperty("caluculatorresult",caluculatorresult.data());
    return app.exec();
}
