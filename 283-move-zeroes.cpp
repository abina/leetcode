class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return;
        }
        
        int i = 0;
        for (int j = 0; j < n;) {
            while (j < n && nums[j] == 0) {
                j++;
            }
            if (j < n) {
                nums[i++] = nums[j++];
            }
        }
        while (i < n) {
            nums[i++] = 0;
        }
    }
};

