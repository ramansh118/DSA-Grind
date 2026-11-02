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
    int maxDepth(TreeNode* root) {
        vector<vector<int>>ans;
        if (root==NULL){
            return 0;
        }
        vector<TreeNode*>first;
        first.push_back(root);
        ans.push_back({root->val});
        queue<TreeNode*>anss;
        int n=first.size();
        for(int i=0;i<n;i++){
            anss.push(first[i]);
        }
        first.clear();
        while(!anss.empty()){
            vector<vector<TreeNode*>>second;
            for(int i=0;i<n;i++){
                second.push_back(child(anss.front()));
                anss.pop();
            }
            int n1=second.size();
            for(int i=0;i<n1;i++){
                int n2=second[i].size();
                for(int j=0;j<n2;j++){
                    first.push_back(second[i][j]);
                }
            }
            second.clear();
            n=first.size();
            for(int i=0;i<n;i++){
                anss.push(first[i]);
            }
            if (first.empty()) break;           
            ans.push_back({first[0]->val}); 
            int n3=ans.size();
            for(int i=1;i<n;i++){
                ans[n3-1].push_back(first[i]->val);
            }
            first.clear();
        }
        return ans.size(); 



        
    }
    vector<TreeNode*>child(TreeNode* root){
        vector<TreeNode*>ans;
        if (root==NULL){
            return ans;
        }
        if (root->left!=NULL){
            ans.push_back(root->left);
        }
        if (root->right!=NULL){
            ans.push_back(root->right);
        }
        return ans;
      
        
    
    }
};