#include <iostream>
template <typename T>
class Range{
    T start;
    T end;
  public:
  Range(T start_, T end_) : start(start_), end(end_) {}
  
  bool contains(const T& value){
      if(value >= start && value <= end){
          return true;
      }
      return false;
  }
  
  T length(){
      return end - start;
  }
  
  void print(){
      std:: cout << "Begin = " << start << std:: endl << "Finish = " << end << std:: endl;
  }
};
int main()
{
Range <int> intRange(3, 10);
intRange.print();
std :: cout << "Length = " << intRange.length() << std:: endl;
std:: cout << (intRange.contains(5) ? "yes" : "No") << std:: endl;

Range <double> doubleRange(3.14, 12.50);
doubleRange.print();
std :: cout << "Length = " << doubleRange.length() << std:: endl;
std:: cout << (doubleRange.contains(12.51) ? "yes" : "No") << std:: endl;

Range <char> charRange('a', 'f');
charRange.print();
std :: cout << "Length = " << (int)charRange.length() << std:: endl;
std:: cout << (charRange.contains('d') ? "yes" : "No") << std:: endl;
    return 0;
}
