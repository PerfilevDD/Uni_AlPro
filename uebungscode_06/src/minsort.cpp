#include <minsort.hpp>
#include <vector>

// Hier wird minsort in place implementiert

std::vector<int> minsort_in_place(std::vector<int>& array){

    int n = array.size();

    for(int i = 0;i < n-1;i++){
            int min = i;
            
            for(int j = i+1; j<n;j++ ){

                if(array[j] < array[min]){
                    min = j;
                }
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            }
    }
 return array;
}
