class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        if (l == r) {
            return l;
        }
        if (nums[l] > nums[l+1]) {
            return l;
        }
        if (nums[r] > nums[r-1]) {
            return r;
        }

        l++;
        r--;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m-1]) {
                r = m - 1;
            } else {
                if (nums[m] > nums[m+1]) {
                    return m;
                }
                l = m + 1;
            }
        }
        
        return -1;
    }
};

