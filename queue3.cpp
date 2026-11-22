#include <iostream>
#include <vector>
#include <queue>

int timeRequiredToBuy(std::vector<int>& tickets, int k){
std::queue<std::pair<int, int>> queue;
for(int i = 0; i < tickets.size(); i++){
    queue.push(std::make_pair(i, tickets[i]));
}
int seconds = 0;
while(! queue.empty()){
    auto current = queue.front();
    queue.pop();
    seconds++;
    current.second--;
    if (current.first == k && current.second == 0){
        return seconds;
    }
    if(current.second > 0){
        queue.push(current);
    }
    }
    return seconds;    /* code */
    
    
}
int main(){
std::vector<int> tickets1 = {2, 3, 2};
std::cout << timeRequiredToBuy(tickets1, 2) << '\n';
std::vector<int> tickets2 = {5, 1, 1, 1};
std::cout << timeRequiredToBuy(tickets2, 0) << '\n';
return 0;   
}
