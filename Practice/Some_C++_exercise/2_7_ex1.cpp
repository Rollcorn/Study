#include <iostream>
#include <cstdlib>


int** create_arr2d(size_t row, size_t colm)
{
    int** m = new int* [row];
    m[0] = new int[row * colm];
    for (size_t i = 1; i != row; ++i)
        m[i] = m[i - 1] + colm;
    return m;
}

void arr_fill(int** m, size_t rows, size_t colms)
{
    for(int i = 0; i != rows; ++i)
    {
        for(int j = 0; j != colms; ++j){
            m[i][j] = i*10 + j;
        }
    }
}

void arr_print(int** m, size_t rows, size_t colms)
{
    for(int i = 0; i != rows; ++i)
    {
        for(int j = 0; j != colms; ++j){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** transpose(int** m, unsigned rows, unsigned cols)
{
    int** m2 = create_arr2d(cols, rows);
    for(int i = 0; i != cols; ++i){
        for(int j = 0; j != rows; ++j){
            m2[i][j] = m[j][i];
        }
    }
    return m2;
}

void free_arr(int** m)
{
    delete [] m[0];
    delete [] m;
}


int main(){
    int** m = create_arr2d(3, 3);
    arr_fill(m, 3, 3);
    arr_print(m, 3, 3);
    int** m_t = transpose(m, 3, 3);
    arr_print(m_t, 3, 3);

    free_arr(m);
    free_arr(m_t);
    return 0;
}
