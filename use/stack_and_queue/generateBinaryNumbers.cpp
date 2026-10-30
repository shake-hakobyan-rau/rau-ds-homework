#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cassert>

std::vector<std::string> generateBinaryNumbers(int n) {
    std::queue<std::string> q;
    std::vector<std::string> result;
    if (n <= 0) {
        return result;
    }
    q.push("1");
    for (int i = 0; i < n; i++) {
        std::string s = q.front();
        q.pop();
        result.push_back(s);
        q.push(s + "0");
        q.push(s + "1");
    }
    return result;
}

void test() {
    assert(generateBinaryNumbers(1) == std::vector<std::string>({"1"}));
    assert(generateBinaryNumbers(3) == std::vector<std::string>({"1", "10", "11"}));
    assert(generateBinaryNumbers(5) == std::vector<std::string>({"1", "10", "11", "100", "101"}));
    assert(generateBinaryNumbers(0).empty());
}

int main() {
    test();
    std::cout << "passed";
}
