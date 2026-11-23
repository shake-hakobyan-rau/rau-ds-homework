#include <iostream>
#include <vector>
  void workWithEmptyVector(){
      std:: vector<int> vec;
      
      for(int i = 0; i <= 10; i++){
          vec.push_back(i);
          
          std:: cout << "Element = " << vec[i] 
          << std:: endl << "Size = " << vec.size() << std:: endl << "Capacity = " << vec.capacity() << std:: endl;
      }
      
      for(int i = 0; i <= 10; i++){
          std:: cout << vec[i];
      }
      
  }
int main()
{
workWithEmptyVector();
    return 0;
}
