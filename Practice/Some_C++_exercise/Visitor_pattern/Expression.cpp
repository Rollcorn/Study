#include <iostream>

/*
    В данном задании вам нужно расставить ключевое слово virtual там, где это необходимо, 
определить метод evaluate там, где его не хватает, а также реализовать деструкторы, 
там где они нужны.
    Метод evaluate, который возвращает значение типа double — значение соответствующего 
арифметического выражения, например, значение экземпляра типа Number — это число, которое 
он хранит, а если у вас есть объект BinaryOperation с операцией +, то нужно вычислить 
значения левого и правого операнда и вернуть их сумму.
*/

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression(){};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    
    double evaluate() const {
        return value;
    }

    ~Number(){};

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
    
    double evaluate() const{
        double value_ = 0;
/*        if( op == '+')
            value_ = (left->evaluate() + right->evaluate());
        else if( op == '-')
            value_ = (left->evaluate() - right->evaluate());
        else if( op == '*')
            value_ = (left->evaluate() * right->evaluate());
        else if( op == '/')
            value_ = (left->evaluate() / right->evaluate());    
*/
          switch (op){
          case '+':
              value_ = (left->evaluate() + right->evaluate());
              break;
          case '-':
              value_ = (left->evaluate() - right->evaluate());
              break;  
          case '*':
              value_ = (left->evaluate() * right->evaluate());
              break;  
          case '/':
              value_ = (left->evaluate() / right->evaluate());
          }

        return value_;
    }
    
    ~BinaryOperation(){
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};


int main(){
    //выражению 3 + 4.5 * 5 будет соответствовать следующий код
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;

    return 0;
}
