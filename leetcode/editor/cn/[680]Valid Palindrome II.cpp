#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
/**
Given a string s, return true if the s can be palindrome after deleting at most 
one character from it. 

 
 Example 1: 

 
Input: s = "aba"
Output: true
 

 Example 2: 

 
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
 

 Example 3: 

 
Input: s = "abc"
Output: false
 

 
 Constraints: 

 
 1 <= s.length <= 10⁵ 
 s consists of lowercase English letters. 
 

 Related Topics 贪心 双指针 字符串 👍 575 👎 0

*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validPalindrome(std::string s) {
        int left = 0, right = s.length() - 1;

        // 用双指针从字符串两端向中间遍历
        while (left < right) {
            // 如果对应字符不相等，尝试删除左侧字符或右侧字符
            if (s[left] != s[right]) {
                // 检查删除左侧字符后，剩余子串是否为回文字符串
                bool left_valid = isPalindrome(s, left + 1, right);
                // 检查删除右侧字符后，剩余子串是否为回文字符串
                bool right_valid = isPalindrome(s, left, right - 1);

                // 如果删除左侧字符或右侧字符后的子串是回文字符串，返回true
                return left_valid || right_valid;
            }

            // 将左右指针向中间移动
            left++;
            right--;
        }

        // 如果遍历完整个字符串，返回true
        return true;
    }

private:
    // 辅助函数：检查字符串s的子串是否为回文字符串
    static bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    string s = "cbbcc";
    solution.validPalindrome(s);
    return 0;
}