class Solution{
public:
	TreeNode* deleteNode(TreeNode* root, int key){
		TreeNode* c=root;
		TreeNode* pc=NULL;
		while(c!=NULL){
			if(key<c->val){
				pc=c;
				c=c->left;
			}else if(key>c->val){
				pc=c;
				c=c->right;
			}else if(c->val==key){
				break;
			}
		}
		if(c==NULL)
			return root;
		TreeNode* nr=c->right;
		TreeNode* ins=c->left;
		if(nr==NULL&&ins==NULL){
		    if(pc!=NULL){
		    if(c->val<pc->val)
		        pc->left=NULL;
		    else
		        pc->right=NULL;
		    return root;
		    }
		    return pc;
		    
		}else if(nr==NULL&&ins!=NULL){
		    nr=ins;
		}else if(nr!=NULL&&ins!=NULL){
		    int k=c->left->val;
	    	TreeNode* pnr=nr;
		
		while(pnr!=NULL){
			if(k>pnr->val){
			    if(pnr->right==NULL){
			        pnr->right=ins;
			        break;
			    }
				pnr=pnr->right;
			}else if(k<pnr->val){
			    if(pnr->left==NULL){
			        pnr->left=ins;
			        break;
			    }
				pnr=pnr->left;
			}
		}
		/*
		    TreeNode* ppnr=NULL;
		    while(!(pnr->left==NULL&&pnr->right==NULL)){
		        if(k>pnr->val){
		            ppnr=pnr;
		            pnr=pnr->right;
		        }else if(k<nr->val){
		            ppnr=pnr;
		            pnr=pnr->left;
		        }
		    }
		    cout<<"pnr"<<pnr->val;
		    if(pnr->val<ppnr->val)
		        ppnr->left=NULL;
		    else
		        ppnr->right=NULL;
		    pnr->left=ins;
		    pnr->right=nr;
		    return pnr;
		    */
		}
		
		if(pc==NULL){
		    return nr;
		}
		else{
		    
			if(nr->val<pc->val)
				pc->left=nr;
			else
				pc->right=nr;
			return root;
		}
		
		return root;
	}
};
