#include <iostream>
#include <forward_list>

void creatAndFillist(int n){
std::forward_list<int> flist;
for(int i = 1; i <= n; i++){
flist.push_front(i);    
}
for(int x : flist){
    std::cout << x << ' ';
}  
    std::cout << '\n';
}
int main(){
creatAndFillist(5);
return 0;    
}
