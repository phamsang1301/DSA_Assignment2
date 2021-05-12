
#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *left, *right;
};

typedef TNode *Tree;

void Init(Tree &root){
	root = NULL;
}

TNode *createNode(int x){
	TNode *p = new TNode;
	if(!p) exit(1);
	p->data = x;
	p->left = p->right =  NULL;
	return p;
}


void insertNode(Tree &root, int x){
	if(root){
		if(root->data == x ) return;
		else
			if( x < root->data ) insertNode(root->left, x);
			else insertNode(root->right, x);
	}else{
		TNode *p = createNode(x);
		root = p;
	}
}

void createTree(Tree &root){
	int n;
	cout<< "\nEnter the number of Tree elements: ";
	cin>> n;
	int x;
	while(n--){
		cout<<"\nEnter the next element: ";
		cin>> x;
		insertNode(root, x);
	}
}

void LNR(Tree root){
	TNode *p;
	while( root ){
		if( root->right == NULL ){
			cout<< root->data << " ";
			root = root->left;
		}
		else{
			p = root->right;
			while(p->left && p->left != root ){
				p = p->left;
			}
			if( p->left == NULL ){
				p->left = root;
				root = root->right;
			}
			else{
				p->left = NULL;
				cout<< root->data << " ";
				root = root->left;
			}
		}
	}
	cout<< endl;
}

int main(){
	/* tree: 50
		    /  \
		  30    70
		  /\	 /\
		20  40  60 90
		/
	   10
	*/
	Tree root;
	Init(root);
	createTree(root);
	LNR(root);
	return 0;
}