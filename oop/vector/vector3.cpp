#include <iostream>
#include <vector>
    std::vector<int>  createVectorFromInput(){
    std:: vector<int> vec;
      
      int x;
      
      while(std:: cin >> x && x != 0){
          vec.push_back(x);
      }
      
      std:: cout << "SIZE = " << vec.size() << std:: endl << "CAPACITY = " << vec.capacity() << std :: endl;
      
      return vec;
  }
  
  int main (){
      
    std::vector<int> inputVec = createVectorFromInput();
    
    for(int i = 0; i < inputVec.size(); i++){
        std::cout << inputVec[i];
        
    }
    std::cout << std:: endl;
      return 0;
  }
