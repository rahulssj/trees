// trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;

};

struct node* newnode(int data) {
	struct node* n = new node();
	n->data = data;
	n->left = n->right = NULL;
	return n;
}
struct node* insert(struct node* root, int data) {
	if (root == NULL) {
		return  newnode(data);
	
	}
	else {
		if (root->data >= data) {

			root->left = insert(root->left, data);
		}
		else {
			root->right = insert(root->right, data);

		}

	}	return root;
}

void inorder(struct node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void bfs(struct node* root) {
	queue <struct node*> q;
	q.push(root);
	while (!q.empty()) {
	
		struct node* temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left) { q.push(temp->left); }
		if (temp->right) { q.push(temp->right); } }
	
	

}
int maxdepth(struct node* root) {
	if (root == NULL) return 0;
	int l = maxdepth(root->left);
	int r = maxdepth(root->right);
	return (l > r ? l : r) + 1;
}
int main()
{ 
	struct node* root=NULL;
	int x;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		root = insert(root, x);
	}
	cout << root->data << endl;
	inorder(root);
	cout << endl;
	bfs(root);
	cout << endl;
	cout<<maxdepth(root);
	return 0;


}

