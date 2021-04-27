/*题目描述
给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。
示例1
输入
[[1,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,0]]
返回值
12
备注:
1 ≤ n,m ≤ 2000
1 ≤ arr i,j ≤ 100
*/
class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m, 0);
        vector<vector<int> > dp(n, temp);
        //初始化dp第一行
        int cur = 0;
        for(int j = 0; j < m; j++) {
            cur += matrix[0][j];
            dp[0][j] = cur;
        }
		//初始化dp第一列
        cur = matrix[0][0];
        for(int i = 1; i < n; ++i) {
            cur += matrix[i][0];
            dp[i][0] = cur;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};
