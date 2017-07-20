#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./header/board.h"

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    Artificial Intelligence 2 exercise: Tic-Tac-Toe with
    Minimax and alpha-beta pruning algorithm
**/

int main(int argc, char *argv[]) {

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<Board>("ia2.project", 1, 0, "Board");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
