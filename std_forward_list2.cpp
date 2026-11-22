#include <iostream>
#include <forward_list>

bool insertAfterPosition(std::forward_list<int>& flist, int pos, int n){
if(pos < 0){
    return false;
}
auto it = flist.begin();
for(int i = 0; i < pos && it != flist.end(); i++){
++it;
}
if(it == flist.end()){
    return false;
}
flist.insert_after(it, n);
return true;
}
int main(){
std::forward_list<int> fl = {1, 2, 3, 4};
insertAfterPosition(fl, 1, 99);
for(int x : fl) std::cout << x << ' ';
std::cout << '\n';
return 0;
}
