class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }
        
        int top = 0;
        int bottom = row - 1;
        while (top < bottom) {
            int m = top + (bottom - top + 1) / 2;
            if (matrix[m][0] == target) {
                return true;
            }
            if (matrix[m][0] < target) {
                top = m;
            } else {
                bottom = m - 1;
            }
        }
        
        int l = 0;
        int r = col - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[top][m] == target) {
                return true;
            } else if (matrix[top][m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return false;
    }
};

