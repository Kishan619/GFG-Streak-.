class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node *ptr1 = head, *ptr2 = ptr1->next;
        ptr1->next = NULL;
        ptr1->prev = ptr2;
        while(ptr2 != NULL){
            ptr2->prev = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
            
        }
        return ptr1;
    }
};
