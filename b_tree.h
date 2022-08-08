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
	if ((card1 & sValue) != (card2 & sValue)) //�Ȱ�ֵ����
		return (card1 & sValue) < (card2 & sValue);
	else//��ֵ��ȣ��򰴻�ɫ����
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


//����������ģ����
template <class T> class BinaryTree;

//�ڵ���
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
	
	//�������
	void InOrder();
	//�ݹ�
	void InOrder(TreeNode<T>* currentNode);


	//ǰ�����
	void PreOrder();
	void PreOrder(TreeNode<T>* currentNode);

	//�ǵݹ��������
	void InOrder1();
	void InOrder2(TreeNode<T>* currentNode);

	//�������
	void PostOrder();
	void PostOrder(TreeNode<T>* currentNode);
	//�������
	void LevelOrder();
	//��ʾ�ڵ�dataֵ
	void Display(TreeNode<T>* currentNode);


	void PlayOrder();

	void Reset()
	{
		root = NULL;
		nodeVec.clear();//������������
	}
public:
	TreeNode<T>* root;

	vector<TreeNode<T>*> nodeVec;//���������ȷ�ڵ�
};

template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

//��ʾ��ǰ�ڵ�data
template<class T>
void BinaryTree<T>::Display(TreeNode<T>* currentNode)
{
	cout << currentNode->data;
}

//�ݹ�ʵ���������
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

//�������
template<class T>
void BinaryTree<T>::LevelOrder()
{
	//����queueʵ�ֲ������
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

//ǰ��������޲Σ�
template<class T>
inline void BinaryTree<T>::PlayOrder()
{
	//ջʵ��ǰ�����
	stack<TreeNode<T>*> node_stack;       //�����ݴ�ڵ��ջ
	TreeNode<T>* currentNode = root;
	while (currentNode != nullptr) {

		nodeVec.push_back(currentNode);
		if (currentNode->data)
		{
			cout << "NodeID:" << currentNode->id << " Yes" << " " << currentNode->desc << endl;




			currentNode = currentNode->leftChild;                // ���Ǽ�����������ǰ��
		}
		else
		{

			cout << "ID:" << currentNode->id << " No" << " " << currentNode->desc << endl;

			//�ýڵ�ѹ��ջ�С�
			currentNode = currentNode->rightChild;                // ���Ǽ�����������ǰ��

		}
	}
}

//ǰ��������޲Σ�
template<class T>
void BinaryTree<T>::PreOrder() {

	//ջʵ��ǰ�����
	stack<TreeNode<T>*> node_stack;       //�����ݴ�ڵ��ջ
	TreeNode<T>* currentNode = root;
	while (currentNode != nullptr || !node_stack.empty()) {
		if (currentNode != nullptr) {                     //����ǰ�Ľڵ�ǿգ�
			cout << currentNode->data << " ";         //������ýڵ��ֵ
			node_stack.push(currentNode);                 //�ýڵ�ѹ��ջ�С�
			currentNode = currentNode->leftChild;                // ���Ǽ�����������ǰ��
		}
		else {
			currentNode = node_stack.top();
			node_stack.pop();
			currentNode = currentNode->rightChild;
		}

	}

}

//ǰ����������Σ�
template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode) {

	//ջʵ��ǰ�����
	stack<TreeNode<T>*> node_stack;       //�����ݴ�ڵ��ջ
	while (currentNode != nullptr || !node_stack.empty()) {
		if (currentNode != nullptr) {                     //����ǰ�Ľڵ�ǿգ�
			cout << currentNode->data << " ";         //������ýڵ��ֵ
			node_stack.push(currentNode);                 //�ýڵ�ѹ��ջ�С�
			currentNode = currentNode->leftChild;                // ���Ǽ�����������ǰ��
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

	//�ǵݹ�ʵ���������
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

	//�ǵݹ�ʵ���������
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



//����������޲Σ�
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

//������������Σ�
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
//	stack<BinaryTreeNode*> node_stack;       //�����ݴ�ڵ��ջ
//	while (root != nullptr || !node_stack.empty()) {
//		if (root != nullptr) {                     //����ǰ�Ľڵ�ǿգ�
//			cout << root->val << " ";         //������ýڵ��ֵ
//			node_stack.push(root);                 //�ýڵ�ѹ��ջ�С�
//			root = root->leftchild;                // ���Ǽ�����������ǰ��
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