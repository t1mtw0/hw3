#include "heap.h"
#include <iostream>

int main() {
    Heap<int> h{2};

    std::cout << std::boolalpha << h.empty()  << std::endl;

    h.push(7);
    h.push(6);

    std::cout << h.top() << std::endl;
    
    h.push(5);
    h.push(4);
    h.push(3);
    h.push(2);
    h.push(1);

    std::cout << h.top() << std::endl;
    std::cout << h.size() << std::endl;
    std::cout << std::boolalpha << h.empty()  << std::endl;

    h.pop();

    std::cout << h.top() << std::endl;
    std::cout << h.size() << std::endl;

    h.pop();

    std::cout << h.top() << std::endl;
    std::cout << h.size() << std::endl;
}