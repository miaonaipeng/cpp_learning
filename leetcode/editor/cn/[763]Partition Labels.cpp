/**
You are given a string s. We want to partition the string into as many parts as 
possible so that each letter appears in at most one part. 

 Note that the partition is done so that after concatenating all the parts in 
order, the resultant string should be s. 

 Return a list of integers representing the size of these parts. 

 
 Example 1: 

 
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits 
s into less parts.
 

 Example 2: 

 
Input: s = "eccbbbbdec"
Output: [10]
 

 
 Constraints: 

 
 1 <= s.length <= 500 
 s consists of lowercase English letters. 
 

 Related Topics 贪心 哈希表 双指针 字符串 👍 931 👎 0

*/
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int n = s.size();
        int start = 0, end = 0;
        vector<int> last(26, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end){
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    return 0;
}