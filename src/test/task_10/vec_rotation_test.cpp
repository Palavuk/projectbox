#include <array>

#include <gtest/gtest.h>

#include <project/task_10/vec_rotation.h>

std::pair<bool, std::array<float, 2>> result(int angle,std::array<float, 2>& vec){
    bool err = rotation(angle, vec);
    return {err, vec};
}

TEST(result, correctness){
    std::array<float, 2> vector {10, 10};
	std::pair<bool, std::array<float, 2>> res (true, vector);
	EXPECT_EQ(res, result(360, vector));
       	EXPECT_EQ(res, result(-360, vector));
       	EXPECT_EQ(res, result(720, vector));
	EXPECT_EQ(res, result(0, vector));

	res = {false, vector};
    EXPECT_EQ(res, result(350, vector));

    res = {true, {-vector[0], vector[1]}};
    EXPECT_EQ(res, result(90, vector));
    
    res = {true, {vector[0], -vector[1]}};
    EXPECT_EQ(res, result(270, vector));

    res = {true, {-vector[0], -vector[1]}};
    EXPECT_EQ(res, result(180, vector));
}
