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

	{//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度

		return (sizeof(array) / sizeof(array[0]));

	}

	int Step;
	void Getjudgments(bool* judgement, int len);

protected:
    USHORT sColor;
    USHORT sValue;
};



bool CompLess(USHORT card1, USHORT card2);


//STL中的map容器屏蔽掉自动排序（逆序结果）
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
//		if (disableCompare)				//第二次判断 disableCompare为true返回false
//		{
//			disableCompare = false;
//			return false;
//		}
//		else                                           //第一次判断 disableCompare为false返回true
//		{
//			disableCompare = true;
//			return true;
//		}
//	}
//};

// // T如果不是基本类型，需要==运算符重载
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

//     //经测试此方法数据超过5个就不行了
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

//禁用map默认排序
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