#include <array>

#include <gtest/gtest.h>

#include <project/task_10/vec_rotation.h>

std::pair<bool, std::array<float, 2>> result(int angle,std::array<float, 2>& vec){
    bool err = rotation(angle, vec);
    return {err, vec};
}

TEST(result, correctness){
	std::array<float, 2> vector {10, 10};
	std::pair<bool, std::array<float, 2>> res1 (true, vector);
	EXPECT_EQ(res1, result(360, vector));
}
