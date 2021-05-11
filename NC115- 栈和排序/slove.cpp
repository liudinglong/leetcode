/*
题目描述
给你一个1->n的排列和一个栈，入栈顺序给定
你要在不打乱入栈顺序的情况下，对数组进行从大到小排序
当无法完全排序时，请输出字典序最大的出栈序列
示例1
输入
[2,1,5,3,4]
返回值
[5,4,3,1,2]
说明
2入栈；1入栈；5入栈；5出栈；3入栈；4入栈；4出栈；3出栈；1出栈；2出栈
备注:
n<=1e6
*/
class Solution {
public:
    /**
     * 栈排序
     * @param a int整型一维数组 描述入栈顺序
     * @param aLen int a数组长度
     * @return int整型vector
     */
    vector<int> solve(int* a, int aLen) {
        // write code here
        vector<int> res;
        vector<int> max_ans(aLen, -1);
        int cur_max = a[aLen - 1];
        for(int i = aLen - 1; i >= 0; i--) {
            cur_max = max(cur_max, a[i]);
            max_ans[i] = cur_max;//记录从a[i]~a[aLen]的最大值
        }
        stack<int> temp;
        int index = 0;
        while(index < aLen) {
            if(temp.empty() || temp.top() < max_ans[index]){//如果栈为空，或者栈顶元素，小于右边的最大值，说明栈顶元素不能出栈，要继续入栈
                temp.push(a[index]);
                index++;//入栈后，遍历下一个元素
            }
            while(!temp.empty() && temp.top() >= max_ans[index]) {//如果栈顶元素，大于等于右边最大值，说明栈顶元素可以出栈
                res.push_back(temp.top());
                temp.pop();
            }
        }
        while(!temp.empty()) {//有可能还有元素没出栈，最后全部出栈
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};
