class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        
        int l = 1;
        int r = 1;
        while (r < n) {
            if (nums[r] == nums[r-1]) {
                r++;
            } else {
                nums[l++] = nums[r++];
            }
        }
        
        return l;
    }
};

