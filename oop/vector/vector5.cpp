#include <iostream>
  #include <vector>
   void manageCapacity(std::vector<int>& v){
       
      std:: cout << "SIZE = " << v.size() << std::endl << "CAPACITY = " << v.capacity() << std::endl;
       
       v.reserve(v.size() + 500);
       
       for(int i = 1; i <= 500 ; i++){
           v.push_back(i);
       }
       
       std:: cout << "Size = " << v.size() << std::endl << "Capacity = " << v.capacity() <<std:: endl;
   } 
  
  int main (){
     std::vector<int> v;
     
     v.push_back(10);
     v.push_back(30);
     
     for(int i = 0; i < v.size() ; i++){
           std:: cout << v[i];
       }
      std::cout << std:: endl;
      
      manageCapacity(v);
      
    return 0;
      
  }
