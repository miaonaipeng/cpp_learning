/**
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the 
intervals non-overlapping. 

 
 Example 1: 

 
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-
overlapping.
 

 Example 2: 

 
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-
overlapping.
 

 Example 3: 

 
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're 
already non-overlapping.
 

 
 Constraints: 

 
 1 <= intervals.length <= 10⁵ 
 intervals[i].length == 2 
 -5 * 10⁴ <= starti < endi <= 5 * 10⁴ 
 

 Related Topics 贪心 数组 动态规划 排序 👍 940 👎 0

*/
#include "algorithm"
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty())
            return 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int removed = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                // 如果当前区间和前一个区间重叠。
                ++removed;
            } else {
                prev = intervals[i][1];
            }
        }
        return removed;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    return 0;
}