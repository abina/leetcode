class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int l = 0;
        int r = 1;
        int lmax = nums[0];
        int rmax = nums[0];
        while (r < n) {
            while (r < n && nums[r] >= lmax) {
                rmax = max(rmax, nums[r]);
                r++;
            }
            if (r < n) {
                l = r;
                lmax = rmax;
                r++;
            }
        }
        
        return l + 1;
    }
};

