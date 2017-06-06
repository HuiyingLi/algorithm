#include<iostream>
#include"listnode.h"
using namespace std;

class Solution{
public:
	void reorderList(ListNode* head){
		ListNode* mh=new ListNode(0);
		mh->next=head;
		ListNode *fast=mh, *slow=mh;
		while(true){
			if(fast->next!=NULL){
				fast=fast->next;
			}else{
				break;
			}
			if(fast->next!=NULL){
				fast=fast->next;
				slow=slow->next;
			}else{
				break;
			}
		}//now fast at the end node, slow at the mid/mid-1 node
		//reverse the second half
		ListNode* p=slow->next;
		ListNode* np=p->next;
		ListNode* nnp=NULL;
		if(np!=NULL)
			nnp=np->next;
		while(np!=NULL){
			np->next=p;
			p=np;
			np=nnp;
			if(nnp!=NULL)
				nnp=nnp->next;
		}
		if(slow->next!=NULL)
		slow->next->next=NULL;
		slow->next=p;
		//merge
		ListNode* p1=mh->next;
		ListNode* p2=slow->next;
		ListNode* tp1;
		ListNode* tp2;
		ListNode* end=slow->next;
		while(p1!=end){
			tp1=p1->next;
			tp2=p2->next;
			p1->next=p2;
			if(p1!=slow)
				p2->next=tp1;
			p1=tp1;
			p2=tp2;
		}
	}
};
int main(){
	ListNode* h=new ListNode(1);
	ListNode* h2=new ListNode(2);
	ListNode* h3=new ListNode(3);
	ListNode* h4=new ListNode(4);
	ListNode* h5=new ListNode(5);
	h->next=h2;
	h2->next=h3;
	h3->next=h4;
	h4->next=h5;
	Solution s;
	s.reorderList(h);
	while(h!=NULL){
		cout<<h->val<<" ";
		h=h->next;
	}
	return 0;}
