#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first=NULL;
Node *second=NULL;
Node *third=NULL;

void create(int A[], int n, Node **p){
    Node *temp, *last;
    *p = new Node;
    (*p)->data = A[0];
    (*p)->next=NULL;
    last = (*p);
    for(int i=1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Dispaly(Node *p){
    while(p){
        cout<<p->data<<endl;
        p = p->next;
    }
}

void merge(Node *p, Node *q) {
    Node *last;
    if(p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }else{
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q) {
        if(p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    if(q) last->next = q;
}


int main()
{
    int A[] = {12,34,36,45,234};
    int B[] = {15,22,45,53,300};
    create(A,5,&first);
    create(B,5,&second);
    merge(first, second);
    Dispaly(third);
}
