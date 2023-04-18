#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
/**
Given a non-negative integer c, decide whether there're two integers a and b 
such that a² + b² = c. 

 
 Example 1: 0

 
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
 

 Example 2: 

 
Input: c = 3
Output: false
 

 
 Constraints: 

 
 0 <= c <= 2³¹ - 1 
 

 Related Topics 数学 双指针 二分查找 👍 428 👎 0

*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        long long left = 0, right = ::sqrt(c);
        while (left <= right){
            if (left *left + right*right == c)
                return true;
            else if (left *left + right*right > c)
                --right;
            else
                ++left;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution solution;
    
    return 0;
}