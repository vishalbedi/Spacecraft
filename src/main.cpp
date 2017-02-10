// C++14 example program

#include <iostream>

using std::cout;
using std::endl;

int main() {
    auto lambda = [](auto x, auto y) { return x + y; };
    cout << lambda(3, 4) << endl;
    return 0;
}
