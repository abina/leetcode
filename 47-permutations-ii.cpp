class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        
        vector<int> perm;
        getPermutation(nums, 0, n, perm, res);
        
        return res;
    }
    
private:
    void getPermutation(vector<int>& nums, int start, int end,
                        vector<int>& perm, vector<vector<int>>& res) {
        if (perm.size() == end) {
            res.push_back(perm);
        }
        
        unordered_set<int> v;
        for (int i = start; i < end; i++) {
            if (v.find(nums[i]) != v.end()) {
                continue;
            }

            v.insert(nums[i]);
            swap(nums[start], nums[i]);
            perm.push_back(nums[start]);
            getPermutation(nums, start + 1, end, perm, res);
            perm.pop_back();
            swap(nums[start], nums[i]);
        }
    }
};

