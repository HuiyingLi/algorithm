#include<iostream>
#include"listnode.h"

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow, *fast;
        ListNode* mh=new ListNode(0);
		mh->next=head;
        slow=mh;
        fast=mh;
		bool start=true;
        while(true){
            slow=slow->next;
            fast=fast->next;
            if(fast==NULL){
                return false;
            }
            if(!start&&fast==slow)
                return true;
			start=false;
            fast=fast->next;
            if(fast==NULL)
                return false;
            if(fast==slow)
                return true;
        }
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
//	h1->next=h1;
//	h2->next=h3;
//	h3->next=h4;
//	h4->next=h5;
	
	Solution s;
	cout<<s.hasCycle(h1);
	return 0;
}
