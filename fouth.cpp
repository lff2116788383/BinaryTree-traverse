#include "fouth.h"

Fourth::Fourth()
{
}

Fourth::~Fourth()
{
}

void Fourth::Reset()
{
	tree_fouth.Reset();
}

bool Fourth::Init(vector<Player>& roundCardRecorder, USHORT& mainColor, vector<USHORT>& handCardsVec, int seatId)
{


	{
		USHORT roundColor = 0;
		if (!roundCardRecorder.empty())
		{
			roundColor = roundCardRecorder.front().m_card & sColor;

			for (vector<Player>::iterator it = roundCardRecorder.begin(); it != roundCardRecorder.end(); it++)
			{
				USHORT card = (*it).m_card;
				if ((card & sColor) == mainColor)
				{
					mainColorCardVec.push_back(card);
				}
				if ((card & sColor) == roundColor)
				{
					roundColorCardVec.push_back(card);
				}

			}



			if (!mainColorCardVec.empty())
			{
				//将取出的主花色牌按点数从小到大排序 
				sort(mainColorCardVec.begin(), mainColorCardVec.end(), CompLess);
				roundMaxCard = mainColorCardVec.back();
			}
			else
			{
				//将取出的回合花色按点数从小到大排序
				sort(roundColorCardVec.begin(), roundColorCardVec.end(), CompLess);
				roundMaxCard = roundColorCardVec.back();
			}


			{
				m_round_card_recorder = roundCardRecorder;
				m_main_color = mainColor;
				m_handcardsVec = handCardsVec;
				m_seatid = seatId;

				m_round_color = roundColor;
				m_round_max_card = roundMaxCard;
			}


		}

		



		//找出手牌中的主花色牌和回合花色牌
		mainColorCardVec.clear();
		roundColorCardVec.clear();
		for (size_t i = 0; i < handCardsVec.size(); i++)
		{
			if ((handCardsVec[i] & sColor) == mainColor)
			{
				mainColorCardVec.push_back(handCardsVec[i]);
			}

			if ((handCardsVec[i] & sColor) == roundColor)
			{
				roundColorCardVec.push_back(handCardsVec[i]);
			}

		}
		cout << "成员数据初始化完成" << endl;
	}



	for (size_t i = 0; i < 5; i++)
	{
		node[i].id = i;
	}
	node[0].desc = "是否有该回合花色";
	node[1].desc = "当前最大牌是否为队友";
	node[2].desc = "可出的牌是否有大于本回合已出牌中最大牌的牌";
	node[3].desc = "当前最大牌是否为队友";
	node[4].desc = "可出的牌是否有大于本回合已出牌中最大牌的牌";

	node[0].data = 0;
	node[1].data = 1;
	node[2].data = 1;
	node[3].data = 1;
	node[4].data = 1;


	//设置节点关系
	tree_fouth.root = &node[0];

	node[0].leftChild = &node[1];
	node[0].rightChild = &node[3];

	node[1].rightChild = &node[2];

	node[3].rightChild = &node[4];



	tree_fouth.PlayOrder();

	return true;
}

map<USHORT, vector<USHORT>> Fourth::GetHandCardsRecorder()
{
	//遍历历史已出牌，计算不同花色牌的数量 找出数量最少的花色（非主花色）
	map<USHORT, vector<USHORT> > cardColorRecorder; //一个花色对应一个存放该花色牌的容器
	vector<USHORT> colorVec;					   //四个花色
	colorVec.push_back(0x0100);
	colorVec.push_back(0x0200);
	colorVec.push_back(0x0300);
	colorVec.push_back(0x0400);

	vector<USHORT> colorCardVec[4]; //存放四个不同花色牌的容器

	//将所有手牌按花色分类
	for (size_t i = 0; i < m_handcardsVec.size(); i++)
	{
		for (size_t j = 0; j < colorVec.size(); j++)
		{
			if ((m_handcardsVec[i] & sColor) == colorVec[j])
			{
				colorCardVec[j].push_back(m_handcardsVec[i]);
			}
		}
	}
	//记录手牌不同花色所有牌
	for (size_t i = 0; i < colorVec.size(); i++)
	{
		cardColorRecorder.insert(pair<USHORT, vector<USHORT> >(colorVec[i], colorCardVec[i]));
	}

	return cardColorRecorder;
}
