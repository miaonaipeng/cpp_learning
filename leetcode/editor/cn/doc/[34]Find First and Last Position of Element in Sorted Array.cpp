//Given an array of integers nums sorted in non-decreasing order, find the
//starting and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// You must write an algorithm with O(log n) runtime complexity.
//
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//
// Example 3:
// Input: nums = [], target = 0
//Output: [-1,-1]
//
//
// Constraints:
//
//
// 0 <= nums.length <= 10⁵
// -10⁹ <= nums[i] <= 10⁹
// nums is a non-decreasing array.
// -10⁹ <= target <= 10⁹
//
//
// Related Topics 数组 二分查找 👍 2226 👎 0


#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int len = nums.size();
        if (len == 0) {
            vector<int> v = {-1, -1};
            return v;
        }
        int firstPosition = findFirstPosition(nums, target);
        if (firstPosition == -1) {
            vector<int> v = {-1, -1};
            return v;
        }
        int lastPosition = findLastPosition(nums, target);
        vector<int> v = {firstPosition, lastPosition};
        return v;
    }

private:
    int findLastPosition(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }


        return -1;
    }
    int findFirstPosition(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid;
            }// nums[mid + 1]不是target出现的第一个位置
            else {
                right = mid - 1;
            }


            return left;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {5, 7, 7, 8, 8, 10};
    solution.searchRange(v, 8);
    return 0;
}
