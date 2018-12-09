#include <iostream>
#include <time.h>
using namespace std;

bool ex = false;

struct Node{
	int x;
	Node *l, *r;
};

void show(Node *tree, int i){
	i--;
	if (tree!=NULL) {
		i=i+2;
		if (tree->x != 1000) {
			cout << "lvl" << i << " " << tree->x << endl;
		}
		show(tree->l, i);
		show(tree->r, i);
	}
}

void add_node(int x, Node *&MyTree) 
{
	if (NULL == MyTree)             
	{
		MyTree = new Node;          
		MyTree->x = x;              
		MyTree->l = MyTree->r = NULL; 
	}

	if (x < MyTree->x)   
	{
		if (MyTree->l != NULL) add_node(x, MyTree->l); 
		else          
		{
			MyTree->l = new Node;                 
			MyTree->l->l = MyTree->l->r = NULL;   
			MyTree->l->x = x;                     
		}
	}

	if (x > MyTree->x)              
	{
		if (MyTree->r != NULL) add_node(x, MyTree->r); 
		else              
		{
			MyTree->r = new Node;                 
			MyTree->r->l = MyTree->r->r = NULL;   
			MyTree->r->x = x;                     
		}
	}
}

void freemem(Node *tree) {
	if (tree != NULL) {
		freemem(tree->l);
		freemem(tree->r);
		delete tree;
	}
}

void del_two(Node *tree) {
	if (tree->l == NULL && tree->r != NULL) {
		tree->x = tree->r->x;
		del_two(tree->r);
	}
	else if (tree->l != NULL && tree->r == NULL) {
		tree->x = tree->l->x;
		del_two(tree->l);
	}
	else if (tree->l != NULL && tree->r != NULL) {
		tree->x = tree->l->x;
		del_two(tree->l);
	}
	else if (tree->l == NULL && tree->r == NULL) {
		 tree->x = 1000;
	}
}

void del(Node *tree, int x) {
	if (tree != NULL){
		if (tree->x == x) {
			del_two(tree);
		}
		else {
			del(tree->l, x);
			del(tree->r, x);
		}
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int n, x;
	Node *tree = NULL;
	cout << "¬ведите число элементов: "; cin >> n;
	for (int i = 0; i < n; i++) {
		x = rand() % 100;
		add_node(x, tree);
	}
	show(tree, -1);
	cout << "¬ведите число дл€ удалени€: "; cin >> x;
	del(tree, x);
	show(tree, -1);
	freemem(tree);
	//cout << endl << "„исло листьев: " << s << endl;
	system("pause");
}