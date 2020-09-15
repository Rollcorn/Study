#include <iostream>
#include <vector>

std::vector<int> siev(int N){
    std::vector<int> prime (N + 1, true);
    for (int i = 2; i <= N; i++)
        if (prime[i])
            if (i * i <= N)
                for (int j = i*i; j <= N; j += i)
                    prime[j] = false;
    return prime;
}

void siev_print(std::vector<int> v){
    for(int i = 0; i <= v.size(); i++){
        if(v[i]) std::cout << i << std::endl;
    }
}

int main(){
    int N;
    std::cin >> N;
    siev_print(siev(N));
  



return 0;
}
