/*
题目描述
一个重复字符串是由两个相同的字符串首尾拼接而成，例如abcabc便是长度为6的一个重复字符串，而abcba则不存在重复字符串。
给定一个字符串，请编写一个函数，返回其最长的重复字符子串。
若不存在任何重复字符子串，则返回0。
示例1
输入
"ababc"
返回值
4
说明
abab为最长的重复字符子串，长度为4 
示例2
输入
"abcab"
返回值
0
说明
该字符串没有重复字符子串 
备注:
字符串长度不超过10000，且仅由小写字母组成
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a string字符串 待计算字符串
     * @return int整型
     */
    int solve(string a) {
        // write code here
        if(a.size() <= 1) return 0;
        int len = a.size();
        int max_len = len / 2;
        int count = 0;
        for(int i = max_len; i > 0; i--) {
            for(int j = 0; j < len - i; j++) {
                if(a[j] == a[j + i]) {
                    count++;
                } else {
                    count = 0;
                }
                if(count == i) {
                    return i * 2;//当count == i时，则[j,j+i)和[j+i,j+2*i)是相等的子串
                }
            }
        }
        return 0;
    }
};