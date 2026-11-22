#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(std::vector<int>& a, std::vector<int>& b){
    std::vector<int> vec;
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            vec.push_back(a[i]);
            i++;
        }
        else{
            vec.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()){
        vec.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        vec.push_back(b[j]);
        j++;
    }

    return vec;
}

void test_mergeSortedVectors(){
    std::vector<int> a = {1, 3, 5, 7};
    std::vector<int> b = {2, 4, 6, 8};
    std::vector<int> vec = mergeSortedVectors(a, b);

    assert(vec.size() == 8);
    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    assert(vec[3] == 4);
    assert(vec[4] == 5);
    assert(vec[5] == 6);
    assert(vec[6] == 7);
    assert(vec[7] == 8);

    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
}

int main(){
    test_mergeSortedVectors();

    return 0;
}