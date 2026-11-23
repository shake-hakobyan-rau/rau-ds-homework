#include <iostream>
#include <vector> 
#include <queue>
int timeRequiredToBuy(const std::vector<int>& tickets, int k){
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < tickets.size(); i++){
        q.push({i, tickets[i]});
    }
    int time = 0;
    
    while(true){
        std::pair<int, int> num = q.front();
        q.pop();
        
        int Index = num.first;
        int remain = num.second;
        time++;
        remain--;
        
        if(Index == k && remain == 0){
            return time;
        }
        if(remain > 0){
            q.push({Index, remain});
        }
    }
}

int main()
{
std::vector<int> tickets1 = {2, 3, 2};
std::cout << timeRequiredToBuy(tickets1, 2) << '\n'; 

std::vector<int> tickets2 = {5, 1, 1, 1};
std::cout << timeRequiredToBuy(tickets2, 0) << '\n';  

return 0;
}
