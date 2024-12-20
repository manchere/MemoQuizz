#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "quizzmanager.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN) && QT_VERSION_CHECK(5, 6, 0) <= QT_VERSION && QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

	QuizzManager quizzManager;
	engine.rootContext()->setContextProperty("quizzManager", &quizzManager);
    engine.load(QUrl(QStringLiteral("qrc:/qt/qml/memoquizz/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
