class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int closest = INT_MAX;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) {
                    return target;
                }
                if (sum < target) {
                    if (target - sum < closest) {
                        ans = sum;
                        closest = target - sum;
                    }
                    l++;
                } else {
                    if (sum - target < closest) {
                        ans = sum;
                        closest = sum - target;
                    }
                    r--;
                }
            }
        }
        
        return ans;
    }
};

