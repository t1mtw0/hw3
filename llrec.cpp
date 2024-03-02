#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == NULL) {
        smaller = larger = NULL;
        return;
    }
    if (head->val <= pivot) {
        smaller = head;
        head = head->next;
        llpivot(head, smaller->next, larger, pivot);
    } else {
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }
}
