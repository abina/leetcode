class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 0 || n < k) {
            return -1;
        }
        
        return helper(nums, k - 1, 0, n - 1);
    }
    
private:
    int helper(vector<int>& nums, int k, int left, int right) {
        if (left >= right) {
            return nums[k];
        }
        
        int l = left;
        int r = right;
        int m = l + (r - l) / 2;
        int tmp = nums[m];
        nums[m] = nums[l];
        while (l < r) {
            while (l < r && nums[r] < tmp) {
                r--;
            }
            if (l < r) {
                nums[l++] = nums[r];
            }
            while (l < r && nums[l] >= tmp) {
                l++;
            }
            if (l < r) {
                nums[r--] = nums[l];
            }
        }
        nums[l] = tmp;
        
        if (l == k) {
            return nums[k];
        } else if (k < l) {
            return helper(nums, k, left, l - 1);
        } else {
            return helper(nums, k, l + 1, right);
        }
    }
};

