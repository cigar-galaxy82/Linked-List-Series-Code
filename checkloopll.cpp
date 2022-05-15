#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first=NULL;

void create(int A[], int n){
    Node *temp, *last;
    first = new Node;
    first->data = A[0];
    first->next=NULL;
    last = first;
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int isLoop(Node *f) {
    Node *p, *q;
    p = q = f;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next  : q;
    }while(p && q && p!=q);
    if( p == q) return 1;
    else return 0;
}

int main()
{
    int A[] = {2,4,6,8,10,9};
    create(A,6);
    //Node *t1, *t2;
    //t1 = first->next;
    //t2 = first->next->next->next->next->next;
    //t2->next = t1;
    cout<<isLoop(first);
}
