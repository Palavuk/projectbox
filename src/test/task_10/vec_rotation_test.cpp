#include <array>

#include <gtest/gtest.h>

#include <project/task_10/vec_rotation.h>

std::pair<bool, std::array<float, 2>> result(int angle,std::array<float, 2>& vec){
    bool err = rotation(angle, vec);
    return {err, vec};
}

TEST(result, correctness){
    EXCEPT_EQ({true, {10, 10}}, result(360, {10, 10}));
}