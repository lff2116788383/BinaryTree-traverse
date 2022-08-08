#pragma once
#include "b_tree.h"
class Fourth
{
private:
	//���ṹ
	BinaryTree<bool> tree_fouth;//�ڵ�id��0~4
	TreeNode<bool> node[5];

private:
	vector<Player>m_round_card_recorder;
	USHORT m_main_color;
	vector<USHORT>m_handcardsVec;

	USHORT m_round_color;
	USHORT m_round_max_card;

	vector<USHORT> mainColorCardVec, roundColorCardVec;//�����������ɫ�� �غϻ�ɫ��

	//�غ�����ƣ�����ɫ>�غϻ�ɫ>������ɫ
	USHORT roundMaxCard;
	int m_seatid;
public:
	Fourth(/* args */);
	~Fourth();

	void Reset();
	bool Init(vector<Player>& roundCardRecorder, USHORT& mainColor, vector<USHORT>& handCardsVec, int seatId);

private:
	map<USHORT, vector<USHORT> > GetHandCardsRecorder();
	
};


#include<iostream>
//#include"b_tree.h"

#include "fouth.h"
using namespace std;
int main()
{
	vector<Player>m_round_card_recorder;
	m_round_card_recorder.push_back(Player(0x010a, 4));
	m_round_card_recorder.push_back(Player(0x0102, 1));
	m_round_card_recorder.push_back(Player(0x0104, 2));

	vector<USHORT> m_handcardsVec; //������13������
	m_handcardsVec.push_back(0x0105);
	USHORT m_main_color = 0x0200;           //����ɫ
	int seatid = 3;
	Fourth fourth;
	fourth.Reset();
	fourth.Init(m_round_card_recorder, m_main_color, m_handcardsVec, seatid);
	USHORT card = fourth.Play();
	cout << "card:" << hex << card << endl;


	system("pause");
	return 0;
}