#ifndef SCOPEDPTR_CPP
#define SCOPEDPTR_CPP

#include "Expression.cpp"

struct ScopedPtr
{
    
    explicit ScopedPtr(Expression *ptr = nullptr): ptr_(ptr){};
    
    ~ScopedPtr(){
        delete ptr_;
    }

// get — возвращает указатель, сохраненный внутри ScopedPtr (например, 
// чтобы передать его в какую-то функцию)
    Expression* get() const{
        return ptr_;
    }
    
    
// release — забирает указатель у ScopedPtr и возвращает значение этого указателя, 
// после вызова release ScopedPtr не должен освобождать память (например, чтобы 
// вернуть этот указатель из функции);
    Expression* release(){
        Expression* res = ptr_;
        ptr_ = nullptr;
        return res;
    }

// reset — метод заставляет ScopedPtr освободить старый указатель, а вместо него 
// захватить новый (например, чтобы переиспользовать ScopedPtr, так как оператор 
// присваивания запрещен).
    void reset(Expression *ptr = nullptr){
        delete ptr_;
        ptr_ = ptr;       
    }
    
    Expression& operator*() const{
        if(ptr_){
            return *ptr_;
        }
    }

    Expression* operator->() const{
        if(ptr_){
            return ptr_;
        }
    }


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression* ptr_;
};





#endif
