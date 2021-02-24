/*
Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.
Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.
*/
#ifndef RATIONAL_HPP
#define RATIONAL_HPP
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
/*  
    Использовал модификатор доступа friend, чтобы определенные вне класса операторы имели доступ к приватным
полям.
    Методы определенны вне класса, чтобы иметь возможность передачи в качестве левого оператора объекта по
значению. Например, чтобы получить результат выражения 1 < a; 
*/
    friend bool operator<(Rational const &lhs, Rational const& rhs)
    friend bool operator==(Rational const &lhs, Rational const& rhs);


private:
    int numerator_;
    int denominator_;
};

    Rational operator+(Rational rational1, Rational const &rational2){
        return rational1 += rational2;
    }

    Rational operator-(Rational rational1, Rational const &rational2){
        return rational1 -= rational2;
    }

    Rational operator*(Rational rational1, Rational const &rational2){
        return rational1 *= rational2;
    }

    Rational operator/(Rational rational1, Rational const &rational2){
        return rational1 /= rational2;
    }

    bool operator<(Rational const &lhs, Rational const& rhs){
        return ((lhs.numerator_ * rhs.denominator_) < (rhs.numerator_ * lhs.denominator_));
    }

    bool operator==(Rational const &lhs, Rational const& rhs){
            return (lhs.numerator_ == rhs.numerator_) and (lhs.denominator_ == rhs.denominator_);
    }

    bool operator!=(Rational const &lhs, Rational const& rhs){
            return !(lhs == rhs);
    }

    bool operator>(Rational const &lhs, Rational const& rhs){
            return rhs < lhs;
    }

    bool operator<=(Rational const &lhs, Rational const& rhs){
            return !(lhs > rhs);
    }

    bool operator>=(Rational const &lhs, Rational const& rhs){
            return !(lhs < rhs);
    } 

#endif
