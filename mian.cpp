#include"fun.cpp"
#include<iostream>
using namespace std;
static  bookiinginformation custom;
int main()
{
		//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[999];//默认最多存储999个航线 全局变量所有函数均可访问
	static FlightTicket DATA[366][999];//存储一年的航班数
	int FlightID_Count = 0;//存储当前航班号个数
	int SearchReasult[999];//用于存储搜索结果
	int SearchCount = 0;//存储搜索结果数
	int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。
	//唯一会改变下标的情况是航班信息的删除







}