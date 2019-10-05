#include <string>
#include <iostream>
#include <algorithm>

struct X {
    int i;
    std::string s;
};

struct hasX {
    X mem;
};

void test() {
    X x, x2 = std::move(x);
    hasX hx, hx2 = std::move(hx);
}

#include <chrono>
int main() {
    using namespace std::chrono;
    auto beg = system_clock::now();

    test();

    auto end = system_clock::now();
    std::cout << "time: " << duration_cast<milliseconds> (end - beg).count() << " .ms" << std::endl;
    return 0;
}
