#include <iostream>
#include <vector>

std::vector<int> siev(int N){
    int TEMP_SIZE = 2*N;
    std::vector<bool> prime (TEMP_SIZE, true);
    std::vector<int> prime_numbs;
    for (int i = 2; prime_numbs.size() < N; ++i){
        if (prime[i]){
            prime_numbs.push_back(i);
            if (i * i <= TEMP_SIZE){
                for (int j = i*i; j <= TEMP_SIZE; j += i){
                    prime[j] = false;
                }
            }
            if(((i+1)*(i+1)) > TEMP_SIZE)    
                TEMP_SIZE *= 2;     //ХЗ КАК ДОБАВИТЬ ПАМЯТИ 
        }
    }    
    return prime_numbs;
}

void siev_print(std::vector<int> v){
    for(int i = 0; i < v.size(); i++){
        std::cout << "Number #" << i << " - " << v[i] << std::endl;
    }

}

int main(){
    int N;
    std::cin >> N;
    std::vector<int> vec {siev(N)};
    siev_print(vec);



return 0;
}
