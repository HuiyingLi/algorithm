#include<iostream>
#include"listnode.h"

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if(head==NULL) return head;
		ListNode* ot=new ListNode(0);	
		ListNode* eh=NULL;
		ListNode* p=NULL, *np=NULL, *nnp=NULL;
		p=head;
		if(p->next!=NULL){
			eh=p->next;
			np=p->next;
			nnp=np->next;
		}
		int i=1;
		while(p->next!=NULL){
			np=p->next;
			nnp=np->next;
			p->next=nnp;
			if(i%2==1){
				if(p->next==NULL)
				ot=p;
				else
				ot=p->next;
			}
			p=np;
			
			i++;
		}
		ot->next=eh;
		return head;
    }
};
int main(){
	Solution s;
	ListNode* n1=new ListNode(1);
	ListNode* n2=new ListNode(2);
	ListNode* n3=new ListNode(3);
	ListNode* n4=new ListNode(4);
	ListNode* n5=new ListNode(5);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	s.oddEvenList(n1);
return 0;}
