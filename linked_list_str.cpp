#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
} *head = NULL, *last = NULL;

struct node* memo(int data)
{
    struct node* List = (struct node*)malloc(1 * sizeof(struct node));

    if (List == NULL) {
        cout << "Memory Is Not Found";
        exit(1);
    }

    else {
        List->data = data;
        List->next = NULL;
        return List;
    }
};

void Create(int data) {
    struct node* List = memo(data);

    if (head == NULL) {
        head = List;
        last = List;
    }

    else {
        last->next = List;
        last = List; // last = last->next;
    }
}

void Print() {
    struct node* temp = head;

    while (temp != last) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " -> NULL" << endl;
}

int main() {

//     Create(5);
//     Create(10);
 
    cout << "Original Linked List: ";
    Print();

    return 0;
}
