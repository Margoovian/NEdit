#pragma once 

#include <concepts>

template <typename From, typename To>
concept convertible_to = std::is_convertible_v<From, To>;