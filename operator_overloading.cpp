#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct DATA {
    string key;
    int data;
    // EITHER THIS
    bool operator < (const DATA & d2) const {return true;}

};

// OR THIS


int main() {
    std::priority_queue<DATA> priorityQ;
    DATA newItem;
    newItem.key = "apples";
    newItem.data = 3;
    priorityQ.push(newItem);
    std::cout << priorityQ.top().key << std::endl;

    std::cout << "Press the 'ENTER' key to continue...";
    std::cin.get();

    return 0;
}
