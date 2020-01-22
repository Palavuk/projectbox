#include <gtest/gtest.h>

#include <project/task_4/matrix.h>

struct where_test_param
{
	Matrix<bool> bool_mask;
	Matrix<float> input_true;
	Matrix<float> input_false;
	Matrix<float> output;
};

class where_test : public ::testing::TestWithParam<where_test_param> {};

TEST_P(where_test, _)
{
	const where_test_param& param = GetParam();
	
	Matrix<float> output = where(param.bool_mask, param.input_true, param.input_false);

	EXPECT_EQ(param.output, output);
		
}

INSTANTIATE_TEST_CASE_P(
	_,
	where_test,
	::testing::Values(
		where_test_param{
			Matrix<bool>(std::vector<bool>({1, 0, 0, 0, 0, 0}), 2, 3),
			Matrix<float>(std::vector<float>({1, 2, 3, 4, 5, 6}), 2, 3),
			Matrix<float>(std::vector<float>({11, 22, 33, 44, 55, 66}), 2, 3),
			Matrix<float>(std::vector<float>({1, 22, 33, 44, 55, 66}), 2, 3)
		}
	)
);
