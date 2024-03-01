#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    if (head->val <= pivot) {
        Node* nextNode = head->next;
        head->next = nullptr;
        llpivot(nextNode, smaller, larger, pivot);
        if (smaller == nullptr) {
            smaller = head;
        } else {
            head->next = smaller;
            smaller = head;
        }
    } else {
        Node* nextNode = head->next;
        head->next = nullptr;
        llpivot(nextNode, smaller, larger, pivot);
        if (larger == nullptr) {
            larger = head;
        } else {
            head->next = larger;
            larger = head;
        }
    }

    head = nullptr;
}