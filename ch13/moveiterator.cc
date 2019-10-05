
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>


void test() {
    std::vector<int> vec1{1, 3, 5, 7, 9, 0, 8, 4, 6, 2};
    std::allocator<int> alloc;
    auto p = alloc.allocate(vec1.size());
    std::uninitialized_copy(std::make_move_iterator(vec1.begin()), std::make_move_iterator(vec1.end()), p);
    alloc.deallocate(p, vec1.size());
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
