#include<iostream>
#include<algorithm>
#include<string>
#include "unordered_map"

using namespace std;
/**
Given two strings s and t of lengths m and n respectively, return the minimum 
window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "". 


 The testcases will be generated such that the answer is unique. 

 
 Example 1: 

 
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' 
from string t.
 

 Example 2: 

 
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
 

 Example 3: 

 
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

 
 Constraints: 

 
 m == s.length 
 n == t.length 
 1 <= m, n <= 10⁵ 
 s and t consist of uppercase and lowercase English letters. 
 

 
 Follow up: Could you find an algorithm that runs in O(m + n) time? 

 Related Topics 哈希表 字符串 滑动窗口 👍 2459 👎 0

*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        unordered_map<char, int> needs;
        for (char c: t) {
            needs[c]++;
        }

        unordered_map<char,int> window;
        int left = 0, right = 0;
        int min_len = s.size() + 1;
        string res = "";

        // 遍历s
        while(right < s.length()){
            char c_right = s[right];
            window[c_right]++;

            while (isContained(window, needs)){
                if (right - left + 1 < min_len){
                    min_len = right- left + 1;
                    res = s.substr(left, min_len);
                }

                // 尝试缩小窗口
                char c_left = s[left];
                ++left;
            }
            ++right;

        }

        return res;
    }

private:
    bool isContained(unordered_map<char, int>& window, unordered_map<char, int>& needs){
        for(const auto& kv : needs){
            if(window[kv.first] < kv.second){
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    return 0;
}

/*
 *
 * 字符计数：为了判断窗口内是否包含目标字符串 t 的所有字符，我们需要一个哈希表来存储 t 中每个字符的数量。这里我们使用unordered_map<char, int>来存储 t 中字符及其数量。同时，我们也需要一个哈希表来存储当前窗口中每个字符的数量。

窗口扩大：我们用两个指针，left 和 right，表示窗口的左右边界。初始时，left 和 right 都指向 0。我们不断地将 right 指向的字符加入到 window 中，然后将 right 向右移动。

窗口缩小：当窗口中包含 t 的所有字符时，我们尝试缩小窗口。即移动 left 指针，将窗口左边的字符排除，同时减少 window 中相应字符的计数。

更新结果：在每次缩小窗口时，我们需要判断当前窗口的长度是否小于之前的最小窗口长度。如果是，则更新结果字符串 res。

重复步骤2-4，直到遍历完整个字符串 s。

我们通过一个例子来说明这个过程。假设 s = "ADOBECODEBANC"，t = "ABC"。

初始化：needs = {'A': 1, 'B': 1, 'C': 1}，window = {}，left = 0，right = 0，min_len = +∞，res = ""。
扩大窗口：window = {'A': 1, 'D': 1, 'O': 1, 'B': 1, 'E': 1, 'C': 1}，right = 5。此时窗口包含了 t 中的所有字符。
缩小窗口：将 left 移动到 1，window = {'A': 0, 'D': 1, 'O': 1, 'B': 1, 'E': 1, 'C': 1}。此时窗口不再包含 t 中的所有字符。
更新结果：当前窗口长度为 6（"ADOBEC"），小于之前的 min_len，所以 min_len = 6，res = "ADOBEC"。
重复步骤2-4，直到 right 到达 s 的末尾。最后得到的结果 res = "BANC"。
这就是滑动窗口算法在这道题中的应用。注意到，窗口的扩大和缩小是一个动态的过程，我们只需要遍历字符串 s 一次，所以时间复杂度为 O(n)，n 为字符串 s 的长度。
 */
