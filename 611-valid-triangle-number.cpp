class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for (int i = n - 1; i > 0; i--) {
            int l = 0;
            int r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] <= nums[i]) {
                    l++;
                } else {
                    count += r - l;
                    r--;
                }
            }
        }
        
        return count;        
    }
};

