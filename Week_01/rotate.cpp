//189. 旋转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp, previous;
        int len = nums.size();
        for (int i = 0; i < k; i++) {
            previous = nums[len - 1];
            for (int j = 0; j < len; j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }

    }
};
