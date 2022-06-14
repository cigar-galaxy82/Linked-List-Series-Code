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

void insert(Node *p, int pos,int n) {
    Node *t = new Node;
    if(pos<0 && pos>lenght(first)) {

    }
    if(pos == 0) {
       t->data = n;
       if(first == NULL) {
        first = t;
        first->next = first;
       }else {
          while(p->next != first) p = p->next;
          p->next = t;
          t->next = first;
          first = t; 
       }
    }else{
        for(int i=0;i<pos-1;i++) {
            p = p->next;
        }
        t->data = n;
        t->next = p->next;
        p->next = t;
    }
}


int main()
{
    int A[] = {6,2,10,40,1};
    create(A,5);
    insert(first, 2 ,10);
    display(first);
}
