#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/**
Given a string s and a string array dictionary, return the longest string in 
the dictionary that can be formed by deleting some of the given string characters. 
If there is more than one possible result, return the longest word with the 
smallest lexicographical order. If there is no possible result, return the empty 
string. 

 
 Example 1: 

 
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
 

 Example 2: 

 
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
 

 
 Constraints: 

 
 1 <= s.length <= 1000 
 1 <= dictionary.length <= 1000 
 1 <= dictionary[i].length <= 1000 
 s and dictionary[i] consist of lowercase English letters. 
 

 Related Topics 数组 双指针 字符串 排序 👍 334 👎 0

*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 对字典d中的字符串按照长度降序、字典序升序进行排序
        std::sort(dictionary.begin(), dictionary.end(), [](const std::string& a, const std::string& b) {
            return a.length() > b.length() || (a.length() == b.length() && a < b);
        });
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution solution;
    
    return 0;
}