#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include <map>
using namespace std;
#define USHORT unsigned short
#define sColor 0xFF00
#define sValue 0x00FF

bool CompLess(USHORT card1, USHORT card2)
{
	if ((card1 & sValue) != (card2 & sValue)) //先按值排序
		return (card1 & sValue) < (card2 & sValue);
	else//若值相等，则按花色排序
		return (card1 & sColor) < (card2 & sColor);
}


class Player
{
public:
	USHORT m_card;
	int m_seatid;
	Player(USHORT card, int seatid) : m_card(card), m_seatid(seatid)
	{
	}
	~Player()
	{
		m_card = 0;
		m_seatid = 0;
	}
};


//声明二叉树模板类
template <class T> class BinaryTree;

//节点类
template<class T>
class TreeNode
{
public:
	TreeNode()
	{
		Reset();
	}
	void Reset()
	{
		data = NULL;
		leftChild = NULL;
		rightChild = NULL;
		id = 0;
		desc = "";
	}
public:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;

	int id;
	string desc;
	

	TreeNode operator=(TreeNode& node)
	{
		data = node.data;
		leftChild = node.leftChild;
		rightChild = node.rightChild;
		id = node.id;
		desc = node.desc;

		return *this;
	};

	
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
	{
		Reset();
	}
	
	//中序遍历
	void InOrder();
	//递归
	void InOrder(TreeNode<T>* currentNode);


	//前序遍历
	void PreOrder();
	void PreOrder(TreeNode<T>* currentNode);

	//非递归中序遍历
	void InOrder1();
	void InOrder2(TreeNode<T>* currentNode);

	//后序遍历
	void PostOrder();
	void PostOrder(TreeNode<T>* currentNode);
	//层序遍历
	void LevelOrder();
	//显示节点data值
	void Display(TreeNode<T>* currentNode);


	void PlayOrder();

	void Reset()
	{
		root = NULL;
		nodeVec.clear();//调用析构函数
	}
public:
	TreeNode<T>* root;

	vector<TreeNode<T>*> nodeVec;//存放所有正确节点
};

template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

//显示当前节点data
template<class T>
void BinaryTree<T>::Display(TreeNode<T>* currentNode)
{
	cout << currentNode->data;
}

//递归实现中序遍历
template<class T>
void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		InOrder(currentNode->leftChild);
		Display(currentNode);
		InOrder(currentNode->rightChild);
	}
}

//层序遍历
template<class T>
void BinaryTree<T>::LevelOrder()
{
	//队列queue实现层序遍历
	queue<TreeNode<T>*> queue_now;
	TreeNode<T>* currentNode = root;
	while (true)
	{
		Display(currentNode);
		if (currentNode->leftChild)
			queue_now.push(currentNode->leftChild);
		if (currentNode->rightChild)
			queue_now.push(currentNode->rightChild);
		if (queue_now.empty())
			break;
		currentNode = queue_now.front();
		queue_now.pop();
	}
}

//前序遍历（无参）
template<class T>
inline void BinaryTree<T>::PlayOrder()
{
	//栈实现前序遍历
	stack<TreeNode<T>*> node_stack;       //用来暂存节点的栈
	TreeNode<T>* currentNode = root;
	while (currentNode != nullptr) {

		nodeVec.push_back(currentNode);
		if (currentNode->data)
		{
			cout << "NodeID:" << currentNode->id << " Yes" << " " << currentNode->desc << endl;




			currentNode = currentNode->leftChild;                // 我们继续向左子树前进
		}
		else
		{

			cout << "ID:" << currentNode->id << " No" << " " << currentNode->desc << endl;

			//该节点压入栈中。
			currentNode = currentNode->rightChild;                // 我们继续向左子树前进

		}
	}
}

//前序遍历（无参）
template<class T>
void BinaryTree<T>::PreOrder() {

	//栈实现前序遍历
	stack<TreeNode<T>*> node_stack;       //用来暂存节点的栈
	TreeNode<T>* currentNode = root;
	while (currentNode != nullptr || !node_stack.empty()) {
		if (currentNode != nullptr) {                     //若当前的节点非空，
			cout << currentNode->data << " ";         //则输出该节点的值
			node_stack.push(currentNode);                 //该节点压入栈中。
			currentNode = currentNode->leftChild;                // 我们继续向左子树前进
		}
		else {
			currentNode = node_stack.top();
			node_stack.pop();
			currentNode = currentNode->rightChild;
		}

	}

}

