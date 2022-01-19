#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> queue;
    bool flag = false;
    std::string input;
    std::map<std::string, int>::iterator next;
    while (!flag) {
        std::cout << "Input name or instruction (exit, next): ";
        std::cin >> input;
        if (input == "exit") flag = true;
        else if (input == "next") {
            if (queue.size() == 0) return 1;
            next = queue.begin();
            std::cout << "-> " << next->first << std::endl;
            --next->second;
            if (next->second == 0) queue.erase(next);
        }
        else {
            std::map<std::string, int>::iterator result = queue.find(input);
            if (result == queue.end()) queue.insert(std::pair<std::string, int>(input, 1));
            else ++result->second;
        }
    }
    return 0;
}