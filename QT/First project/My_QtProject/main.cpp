#include <QTextStream>
#include <iostream>

int main()
{
    QTextStream out(stdout);

    //Init #1: Traditional way
    QString str1 = "The night train";
    out << str1 << endl;

    //Init #2: Object way
    QString str2("A yellow rose");
    out << str2 << endl;

    //Init #3:
    std::string s1 = "A blue sky";
    QString str3 = s1.c_str();
    out << str3 << endl;

    //Init #4:
    std::string s2 = "A thick fog";
    QString str4 = QString::fromLatin1(s2.data(), s2.size());
    out << str4 << endl;

    //Init #5:
    char s3[] = "A deep forest";
    QString str5(s3);
    out <<str5 << endl;

    return 0;
}



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
