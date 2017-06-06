class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p=new ListNode(0);
        ListNode* r=p;
        p->next=head;
        ListNode* np, *nnp;
        while(p->next!=NULL&&p->next->next!=NULL){
            np=p->next;
            nnp=np->next;
            p->next=nnp;
            np->next=nnp->next;
            nnp->next=np;
            p=np;
        }
        return r->next;
    }
};
