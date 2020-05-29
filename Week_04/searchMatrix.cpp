//74. 搜索二维矩阵
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] < target) {
                row++;
            }else if (matrix[row][col] > target) {
                col--;
            }else {
                return true;
            }
        }
        return false;
        
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == matrix[mid/n][mid%n]) {
                return true;
            }else if (target < matrix[mid/n][mid%n]) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return false;
    }
};
