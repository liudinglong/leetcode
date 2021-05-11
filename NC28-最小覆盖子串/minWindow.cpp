/*
题目描述
给出两个字符串 SS 和 TT，要求在O(n)O(n)的时间复杂度内在 SS 中找出最短的包含 TT 中所有字符的子串。
例如：

S ="XDOYEZODEYXNZ"S="XDOYEZODEYXNZ"
T ="XYZ"T="XYZ"
找出的最短子串为"YXNZ""YXNZ".

注意：
如果 SS 中没有包含 TT 中所有字符的子串，返回空字符串 “”；
满足条件的子串可能有很多，但是题目保证满足条件的最短的子串唯一。

示例1
输入
复制
"XDOYEZODEYXNZ","XYZ"
返回值
复制
"YXNZ"
*/

/*
最小滑动窗口算法思路
初始化begin=0, end=0, min_window = INT_MAX
判断[begin, end]区间是否满足条件，如果满足条件，则检查end - begin + 1 < min_window,成立则更新min_window 为 end - begin + 1，接着begin++，直到[begin, end]区间不满足条件
如果不满足条件，则end++
*/

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T) {
        // write code here
        if(S.size() < T.size()) return "";
        int begin = 0, end = 0;//初始化begin，end为0
        unordered_map<char, int> char_count;//记录[begin, end]区间每个字符的数量
        unordered_map<char, int> missed_char;//记录[begin, end]区间缺失的字符及数量
        for(auto c : T) {
            if(missed_char.find(c) == missed_char.end()) {
                missed_char[c] = 1;
            } else {
                missed_char[c] += 1;
            }
        }//统计T的每个字符的数量
        unordered_map<char, int> T_chars = missed_char;
        int min_len = INT_MAX;
        int min_begin = -1;
        while(end < S.size()) {
            if(missed_char.find(S[end]) != missed_char.end()) {
                missed_char[S[end]] -= 1;//匹配到缺失字符，对应缺失字符缺失数量-1
                if(missed_char[S[end]] == 0)//缺失数量为0，则从missed_char里面删除
                    missed_char.erase(missed_char.find(S[end]));
            }
            if(char_count.find(S[end]) == char_count.end()) {
                char_count[S[end]] = 1;
            } else {
                char_count[S[end]] += 1;
            }
            while(missed_char.empty()) {//[begin, end]区间满足条件
                if(end - begin + 1 < min_len) {
                    min_begin = begin;
                    min_len = end - begin + 1;//更新结果
                }
                char_count[S[begin]] -= 1;//S[begin]在当前区间记数减1
                if( T_chars.find(S[begin]) != T_chars.end() && char_count[S[begin]] < T_chars[S[begin]]) {//如果S[begin]是目的字符集需要的，则S[begin]缺失计数+1
                    if(missed_char.find(S[begin]) == missed_char.end())
                        missed_char[S[begin]] = 1;
                    else if(missed_char[S[begin]] < T_chars[S[begin]]) {
                        missed_char[S[begin]] += 1;
                    }
                }
                begin++;
            }
            end++;
        }
        if(min_begin != -1)
            return S.substr(min_begin, min_len);
        else 
            return "";
    }
};