#include <gtest/gtest.h>
#include "minsum.cpp"

// Test fixture for Solution class
class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

// Test case for a basic scenario where a valid triplet exists.
TEST_F(SolutionTest, BasicCase) {
    vector<int> nums = {8, 6, 1, 5, 3};
    EXPECT_EQ(sol.minimumSum(nums), 9); // Triplet (1, 5, 3) -> sum = 9
}

// Test case where multiple valid triplets exist.
TEST_F(SolutionTest, MultipleTriplets) {
    vector<int> nums = {5, 4, 8, 2, 7, 1, 6};
    // Possible triplets:
    // (4, 8, 2) -> sum 14
    // (4, 8, 1) -> sum 13
    // (2, 7, 1) -> sum 10
    // (4, 7, 1) -> sum 12
    // (1, 6, ?) -> no right element
    // The minimum sum is from (2, 7, 1) which is 10.
    EXPECT_EQ(sol.minimumSum(nums), 10);
}

// Test case for an array with less than 3 elements.
TEST_F(SolutionTest, LessThanThreeElements) {
    vector<int> nums = {1, 2};
    EXPECT_EQ(sol.minimumSum(nums), -1);
}

// Test case for an array with exactly 3 elements forming a valid triplet.
TEST_F(SolutionTest, ThreeElementsValid) {
    vector<int> nums = {1, 3, 2};
    EXPECT_EQ(sol.minimumSum(nums), 6);
}

// Test case for an array with exactly 3 elements not forming a valid triplet.
TEST_F(SolutionTest, ThreeElementsInvalid) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(sol.minimumSum(nums), -1);
}

// Test case for a sorted array where no valid triplet can be formed.
TEST_F(SolutionTest, SortedArray) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.minimumSum(nums), -1);
}

// Test case for a reverse-sorted array where no valid triplet can be formed.
TEST_F(SolutionTest, ReverseSortedArray) {
    vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(sol.minimumSum(nums), -1);
}

// Test case with duplicate numbers.
TEST_F(SolutionTest, WithDuplicates) {
    vector<int> nums = {6, 5, 4, 3, 4, 5};
    // Triplet (3, 4, ?) -> no right element smaller than 4
    // Triplet (3, 5, ?) -> no right element smaller than 5
    EXPECT_EQ(sol.minimumSum(nums), -1);
}

TEST_F(SolutionTest, WithDuplicatesValid) {
    vector<int> nums = {1, 1, 3, 1};
    EXPECT_EQ(sol.minimumSum(nums), 5); // Triplet (1, 3, 1)
}