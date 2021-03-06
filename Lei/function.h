//#include <iostream>
//#include <string.h>
//using namespace std;
//typedef struct Flightid //用于表示航班号，航班号只代表航班基本信息。
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
//class bookiinginformation
//{
//public:
//	int year, month, day;
//	int primary;
//	char departure[8];
//	char destination[8];
//	int flyday;
//	int flynumber[999];
//};
//static  bookiinginformation custom;
//int JudgeAircraftSize(FlightID* ID, int n)//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
//{
//	if (strcmp(ID[n].AircraftType, "319") && strcmp(ID[n].AircraftType, "320") \
//		&& strcmp(ID[n].AircraftType, "321") && strcmp(ID[n].AircraftType, "737") && strcmp(ID[n].AircraftType, "738"))
//		return 2;
//	else
//		return 1;
//}
//int JudgeAircraftSizeSeat(int n)
//{
//	if (n == 1)
//		return 188;
//	else
//		return 448;
//}
//int FirstClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//头等舱订票人数
//{
//	int m, n, f_count = 0;
//	if (judge == 1)
//	{
//		for (m = 0; m < 4; m++)
//		{
//			for (n = 0; n < 2; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
//					f_count++;//有座人数
//			}
//		}
//	}
//	else
//	{
//		for (m = 0; m < 4; m++)
//		{
//			for (n = 0; n < 3; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
//					f_count++;//有座人数
//			}
//		}
//	}
//	return f_count;
//}
//int BusinessClassTicketRemain(FlightTicket* DATA, int daycount, int i)//商务舱人数
//{
//	int m, n, b_count = 0;
//	for (m = 0; m < 6; m++)
//	{
//		for (n = 0; n < 6; n++)
//		{
//			if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
//				b_count++;//有座人数
//		}
//	}
//	return b_count;
//}
//int EconomyClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//经济舱订票人数
//{
//	int m, n, e_count = 0;
//	if (judge == 1)
//	{
//		for (m = 0; m < 6; m++)
//		{
//			for (n = 0; n < 30; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
//					e_count++;//有座人数
//			}
//		}
//	}
//	else
//	{
//		for (m = 0; m < 10; m++)
//		{
//			for (n = 0; n < 40; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
//					e_count++;//有座人数
//			}
//		}
//	}
//	return e_count;
//}
//
//int WeekDayTransfer(int year, int month, int day)//使用蔡勒公式转换日期与星期
//{
//	int week = 0;
//	int century = year / 100;//注意这边实际上是年份的前两位，不是世纪数
//	year = year % 100;//年份的后两位
//	if (month == 1 || month == 2)//月份的范围为3-14，所以1月2月变成了13月14月
//	{
//		month += 12;
//		year--;
//	}
//	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
//	week = week % 7;
//	return (week >= 0) ? week : (7 + week);
//}
//
//int DateTransfer(int year, int month, int day)//返回日期对应天数
//{
//	int daycount = 0;
//	if (year % 4 == 0 && year % 100 != 0)
//		daycount++;
//	switch (month)
//	{
//	case 12:
//		daycount += 30;
//	case 11:
//		daycount += 31;
//	case 10:
//		daycount += 30;
//	case 9:
//		daycount += 31;
//	case 8:
//		daycount += 31;
//	case 7:
//		daycount += 30;
//	case 6:
//		daycount += 31;
//	case 5:
//		daycount += 30;
//	case 4:
//		daycount += 31;
//	case 3:
//		daycount += 28;
//	case 2:
//		daycount += 31;
//		break;
//	}
//	daycount += day;
//	return daycount;
//}
//void PrintFlightTitle()
//{
//	printf("编号\t航班号\t\t起飞时间\t起飞机场\t到达机场\t到达时间\t飞行时间\t执飞机型\t经济舱价格\t剩余座位数\n");
//	return;
//}
//int hour(int x)//对飞行时间的分段
//{
//	return (x / 100);
//}
//int minut(int x)//对飞行时间的分段
//{
//	return (x - 100 * (x / 100));
//}
//int seattranslate(char seat[3], int n)
//{
//	switch (seat[n])
//	{
//	case 'A':return 0; break;
//	case 'B':return 1; break;
//	case 'C':return 2; break;
//	case 'D':return 3; break;
//	case 'E':return 4; break;
//	case 'F':return 5; break;
//	case 'G':return 6; break;
//	case 'H':return 7; break;
//	case 'I':return 8; break;
//	case 'J':return 9; break;
//	}
//}
//void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size)//n是DATA的数组序号，account为用户账号,size是飞机型号判断结果
//{
//	int p_num, i, a, b, c = 0;
//	for (i = 0; i < 3; i++)
//	{
//		if (seat[i] != '/0')
//			p_num++;
//	}
//	if (size == 1)//小飞机订票
//	{
//		if (p_num == 1)//单人
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 0; a < 2; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].FirstClassTicketRemain--;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
//						break;
//					}
//
//				}
//			}
//			else//经济舱
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 2; a < 32; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].EconomyClassTicketRemain--;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
//						break;
//					}
//				}
//			}
//		}
//		else//双人
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 0; a < 2; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
//						break;
//					}
//					else
//					{
//						cout << "对不起，已无并排位置，请重新订票";
//						braek;
//					}
//				}
//			}
//			else//双人经济舱
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 2; a < 32; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].FirstClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
//						break;
//					}
//				}
//			}
//		}
//	}
//	else//大飞机订票
//	{
//		if (p_num == 1)
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 0; a < 3; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].FirstClassTicketRemain--;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
//						break;
//					}
//
//				}
//			}
//			else if (Class = 'b')
//			{
//				if (p_num > DATA[n].BusinessClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 3; a < 9; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].BusinessClassTicketRemain--;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
//						break;
//					}
//				}
//			}
//			else//经济舱订票
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 9; a < 49; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].EconomyClassTicketRemain--;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
//						break;
//					}
//				}
//			}
//		}
//		else//双人
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 0; a < 3; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
//						break;
//					}
//					else
//					{
//						cout << "对不起，已无并排位置，请重新订票";
//						braek;
//					}
//				}
//			}
//			else if (Class = 'b')
//			{
//				if (p_num > DATA[n].BusinessClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 3; a < 9; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain - 2;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
//						break;
//					}
//					else
//					{
//						cout << "对不起，已无并排位置，请重新订票";
//						braek;
//					}
//				}
//			}
//			else//双人经济舱
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "对不起，您的订票信息有误" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 9; a < 50; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
//						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
//						break;
//					}
//					else
//					{
//						cout << "对不起，已无并排位置，请重新订票";
//						braek;
//					}
//
//				}
//			}
//		}
//	}
//}
//
//void Refunding(FlightTicket* DATA, int n, char seat[3], int account, char Class)
//{
//	int p_num, i, a, b = 0;
//	for (i = 0; i < 3; i++)
//	{
//		if (seat[i] != '/0')
//			p_num++;
//	}
//	if (p_num == 1)
//	{
//		b = seattranslate(seat, 0);
//		for (a = 0; a < 50; a++)
//		{
//			if (DATA[n].Seat[a][b] == account)
//			{
//				DATA[n].Seat[a][b] = 0;
//				if (Class = 'f')
//				{
//					DATA[n].FirstClassTicketRemain++;
//					cout << "您已成功退票" << endl;
//				}
//				else if (Class = 'b')
//				{
//					DATA[n].BusinessClassTicketRemain++;
//					cout << "您已成功退票" << endl;
//				}
//				else
//				{
//					DATA[n].EconomyClassTicketRemain++;
//					cout << "您已成功退票" << endl;
//				}
//			}
//		}
//	}
//	else
//	{
//		b = seattranslate(seat, 0);
//		c = seattranslate(seat, 1);
//		for (a = 0; a < 50; a++)
//		{
//			if ((DATA[n].Seat[a][b] == account) && (DATA[n].Seat[a][c] == account))
//			{
//				DATA[n].Seat[a][b] = 0;
//				DATA[n].Seat[a][c] = 0;
//				if (Class = 'f')
//				{
//					DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain + 2;
//					cout << "您已成功退票" << endl;
//				}
//				else if (Class = 'b')
//				{
//					DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain + 2;
//					cout << "您已成功退票" << endl;
//				}
//				else
//				{
//					DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain + 2;
//					cout << "您已成功退票" << endl;
//				}
//			}
//		}
//	}
//	return 0;
//}
//void Changing()
//{
//
//}