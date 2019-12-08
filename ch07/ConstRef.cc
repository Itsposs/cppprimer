#include <chrono>
#include <iostream>

class ConstRef {
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

//ConstRef::ConstRef(int ii) {
//    i = ii;
//    ci = ii;
//    ri = i;
//}

ConstRef::ConstRef(int ii)
    : i(ii), ci(ii), ri(i) { }

void test() {

}

int main() {
    using namespace std::chrono;
    auto beg = system_clock::now();

    test();

    auto end = system_clock::now();
    std::cout << "time: " << duration_cast<milliseconds> (end - beg).count() << "ms." << std::endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
