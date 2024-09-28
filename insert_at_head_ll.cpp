#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
}*head = NULL, *last = NULL;


struct node* memo(int data){
	struct node* List = (struct node*)malloc(1*sizeof(struct node));
	
	if(List == NULL){
		cout<<"memory not found";
		exit(1);
	}
	
	List -> data = data;
	List -> next = NULL;
	return List;
}

void create(int data){
	struct node* List = memo(data);
	
	if(head==NULL){
		head = List;
		last = List;
	}
	else{
		last -> next = List;
		last = last -> next;
	}	
}
void Insert_At_Begining(int data) {

    struct node* link = memo(data);
	    if (head == NULL) {
	   		last = link;
	    }
	    link->next = head;
	    head = link;
	    return;
}

void Insert_At_Last(int data) {
    if (last == NULL) {
        create(data);
        return;
    }

    struct node* newNode = memo(data);
    last->next = newNode;
    last = newNode;
    return;
}

void print(){
	struct node* temp = head;
	while(temp!=last){
		cout<<temp -> data;
		cout<<"\n";
		temp = temp -> next;
	}
	cout << temp->data;
}

int main(){
	   Insert_At_Last(190);
	create(5);
	create(10);
	
	   Insert_At_Begining(10);
//	     Insert_At_Begining(19);
//	     
	     Insert_At_Last(60);
    cout << "After Insert At Begining : ";
    print();

	return 0;
}
