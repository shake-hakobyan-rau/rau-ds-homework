#include <iostream>
#include <vector>
    int removeElementsGreaterThan(std::vector<int>& v, int value = 0){
        int removeCounter = 0;
        for(int i = v.size(); i >= 0; i--){
            if(v[i] > value){
                v.pop_back();
                removeCounter++;
            }
        }
        
        std:: cout << "Counter = " << removeCounter << std::endl;
        
        for(int i = 0; i < v.size(); i++){
            std:: cout << v[i];
        }
        return removeCounter;
    }

int main()
{
    std::vector<int> v = {1, 3, 5, 7, 9};
    int removed = removeElementsGreaterThan(v, 5);
    
    return 0;
}
