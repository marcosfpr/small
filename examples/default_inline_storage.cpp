#include <iostream>
#include <small/vector.h>

// A relocatable custom type whose default inline storage should be at least 10 elements
struct my_type {
    int a;
    double b;
};

namespace small {
    template <> struct is_relocatable<my_type> : std::true_type {};
    template <> struct default_inline_storage<my_type> : std::integral_constant<size_t, 10> {};
} // namespace small

int main() {
    // Inline storage for at least 5 elements
    small::vector<my_type, 5> v1 = {{1, 1.1}, {2, 2.2}, {3, 3.3}, {4, 4.4}, {5, 5.5}};
    for (const auto &x : v1) {
        std::cout << '<' << x.a << ',' << x.b << '>' << ' ';
    }
    std::cout << "\n";

    // Default inline storage for at least 10 elements
    small::vector<my_type> v2 = {{1, 1.1}, {2, 2.2}, {3, 3.3}, {4, 4.4}, {5, 5.5}};
    for (const auto &x : v2) {
        std::cout << '<' << x.a << ',' << x.b << '>' << ' ';
    }
    std::cout << "\n";

    return 0;
}