#include <QTextStream>

int main() {

   QTextStream out(stdout);

   // Исходная строка
   QString str = "Lovely";

   // С помощью метода append() добавляем новую строку в конец исходной строки
   str.append(" season");
   out << str << endl;

   // С помощью метода remove() удаляем 3 символа, начиная с позиции №10 исходной строки
   str.remove(10, 3);
   out << str << endl;

   // С помощью метода replace() заменяем 3 символа, начиная с позиции №7 исходной строки
   str.replace(7, 3, "girl");
   out << str << endl;

   // Очищаем строку
   str.clear();

   if (str.isEmpty()) {
     out << "The string is empty" << endl;
   }

   return 0;
}
