#include<iostream>
#include"listnode.h"
using namespace std;
class Solution{
public:
/*	
	ListNode* partition(ListNode* mh, ListNode* right){
		ListNode* pvt=mh->next;
		ListNode* h=mh;
		ListNode* rt=pvt;
		ListNode* p=pvt->next;//
		while(p!=NULL&&p!=right){
			if(p->val<pvt->val){
				h->next=p;
				rt->next=p->next;
				p->next=pvt;
				h=h->next;
				p=rt->next;
			}else{
				rt=rt->next;
				p=p->next;
			}
		}
		
		return pvt;
	}
	void qsort(ListNode* mh, ListNode* right){
		if(mh->next==right)
			return;
		ListNode* pvt=partition(mh, right);
		qsort(mh, pvt);
		qsort(pvt,right);	
	}
*/
	ListNode* sortList(ListNode* head){
		if(head==NULL||head->next==NULL)
			return head;
		ListNode* mh=new ListNode(0);
		mh->next=head;
		mergesort(mh,NULL);	
		return mh->next;
	}

	ListNode* merge(ListNode* s1, ListNode* e1, ListNode* s2, ListNode* e2){
		if(s2->next==NULL)
			return e1;
		if(s1->next==NULL)
			return e2;
		ListNode* np1=s1->next, *np2=s2->next;
		ListNode* mh=new ListNode(0);
		ListNode* mp=mh;
		ListNode* p1=np1, *p2=np2;
		e1->next=NULL;
		ListNode* f=e2->next;
		e2->next=NULL;
		while(np1!=NULL&&np2!=NULL){
			if(np1->val<np2->val){
				ListNode* o1=np1;
				while(np1!=NULL&&np1->val<np2->val){
					p1=np1;
					np1=np1->next;
				}
				//from o1 to p1, append to tail of new list
				mp->next=o1;
				mp=p1;
			}else{
				ListNode* o2=np2;
				while(np2!=NULL&&np2->val<=np1->val){
					p2=np2;
					np2=np2->next;
				}
				mp->next=o2;
				mp=p2;
			}
		}
		ListNode* ret;
		if(np1==NULL){
			mp->next=np2;
			e2->next=f;
			ret=e2;
		} 
		if(np2==NULL){
			mp->next=np1;
			e1->next=f;
			ret=e1;
		}
		s1->next=mh->next;
		return ret;
	}
	ListNode* mergesort(ListNode* mh, ListNode* right){
		if(mh->next==right)
			return right;
		if(mh->next==NULL)
			return NULL;
		//slow-fast pointer to get the middle
		ListNode* slow=mh, *fast=mh, *bfast;
		while(true){
			slow=slow->next;
			bfast=fast;
			fast=fast->next;
			if(fast==right){
				break;
			}
			bfast=fast;
			fast=fast->next;
			if(fast==right)
				break;
		}
		if(right==NULL)
			right=bfast;
		ListNode* mh1=new ListNode(0);
		ListNode* tmp=slow->next;
		ListNode* tail=mergesort(mh,slow);
		mh1->next=tmp;
		ListNode* nr=mergesort(mh1,right);
		ListNode* ret= merge(mh,tail,mh1,nr);
		return ret;
	}
};
int main(){
	ListNode* h1=new ListNode(3);
	ListNode* h2=new ListNode(9);
	ListNode* h3=new ListNode(6);
	ListNode* h4=new ListNode(2);
	ListNode* h5=new ListNode(5);
	ListNode* h6=new ListNode(7);
	ListNode* h7=new ListNode(4);
	ListNode* h8=new ListNode(8);
	ListNode* h9=new ListNode(1);
	h1->next=h2;
/*	h2->next=h3;
	h3->next=h4;
	h4->next=h5;
	h5->next=h6;
	h6->next=h7;
	h7->next=h8;
	h8->next=h9;
*/	Solution s;
	s.sortList(h1);
return 0;}

