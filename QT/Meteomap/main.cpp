#include <iostream>
#include <QWidget>

#include "meteo.h"
#include "mongoConnect.h"

const int WINDOW_SIZE = 600;


int main(int argc, char *argv[])
{
    mongocxx::instance  inst{};
    mongocxx::uri       myURI("mongodb://localhost:27017");
    document myDoc;
    try {

         mongocxx::client        conn(myURI);
         mongocxx::database      myDB = conn["meteodb"];
         mongocxx::collection    myColl = myDB["cities"];

         myDoc << "name" << "Кингстон";
         mongocxx::cursor    myCor = myColl.find(myDoc.view());

         for (auto&& doc :myCor) {
             std::cout << bsoncxx::to_json(doc) << std::endl;
         }

     } catch (const std::exception& xcp){
         std::cout << "connection failed: " << xcp.what() << "\n";
         return EXIT_FAILURE;

     }

    QGraphicsScene scene(QRectF(WINDOW_SIZE/2, -WINDOW_SIZE/2, WINDOW_SIZE/2, -WINDOW_SIZE/2));
    QGraphicsView view(&scene);
    view.setFixedSize(QSize(WINDOW_SIZE, WINDOW_SIZE));

    QApplication a(argc, argv);

    view.show();


    return a.exec();
}

