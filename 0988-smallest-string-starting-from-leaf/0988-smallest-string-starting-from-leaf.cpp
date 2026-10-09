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
    void func(TreeNode* root, string level,string &ans){
        if(!root) return;

        level+=char(root->val + 'a');
        if(!root->left && !root->right){
            reverse(level.begin(),level.end());
            if(ans.empty()||ans > level){
                ans = level;
            }
            return;
        }
        func(root->left,level,ans);
        func(root->right,level,ans);
   
        
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root == nullptr) return "";

        string ans = "";
        func(root,"",ans);
        return ans;
    }
};