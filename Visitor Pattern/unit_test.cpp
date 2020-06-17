#include "gtest/gtest.h"


#include "visit_test.hpp"
#include "Test.hpp"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
