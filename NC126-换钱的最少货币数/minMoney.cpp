/******
题目描述
给定数组arr，arr中所有的值都为正整数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个aim，代表要找的钱数，求组成aim的最少货币数。
如果无解，请返回-1.
【要求】
时间复杂度O(n \times aim)O(n×aim)，空间复杂度On。

示例1
输入
[5,2,3],20
返回值
4
示例2
输入
[5,2,3],0
返回值
0
示例3
输入
[3,5],2
返回值
-1
*/
class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        int dp[aim + 1];
        dp[0] = 0;
        for(int i = 1; i <= aim; i++) {
            dp[i] = aim; //最大钱币数为aim
            for(int j = 0; j < arr.size(); j++) {//复杂度为aim*n, 空间复杂度为aim
                if(i - arr[j] >= 0)
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            } 
        }
        if(dp[aim] == aim) return -1;
        return dp[aim];
    }
};
