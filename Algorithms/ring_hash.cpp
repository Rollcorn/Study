#include <iostream>

//РЕАЛИЗАЦИЯ КОЛЬЦЕВОЙ ХЭШ-ФУНКЦИИ
//если константа не инициализированна то высчитываем её данной функцией
int hInit(unsigned int strLen) {
    int d = 52;
    int    p = 65713;

    int h = 1;
    for(unsigned int i=1; i < strLen; i++) {
        h = (h*d) % p;
    }

    return h;
}

int ringHash(char* str, unsigned int strLen, int prevHash, int *h) {
    int d = 52; //Константа из формулы
    int    p = 65713; //Вычисления производятся по модулю простого числа

    //h = d^(len-1) (mod p) - константа для быстроого пересчета хэша
    if(*h == 0) { //Если константа не инициализирована
        *h = hInit(strLen);
    }

    //Если считаем хеш первый раз
    if(prevHash == 0) {
        for(unsigned int i=0; i<strLen; i++) {
            prevHash += (d*prevHash + (int)str[i]) % p;
        }
        if(prevHash < 0) {
            prevHash += p;
        }

        return prevHash;
    }
    //Если пересчитываем для другого окна
    else {
        int hash = (d * (prevHash - (int)str[0] * (*h)) + (int)str[strLen]) % p;
        if(hash < 0) {
            hash += p;
        }

        return hash;
    }
}

//РЕАЛИЗАЦИЯ АЛГОРИТМА РОБИНА-КАРПА

int rabinKarpSearch(char* text, char* str) {
        unsigned int strLen = strlen(str);
        unsigned int textLen = strlen(text);
        int h = 0;

        //Хэш подстроки для поиска
        int strHash = ringHash(str, strLen, 0, &h);
        //Хэш первого окна в тексте
        int textHash = ringHash(text, strLen, 0, &h);

        for(unsigned int k = 0; k <= (textLen-strLen); k++) {
            if(strHash == textHash) {
                //Если хэши совпали, проверяем посимвольно
                for(unsigned int i = 0; (i < strLen) && (str[i] == text[k+i]); i++) {
                    if(i == (strLen-1)) {
                        return k;
                    }
                }
            }

            //Хэш следующего окна
            textHash = ringHash(&text[k], strLen, textHash, &h);
        }

        //Строка не найдена
        return -1;
}
