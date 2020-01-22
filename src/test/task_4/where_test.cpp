#include <gtest/gtest.h>

#include <project/task_4/matrix.h>

struct where_test_param
{
	matrix<bool> bool_mask;
	matrix<float> input_true;
	matrix<float> input_false;
	matrix<float> output;
};

class where_test : public ::testing::TestWithParam<where_test_param> {};

TEST_P(where_test, _)
{
	const where_test_param& param = GetParam();
	
	matrix<float> output = where(param.bool_mask, param.input_true, param.input_false);

	EXPECT_EQ(param.output, output);
		
}

INSTANTIATE_TEST_CASE_P(
	_,
	where_test,
	::testing::Values(
		where_test_param{
			matrix<bool>(std::vector<bool>({1, 0, 0, 0, 0, 0}), 2, 3),
			matrix<float>(std::vector<float>({1, 2, 3, 4, 5, 6}), 2, 3),
			matrix<float>(std::vector<float>({11, 22, 33, 44, 55, 66}), 2, 3),
			matrix<float>(std::vector<float>({1, 22, 33, 44, 55, 66}), 2, 3)
		}
	)
);
