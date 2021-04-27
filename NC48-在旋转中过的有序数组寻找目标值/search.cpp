/*
题目描述
给定一个整数数组nums，按升序排序，数组中的元素各不相同。
nums数组在传递给search函数之前，会在预先未知的某个下标 t（0 <= t <= nums.length-1）上进行旋转，让数组变为[nums[t], nums[t+1], ..., nums[nums.length-1], nums[0], nums[1], ..., nums[t-1]]。
比如，数组[0,2,4,6,8,10]在下标2处旋转之后变为[6,8,10,0,2,4]
现在给定一个旋转后的数组nums和一个整数target，请你查找这个数组是不是存在这个target，如果存在，那么返回它的下标，如果不存在，返回-1
示例1
输入
[6,8,10,0,2,4],10
返回值
2
示例2
输入
[6,8,10,0,2,4],3
返回值
-1
示例3
输入
[2],1
返回值
-1
备注:
1 <= nums.length <= 4000
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int binary_search(vector<int> & nums, int target, int begin, int end) {
        int mid = -1;
        while(begin <= end) {
            mid = (begin + end) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid - 1;
            else begin = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // write code here
        int max_index = -1;
        //先用二分查找找到最大值的坐标，最大值坐标i满足nums[i] > nums[i+1]
        int head = 0, tail = nums.size() - 1;
        int mid;
        while(head <= tail) {
            mid = (head + tail) / 2;
            if(nums[mid] > nums[mid + 1]) {
                max_index = mid;
                break;
            } else if(nums[mid] > nums[0]) {
                head = mid + 1;
            } else {
                tail = mid - 1;
            }
        }
        if(max_index == -1) return binary_search(nums, target, 0, nums.size() - 1);//没有旋转，直接所有范围二分查找
        if(target > nums[max_index] || target < nums[max_index + 1]) {
            return -1;
        }
        if(target >= nums[0]) {
            return binary_search(nums, target, 0, max_index);//在前半部分查找
        } else {
            return binary_search(nums, target, max_index + 1, nums.size() - 1);//在后半部分查找
        }
    }
};
