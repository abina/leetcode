class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                index.push_back(m[target - nums[i]]);
                index.push_back(i);
                return index;
            } else {
                m[nums[i]] = i;
            }
        }
        
        return index;
    }
};

