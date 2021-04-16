/*
给出一组可能包含重复项的数字，返回该组数字的所有排列。

示例1
输入
[1,1,2]
返回值
[[1,1,2],[1,2,1],[2,1,1]]

*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        set<vector<int> > res; //用set来去重，因为有重复数字，所以交换可能得到相同排列
        dfs(res, num, 0);
        vector<vector<int> > result;
        for(auto vc : res) result.push_back(vc);
        return result;
    }
    void dfs(set<vector<int> > &res, vector<int> &path, int level) {
        if(level == path.size()) {
            res.insert(path);
            return;
        };
        for(int i = level; i < path.size(); i++) { // level和包括自己的之后的每个元素交换位置
            if(i != level && path[i] == path[level]) continue;//剪枝，这里是关键，相等元素没必要换位置，但是同一个位置元素，为了递归要进行交换
            swap(path[i], path[level]);
            dfs(res, path, level + 1);
            swap(path[i], path[level]);
        }
    }
};
