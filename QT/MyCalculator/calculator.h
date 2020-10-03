#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QString>

#include "mybutton.h"

class Calculator : public QWidget
{
        Q_OBJECT
public:
    Calculator();

private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void doubleOperandClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void addToMemory();
    void minToMemory();
private:
    MyButton* createButton(const QString& text, const char* member);

    void abortOperation();
    double      m_sum_in_memory;

    QString     m_pending_operation;

    QLineEdit*  m_display_up;
    QLineEdit*  m_display_down;
    QLabel*     m_sign;

    MyButton* m_digitButtons[10];

    bool calculate(double operand, const QString& operation);

    QString m_squareRoot_sign = QChar(0x0000221A);
    QString m_power_sign = 'x' + QChar(0x000000b2);
    QString m_reciprocal_sign = "1/x";

    QString m_division_sign = QChar(0x000000F7);
    QString m_times_sign = QChar(0x000000D7);
    QString m_plus_sign = "+";
    QString m_minus_sign = "-";

    QString m_change_sign = QChar(0x000000b1);

};

#endif // CALCULATOR_H
