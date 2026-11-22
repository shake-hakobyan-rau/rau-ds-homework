#include <iostream>
#include <forward_list>

int removeAllOccurrences(std::forward_list<int>& flist, int n){
int c = 0;
auto prev = flist.before_begin();
auto cur = flist.begin();
while(cur != flist.end()){
if(*cur == n){
cur = flist.erase_after(prev);
c++;     
}
else{
prev = cur;
++cur;
}    
    
}
return c;
}
int main(){
std::forward_list<int> fl = {1, 2, 3, 2, 4, 2};
int removed = removeAllOccurrences(fl, 2);
for(int x : fl) std::cout << x << ' ';
std::cout << "\nremoved: " << removed << '\n';
return 0;
}
