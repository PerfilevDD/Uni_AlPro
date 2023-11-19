#include <mergesort.hpp>

#include <vector>

std::vector<int> elminarr(const std::vector<int>& arr, const int& num){
    std::vector<int> ret_arr(num);
    for (int i = 0; i < num - 1; i++){
        ret_arr.push_back(arr[i]);
    }
    return ret_arr;
}

std::vector<int> mergesort(std::vector<int>& A){
    int k = A.size();
    if (k>1){
        int t = k / 2;
        std::vector<int> L = elminarr(A, t);
        std::vector<int> R = elminarr(A, k - t);
        L = mergesort(L);
        R = mergesort(R);

        return merge(L, R);
    }
    return A;
}

