#include <iostream>
#include <vector> 
#include <queue>
#include <string> 
std:: vector<std::string> generateBinaryNumbers(int N){
    std::vector<std::string> result;
    std::queue<std::string> q;
    
    q.push("1");
    for(int i = 0; i < N; i++){
        std::string num = q.front();
        q.pop();
        
        result.push_back(num);
        q.push(num + "0");
        q.push(num + "1");
    }
    return result;
}

int main()
{
auto result = generateBinaryNumbers(5);
for(int i = 0; i < result.size(); i++){
    std:: cout << result[i] << " ";
}
 std::cout << std::endl;
 
    return 0;
}
