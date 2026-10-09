#include <iostream>
#include <string>
#include <vector>
template <typename T>
T linearSearch(std:: vector<T>& v, const T& value){
    for (int i = 0; i < v.size(); i++){
        if(v[i] == value){
            return i;
        }
    }
    return -1;
}
int main()
{
    std:: vector<int> vec1 = {10, 20, 30, 40, 50};
    std::cout << linearSearch(vec1, 30) << std :: endl;
    
    std:: vector<double> vec2 = {1.1, 3.3, 6.6, 5.5};
    std:: cout << linearSearch(vec2, 5.5) << std:: endl;

    return 0;
}
