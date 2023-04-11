/**
Given a positive integer num, return true if num is a perfect square or false 
otherwise. 

 A perfect square is an integer that is the square of an integer. In other 
words, it is the product of some integer with itself. 

 You must not use any built-in library function, such as sqrt. 

 
 Example 1: 

 
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
 

 Example 2: 

 
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an 
integer.
 

 
 Constraints: 

 
 1 <= num <= 2³¹ - 1 
 

 Related Topics 数学 二分查找 👍 480 👎 0

*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long) mid * mid == num) {
                return true;
            } else if ((long long) mid * mid < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    std::cout << solution.isPerfectSquare(7);
    return 0;
}
