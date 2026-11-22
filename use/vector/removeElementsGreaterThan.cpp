#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& vec, int value){
    int count = 0;
    while(vec.size() > 0){
            if (vec.back() > value){
                vec.pop_back();
                count++;
            }
            else{
                break;
            }
        }
        return count;
}

void test_removeElementsGreaterThan(){
    std::vector<int> vec = {1, 3, 5, 7, 9};
    int removed = removeElementsGreaterThan(vec, 5);

    assert(removed == 2);
    assert(vec.size() == 3);
    assert(vec[0] == 1);
    assert(vec[1] == 3);
    assert(vec[2] == 5);
    
    std::cout << removed << "\n";
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
}

int main(){
    test_removeElementsGreaterThan();

    return 0;
}