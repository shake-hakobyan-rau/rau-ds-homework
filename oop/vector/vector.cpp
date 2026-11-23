#include <iostream>
#include <vector>
void createFillvector(int N){
   std:: vector<int> v(N);            
    
    for(int i = 0; i < N; i++){
        v[i] = i + 1;              
    }
    
    for(int i = 0; i < N; i++){
        std::cout << v[i];              
    }
    
   std:: cout << std:: endl;
    
    std::cout << v.size() << std:: endl << v.capacity() << std::  endl;       
    
}
int main()
{
 createFillvector(5);
    return 0;
}
