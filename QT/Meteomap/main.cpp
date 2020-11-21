#include <iostream>
#include <QWidget>


#include "meteo.h"
#include "mongoConnect.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(QRectF(0, 0, 1080, 540));
    QGraphicsView view(&scene);

    view.setFixedSize(QSize(1100, 550));

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
         iter++;
         for(; iter != iterEnd; iter++){

             bsoncxx::document::element myName = (*iter)["name"];
             bsoncxx::document::element myLocation = (*iter)["location"]["coordinates"];
             bsoncxx::document::element myPriority = (*iter)["priority"];
             bsoncxx::document::element myMinLvl = (*iter)["min_level"];
             bsoncxx::document::element myMaxLvl = (*iter)["max_level"];
//Получаю данные из БД
             std::string strName = myName.get_string().value.to_string();
             double x = double((myLocation.get_array().value[0]).get_double());
             double y = double((myLocation.get_array().value[1]).get_double());
             int32_t strPriority = int32_t(myPriority.get_int32().value);
             int32_t strMinLvl = int32_t(myMinLvl.get_int32().value);
             int32_t strMaxLvl = int32_t(myMaxLvl.get_int32().value);


             std::cout << "Имя: " << strName << "; "
                       << "Локация: " << x << " : "
                                      << y << "; "
                       << "Приоретет: " << strPriority << "; "
                       << "Минимальный: " << strMinLvl << "; "
                       << "Максимальный: " << strMaxLvl
                       << std::endl;
//Создаю объект обозначающих город в данной точке.
                QGraphicsRectItem* cityPoint = scene.addRect(QRectF(0, 0, 10, 10), QPen(Qt::black), QBrush(Qt::red));
//Преобразую координаты карты к координатам сцены на экране.
                double locX;
                double locY;
                if(x <= 0){
                    x = qAbs(x);
                    locX = (180 - x);
                }else locX = 180 + x;

                if(y <= 0){
                    y = qAbs(y);
                    locY = 90 + y;
                }else locY = 90 - y;

                cityPoint->setPos(3*locX, 3*locY);
//Прячу эллементы в случае коллизии.
                if(!cityPoint->collidingItems().isEmpty()){
                    cityPoint->hide();
                }
             view.show();

            }
         } catch (const std::exception& xcp){
         std::cout << "connection failed: " << xcp.what() << "\n";
         return EXIT_FAILURE;
     }

    return app.exec();
}

