#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTestSuite, TestOnePlusOneShouldEqualTwo) {
  EXPECT_EQ(2, calculator::add(1, 1));
}

TEST(CalculatorTestSuite, TestOnePlusTwoShouldEqualThree) {
  EXPECT_EQ(3, calculator::add(1, 2));
}
