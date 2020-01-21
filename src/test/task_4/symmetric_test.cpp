#include <gtest/gtest.h>

#include <task_4/matrix.h>

struct symmetric_param{
	matrix<float> input;
	bool expected_output;
};

class symmetric_test: public ::testing::TestWithParam<symmetric_param> {};

TEST_P(symmetric_test, _){
    const symmetric_param& param = GetParam();
    bool output = param.input.is_symmetric();
    EXPECT_EQ(param.expected_output, output);
};

INSTANTIATE_TEST_CASE_P(
    _,
    symmetric_test,
    ::testing::Values(
        symmetric_param{
            matrix<float>({1,1,1,1}, 2, 2);
            bool true;
        }
    )
);