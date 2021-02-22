/*
Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.

Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.
*/

#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    Rational& operator+=(Rational const& rat) 
    {
        this->numerator_ = numerator_ * rat.denominator_ + rat.numerator_ * denominator_;
        denominator_ = denominator_ * rat.denominator_;
        return *this;
    }   
    
    Rational& operator-=(Rational const& rat) 
    {
        numerator_ = numerator_ * rat.denominator_ - rat.numerator_ * denominator_;
        denominator_ = denominator_ * rat.denominator_;
        return *this;
    }

    Rational& operator*=(Rational const& rat) 
    {
        numerator_ *= rat.numerator_;
        denominator_ *= rat.denominator_;
        return *this;
    }

    Rational& operator/=(Rational const& rat)
    {
        numerator_ *=  rat.denominator_;
        denominator_ *= rat.numerator_;
        return *this;
    } 
   
     Rational operator-() const
     {
         return  Rational(-numerator_, denominator_);
     }
    
     Rational operator+() const
     {
         return *this;
     }
   
    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }
    
    void print(){
        std::cout << numerator_ << '/' << denominator_;
    }

private:
    int numerator_;
    int denominator_;
};


int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);

    r1.add(r2);
    std::cout << r1.to_double() << std::endl;
    r1.sub(r2);
    std::cout << r1.to_double() << std::endl;
    r1.neg();
    std::cout << r1.to_double() << std::endl;
    r3.mul(r1);
    std::cout << r3.to_double() << std::endl;
    r3.div(r2);
    std::cout << r3.to_double() << std::endl;
    
    r1 += r2;
    r1.print(); 
    std::cout << std::endl;
    r2 *= r2;
    r2.print();
    std::cout << std::endl;
    r1 /= r2;
    r1.print();
    std::cout << std::endl;
    r3 -= r1;
    r3.print();
    std::cout << std::endl;



}
