/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = p->val;
        int qv = q->val;
        if (root == nullptr) {
            return nullptr;
        } 
        int v = root->val;
        if (v == pv || v == qv) {
            return root;
        } 
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l == nullptr && r == nullptr) {
            return nullptr;
        } else if (l != nullptr && r != nullptr) {
            return root;
        } else if (l != nullptr) {
            return l;
        } else {
            return r;
        }
    }

};
