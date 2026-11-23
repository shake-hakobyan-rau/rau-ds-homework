#include <iostream>
#include <vector>
    std::vector<int> resizeVector(std::vector<int>& v, int newSize, int value = 0){
        
        std:: cout << "Befor vector" << std:: endl;
        
        for(int i =0; i < v.size(); i++){
            std:: cout << v[i];
        }
        
        std:: cout << std:: endl;
        
        v.resize(newSize, value);
        
        std:: cout << "After vector" << std:: endl;
        
        for(int i =0; i < v.size(); i++){
            std:: cout << v[i];
        }
        return v;
    }

int main()
{
    std::vector<int> v = {1, 2, 3};
    resizeVector(v, 5, 42);
    
    return 0;
}
