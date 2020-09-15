#pragma once
#include <exception>

class test_runner {
  private:
    uint32_t fail_count;

  public:
    test_runner() {
      this->fail_count = 0;
    }

    ~test_runner() {
      if (this->fail_count > 0) {
        std::cerr << "FAIL: " << this->fail_count << " failed the test." << '\n';
        exit(1);
      }
    }

    template <typename F, typename T>
    void run_test(F test_function, T* obj) {
      try {
        test_function(obj);
        std::cerr << "Success." << '\n';
      } catch (std::exception& e) {
        std::cerr << "Failed. Error: " << e.what() << '\n';
        this->fail_count++;
      }
    }
};
