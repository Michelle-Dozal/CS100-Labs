#include "gtest/gtest.h"

#include "op_test.hpp"

#include "rand_test.hpp"
#include "mult_test.hpp"
#include "pow_test.hpp"

#include "Sub_test.hpp"
#include "Add_test.hpp"
#include "Div_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
