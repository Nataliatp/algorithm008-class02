使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
用二分查找，当中间这个值的前后都比它大，说明它是旋转点
当nums[0] < = nums[mid]，说明前半部分是有序的，无序旋转点在后半部分
当nums[0] > nums[mid]，说明前半部分已经发生了旋转，无序旋转点在前半部分
class Solution {
public:
    int search(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size() - 1;
            while (low <= high) {
                int mid = low + (high - low)/2;
                if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
                    return mid;
                }else if (nums[0] <= nums[mid]) {
                    low = mid + 1;
                }else {
                    high = mid - 1;
                }
            }
            return -1;      
    }
};
