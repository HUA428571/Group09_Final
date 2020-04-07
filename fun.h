#include <iostream>
#include <string.h>
#ifndef STRUCT
#define STRUCT
typedef struct FlightID //用于表示航班号，航班号只代表航班基本信息。
{
	char Carrier[4] = { 'X','X','X','X' };						//航空公司，用两个大写字母表示
	char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//航班号
	char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//开航日期，以星期为周期，星期几与数组下标对应，开航为1，不开航为0
	char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//出发机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//抵达机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	int DepartureTime = 2500;					//出发时刻，四字码
	int ArrivalTime = 2500;					//到达时刻，四字码。eg 1230（12时30分）
	int TravelTimeHour = 0;//飞行时间(时)
	int TravelTimeMinute = 0;//飞行时间(分)
	int Price = 0;
	char AircraftType[4] = { 'X','X' ,'X' };					//飞机型号，三字码。eg 787，350
	char Class[4] = { 'X','X' ,'X' ,'X' };							//舱位，两舱或三舱，注意结尾的\0。
}FlightID;
typedef struct FlightTicket //每日机票情况
{
	int Seat[50][10] = { 0 };
	int FirstClassTicketRemain = 0;
	int BusinessClassTicketRemain = 0;
	int EconomyClassTicketRemain = 0;
	int ActuralDepartureTime = 2500;
	int ActuralArrivalTime = 2500;
}FlightTicket;
typedef struct bookiinginformation
{
	int year, month, day;
	int primary;
	char departure[8];
	char destination[8];
	int flyday;
	int flynumber[999];
}bookiinginformation;
extern bookiinginformation custom;
#endif // !STRUCT

using namespace std;
int WeekDayTransfer(int year, int month, int day);//使用蔡勒公式转换日期与星期
int DateTransfer(int year, int month, int day);//返回日期对应天数
int JudgeAircraftSize(FlightID* ID, int n);//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
int JudgeAircraftSizeSeat(int n);
int FirstClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge);//头等舱订票人数
int EconomyClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge);//经济舱订票人数
int hour(int x);//对飞行时间的分段
int minut(int x);//对飞行时间的分段
int seattranslate(char seat[3], int n);
//文件读取写入函数
int ImportFlightDatabase(FlightID* ID);//用于在开头询问是否要引入现有航线数据库,函数返回读取航班个数
int SaveFlightDatabase(FlightID* ID, int IDcount);
//打印函数
void PrintFlightTitle();//打印标题栏
void PrintFlight(FlightID* ID, int n, int i);//传入数组，数组下标，序号
void PrintFlightTicket();
int PrintSearch(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount);//展示查询的结果
void PrintInformation(FlightID* ID, int IDcount);
//数据处理函数
int SearchFlightID(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount);//查找航班号，返回查找到航班个数
int SearchFlightDepartureAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount);//查找航起飞地，返回查找到航班个数
int SearchFlightArrivalAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount);//查找航起飞地，返回查找到航班个数
int NewFlight(FlightID* ID, int& IDcount);
int SortByDepartureTime(FlightID* ID, int IDcount, int* SortReasult);//冒泡排序法按照时间排序航班；
int DeleteFlight(FlightID* ID, FlightTicket* DATA, int& IDcount, int Delete);
//订票相关函数
int Searching(FlightID* ID, FlightTicket* DATA, int daycount);
void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size);//n是DATA的数组序号，account为用户账号,size是飞机型号判断结果
void Refunding(FlightTicket* DATA, int n, char seat[3], int account, char Class);