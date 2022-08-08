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
				//��ȡ��������ɫ�ư�������С�������� 
				sort(mainColorCardVec.begin(), mainColorCardVec.end(), CompLess);
				roundMaxCard = mainColorCardVec.back();
			}
			else
			{
				//��ȡ���Ļغϻ�ɫ��������С��������
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

		



		//�ҳ������е�����ɫ�ƺͻغϻ�ɫ��
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
		cout << "��Ա���ݳ�ʼ�����" << endl;
	}



	for (size_t i = 0; i < 5; i++)
	{
		node[i].id = i;
	}
	node[0].desc = "�Ƿ��иûغϻ�ɫ";
	node[1].desc = "��ǰ������Ƿ�Ϊ����";
	node[2].desc = "�ɳ������Ƿ��д��ڱ��غ��ѳ���������Ƶ���";
	node[3].desc = "��ǰ������Ƿ�Ϊ����";
	node[4].desc = "�ɳ������Ƿ��д��ڱ��غ��ѳ���������Ƶ���";

	node[0].data = 0;
	node[1].data = 1;
	node[2].data = 1;
	node[3].data = 1;
	node[4].data = 1;


	//���ýڵ��ϵ
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
	//������ʷ�ѳ��ƣ����㲻ͬ��ɫ�Ƶ����� �ҳ��������ٵĻ�ɫ��������ɫ��
	map<USHORT, vector<USHORT> > cardColorRecorder; //һ����ɫ��Ӧһ����Ÿû�ɫ�Ƶ�����
	vector<USHORT> colorVec;					   //�ĸ���ɫ
	colorVec.push_back(0x0100);
	colorVec.push_back(0x0200);
	colorVec.push_back(0x0300);
	colorVec.push_back(0x0400);

	vector<USHORT> colorCardVec[4]; //����ĸ���ͬ��ɫ�Ƶ�����

	//���������ư���ɫ����
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
	//��¼���Ʋ�ͬ��ɫ������
	for (size_t i = 0; i < colorVec.size(); i++)
	{
		cardColorRecorder.insert(pair<USHORT, vector<USHORT> >(colorVec[i], colorCardVec[i]));
	}

	return cardColorRecorder;
}
