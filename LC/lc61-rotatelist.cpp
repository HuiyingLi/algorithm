#include<iostream>

using namespace std;


struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
		int len=0;
		ListNode* p=head;
		if(!head)
		    return head;
		while(p->next!=NULL){
			p=p->next;
			len++;
		}
		len++;
		p->next=head;
		k%=len;
		p=head;
		cout<<len<<" "<<k<<endl;
		for(int i=0;i<len-k-1;i++){
			p=p->next;
		}
		head=p->next;
		p->next=NULL;
		return head;
    }

};
int main(){return 0;}
