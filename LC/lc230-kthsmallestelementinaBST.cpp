class Solution {

public:

    bool flag=false;

    int T;

    int c;

    int k;

    bool dfs(TreeNode* n){

        if(n==NULL) return false;

        if(n->left!=NULL)

            if(dfs(n->left))

                return true;

        c++;

        if(c==k){

            T=n->val;

            return true;

        }

        if(dfs(n->right))

            return true;

        return false;

    }

    int kthSmallest(TreeNode* root, int k) {

        c=0;

        this->k=k;

        dfs(root);

        return T;

    }

};
