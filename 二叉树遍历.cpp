#pragma once
#include<iostream>
//#include"b_tree.h"

#include "fouth.h"
using namespace std;
int main()
{
	/*BinaryTree<char> tree_now;
	TreeNode<char> add, sub, mul, div, A, B, C, D, E;
	add.data = '+';
	sub.data = '-';
	mul.data = '*';
	div.data = '/';
	A.data = 'A';
	B.data = 'B';
	C.data = 'C';
	D.data = 'D';
	E.data = 'E';

	tree_now.root = &add;
	add.leftChild = &sub;
	add.rightChild = &E;
	sub.leftChild = &mul;
	sub.rightChild = &D;
	mul.leftChild = &div;
	mul.rightChild = &C;
	div.leftChild = &A;
	div.rightChild = &B;

	cout << "递归中序遍历" << endl;
	tree_now.InOrder1();
	cout << endl;

	cout << "前序遍历" << endl;
	tree_now.PreOrder();
	cout << endl;

	cout << "后序遍历" << endl;
	tree_now.PostOrder();
	cout << endl;
	tree_now.LevelOrder();*/




	BinaryTree<bool> tree_test;
	TreeNode<bool> a,b,c,d,e;
	a.data = 0;
	a.id = 1;
	a.desc = "是否有该回合花色";

	b.data = 1;
	b.id = 2;
	b.desc = "当前最大牌是否为队友";
	
	c = b;
	c.id = 3;

	/*c.data = 0;
	c.id = 3;
	c.desc = "当前最大牌是否为队友";*/
	

	d.data = 0;
	d.id = 4;
	d.desc = "可出的牌是否有大于本回合已出牌中最大牌的牌";
	

	e.data = 0;
	e.id = 5;
	e.desc = "可出的牌是否有大于本回合已出牌中最大牌的牌";
	

	tree_test.root = &a;
	a.leftChild = &b;
	a.rightChild = &c;

	b.rightChild = &d;

	c.rightChild = &e;


	cout << "前序遍历" << endl;
	tree_test.PlayOrder();
	cout << endl;



	cout << "final id:" << tree_test.nodeVec.back()->id << endl;

	//BinaryTreeNode* A = new BinaryTreeNode(1);
	//BinaryTreeNode* B = new BinaryTreeNode(2);
	//BinaryTreeNode* C = new BinaryTreeNode(4);
	//BinaryTreeNode* D = new BinaryTreeNode(7);
	//BinaryTreeNode* E = new BinaryTreeNode(3);
	//BinaryTreeNode* F = new BinaryTreeNode(5);
	//BinaryTreeNode* G = new BinaryTreeNode(6);
	//BinaryTreeNode* H = new BinaryTreeNode(8);
	//A->leftchild = B;
	//A->rightchild = E;
	//B->leftchild = C;
	//C->rightchild = D;
	//E->leftchild = F;
	//E->rightchild = G;
	//G->leftchild = H;
	//std::cout << "Pre order traversal:" << std::endl;
	//pre_traversal(A);
	//std::cout << std::endl << "In order traversal:" << std::endl;
	//in_traversal(A);
	//std::cout << std::endl << "Post order traversal:" << std::endl;
	//post_traversal(A);


	//四号位二叉树
	//BinaryTree<bool> tree_fouth;//节点id从0~4

	//TreeNode<bool> node[5];
	//for (size_t i = 0; i < 5; i++)
	//{
	//	node[i].id = i;
	//}
	//node[0].desc = "是否有该回合花色";
	//node[1].desc = "当前最大牌是否为队友";
	//node[2].desc = "可出的牌是否有大于本回合已出牌中最大牌的牌";
	//node[3].desc = "当前最大牌是否为队友";
	//node[4].desc = "可出的牌是否有大于本回合已出牌中最大牌的牌";

	//node[0].data = 1;
	//node[1].data = 1;
	//node[2].data = 1;
	//node[3].data = 1;
	//node[4].data = 1;


	////设置节点关系
	//tree_fouth.root = &node[0];

	//node[0].leftChild = &node[1];
	//node[0].rightChild = &node[3];

	//node[1].rightChild = &node[2];

	//node[3].rightChild = &node[4];



	//tree_fouth.PlayOrder();

	Fourth fourth;

	//fourth.Init();

	system("pause");
	return 0;
}