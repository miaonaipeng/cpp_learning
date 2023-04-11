/**
You have a long flowerbed in which some of the plots are planted, and some are 
not. However, flowers cannot be planted in adjacent plots. 

 Given an integer array flowerbed containing 0's and 1's, where 0 means empty 
and 1 means not empty, and an integer n, return true if n new flowers can be 
planted in the flowerbed without violating the no-adjacent-flowers rule and false 
otherwise. 

 
 Example 1: 
 Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
 
 Example 2: 
 Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 
 
 Constraints: 

 
 1 <= flowerbed.length <= 2 * 10⁴ 
 flowerbed[i] is 0 or 1. 
 There are no two adjacent flowers in flowerbed. 
 0 <= n <= flowerbed.length 


 Related Topics 贪心 数组 👍 543 👎 0

*/
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        // 排除开头和结尾
        for (int i = 0; i < size && count < n; ++i) {
            if (flowerbed[i] == 0) {
                int prev = (i == 0 ? 0 : flowerbed[i - 1]);
                int next = (i == size - 1 ? 0 : flowerbed[i + 1]);
                if (prev == 0 && next == 0){
                    ++count;
                    flowerbed[i] = 1;
                }
            }
        }
        return count == n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v{1,0,0,0,0,1};
    solution.canPlaceFlowers(v, 2);
    cin.get();
    return 0;
}