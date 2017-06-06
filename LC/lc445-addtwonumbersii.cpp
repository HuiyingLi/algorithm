#include<iostream>
#include<stack>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> n1;
		stack<int> n2;
		while(l1!=NULL&&l2!=NULL){
			if(l1!=NULL){
				n1.push(l1->val);
				l1=l1->next;
			}
			if(l2!=NULL){
				n2.push(l2->val);
				l2=l2->next;
			}
		}
		ListNode* n=new ListNode(0);
		int c=0;
		ListNode* prev=NULL;
		while(!n1.empty()||!n2.empty()){
			n->next=prev;
			int v1=0,v2=0;
			if(!n1.empty())
				v1=n1.top();
			if(!n2.empty())
				v2=n2.top();
			int v=v1+v2+c;
			if(v>=10){
				c=1;
				v%=10;
			}else{c=0;}
			n1.pop();
			n2.pop();
			n->val=v;
			prev=n;
			n=new ListNode(0);
		}
		if(c==1){
			n->val=1;
			n->next=prev;
			return n;
		}else{
			return prev;
		}
    }

};
int main(){return 0;}
