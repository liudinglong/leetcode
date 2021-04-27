/*
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
窗口大于数组长度的时候，返回空
示例1
输入
[2,3,4,2,6,2,5,1],3
返回值
[4,4,6,6,6,5]
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        if(size == 0 || size > num.size()) return {};
        int cur_max = num[0], max_index = 0;
        //先求出第一个窗口最大值，并记录坐标
        for(int i = 1; i < size; i++) {
            if(num[i] >= cur_max) {
                cur_max = num[i];
                max_index = i;
            }
        }
        vector<int> res;
        res.push_back(cur_max);
        for(int i = size; i < num.size(); ++i) {
            if(num[i] >= cur_max) {//当前值，大于当前最大值，更新当前最大值及坐标
                max_index = i;
                cur_max = num[i];
                res.push_back(cur_max);
            } else {
                if(i - max_index < size) {//当前最大值还在窗口内，则直接保存当前滑动窗口最大值
                    res.push_back(cur_max);
                } else { //否则要在当前滑动窗口重新找最大值并记录最大值坐标
                    cur_max = num[i];
                    max_index = i;
                    int index = i - 1;
                    while(index > i - size) {
                        if(num[index] > cur_max) {
                            cur_max = num[index];
                            max_index = index;
                        }
                        index--;
                    }
                    res.push_back(cur_max);
                }
            }
        }
        return res;
    }
};
