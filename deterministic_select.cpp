#include "deterministic_select.hpp"
#include <iostream>
#include <vector> 
#include <limits> 
#include <algorithm>
#include <stdexcept> 

// ---Public Functions--- 
int deterministicSelectKthSmallest (const std::vector<int>& arr, int k ){
    std::vector<int> v = arr;
    deterministicSelect(v, 0, v.size()-1, k);
}

double deterministicSelectMedian (const std::vector<int> & arr){
    std::vector<int> v = arr;
    int size = arr.size();
    if (size == 1){
        return v[0];
    }
    if (size % 2 == 1){
        return deterministicSelect(v, 0, v.size()-1, size/2);
    }
    else {
        int lowerMid = deterministicSelect(v, 0, size-1, size/2 - 1);
        int upperMid = deterministicSelect(v, 0, size-1, size/2);
        return (lowerMid + upperMid)/ 2.0;
    }
}
// ---External Helper Functions--- 
// findGroupMedian to find the lower median of the group size <= 5 for pivot. 
static int findGroupMedian (std::vector<int>& group){
    std::sort(group.begin(), group.end());
    int size = group.size();
    return group[size/2];
}
// deterministicSelect core algorithm, finding the K smallest elements across a range in O(n).
static int deterministicSelect (std::vector<int>& arr, int left, int right, int k ){}

