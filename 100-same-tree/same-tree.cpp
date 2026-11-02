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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int first= countt(p);
        int second=countt(q);
        if (first!=second){
            return false;
        }
        return same(p,q);

    }
    bool same(TreeNode* p, TreeNode* q){
            if (p==NULL && q==NULL){
                return true;
            }
            if (p!=NULL && q==NULL){
                return false;
            }
            if (p==NULL && q!=NULL){
                return false;
            }

            if (p->val!=q->val){
                return false;
            }
            return same(p->left,q->left) && same(p->right,q->right);
            

            
        }
    
    int countt(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        return 1+countt(root->left)+countt(root->right);
    }
};