#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include <project/task_3/Source.h>

std::string result(std::string format)
{
	std::stringstream stream;
	message(stream, format.c_str());
	return stream.str();
}

template <class ... Args>
std::string result(std::string format, Args ... args)
{
	std::stringstream stream;
	message(stream, format.c_str(), args...);
	return stream.str();
};

TEST(variadic, correctness)
{
	EXPECT_EQ("a + 2 = 3 b c 10", result("% + % = % % % %", 'a', 2, 3.0, 'b', 'c', 10.0));
	EXPECT_EQ("% + % = %", result("% + % = %"));
	EXPECT_EQ("a + 2 = 3", result("% + % = %", 'a', 2, 3.0, 1, "abcdef", 156));
	EXPECT_EQ("% and %", result("%", "% and %", 1, 2));
	EXPECT_EQ("1 2 3 4 5 6 7 8 9 10", result("% % % % % % % % % %", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12));
	EXPECT_EQ("1 2 3 4 5 6", result("1 2 3 4 % %", 5, 6));
	EXPECT_EQ("", result(""));
	EXPECT_EQ("a 5 a", result("a % a", 5));

	std::array<int, 3> t1_i3_0{ 1, 2, 3 }, t1_i3_1{ 4, 5, 6 };
	std::array<int, 6> e1_i6{ 1, 2 ,3 ,4 ,5 ,6 };
	EXPECT_EQ(e1_i6, cat(t1_i3_0, t1_i3_1));

	std::array<int, 2> t2_i2_0{ 1, 2 }, t2_i2_1{ 3, 4 }, t2_i2_2{ 5, 6 };
	std::array<int, 6> e2_i6{ 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(e2_i6, cat(t2_i2_0, t2_i2_1, t2_i2_2));

	std::array<int, 1> t3_i1_0{ 1 },
		t3_i1_1{ 2 },
		t3_i1_2{ 3 },
		t3_i1_3{ 4 },
		t3_i1_4{ 5 },
		t3_i1_5{ 6 };
	std::array<int, 6> e3_i6{ 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(e3_i6, cat(t3_i1_0, t3_i1_1, t3_i1_2, t3_i1_3, t3_i1_4, t3_i1_5));

	t1_i3_0 = { 1, 2, 3 }; t1_i3_1 = { 4, 5, 6 };
	std::array<int, 3> e1_i3_0{ 11, 22, 33 }, e1_i3_1{ 44, 55, 66 };
	std::array<int, 6> t1_i6{ 11, 22 ,33 ,44 ,55 ,66 };
	uncat(t1_i3_0, t1_i3_1) = t1_i6;
	EXPECT_TRUE(t1_i3_0 == e1_i3_0 && t1_i3_1 == e1_i3_1);


	EXPECT_NO_THROW({ uncat(t1_i3_0, t1_i3_1); });

	EXPECT_NO_THROW({ uncat(t1_i3_0, t1_i3_1, t1_i3_0, t1_i3_1); });
}
