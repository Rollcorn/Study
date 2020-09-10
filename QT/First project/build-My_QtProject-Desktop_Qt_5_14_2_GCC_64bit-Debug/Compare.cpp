#include <iostream>
#include <QTextStream>


// Добавляем для лучшей читаемости кода
const int STR_EQUAL = 0;

/*int main() {

   QTextStream out(stdout);

   // Будем сравнивать следующие 3 строки
   QString a = "Rain";
   QString b = "rain";
   QString c = "rain\n";

// Первое сравнение: отличие сразу же в первом символе
   if (QString::compare(a, b) == STR_EQUAL) {
     out << "a, b are equal" << endl;
   } else {
     out << "a, b are not equal" << endl;
   }

   out << "In case insensitive comparison:" << endl;

// С помощью флага Qt::CaseInsensitive отключаем чувствительность к регистру
   if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL) {
     out << "a, b are equal" << endl; // и получаем равные строки
   } else {
     out << "a, b are not equal" << endl;
   }

   if (QString::compare(b, c) == STR_EQUAL) {
     out << "b, c are equal" << endl;
   } else {
     out << "b, c are not equal" << endl;
   }

   // Удаляем символ новой строки в строке c
   c.chop(1);

   out << "After removing the new line character" << endl;

   if (QString::compare(b, c) == STR_EQUAL) {
     out << "b, c are equal" << endl; // теперь наши строки равны
   } else {
     out << "b, c are not equal" << endl;
   }

   return 0;
}
*/
