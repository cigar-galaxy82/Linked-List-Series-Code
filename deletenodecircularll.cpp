#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *first;

void create(int A[],int n) {
    Node *temp, *last;
    first = new Node;
    first->data= A[0];
    first->next = first;
    last = first;

    for(int i=1;i<n;i++) {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void display(Node *p) {
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p != first);
}

int lenght(Node *p) {
    int len =0;
    do{
        len++;
        p = p->next;
    }while(p!=first);

    return len;
}

void deleteNode(int  pos) {
    Node *p, *q;
    if(pos == 1) {
        p = first;
        q = NULL;
        do {
            p = p->next;
        }
        while(p != first);

        if(p == first) {
            delete first;
            first = NULL;
        }else {
            p->next = first->next;
            delete first;
            first = p->next;
        }
    }else {
        p = first;
        q = NULL;
        for(int i=0;i<pos-2;i++) {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
    }
}

int main()
{
    int A[] = {6,2,10,40,1};
    create(A,5);
    display(first);
    deleteNode(4);
    display(first);
}
