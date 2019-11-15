// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};

 void reverse(struct node* head) {
	struct node* prev = NULL, *next, *current=head;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	
	}
	head = prev;
	
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}

	
}
 void recreverse(struct node* head) {
	 if (head == NULL) return;
	 recreverse(head->next);
	 cout << head->data << "->";
 }

int main()
{
	struct node* head = new node();
	head->next = NULL;
	struct node* temp=new node();
	temp->next = NULL;

	int x;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (i==0) {
		/*	head->data = x;
			temp = head;
			temp->next=NULL;
		*/
			struct node* newnode = new node();
			newnode->data = x;
			newnode->next = NULL;
			head->next = newnode;
			head = head->next;
			temp = head;
		}
		else {
			struct node* newnode = new node();
			newnode->data = x;
			newnode->next = NULL;
			temp->next = newnode;
			temp = temp->next;
		}
	}
	struct node* head1 = head;

	while (head1 != NULL) {
		cout << head1->data<<"->";
		head1 = head1->next;
	}
	cout << endl;
	recreverse(head); cout << endl;
	reverse(head);
   return 0;
}

