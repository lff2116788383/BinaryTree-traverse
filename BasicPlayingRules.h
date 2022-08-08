#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <string>
using namespace std;
#define USHORT unsigned short
#define PokerColor(x)  x&0xFF00
#define PokerValue(x)  x&0x00FF



// struct Player
// {
// 	USHORT m_card;
// 	int m_seatid;
// 	Player(USHORT card, int seatid) : m_card(card),m_seatid(seatid)
// 	{
// 	}
// };

class Player
{
public:
	USHORT m_card;
	int m_seatid;
	Player(USHORT card, int seatid) : m_card(card),m_seatid(seatid)
	{
	}
	~Player()
	{
		m_card = 0;
		m_seatid = 0;
	}
};

class BasicPlayingRules
{
public:
	BasicPlayingRules();
	~BasicPlayingRules();


	template <class T>

	int getArrayLen(T& array)

	{//ʹ��ģ�嶨��һ ������getArrayLen,�ú�������������array�ĳ���

		return (sizeof(array) / sizeof(array[0]));

	}

	int Step;
	void Getjudgments(bool* judgement, int len);

protected:
    USHORT sColor;
    USHORT sValue;
};



bool CompLess(USHORT card1, USHORT card2);


//STL�е�map�������ε��Զ�������������
//template<class T>
//struct DisableCompare : public std::binary_function<T, T, bool>
//{
//	bool operator()(T lhs, T rhs) const
//	{
//		static bool disableCompare = false;
//		if (lhs == rhs)
//		{
//			return false;
//		}
//		if (disableCompare)				//�ڶ����ж� disableCompareΪtrue����false
//		{
//			disableCompare = false;
//			return false;
//		}
//		else                                           //��һ���ж� disableCompareΪfalse����true
//		{
//			disableCompare = true;
//			return true;
//		}
//	}
//};

// // T������ǻ������ͣ���Ҫ==���������
// template <typename T>
// struct DisableCompare : public std::binary_function<T, T, bool>
// {
//     // bool operator()(T lhs, T rhs) const
//     // {
//     //     static T l = lhs;
//     //     static T r = rhs;

//     //     if (lhs == rhs)
//     //     {
//     //         return false;
//     //     }

//     //     if (l == rhs && r == lhs)
//     //     {
//     //         l = lhs;
//     //         r = rhs;
//     //         return false;
//     //     }

//     //     l = lhs;
//     //     r = rhs;
//     //     return true;
//     // }

//     //�����Դ˷������ݳ���5���Ͳ�����
//     // bool operator()(T lhs, T rhs) const
//     // {
//     //     static bool s_bFlag = false;
//     //     if (lhs == rhs)
//     //     {
//     //         return false;
//     //     }
//     //     if (s_bFlag)
//     //     {
//     //         s_bFlag = false;
//     //     }
//     //     else
//     //     {
//     //         s_bFlag = true;
//     //     }
//     //     return s_bFlag;
//     // }
// };

//����mapĬ������
template<class T>
struct DisableCompare : public std::binary_function<T, T, bool>
{
   bool operator()(T lhs, T rhs)const
   {
       static bool disblecompare = false;
       if (lhs == rhs)
       {
           return false;
       }
       if (disblecompare)
       {
           disblecompare = false;
           return false;
       }
       else
       {
           disblecompare = true;
           return true;
       }
   }
};









string printfCard(USHORT card);