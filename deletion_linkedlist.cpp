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
void Delete_At_Begining() {

	    if (head == NULL) {
	   		return;
	    }
	    struct node* temp = head;
	    head = head -> next;
	    delete temp;
	    return;
}


void Delete_At_pos(int pos) {

	    if (head == NULL) {
	   		cout<<"linked list is empty";
	    }
	    
	    if(pos == 1){
	    	Delete_At_Begining();
		}
	    
	    struct node* temp = head;
	    struct node* temp2;
	    int c=1;
	    while(c<pos-1){
	    	temp = temp -> next;
	    	c++;
		}
		temp2 = temp -> next;
	    temp -> next =temp -> next -> next;
	    delete temp2;
	    return;
}

void Delete_At_Last() {
    if (head == NULL) {
        return;
    }

    struct node* temp = head;
    while(temp -> next -> next != NULL){
    	temp = temp -> next;
	}
	last = temp;
	delete(temp -> next);
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
	create(5);
	create(10);
	create(15);
	create(80);
	Delete_At_pos(4);
    cout << "After Insert At Begining : ";
    print();

	return 0;
}
