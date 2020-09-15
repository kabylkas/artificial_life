#pragma once
#include "World.h"
#include <exception>
#include <sstream>

#define SPOT() (std::make_tuple(__FUNCTION__,__FILE__,__LINE__))

template <typename T1, typename T2, typename T3>
static void A(const T1& a, const T2& b, const T3& message) {
  if (a != b) {
    std::stringstream ss;
    auto [func, file, line] = message;
    ss << "[" << a << " != " << b << "] (" << func << ", " << file << ", " << line << '\n';
    throw std::runtime_error(ss.str());
  }
}

template <uint32_t W, uint32_t H, bool ALLOW_SHARE>
static void test_world_wrap_x(World<W, H, ALLOW_SHARE>* w) {
  {
    uint32_t x = w->wrap_x(10+2);
    uint32_t expected_x = 2;
    A(x, expected_x, SPOT());
  }

  {
    uint32_t x = w->wrap_x(10-2);
    uint32_t expected_x = 8;
    A(x, expected_x, SPOT());
  }

  {
    uint32_t x = w->wrap_x(0-1);
    uint32_t expected_x = 9;
    A(x, expected_x, SPOT());
  }

  {
    uint32_t x = w->wrap_x(0-3);
    uint32_t expected_x = 7;
    A(x, expected_x, SPOT());
  }
}
