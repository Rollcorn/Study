#include <iostream>
#include <tuple>

std::tuple<int, int, int> MaxCrossingSabarray(int* A, int low, int mid, int high){
    int left_sum = 0;
    int max_left;
    int sum = 0;
    
    for(int i = mid; i != low; i--){
        sum += A[i];
        if (i == mid){
            left_sum = sum;
            max_left = i;
        } else if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum;
    int max_right;
    sum = 0;
    
    for (int j = mid + 1; j != high; j++) {
        sum += A[j];
        if(j == mid){
            right_sum = sum;
            max_right = j;
        } else if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }

    return std::make_tuple(max_left, max_right, left_sum + right_sum);
}

std::tuple<int, int, int> MaxSubarray(int* A, int low, int high){
    int left_sum;
    int left_low;
    int left_high;

    int cross_low;
    int cross_high;
    int cross_sum;

    int right_low;
    int right_high;
    int right_sum;

    //Base case
    if (high == low){
        return std::make_tuple(low, high, A[low]);
    }
    else {
        int mid = (low + high)/2;
        std::tie(left_low, left_high, left_sum) = MaxSubarray(A, low, mid);
        std::tie(right_low, right_high, right_sum) = MaxSubarray(A, mid + 1, high);
        std::tie(cross_low, cross_high, cross_sum) = MaxCrossingSabarray(A, low, mid, high);

        if (!(left_sum < right_sum) and !(left_sum < cross_sum))
            return std::make_tuple(left_low, left_high, left_sum);
        else if (!(right_sum < left_sum) and !(right_sum < cross_sum))
            return std::make_tuple(right_low, right_high, right_sum);
        else 
            return std::make_tuple(cross_low, cross_high, cross_sum);
    }    
}


int main(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int A1[] = { -13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -22, -15, -4, -7};   
    int ArrSize = 16;
    int low, high, sum;
    std::cout << ArrSize << '\n';
    std::tie(low, high, sum) = MaxSubarray(A1, 0, ArrSize);
    std::cout << "Low boundary is: " << low << '\n' << "High boudary is: " << high << '\n' << "Income is: " << sum << '\n';

    return 0;
}

