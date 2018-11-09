class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[l];
                        tmp[3] = nums[r];
                        res.push_back(tmp);
                        do {
                            l++;
                        } while (nums[l] == nums[l-1]);
                        do {
                            r--;
                        } while (nums[r] == nums[r+1]);
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        
        return res;
    }
};

