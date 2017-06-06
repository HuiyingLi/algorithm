/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class BSTIterator {

public:

    queue<int> q;

    void dfs(TreeNode* root){

        if(root==NULL)

            return;

        dfs(root->left);

        q.push(root->val);

    //    cout<<"push "<<root->val;

        dfs(root->right);

    }

    BSTIterator(TreeNode *root) {

        dfs(root);

    }



    /** @return whether we have a next smallest number */

    bool hasNext() {

        if(q.empty())

            return false;

        return true;

        

    }



    /** @return the next smallest number */

    int next() {

        int ans=q.front();

        q.pop();

        return ans;

    }

};



/**

 * Your BSTIterator will be called like this:

 * BSTIterator i = BSTIterator(root);

 * while (i.hasNext()) cout << i.next();

 */
