class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (nums[m] >= x) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        
        r = l + 1;
        while (k-- > 0) {
            if (l < 0) {
                r++;
            } else if (r >= n) {
                l--;
            } else if (x - nums[l] <= nums[r] - x) {
                l--;
            } else {
                r++;
            }
        }
        
        return vector<int>(nums.begin() + l + 1, nums.begin() + r);
    }
};

