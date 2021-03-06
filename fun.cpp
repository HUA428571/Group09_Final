#include <iostream>
#include <string.h>
using namespace std;
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
//辅助函数
int WeekDayTransfer(int year, int month, int day)//使用蔡勒公式转换日期与星期
{
	int week = 0;
	int century = year / 100;//注意这边实际上是年份的前两位，不是世纪数
	year = year % 100;//年份的后两位
	if (month == 1 || month == 2)//月份的范围为3-14，所以1月2月变成了13月14月
	{
		month += 12;
		year--;
	}
	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
	week = week % 7;
	return (week >= 0) ? week : (7 + week);
}
int DateTransfer(int year, int month, int day)//返回日期对应天数
{
	int daycount = 0;
	if (year % 4 == 0 && year % 100 != 0)
		daycount++;
	switch (month)
	{
	case 12:
		daycount += 30;
	case 11:
		daycount += 31;
	case 10:
		daycount += 30;
	case 9:
		daycount += 31;
	case 8:
		daycount += 31;
	case 7:
		daycount += 30;
	case 6:
		daycount += 31;
	case 5:
		daycount += 30;
	case 4:
		daycount += 31;
	case 3:
		daycount += 28;
	case 2:
		daycount += 31;
		daycount += day;
		break;
	}
	return daycount;
}
int JudgeAircraftSize(FlightID* ID, int n)//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
{
	if (strcmp(ID[n].AircraftType, "319") && strcmp(ID[n].AircraftType, "320") && strcmp(ID[n].AircraftType, "321") && strcmp(ID[n].AircraftType, "737") && strcmp(ID[n].AircraftType, "738"))
		return 2;
	else
		return 1;
}
int JudgeAircraftSizeSeat(int n)
{
	if (n == 1)
		return 188;
	else
		return 448;
}
int FirstClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//头等舱订票人数
{
	int m, n, f_count = 0;
	if (judge == 1)
	{
		for (m = 0; m < 4; m++)
		{
			for (n = 0; n < 2; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
					f_count++;//有座人数
			}
		}
	}
	else
	{
		for (m = 0; m < 4; m++)
		{
			for (n = 0; n < 3; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
					f_count++;//有座人数
			}
		}
	}
	return f_count;
}
int BusinessClassTicketRemain(FlightTicket* DATA, int daycount, int i)//商务舱人数
{
	int m, n, b_count = 0;
	for (m = 0; m < 6; m++)
	{
		for (n = 0; n < 6; n++)
		{
			if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
				b_count++;//有座人数
		}
	}
	return b_count;
}
int EconomyClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//经济舱订票人数
{
	int m, n, e_count = 0;
	if (judge == 1)
	{
		for (m = 0; m < 6; m++)
		{
			for (n = 0; n < 30; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
					e_count++;//有座人数
			}
		}
	}
	else
	{
		for (m = 0; m < 10; m++)
		{
			for (n = 0; n < 40; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//判断是否满座
					e_count++;//有座人数
			}
		}
	}
	return e_count;
}
int hour(int x)//对飞行时间的分段
{
	return (x / 100);
}
int minut(int x)//对飞行时间的分段
{
	return (x - 100 * (x / 100));
}
int seattranslate(char seat[3], int n)
{
	switch (seat[n])
	{
	case 'A':return 0; break;
	case 'B':return 1; break;
	case 'C':return 2; break;
	case 'D':return 3; break;
	case 'E':return 4; break;
	case 'F':return 5; break;
	case 'G':return 6; break;
	case 'H':return 7; break;
	case 'I':return 8; break;
	case 'J':return 9; break;
	}
}
//文件读取写入函数
int ImportFlightDatabase(FlightID* ID)//用于在开头询问是否要引入现有航线数据库,函数返回读取航班个数
{
	char choice;
	do {
		cout << "导入默认航线数据(1)/上次保存的航线数据(2)/不导入(N)？" << endl;
		cin >> choice;
	} while (choice != '1' && choice != '2' && choice != 'n' && choice != 'N');
	if (choice == '1' || choice == '2')
	{
		FILE* fp;
		if (choice == '1')
		{
			if ((fp = fopen(".\\Default_FlightID_Database_2.txt", "r")) == NULL)
			{
				printf("Fail to open file!\n");
				return 0;
			}
		}
		else
		{
			if ((fp = fopen(".\\FlightID_Database.txt", "r")) == NULL)
			{
				printf("Fail to open file!\n");
				return 0;
			}
		}
		int FlightIDcount = 0;
		char c;
		while (!feof(fp))
		{
			int i = 1;
			while ((c = fgetc(fp)) != ',')//读取班期
			{
				ID[FlightIDcount].FlyDay[i] = c;
				i++;
			}
			i = 0;
			while ((c = fgetc(fp)) != ',')//读取出发机场
			{
				ID[FlightIDcount].DepartureAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].DepartureAirport[i] = '\0';//字符串结尾
			fscanf_s(fp, "%d", &ID[FlightIDcount].DepartureTime);//读取出发时间
			fgetc(fp);
			fscanf_s(fp, "%d", &ID[FlightIDcount].ArrivalTime);//读取到达时间
			i = 0;
			fgetc(fp);
			while ((c = fgetc(fp)) != ',')//读取到达机场
			{
				ID[FlightIDcount].ArrivalAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].ArrivalAirport[i] = '\0';//字符串结尾
			i = 0;
			while (i < 2)//读取航空公司
			{
				c = fgetc(fp);
				ID[FlightIDcount].Carrier[i] = c;
				i++;
			}
			ID[FlightIDcount].Carrier[i] = '\0';//字符串结尾
			i = 0;
			while ((c = fgetc(fp)) != ',')//读取航班号
			{
				ID[FlightIDcount].ID[i] = c;
				i++;
			}
			ID[FlightIDcount].ID[i] = '\0';//字符串结尾
			i = 0;
			while ((c = fgetc(fp)) != ',')//读取机型
			{
				ID[FlightIDcount].AircraftType[i] = c;
				i++;
			}
			ID[FlightIDcount].AircraftType[i] = '\0';//字符串结尾
			i = 0;
			while (((c = fgetc(fp)) != ','))//读取舱位
			{
				ID[FlightIDcount].Class[i] = c;
				i++;
			}
			ID[FlightIDcount].Class[i] = '\0';//字符串结尾
			fscanf_s(fp, "%d", &ID[FlightIDcount].TravelTimeHour);//读取飞行时间
			c = fgetc(fp);//读取冒号
			fscanf_s(fp, "%2d", &ID[FlightIDcount].TravelTimeMinute);
			ID[FlightIDcount].Price = ID[FlightIDcount].TravelTimeHour * 675 + ID[FlightIDcount].TravelTimeMinute * 11.25;
			FlightIDcount++;
			if ((c = fgetc(fp)) == EOF)break;
		}
		fclose(fp);
		cout << "成功导入" << FlightIDcount << "个航线数据！" << endl;
		return FlightIDcount;
	}
	if (choice == 'n' || choice == 'N')
	{
		return 0;
	}
}
int SaveFlightDatabase(FlightID* ID, int IDcount)
{
	char choice;
	FILE* fp;
	do {
		cout << "建立新数据库(A)/在已有数据库上增加(B)" << endl;
		cin >> choice;
	} while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');
	if (choice == 'A' || choice == 'a')
	{
		if ((fp = fopen(".\\FlightID_Database.txt", "w")) == NULL)
		{
			printf("Fail to establish new file!\n");
			return 0;
		}
	}
	else
	{
		if ((fp = fopen(".\\FlightID_Database.txt", "a")) == NULL)
		{
			printf("Fail to open file!\n");
			return 0;
		}
	}
	for (int i = 0; i < IDcount; i++)
	{
		//printf("%c%c%c%c%c%c%c,%s,%04d,%04d,%s,%s%s,%s,%s,%d:%02d\n", ID[i].FlyDay[1], ID[i].FlyDay[2], ID[i].FlyDay[3], ID[i].FlyDay[4], ID[i].FlyDay[5], ID[i].FlyDay[6], ID[i].FlyDay[7], ID[i].DepartureAirport, ID[i].DepartureTime, ID[i].ArrivalTime, ID[i].ArrivalAirport, ID[i].Carrier, ID[i].ID, ID[i].AircraftType, ID[i].Class, ID[i].TravelTimeHour, ID[i].TravelTimeMinute);
		fprintf(fp, "%c%c%c%c%c%c%c,%s,%04d,%04d,%s,%s%s,%s,%s,%d:%02d\n", ID[i].FlyDay[1], ID[i].FlyDay[2], ID[i].FlyDay[3], ID[i].FlyDay[4], ID[i].FlyDay[5], ID[i].FlyDay[6], ID[i].FlyDay[7], ID[i].DepartureAirport, ID[i].DepartureTime, ID[i].ArrivalTime, ID[i].ArrivalAirport, ID[i].Carrier, ID[i].ID, ID[i].AircraftType, ID[i].Class, ID[i].TravelTimeHour, ID[i].TravelTimeMinute);
	}
	cout << "已成功导出" << IDcount << "个航线数据" << endl;
	fclose(fp);
	return IDcount;
}
//打印函数
void PrintFlightTitle()//打印标题栏
{
	printf("编号\t航班号\t\t起飞时间\t起飞机场\t到达机场\t到达时间\t飞行时间\t执飞机型\n");
	return;
}
void PrintFlight(FlightID* ID, int n, int i)//传入数组，数组下标，序号
{
	printf("%d\t%s%s\t\t%04d\t\t%s\t\t%s\t\t%04d\t\t%d小时%02d分钟\t%s\n", i, ID[n].Carrier, ID[n].ID, ID[n].DepartureTime, ID[n].DepartureAirport, ID[n].ArrivalAirport, ID[n].ArrivalTime, ID[n].TravelTimeHour, ID[n].TravelTimeMinute, ID[n].AircraftType);
	return;
}
void PrintFlightTicket()
{
	;
}
int PrintSearch(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount)//展示查询的结果
{
	int SearchReasultChoice;
	if (SearchCount)
	{
		if (SearchCount == 1)
		{
			cout << "成功找到一个航班！" << endl;
			return SearchReasult[0];
		}
		else
		{
			cout << "共为您找到" << SearchCount << "个航班\n" << "请选择您需要查询的航班序号：" << endl;
			for (int i = 0; i <= SearchCount; i++)
			{
				PrintFlight(ID, i, i + 1);
			}
			cin >> SearchReasultChoice;
			return SearchReasult[SearchReasultChoice - 1];
		}
	}
	else
	{
		cout << "没有找到符合条件的航班！" << endl;
		return 999;
	}
}
void PrintInformation(FlightID* ID, int IDcount)
{
	cout << "现有" << IDcount << "个航班数据" << endl;
	PrintFlightTitle();
	for (int i = 0; i < IDcount; i++)
	{
		PrintFlight(ID, i, i + 1);
	}
}
//数据处理函数
int SearchFlightID(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//查找航班号，返回查找到航班个数
{
	//查询航班号分两种情况，第一种纯数字，即没有航空公司代码，这种情况下可能重名；第二种字母加数字，即有航空公司代码，这种情况下航班号唯一。
	SearchCount = 0; //记录搜索到的航班个数,先置零
	if (strcmp(search, "AAAA") < 0)//纯数字
	{
		for (int i = 0; i < IDcount; i++)
		{
			if (!strcmp(search, ID[i].ID))
			{
				SearchReasult[SearchCount] = i;
				SearchCount++;
			}
		}
	}
	else
	{
		for (int i = 0; i < IDcount; i++)
		{
			char a[12];//存储航空公司+航班号的合体
			a[0] = ID[i].Carrier[0];
			a[1] = ID[i].Carrier[1];
			a[2] = '\0';
			strcat(a, ID[i].ID);
			if (!strcmp(search, a))
			{
				SearchReasult[SearchCount] = i;
				SearchCount++;
				return SearchCount;
			}
		}
	}
	return SearchCount;
}
int SearchFlightDepartureAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//查找航起飞地，返回查找到航班个数
{
	SearchCount = 0; //记录搜索到的航班个数,先置零
	for (int i = 0; i < IDcount; i++)
	{
		if (!strcmp(search, ID[i].DepartureAirport))
		{
			SearchReasult[SearchCount] = i;
			SearchCount++;
			return SearchCount;
		}
	}
}
int SearchFlightArrivalAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//查找航起飞地，返回查找到航班个数
{
	SearchCount = 0; //记录搜索到的航班个数,先置零
	for (int i = 0; i < IDcount; i++)
	{
		if (!strcmp(search, ID[i].ArrivalAirport))
		{
			SearchReasult[SearchCount] = i;
			SearchCount++;
			return SearchCount;
		}
	}
}
int NewFlight(FlightID* ID, int& IDcount)
{
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	int SearchReasult[2];
	int SearchCount = 0;
	cout << "请输入完整航班号：";
	cin >> Input;
	if (SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
	{
		cout << "重复的航班号！请重新输入\n";
		return IDcount;
	}
	ID[IDcount].Carrier[0] = Input[0];
	ID[IDcount].Carrier[1] = Input[1];
	ID[IDcount].Carrier[2] = '\0';
	ID[IDcount].ID[0] = Input[2];
	ID[IDcount].ID[1] = Input[3];
	ID[IDcount].ID[2] = Input[4];
	ID[IDcount].ID[3] = Input[5];
	ID[IDcount].ID[4] = Input[6];
	ID[IDcount].ID[5] = Input[7];
	ID[IDcount].ID[6] = Input[8];
	ID[IDcount].ID[7] = Input[9];
	cout << "请输入开航日期：";
	cin >> ID[IDcount].FlyDay;
	cout << "请输入起飞机场：";
	cin >> ID[IDcount].DepartureAirport;
	cout << "请输入降落机场：";
	cin >> ID[IDcount].ArrivalAirport;
	cout << "请输入起飞时间：";
	cin >> ID[IDcount].DepartureTime;
	cout << "请输入降落时间：";
	cin >> ID[IDcount].ArrivalTime;
	cout << "请输入飞行时间（小时）：";
	cin >> ID[IDcount].TravelTimeHour;
	cout << "请输入飞行时间（分钟）：";
	cin >> ID[IDcount].TravelTimeMinute;
	cout << "请输入执飞机型：";
	cin >> ID[IDcount].AircraftType;
	cout << "请输入舱位：";
	cin >> ID[IDcount].Class;
	ID[IDcount].Price = ID[IDcount].TravelTimeHour * 675 + ID[IDcount].TravelTimeMinute * 11.25;
	IDcount++;
	cout << "已成功添加第" << IDcount << "个航线数据" << endl;//这句话可能后期要加到上级菜单函数里头
	return IDcount;
}//可选功能：检验输入数据的正确性，不过这个太繁杂了，先不做。
int SortByDepartureTime(FlightID* ID, int IDcount, int* SortReasult)//冒泡排序法按照时间排序航班；
{
	int i;
	//首先要初始化一下存储排序结果的数组
	for (i = 0; i < IDcount; i++)
	{
		SortReasult[i] = i;
	}
	int i1, i2;
	//先写一个时间由早到晚的
	//谁会时间由晚到早查呢，就不写了。
	for (i1 = 0; i1 < (IDcount - 1); i1++)
	{
		for (i2 = 0; i2 < (IDcount - i1 - 1); i2++)
		{
			if (ID[SortReasult[i2]].DepartureTime > ID[SortReasult[i2 + 1]].DepartureTime)
			{
				int Switch;
				Switch = SortReasult[i2];
				SortReasult[i2] = SortReasult[i2 + 1];
				SortReasult[i2 + 1] = Switch;
			}
		}
	}
	return 0;
}
int DeleteFlight(FlightID* ID, FlightTicket* DATA, int& IDcount, int Delete)
{
	for (int i = Delete; i < IDcount; i++)
	{
		ID[i] = ID[i + 1];
		DATA[i] = DATA[i + 1];
	}
	return IDcount - 1;
}
//订票相关函数
int Searching(FlightID* ID, FlightTicket* DATA, int daycount)
{
	int i, j, a, f, e, b=0, r, count = 0;
	for (i = 0; i < 999; i++)
	{
		if ((strcmp(ID[i].ArrivalAirport, custom.destination) == 0)\
			&& (strcmp(ID[i].DepartureAirport, custom.departure) == 0) && (ID[i].FlyDay[custom.flyday] == '1'))//根据时间起始地判断ID
		{
			a = JudgeAircraftSizeSeat(JudgeAircraftSize(ID, i));//正在筛选的航线的飞机总座位数
			if (JudgeAircraftSize(ID, i) == 1)
			{
				f = FirstClassTicketRemain(DATA, daycount, i, 1);
				e = EconomyClassTicketRemain(DATA, daycount, i, 1);
				r = a - f - e;
			}
			else
			{
				f = FirstClassTicketRemain(DATA, daycount, i, 2);
				b = BusinessClassTicketRemain(DATA, daycount, i);
				e = EconomyClassTicketRemain(DATA, daycount, i, 2);
				r = a - f - e;
			}
			if (r > 0)
			{
				count++;//符合条件的飞机数
				for (j = 0; j < count; j++)
				{
					custom.flynumber[j] = i;//筛选后符合要求的ID号集合
					DATA[(daycount - 2) * 999 + i].FirstClassTicketRemain = f;
					DATA[(daycount - 2) * 999 + i].EconomyClassTicketRemain = e;
					if (JudgeAircraftSize(ID, i) == 2)
						DATA[(daycount - 2) * 999 + i].BusinessClassTicketRemain = b;

				}
			}
		}
	}
	return j;//返回ID数组内符合要求的飞机总数
}
void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size)//n是DATA的数组序号，account为用户账号,size是飞机型号判断结果
{
	int p_num=0, i, a, b, c = 0;
	for (i = 0; i < 3; i++)
	{
		if (seat[i] != '/0')
			p_num++;
	}
	if (size == 1)//小飞机订票
	{
		if (p_num == 1)//单人
		{
			if (Class == 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				for (a = 0; a < 2; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].FirstClassTicketRemain--;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
						break;
					}

				}
			}
			else//经济舱
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				for (a = 2; a < 32; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].EconomyClassTicketRemain--;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
						break;
					}
				}
			}
		}
		else//双人
		{
			if (Class == 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 0; a < 2; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
						break;
					}
					else
					{
						cout << "对不起，已无并排位置，请重新订票";
						break;
					}
				}
			}
			else//双人经济舱
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				for (a = 2; a < 32; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].FirstClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
						break;
					}
				}
			}
		}
	}
	else//大飞机订票
	{
		if (p_num == 1)
		{
			if (Class == 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				for (a = 0; a < 3; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].FirstClassTicketRemain--;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
						break;
					}

				}
			}
			else if (Class == 'b')
			{
				if (p_num > DATA[n].BusinessClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				for (a = 3; a < 9; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].BusinessClassTicketRemain--;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
						break;
					}
				}
			}
			else//经济舱订票
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				for (a = 9; a < 49; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].EconomyClassTicketRemain--;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << "座" << endl;
						break;
					}
				}
			}
		}
		else//双人
		{
			if (Class == 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 0; a < 3; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
						break;
					}
					else
					{
						cout << "对不起，已无并排位置，请重新订票";
						break;
					}
				}
			}
			else if (Class == 'b')
			{
				if (p_num > DATA[n].BusinessClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 3; a < 9; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain - 2;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
						break;
					}
					else
					{
						cout << "对不起，已无并排位置，请重新订票";
						break;
					}
				}
			}
			else//双人经济舱
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "对不起，您的订票信息有误" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 9; a < 50; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
						cout << "您的座位位于" << a + 1 << "排，" << seat[0] << seat[1] << "座" << endl;
						break;
					}
					else
					{
						cout << "对不起，已无并排位置，请重新订票";
						break;
					}

				}
			}
		}
	}
}
void Refunding(FlightTicket* DATA, int n, char seat[3], int account, char Class)//退票
{
	int p_num = 0;
    int i, a, b = 0, c;
	for (i = 0; i < 3; i++)
	{
		if (seat[i] != '/0')
			p_num++;
	}
	if (p_num == 1)
	{
		b = seattranslate(seat, 0);
		for (a = 0; a < 50; a++)
		{
			if (DATA[n].Seat[a][b] == account)
			{
				DATA[n].Seat[a][b] = 0;
				if (Class =='f')
				{
					DATA[n].FirstClassTicketRemain++;
					cout << "您已成功退票" << endl;
				}
				else if (Class =='b')
				{
					DATA[n].BusinessClassTicketRemain++;
					cout << "您已成功退票" << endl;
				}
				else
				{
					DATA[n].EconomyClassTicketRemain++;
					cout << "您已成功退票" << endl;
				}
			}
		}
	}
	else
	{
		b = seattranslate(seat, 0);
		c = seattranslate(seat, 1);
		for (a = 0; a < 50; a++)
		{
			if ((DATA[n].Seat[a][b] == account) && (DATA[n].Seat[a][c] == account))
			{
				DATA[n].Seat[a][b] = 0;
				DATA[n].Seat[a][c] = 0;
				if (Class == 'f')
				{
					DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain + 2;
					cout << "您已成功退票" << endl;
				}
				else if (Class == 'b')
				{
					DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain + 2;
					cout << "您已成功退票" << endl;
				}
				else
				{
					DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain + 2;
					cout << "您已成功退票" << endl;
				}
			}
		}
	}
	return;
}
