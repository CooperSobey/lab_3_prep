#include <iostream>
#include <ostream>

#include "UniquePtr.h"

void testEqual() {
    UniquePtr<int> ptr1(new int(7));

    if (ptr1 != nullptr) {
        std::cout << "Test ptr1 not null pass" << std::endl;
    }
}

struct TestArrow {
    void testArrow() {
        std::cout << "Test arrow pass" << std::endl;
    }
};

int main() {
    // UniquePtr<int> ptr(new int(5));
    // they test all methods here...
    UniquePtr<int> ptr(new int(5));
    std::cout << "Test .get " << ptr.get() << std::endl;
    std::cout << "Test * op "<< *ptr << std::endl;
    testEqual();

    ptr.reset();
    if (ptr == nullptr) {
        std::cout << "Test ptr reset pass" << std::endl;
    }

    UniquePtr<TestArrow> ptr2(new TestArrow());
    ptr2->testArrow();

    return 0;
}
