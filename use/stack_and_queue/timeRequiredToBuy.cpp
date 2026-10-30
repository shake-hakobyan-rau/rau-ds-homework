#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cassert>

int timeRequiredToBuy(const std::vector<int>& tickets, int k) {
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < tickets.size(); i++) {
        q.push({i, tickets[i]});
    }
    int time = 0;
    while (!q.empty()) {
        int index = q.front().first;
        int count = q.front().second;
        q.pop();
        count--;
        time++;
        if (count == 0 && index == k) {
            return time;
        }
        if (count > 0) {
            q.push({index, count});
        }
    }
    return time;
}

void test() {
    assert(timeRequiredToBuy({2, 3, 2}, 2) == 6);
    assert(timeRequiredToBuy({5, 1, 1, 1}, 0) == 8);
    assert(timeRequiredToBuy({1}, 0) == 1);
    assert(timeRequiredToBuy({1, 1, 1}, 1) == 2);
}

int main() {
    test();
    std::cout << "passed";
}