//前序遍历（带参）
template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode) {

	//栈实现前序遍历
	stack<TreeNode<T>*> node_stack;       //用来暂存节点的栈
	while (currentNode != nullptr || !node_stack.empty()) {
		if (currentNode != nullptr) {                     //若当前的节点非空，
			cout << currentNode->data << " ";         //则输出该节点的值
			node_stack.push(currentNode);                 //该节点压入栈中。
			currentNode = currentNode->leftChild;                // 我们继续向左子树前进
		}
		else {
			currentNode = node_stack.top();
			node_stack.pop();
			currentNode = currentNode->rightChild;
		}

	}

}


template<class T>
void BinaryTree<T>::InOrder1() {

	//非递归实现中序遍历
	stack<TreeNode<T>*> stack_node;
	TreeNode<T>* currentNode = root;
	while (currentNode != nullptr || !stack_node.empty()) {
		if (currentNode != nullptr) {
			stack_node.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = stack_node.top();
			cout << currentNode->data << " ";
			stack_node.pop();
			currentNode = currentNode->rightChild;
		}
	}
}

template<class T>
void BinaryTree<T>::InOrder2(TreeNode<T>* currentNode) {

	//非递归实现中序遍历
	stack<TreeNode<T>*> stack_node;
	while (currentNode != nullptr || !stack_node.empty()) {
		if (currentNode != nullptr) {
			stack_node.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = stack_node.top();
			cout << currentNode->data << " ";
			stack_node.pop();
			currentNode = currentNode->rightChild;
		}
	}
}



//后序遍历（无参）
template<class T>
inline void BinaryTree<T>::PostOrder()
{
	

	stack<TreeNode<T>*> stack_node;
	TreeNode<T>* currentNode = root;
	TreeNode<T>* lastvisit = currentNode;
	while (currentNode != nullptr || !stack_node.empty()) {
		if (currentNode != nullptr) {
			stack_node.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = stack_node.top();
			if (currentNode->rightChild == nullptr || currentNode->rightChild == lastvisit) {

				cout << currentNode->data << " ";
				stack_node.pop();
				lastvisit = currentNode;
				currentNode = nullptr;
			}
			else {
				currentNode = currentNode->rightChild;
			}

		}
	}
}

//后序遍历（带参）
template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode) {
	stack<TreeNode<T>*> stack_node;
	TreeNode<T>* lastvisit = currentNode;
	while (currentNode != nullptr || !stack_node.empty()) {
		if (currentNode != nullptr) {
			stack_node.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = stack_node.top();
			if (currentNode->rightChild == nullptr || currentNode->rightChild == lastvisit) {

				//cout << currentNode->data << " ";
				Display(currentNode);
				stack_node.pop();
				lastvisit = currentNode;
				currentNode = nullptr;
			}
			else {
				currentNode = currentNode->rightChild;
			}

		}
	}

}





//
//struct BinaryTreeNode {
//	int val;
//	BinaryTreeNode* leftchild;
//	BinaryTreeNode* rightchild;
//	BinaryTreeNode(int const& _val, BinaryTreeNode* _leftchild = NULL, BinaryTreeNode* _rightchild = NULL) :
//		val(_val), leftchild(_leftchild), rightchild(_rightchild) {}
//
//
//};
//
//void pre_traversal(BinaryTreeNode* root) {
//	stack<BinaryTreeNode*> node_stack;       //用来暂存节点的栈
//	while (root != nullptr || !node_stack.empty()) {
//		if (root != nullptr) {                     //若当前的节点非空，
//			cout << root->val << " ";         //则输出该节点的值
//			node_stack.push(root);                 //该节点压入栈中。
//			root = root->leftchild;                // 我们继续向左子树前进
//		}
//		else {
//			root = node_stack.top();
//			node_stack.pop();
//			root = root->rightchild;
//		}
//
//	}
//
//}
//
//void in_traversal(BinaryTreeNode* root) {
//	stack<BinaryTreeNode*> stack_node;
//	while (root != nullptr || !stack_node.empty()) {
//		if (root != nullptr) {
//			stack_node.push(root);
//			root = root->leftchild;
//		}
//		else {
//			root = stack_node.top();
//			cout << root->val << " ";
//			stack_node.pop();
//			root = root->rightchild;
//		}
//	}
//}
//
//
//void post_traversal(BinaryTreeNode* root) {
//	stack<BinaryTreeNode*> stack_node;
//	BinaryTreeNode* lastvisit = root;
//	while (root != nullptr || !stack_node.empty()) {
//		if (root != nullptr) {
//			stack_node.push(root);
//			root = root->leftchild;
//		}
//		else {
//			root = stack_node.top();
//			if (root->rightchild == nullptr || root->rightchild == lastvisit) {
//
//				cout << root->val << " ";
//				stack_node.pop();
//				lastvisit = root;
//				root = nullptr;
//			}
//			else {
//				root = root->rightchild;
//			}
//
//		}
//	}
//
//}