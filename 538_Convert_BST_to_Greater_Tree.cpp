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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return convertBST(root, sum);
    }

private:
    TreeNode* convertBST(TreeNode* node, int& sum) {
        if (node == NULL) {
            return node;
        }
        if (node->right != NULL) {
            node->right = convertBST(node->right, sum);
        }
        node->val += sum;
        sum = node->val;
        if (node->left != NULL) {
            node->left = convertBST(node->left, sum);
        }
        
        return node;
    }
};

