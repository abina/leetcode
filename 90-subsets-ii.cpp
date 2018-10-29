class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        vector<int> subset;
        getSubsets(nums, 0, n, subset, res);
        
        return res;
    }
    
private:
    void getSubsets(vector<int>& nums, int start, int end,
                    vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        
        for (int i = start; i < end; i++) {
            if (i == start || nums[i] != nums[i-1]) {
                subset.push_back(nums[i]);
                getSubsets(nums, i + 1, end, subset, res);
                subset.pop_back();
            }
        }
    }
};

