#include<iostream>
#include "listnode.h"

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		if(head==NULL) return head;
		ListNode* mh=new ListNode(0);
		mh->next=head;
		ListNode* p=head;
		ListNode* np=p->next;
		while(np!=NULL){
			ListNode* nt=mh->next;
			ListNode* t=mh;
			while(t!=np&&nt->val<np->val){
				nt=nt->next;
				t=t->next;
			}
			if(p==t){
				p=p->next;
				np=np->next;
			}else{
				p->next=np->next;
				t->next=np;
				np->next=nt;
				np=p->next;
			}
		}
		return mh->next;
    }
};
int main(){return 0;}
