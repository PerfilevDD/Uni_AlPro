#include <mergesort.hpp>

#include <vector>

std::vector<int> elminarr(const std::vector<int> &arr, const int &num)
{
    std::vector<int> ret_arr(num);
    for (int i = 0; i < num - 1; i++)
    {
        ret_arr.push_back(arr[i]);
    }
    return ret_arr;
}

std::vector<int> mergesort(std::vector<int> &A)
{
    int k = A.size();
    if (k > 1)
    {
        int t = k / 2;
        std::vector<int> L = elminarr(A, t);
        std::vector<int> R = elminarr(A, k - t);
        L = mergesort(L);
        R = mergesort(R);

        return merge(L, R);
    }
    else
    {
        return A;
    }
}

std::vector<int> merge(std::vector<int> &L, std::vector<int> &R)
{
    std::vector<int> Y(L.size(), R.size());
    int i, j = 0;
    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
        {
            Y[i + j] = L[i];
            i++;
        }
        else
        {
            Y[i + j] = R[j];
            j++;
        }
    }
    while (i < L.size())
    {
        Y[i + j] = L[i];
        i++;
    }
    while (j < R.size())
    {
        Y[i + j] = R[j];
        j++;
    }
    return Y;
}