class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        
        int l = 0;
        int r = n - 1;
        int m = l + (r - l) / 2;
        while (l < r) {
            if (nums[m] == target) {
                break;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
            m = l + (r - l) / 2;
        }
        
        int rl = m;
        while (l < rl) {
            int mid = l + (rl - l) / 2;
            if (nums[mid] == target) {
                rl = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] == target) {
            res[0] = l;
        } else {
            return res;
        }
        
        l = m;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] == target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        res[1] = l;
        
        return res;
    }
};

