/**
 * Mozart++ Template Library
 * Licensed under MIT License
 * Copyright (c) 2020 Covariant Institute
 * Website: https://covariant.cn/
 * Github:  https://github.com/covariant-institute/
 */

#include <mozart++/core>
#include <cstdio>

#include <vector>
#include <list>
#include <deque>
#include <unordered_map>

int main() {
    using namespace mpp;
    static_assert(is_iterable_v<std::vector<int>>, "You wrote a bug");
    static_assert(is_iterable_v<std::vector<std::vector<int>>>, "You wrote a bug");
    static_assert(is_iterable_v<std::string>, "You wrote a bug");
    static_assert(!is_iterable_v<int>, "You wrote a bug");
    static_assert(!is_iterable_v<mpp::function<void()>>, "You wrote a bug");
    static_assert(!is_iterable_v<mpp::function<const char *()>>, "You wrote a bug");
    static_assert(!is_iterable_v<mpp::function<const char *()>>, "You wrote a bug");
}
