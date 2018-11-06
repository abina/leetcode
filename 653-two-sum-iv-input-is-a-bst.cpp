/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        tree2arr(root, nums);
        
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) {
                return true;
            }
            if (sum > k) {
                r--;
            } else {
                l++;
            }
        }
        
        return false;
    }
    
private:
    void tree2arr(TreeNode* node, vector<int>& nums) {
        if (node == NULL) {
            return;
        }
        
        tree2arr(node->left, nums);
        nums.push_back(node->val);
        tree2arr(node->right, nums);
    }
};

