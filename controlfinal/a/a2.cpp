
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            ++i;
        }
        else {
            result.push_back(arr2[j]);
            ++j;
        }
    }

    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        ++i;
    }

    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        ++j;
    }

    return result;
}

std::vector<int> mergeKArrays(std::vector<std::vector<int>>& arrays, int start, int end) {
    if (start == end) {
        return arrays[start];
    }

    int mid = (start + end) / 2;
    std::vector<int> left = mergeKArrays(arrays, start, mid);
    std::vector<int> right = mergeKArrays(arrays, mid + 1, end);

    return mergeArrays(left, right);
}

int main() {
    
    std::vector<std::vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int k = arrays.size();
    std::vector<int> result = mergeKArrays(arrays, 0, k - 1);

    std::cout << "Array combinado: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
