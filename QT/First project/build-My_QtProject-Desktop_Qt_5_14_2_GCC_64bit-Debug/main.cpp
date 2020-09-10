#include <QTextStream>
#include <iostream>

/*
{

    QTextStream out(stdout);

    QString str = "There are many stars.";

// Способ №1: foreach является расширением языка C++ средствами Qt
    foreach (QChar qc, str) {
      out << qc << " ";
    }

    out << endl;

// Способ №2: Использование итераторов
    for (QChar *it=str.begin(); it!=str.end(); ++it) {
      out << *it << " " ;
    }

    out << endl;

// Способ №3
    for (int i = 0; i < str.size(); ++i) {
      out << str.at(i) << " ";
    }

    out << endl;

    return 0;

}
*/
/*
{

   QTextStream out(stdout);

// Исходная строка
   QString str = "The night train";

// Возвращаем подстроку длиной 5 символов, начиная с правого края строки str
   out << str.right(5) << endl;

// Возвращаем подстроку длиной 9 символов, начиная с левого края строки str
   out << str.left(9) << endl;

// Возвращаем подстроку длиной 5 символов, начиная с 4-ого символа строки str
   out << str.mid(4, 5) << endl;

// Первым параметром мы указываем исходную строку, вторым — начальную позицию,
// третьим — длину подстроку
   QString str2("The big apple");
   QStringRef sub(&str2, 0, 7);

   out << sub.toString() << endl;

   return 0;
}
*/
/*
{
    QTextStream out(stdout);

       // Используем маркер %1 для вставки значения
       QString s1 = "There are %1 white roses";

       // Наш маркер будет заменяться этим целочисленным значением
       int n = 12;

       // Выполняем операцию вставки значения
       out << s1.arg(n) << endl;

       // Используем маркер %1 для вставки значения
       QString s2 = "The tree is %1 m high";

       // Наш маркер будет заменяться этим значением типа с плавающей запятой
       double h = 5.65;

       // Выполняем операцию вставки значения
       out << s2.arg(h) << endl;

       // Используем 2 маркера для вставки 2-ух значений
       QString s3 = "We have %1 lemons and %2 oranges";

       // Наши маркеры будут заменяться следующими значениями
       int ln = 12;
       int on = 4;

       // Выполняем операцию вставки
       out << s3.arg(ln).arg(on) << endl;
    return 0;
}
*/
/*
{
    QTextStream out(stdout);

      // Обычная строка
      QString s1 = "Eagle";

      // Здесь у нас символ новой строки
      QString s2 = "Eagle\n";

      // Здесь у нас пробел в конце строки
      QString s3 = "Eagle ";

      // А это вообще кириллица
      QString s4 = "орел";

      out << s1.length() << endl;
      out << s2.length() << endl;
      out << s3.length() << endl;
      out << s4.length() << endl;

    return 0;
}
*/

/*
{
    QTextStream out(stdout);

    //Original string
    QString a = "Eagle";

    //Out the first string elem
    out << a[0] << endl;

    //Out fifth string elem
    out << a[4] << endl;

    //Out first string elem by at()
    out << a.at(0) << endl;

    return 0;
}

*/
/*
{
    QTextStream out(stdout);

    //Init #1: Traditional way
    QString str1 = "The night train";
    out << str1 << endl;

    //Init #2: Object way
    QString str2("A yellow rose");
    out << str2 << endl;

    //Init #3: Метод c_str() генерирует строку C-style.
    std::string s1 = "A blue sky";
    QString str3 = s1.c_str();
    out << str3 << endl;

    //Init #4: конвертируем стандартную строку C++ в объект
    //         класса QString, используя метод fromLatin1()
    std::string s2 = "A thick fog";
    QString str4 = QString::fromLatin1(s2.data(), s2.size());
    out << str4 << endl;

    //Init #5: строка в языке C, которая является массивом символов
    char s3[] = "A deep forest";
    QString str5(s3);
    out <<str5 << endl;

    return 0;
}
*/


/*{
    QTextStream out(stdout);

    QString a = "love";

    a.append(" chess");

    a.prepend("I ");

    out << a << endl;

    out << "The a string has " << a.count() << " charactes"
                                            << endl;

    out << a.toUpper() << endl;

    out << a.toLower() << endl;

    return 0;
}
*/
