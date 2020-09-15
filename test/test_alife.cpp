#include "test_world.h"
#include "test_runner.h"
#include <exception>

int main() {
  test_runner tw;

  // Testing world
  {
    const uint32_t w = 10u;
    const uint32_t h = 10u;
    const bool allow = false;
    World<w, h, allow> world_under_test;
    tw.run_test(test_world_wrap_x<w, h, allow>, &world_under_test);
  }
  return 0;
}
