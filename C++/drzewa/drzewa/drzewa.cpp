// drzewa.cpp: Określa punkt wejścia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

void add(int a, node* &adress)//dodaje elementy
{

	if (adress == 0)
	{
		adress = new node;
		adress->data = a;
		adress->left = NULL;
		adress->right = NULL;
	}
	else
	{
		node* pomoc;
		if (a<adress->data&&adress->left != NULL)
		{
			add(a, adress->left);
		}
		if (a<adress->data&&adress->left == NULL)
		{
			pomoc = new node;
			adress->left = pomoc;
			pomoc->data = a;
			pomoc->left = NULL;
			pomoc->right = NULL;
		}

		if (a>= adress->data &&adress->right != NULL)
		{
			add(a, adress->right);

		}
		if (a >= adress->data && adress->right == NULL)
		{
			pomoc = new node;
			adress->right = pomoc;
			pomoc->data = a;
			pomoc->left = NULL;
			pomoc->right = NULL;
		}
	}
}

void addd(int a, node* &adress)//dodaje elementy
{

	if (adress == 0)
	{
		adress = new node;
		adress->data = a;
		adress->left = NULL;
		adress->right = NULL;
	}
	else
	{
		node* pomoc;
		if (a>adress->data&&adress->left != NULL)
		{
			add(a, adress->left);
		}
		if (a>adress->data&&adress->left == NULL)
		{
			pomoc = new node;
			adress->left = pomoc;
			pomoc->data = a;
			pomoc->left = NULL;
			pomoc->right = NULL;
		}

		if (a <= adress->data &&adress->right != NULL)
		{
			add(a, adress->right);

		}
		if (a <= adress->data && adress->right == NULL)
		{
			pomoc = new node;
			adress->right = pomoc;
			pomoc->data = a;
			pomoc->left = NULL;
			pomoc->right = NULL;
		}
	}
}
void nodes(node* tree, int &a)//wywołuje funkcje liczącą
{
	if (tree->left != NULL)
	{
		nodes(tree->left, a);
	}
	if (tree->right != NULL)
	{
		nodes(tree->right, a);
	}
	a++;
}

int numberofnodes(node* tree)//zwraca ilosc wierzchołków w drzewie
{
	int  number = 0;
	nodes(tree, number);
	return number;
}

void leafs(node* tree, int &a)//wywołuje funkcje liczącą
{
	if (tree->left != NULL)
	{
		leafs(tree->left, a);
	}
	if (tree->right != NULL)
	{
		leafs(tree->right, a);
	}
    if(tree->right == NULL && tree->left == NULL)
	a++;
}

int numberofleafs(node* tree) //zwraca ilosc wierzchołków w drzewie
{
	int  number = 0;
	leafs(tree, number);
	return number;
}

void heightoftree(node* tree, int level, int &maxheight)
{
	if (maxheight < level)
	{
		maxheight = level;
	}
	if (tree->left != NULL)
	{
		heightoftree(tree->left, level + 1, maxheight);
	}
	if (tree->right != NULL)
	{
		heightoftree(tree->right, level + 1, maxheight);
	}
}

int height(node* tree)//wyznacza wysokosc drzewa
{
	int height = 0;
	int level = 0;
	heightoftree(tree, level, height);
	return height;
}

void BSTtreecheck(node* tree, bool &ret, int data,int leftorright)//jesli lewo leftorright (-1), prawo (1) zaczynasz od korzenia =0
{
	if (tree->left != 0)
	{
		if (leftorright == 0)
		{
			if (tree->left->data > tree->data)
			{
				ret = 0;
				return;
			}
		}
		if (leftorright == 1)
		{
			if (tree->left->data > tree->data || tree->left->data < data)
			{
				ret = 0;
			}
		}
		BSTtreecheck(tree->left, ret, tree->data, -1);
	
	}
	if (tree->right != 0)
	{
		if (leftorright == 0)
		{
			if (tree->right->data < tree->data)
			{
				ret = 0;
				return;
			}
		}

		if (leftorright == -1)
		{
			if (tree->right->data < tree->data || tree->right->data>data)
			{
				ret = 0;
				return;
			}
			BSTtreecheck(tree->right, ret, tree->data, 1);
		}
	}
		
		
	
	
}
bool BSTtree(node*tree)
{
	bool ret = 1;
	BSTtreecheck(tree, ret, tree->data, 0);

	return ret;
}


int main()
{
	int a;
	node* root=0;
	add(5, root);
	add(2, root);
	add(10, root);
	add(7, root);
	add(13, root);
	add(13, root);
	add(1, root);
	add(15, root);
	add(15, root);
	add(17, root);
	add(13, root);
	add(4, root);
	//cout << numberofnodes(root) << endl;//wyswietla liczbe wierzchołków
	//cout << numberofleafs(root) << endl;
	//cout << height(root) << endl;
	cout << BSTtree(root) << endl;
	cin>> a;

    return 0;
}

