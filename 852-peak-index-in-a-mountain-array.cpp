class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 2;
        
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[m - 1]) {
                r = m - 1;
            } else {
                if (nums[m] > nums[m + 1]) {
                    return m;
                } else {
                    l = m + 1;
                }
            }
        }
        
        return -1;
    }
};

