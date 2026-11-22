#include <iostream>
#include <vector>
#include <string>
#include <queue>

std::string hotPotato(std::vector<std::string> players, int k){
std::queue<std::string> q;
for(std::string p : players){
q.push(p);
}
while(q.size() > 1){
for(int i = 0; i < k; i++){
std::string temp = q.front();
q.pop();
q.push(temp);
}  
q.pop();
}
return q.front();
}
int main(){
std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
std::cout << hotPotato(players, 7) << '\n';
return 0;   
}
