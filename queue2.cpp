#include <iostream>
#include <vector>
#include <string>
#include <queue>

std::vector<std::string> generateBinaryNumbers(int n){
std::vector<std::string> result;
if(n <= 0)
    return result;
    std::queue<std::string> q;
    q.push("1");
    for(int i = 1; i <= n; i++){
        std::string current = q.front();
        q.pop();
        result.push_back(current);
        q.push(current + "0");
        q.push(current + "1");
         
    }
return result;
}

int main(){
auto result = generateBinaryNumbers(5);
std::cout << "{";
for(const auto& num : result){

    std::cout << num << ", ";
}
std::cout << "}" << std::endl;

return 0;
}
