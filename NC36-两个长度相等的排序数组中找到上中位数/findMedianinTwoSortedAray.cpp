/*
题目描述
给定两个有序数组arr1和arr2，已知两个数组的长度都为N，求两个数组中所有数的上中位数。
上中位数：假设递增序列长度为n，若n为奇数，则上中位数为第n/2+1个数；否则为第n/2个数
[要求]
时间复杂度为O(logN)O(logN)，额外空间复杂度为O(1)O(1)
示例1
输入
[1,2,3,4],[3,4,5,6]
返回值

3
说明
总共有8个数，上中位数是第4小的数，所以返回3。 
示例2
输入
[0,1,2],[3,4,5]
返回值
2
说明
总共有6个数，那么上中位数是第3小的数，所以返回2 
备注:
1≤N≤10^5
 0≤arr1[i],arr2[i]​≤10^9
*/
class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        // write code here
        int num = 0;
        int n = arr1.size();
        int m = arr2.size();
        if (m == 0 || n == 0 || m != n) {//题目要求两个数组长度相等
            return 0;
        }
        return findKth(arr1, 0, arr2, 0, n);
    }
    
    int findKth(vector<int>& arr1, int start1, vector<int>& arr2, int start2, int k) {
        if(k == 1) return min(arr1[start1], arr2[start2]);
        int m = k / 2;
        int n = k - m;//保证 m + n = k
        int index1 = m - 1 + start1;//计算出index1的下标值，满足[start1,index1]有m个元素
        int index2 = n - 1 + start2;//计算出index2的下标值，满足[start2,index2]有n个元素
        if(arr1[index1] == arr2[index2]) return arr1[index1];//如果arr1[index1]等于arr2[index2]，又m+n=k，则arr1[index1],就是第k小的
        else if(arr1[index1] < arr2[index2]) {//<=arr1[index1]的数不可能为第K小的，排除m个
            return findKth(arr1, start1 + m, arr2, start2, k - m);
        } else {
            return findKth(arr1, start1, arr2, start2 + n, k - n);//<=arr2[index2]的不可能是第K小的，排除n个
        }
    }
};