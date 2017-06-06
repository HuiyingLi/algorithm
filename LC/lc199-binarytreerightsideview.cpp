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

    vector<int> ans;

    void dfs(TreeNode* n,int d){

        if(n==NULL)

            return;

        

        if(d>=ans.size()){

            ans.push_back(n->val);

        }else{

            ans[d]=n->val;

        }

        dfs(n->left,d+1);

        dfs(n->right,d+1);

    }

    vector<int> rightSideView(TreeNode* root) {

        dfs(root,0);

        return ans;

        

    }

};
