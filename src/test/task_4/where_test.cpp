#include <gtest/gtest.h>

#include <project/task_4/matrix.h>

struct where_param{
	matrix<float> a;
	matrix<float> b;
	matrix<float> expected_output;
};

class where_test: public ::testing::TestWithParam<where_param> {};

TEST_P(where_test, _){
    const where_param& param = GetParam();
    matrix<float> output = where(param.a < param.b, param.a, param.b);
    EXPECT_EQ(param.expected_output, output);
};

INSTANTIATE_TEST_CASE_P(
    _,
    where_test,
    ::testing::Values(
        where_param{
            matrix<float>({1,1,1,1,1,1}, 2, 3);
            matrix<float>({0,0,0,0,0,0}, 2, 3);
            matrix<float>({0,0,0,0,0,0}, 2, 3);
        },
        where_param{
            matrix<float>({1,0,1,1,1,1}, 2, 3);
            matrix<float>({0,1,1,0,0,0}, 2, 3);
            matrix<float>({0,0,1,0,0,0}, 2, 3);
        }
    )
);
