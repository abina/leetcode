class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = 0;
        while (r < n) {
            if (nums[r] != val) {
                nums[l++] = nums[r++];
            } else {
                r++;
            }
        }
        
        return l;        
    }
};

