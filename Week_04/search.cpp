//33. 搜索旋转排序数组
//为什么提交还是会超时？
class Solution {
public:
    int search(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size() - 1;
            while (low <= high) {
                int mid = low + (high - low)/2;
                if (nums[mid] == target) {
                    return mid;
		//当[0, mid]有序时，向后规约条件
                }else if (nums[0] <= nums[mid] && (target > nums[mid] || target < nums[0])) {
                    low = mid + 1;
		//当[0, mid]发生旋转时，向后规约条件
                }else if (target > nums[mid] && target < nums[0]) {
                    low = mid + 1;
                }else {
                    high = mid;
                }
            }
            return -1;      
    }
};

