//
// Created by Alan Freitas on 9/7/21.
//

#ifndef SMALL_STACK_H
#define SMALL_STACK_H

#include "vector.h"
#include <stack>

namespace small {
    template <class T, size_t N = default_inline_storage_v<T>, class Container = small::vector<T, N>>
    using stack = std::stack<T, Container>;
}

#endif // SMALL_STACK_H