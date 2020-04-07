////b19030334雷尚远[面向旅客的大部分功能]:订票、退票、改签、选座界面及相关限制
////余票查询、航班查询、排序[面向客户]; 旅客订票信誉
//#include<iostream>
//#include <windows.h>
//#include"function.h"
//using namespace std;
//int j = 0;
//#ifdef structdefine
//#define structdefine
//typedef struct flightid //用于表示航班号，航班号只代表航班基本信息。
//{
//	char carrier[4] = { 'x','x','x','x' };						//航空公司，用两个大写字母表示
//	char id[8] = { 'x','x' ,'x' ,'x','x','x' ,'x' ,'x' };								//航班号
//	char flyday[8] = { 'x','x' ,'x' ,'x' ,'x' ,'x' ,'x' ,'x' };							//开航日期，以星期为周期，星期几与数组下标对应，开航为1，不开航为0
//	char departureairport[8] = { 'x','x','x' ,'x' ,'x' ,'x' ,'x' ,'x' };				//出发机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
//	char arrivalairport[8] = { 'x','x' ,'x' ,'x' ,'x' ,'x' ,'x' ,'x' };					//抵达机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
//	int departuretime = 2500;					//出发时刻，四字码
//	int arrivaltime = 2500;					//到达时刻，四字码。eg 1230（12时30分）
//	int traveltimehour = 0;//飞行时间(时)
//	int traveltimeminute = 0;//飞行时间(分)
//	int price = 0;
//	char aircrafttype[4] = { 'x','x' ,'x' };					//飞机型号，三字码。eg 787，350
//	char Class[4] = { 'x','x' ,'x' ,'x' };							//舱位，两舱或三舱，注意结尾的\0。
//}flightid;
//
//typedef struct flightticket //每日机票情况
//{
//	int seat[50][10] = { 0 };
//	int acturaldeparturetime = 2500;
//	int acturalarrivaltime = 2500;
//	int firstclassticketremain = 0;
//	int businessclassticketremain = 0;
//	int economyclassticketremain = 0;
//}flightticket;
//#endif // !struct
//static flightid id[999];//默认最多存储999个航线 全局变量所有函数均可访问
//static flightticket data[366][999];//存储一年的航班数据
//void prebooking();
//void head();
//int datetransfer(int year, int month, int day);//变化为天数
//int weekdaytransfer(int year, int month, int day);//变化为星期数
//int judgeaircraftsize(flightid* id, int n);//判断机型
//int order();//系统选项界面
//void booking(flightticket* data, int n, char Class, char seat[3], int account, int size);
//void refunding(flightticket* data, int n, char seat[3], int account, char Class);
//int changing();
//int searching(flightid* id, flightticket* data, int daycount);
//int main()
//{
//	int x = 0;
//	head();
//	x = order();
//	switch (x)
//	{
//	case 0: head(); break;
//	}
//	return 0;
//}