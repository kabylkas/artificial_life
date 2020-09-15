#include <iostream>
#include <utility>
#include <tuple>

int main() {
  std::pair<uint32_t, uint32_t> p = std::make_pair(2, 3);
  auto [x, y] = p;
  std::cout << x << " " << y << '\n';

  auto a = std::make_tuple(__FUNCTION__, __FILE__);
  return 0;
}
