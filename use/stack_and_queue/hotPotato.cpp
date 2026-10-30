#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cassert>

std::string hotPotato(const std::vector<std::string>& players, int k) {
    std::queue<std::string> q;
    for (int i = 0; i < players.size(); i++) {
        q.push(players[i]);
    }
    while (q.size() > 1) {
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

void test() {
    assert(hotPotato({"Alice", "Bob", "Charlie", "David"}, 7) == "Alice");
    assert(hotPotato({"Alice", "Bob", "Charlie"}, 0) == "Charlie");
    assert(hotPotato({"Alice"}, 5) == "Alice");
    assert(hotPotato({"Alice", "Bob"}, 1) == "Alice");
}

int main() {
    test();
    std::cout << "passed";
}
