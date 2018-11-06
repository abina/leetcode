class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int target = 0 - nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    vector<int> tri(3);
                    tri[0] = nums[i];
                    tri[1] = nums[l];
                    tri[2] = nums[r];
                    ans.push_back(tri);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        
        return ans;
    }
};

