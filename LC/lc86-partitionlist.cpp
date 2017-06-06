#include<iostream>
#include "listnode.h"
using namespace std;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode* p=head;
		ListNode* h1=NULL;
		ListNode* t1=NULL;
		ListNode* h2=NULL;
		ListNode* t2=NULL;
		while(p!=NULL){
			if(p->val<x){
				if(h1==NULL){
					h1=p;
					t1=h1;
				}else{
					t1->next=p;
					t1=t1->next;
				}
			}else if(p->val>=x){
				if(h2==NULL){
					h2=p;
					t2=h2;
				}else{
					t2->next=p;
					t2=t2->next;
				}
			}
			p=p->next;
		}
		if(h2!=NULL) t2->next=NULL;
		if(h1!=NULL){
			t1->next=h2;
			return h1;
		}else{
			return h2;
		}
    }
};
int main(){return 0;}
