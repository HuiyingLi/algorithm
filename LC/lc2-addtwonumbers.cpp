#include<iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret;
		ListNode* cur;
		ListNode* prev;
		int c=0;
		bool init=true;
		while(l1!=NULL||l2!=NULL){
			if(init){
				cur=new ListNode(0);
				ret=cur;
				init=false;
			}else{
				cur=new ListNode(0);
				prev->next=cur;
			}
			int v1=0;
			int v2=0;
			if(l1!=NULL)
				v1=l1->val;
			if(l2!=NULL)
				v2=l2->val;
			int v=v1+v2+c;
			cout<<v<<endl;
			if(v>=10){
				cur->val=v%10;
				c=1;	
			}else{
				cur->val=v;
				c=0;
			}
			if(l1!=NULL)
				l1=l1->next;
			if(l2!=NULL)
				l2=l2->next;
			prev=cur;
		}
		if(c>0){
			prev->next=new ListNode(1);
			
		}
		return ret;
    }

};

int main(){return 0;}
