#include <mergesort.hpp>
#include <iostream>
#include <vector>

std::vector<int> elminarr(const std::vector<int> &arr, const int &start, const int &num)
{
    std::vector<int> ret_arr;
    for (int i = start; i < num; i++)
    {
        ret_arr.push_back(arr[i]);
    }
    return ret_arr;
}

std::vector<int> mergesort(std::vector<int> &arr)
{
    int arr_size = arr.size();
    if (arr_size > 1)
    {
        int middle = arr_size / 2;
        std::vector<int> left_arr = elminarr(arr, 0, middle);
        std::vector<int> right_arr = elminarr(arr, middle, arr_size);
        left_arr = mergesort(left_arr);
        right_arr = mergesort(right_arr);

        return merge(left_arr, right_arr);
    }
    else
    {
        return arr;
    }
}

std::vector<int> merge(std::vector<int> &left_arr, std::vector<int> &right_arr)
{
    std::vector<int> merge_arr(left_arr.size() + right_arr.size());
    int i = 0;
    int j = 0;

    for (; i < left_arr.size(); i++)
    {
        for (; j < right_arr.size(); j++)
        {

            if (left_arr[i] <= right_arr[j])
            {
                merge_arr[i + j] = left_arr[i];
            }
            else
            {
                merge_arr[i + j] = right_arr[j];
            }
        }
    }

    for (;i < left_arr.size(); i++)
    {
        merge_arr[i + j] = left_arr[i];
        
    }
    for (;j < right_arr.size(); j++)
    {
        merge_arr[i + j] = right_arr[j];
    }
    return merge_arr;
}