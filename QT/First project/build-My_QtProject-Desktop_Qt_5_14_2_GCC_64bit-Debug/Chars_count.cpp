#include <QTextStream>
/*
int main() {

  QTextStream out(stdout);

  // Создадим по одной переменной для каждой категории символов
  int digits  = 0;
  int letters = 0;
  int spaces  = 0;
  int puncts  = 0;

  // Исходная строка
  QString str = "7 white, 13 red roses.";

  // Выполняем посимвольный перебор строки
  foreach(QChar s, str) {

    // Используем необходимые методы для сортировки символов по соответствующим категориям
    if (s.isDigit()) {
      digits++;
    } else if (s.isLetter()) {
      letters++;
    } else if (s.isSpace()) {
      spaces++;
    } else if (s.isPunct()) {
      puncts++;
    }
  }

  // Выводим результат на экран
  out << QString("There are %1 characters").arg(str.count()) << endl;
  out << QString("There are %1 letters").arg(letters) << endl;
  out << QString("There are %1 digits").arg(digits) << endl;
  out << QString("There are %1 spaces").arg(spaces) << endl;
  out << QString("There are %1 punctuation characters").arg(puncts) << endl;

  return 0;
}
*/
