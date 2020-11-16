#include <iostream>
#include <QWidget>

#include "meteo.h"
#include "mongoConnect.h"

//const int WINDOW_SIZE = 600;


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(QRectF(100, 100, 100, 100));
    QGraphicsView view(&scene);
    view.setFixedSize(QSize(100, 100));

    mongocxx::instance  inst{};
    mongocxx::uri       myURI("mongodb://localhost:27017");
    document myDoc;

    try {

         mongocxx::client           conn(myURI);
         mongocxx::database         myDB = conn["meteodb"];
         mongocxx::collection       myColl = myDB["cities"];
         mongocxx::cursor           myCur = myColl.find({});

         mongocxx::cursor::iterator iter = myCur.begin();
         mongocxx::cursor::iterator iterEnd = myCur.end();

         for(int64_t i = 1; iter != iterEnd; i++){
             iter++;

             bsoncxx::document::element myName = (*iter)["name"];
             bsoncxx::document::element myLocation = (*iter)["location"]["coordinates"];
             bsoncxx::document::element myPriority = (*iter)["priority"];
             bsoncxx::document::element myMinLvl = (*iter)["min_level"];
             bsoncxx::document::element myMaxLvl = (*iter)["max_level"];

             std::string strName = std::string(myName.get_string().value);
             std::string strLocation = std::string(myLocation.get_string().value);
             int32_t strPriority = int32_t(myPriority.get_int32().value);
             int32_t strMinLvl = int32_t(myMinLvl.get_int32().value);
             int32_t strMaxLvl = int32_t(myMaxLvl.get_int32().value);



             std::cout << "Имя: " << strName << " "
                       << "Локация: " << strLocation << " "
                       << "Приоретет: " << strPriority << " "
                       << "Минимальный: " << strMinLvl << " "
                       << "Максимальный: " << strMaxLvl
                       << std::endl;

             //std::cout << bsoncxx::to_json(*iterBegin) << std::endl;

         }
         } catch (const std::exception& xcp){
         std::cout << "connection failed: " << xcp.what() << "\n";
         return EXIT_FAILURE;
     }

    view.show();
    return app.exec();

}

