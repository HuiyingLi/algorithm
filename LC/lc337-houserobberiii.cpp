class Solution {
public:
    int l[100000];
    int nls[100000];
    int N;
    //@1:total money @2:total nodes @3:is root used
    vector<int> dfs(TreeNode* node, int id){
        vector<int> ret(3);
        if(node==NULL){
            ret[0]=ret[1]=ret[2]=0;
            return ret;
        }
        int nnode=1;
        //children
        bool rootused_a=false;
        vector<int> rl=dfs(node->left, id+1);
        vector<int> rr=dfs(node->right,id+rl[1]+1);
        nnode+=rl[1]+rr[1];
        nls[id]=rl[1];
        int a=rl[0]+rr[0];
        if(rl[2]==0&&rr[2]==0){
            rootused_a=true;
            a+=node->val;
        }
        //self + grandsons
        int b=node->val;
        if(node->left!=NULL){
            //vector<int> r=dfs(node->left->left, id+1);
            int id1=id+2;
            int id2=id+nls[id+1]+2;
            
            if(node->left->left!=NULL){
                b+=l[id1];
            }
            if(node->left->right!=NULL){
                b+=l[id2];
            }
        }
        if(node->right!=NULL){
            int id3=id+rl[1]+2;
            int id4=id+rl[1]+2+nls[id+rl[1]+1];
            if(node->right->left!=NULL){
                b+=l[id3];
            }
            if(node->right->right!=NULL){
                b+=l[id4];
            }
        }
        ret[1]=nnode;
        if(a>b){
            l[id]=a;
            ret[0]=a;
            ret[2]=rootused_a;
        }else{
            l[id]=b;
            ret[0]=b;
            ret[2]=true;
        }
        return ret;
    }
    int rob(TreeNode* root) {
        memset(l,0,sizeof(l));
        N=0;
        return dfs(root, 0)[0];
    }
};
