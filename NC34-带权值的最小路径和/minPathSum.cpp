/*
题目描述
给定一个由非负整数填充的m x n的二维数组，现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
注意：你每次只能向下或向右移动。


示例1
输入
[[1,2],[5,6],[1,1]]
返回值
8
*/
class Solution {
public:
    /**
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& grid) {
        // write code here
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> temp(n, 0);
        vector<vector<int> > dp(m, temp);
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];//初始化第一行数据
        }
        for(int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];//初始化第一列数据
        }
        for(int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]; //当前最小路径，等于上方和左边最小路径中的较小值+当前值
            }
        }
        return dp[m - 1][n - 1];
    }
};
