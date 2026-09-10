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
    bool check(TreeNode* root){
        if(!root) return true;
        int n = 0;
        int sum = 0;
        queue<TreeNode*>  q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            n++;
            sum+= curr->val;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return root->val == sum/n;
    }
    int ans = 0;
    void inorder(TreeNode* root){
        if(!root) return;

        // left
        inorder(root->left);
        //root
        ans+=check(root);
        //right
        inorder(root->right);

    }

    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;

        inorder(root);
        return ans;
        
    }
};