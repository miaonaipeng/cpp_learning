/**
There are n children standing in a line. Each child is assigned a rating value 
given in the integer array ratings. 

 You are giving candies to these children subjected to the following 
requirements: 

 
 Each child must have at least one candy. 
 Children with a higher rating get more candies than their neighbors. 
 

 Return the minimum number of candies you need to have to distribute the 
candies to the children. 

 
 Example 1: 

 
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 
candies respectively.
 

 Example 2: 

 
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 
candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

 
 Constraints: 

 
 n == ratings.length 
 1 <= n <= 2 * 10⁴ 
 0 <= ratings[i] <= 2 * 10⁴ 
 

 Related Topics 贪心 数组 👍 1165 👎 0

*/
#include "algorithm"
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if (size < 2) return size;
        vector<int> child(size, 1);

        for (int i = 1; i < size; ++i) {
            if (ratings[i-1] < ratings[i] ){
                child[i] = child[i-1] + 1;

            }
        }
        for (int i = size - 1; i >= 1; --i) {
            if (ratings[i -1] > ratings[i] && child[i-1] <= child[i]){
                child[i-1] = child[i]+1;
            }
        }

        int sum = 0;
        for (auto item: child) {
            sum += item;
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> rating{1,0,2};
    cout<< solution.candy(rating);

    return 0;
}