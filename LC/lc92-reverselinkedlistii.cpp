#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n){
		if(m==n)return head;
		
		ListNode* t;
		ListNode* mh=new ListNode(0);
		mh->next=head;
		head=mh;
		ListNode* p=head;
		for(int i=0;i<m-1;i++){
			p=p->next;
		}
		t=p;
		p=p->next;
		ListNode* np=p->next;
		ListNode* nnp=np->next;
		for(int i=m;i<n;i++){
			np->next=p;
			p=np;
			np=nnp;
			if(np!=NULL)
			    nnp=np->next;
		}
		t->next->next=np;
		t->next=p;
		return head->next;
	}
};
int main(){
	
	return 0;
}
