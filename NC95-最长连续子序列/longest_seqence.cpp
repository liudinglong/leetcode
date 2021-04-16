/***
给定无序数组arr，返回其中最长的连续序列的长度(要求值连续，位置可以不连续,例如 3,4,5,6为连续的自然数）
输入
[100,4,200,1,3,2]
返回值
4
示例2
输入
[1,1,1]
返回值
1
*/
#include<unordered_set>
class Solution {
public:
    /**
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr) {
        // write code here
        unordered_set<int> tmp;
        int max_len = 1;
        for(auto num : arr) tmp.insert(num);//把所有元素放到哈希集合里
        for(auto num : arr) {
            int len = 1;
            if(tmp.count(num - 1) == 0 && tmp.count(num + 1) == 0) {
                tmp.erase(num);//前后元素都不存在，删除，查下一个元素
                continue;
            }
            int index = num - 1;
            tmp.erase(num);
            while(tmp.count(index) > 0) {
                tmp.erase(index);//查当前元素之前的元素，每查到一个元素，删除它，计数加1
                index--;
                len++;
            }
            index = num + 1;
            while(tmp.count(index) > 0) {
                tmp.erase(index);//查当前元素之后的元素，每查到一个元素，删除它，计数加1
                index++;
                len++;
            }
            if(len > max_len) max_len = len;
        }
        return max_len;
    }
    
};
