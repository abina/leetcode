class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        int l = 2;
        int r = 2;
        while (r < n) {
            if (nums[r] != nums[r-1]) {
                nums[l++] = nums[r++];
            } else if (nums[l-1] != nums[l-2]) {
                nums[l++] = nums[r++];
            } else {
                r++;
            }
        }
        
        return l;
    }
};

