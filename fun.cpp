#include <iostream>
#include <string.h>
using namespace std;
typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�������������Ϣ��
{
	char Carrier[4] = { 'X','X','X','X' };						//���չ�˾����������д��ĸ��ʾ
	char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//�����
	char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ1��������Ϊ0
	char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
	char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
	int DepartureTime = 2500;					//����ʱ�̣�������
	int ArrivalTime = 2500;					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
	int TravelTimeHour = 0;//����ʱ��(ʱ)
	int TravelTimeMinute = 0;//����ʱ��(��)
	int Price = 0;
	char AircraftType[4] = { 'X','X' ,'X' };					//�ɻ��ͺţ������롣eg 787��350
	char Class[4] = { 'X','X' ,'X' ,'X' };							//��λ�����ջ����գ�ע���β��\0��
}FlightID;
typedef struct FlightTicket //ÿ�ջ�Ʊ���
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
//��������
int WeekDayTransfer(int year, int month, int day)//ʹ�ò��չ�ʽת������������
{
	int week = 0;
	int century = year / 100;//ע�����ʵ��������ݵ�ǰ��λ������������
	year = year % 100;//��ݵĺ���λ
	if (month == 1 || month == 2)//�·ݵķ�ΧΪ3-14������1��2�±����13��14��
	{
		month += 12;
		year--;
	}
	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
	week = week % 7;
	return (week >= 0) ? week : (7 + week);
}
int DateTransfer(int year, int month, int day)//�������ڶ�Ӧ����
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
int JudgeAircraftSize(FlightID* ID, int n)//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
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
int FirstClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//ͷ�Ȳն�Ʊ����
{
	int m, n, f_count = 0;
	if (judge == 1)
	{
		for (m = 0; m < 4; m++)
		{
			for (n = 0; n < 2; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
					f_count++;//��������
			}
		}
	}
	else
	{
		for (m = 0; m < 4; m++)
		{
			for (n = 0; n < 3; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
					f_count++;//��������
			}
		}
	}
	return f_count;
}
int BusinessClassTicketRemain(FlightTicket* DATA, int daycount, int i)//���������
{
	int m, n, b_count = 0;
	for (m = 0; m < 6; m++)
	{
		for (n = 0; n < 6; n++)
		{
			if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
				b_count++;//��������
		}
	}
	return b_count;
}
int EconomyClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//���òն�Ʊ����
{
	int m, n, e_count = 0;
	if (judge == 1)
	{
		for (m = 0; m < 6; m++)
		{
			for (n = 0; n < 30; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
					e_count++;//��������
			}
		}
	}
	else
	{
		for (m = 0; m < 10; m++)
		{
			for (n = 0; n < 40; n++)
			{
				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
					e_count++;//��������
			}
		}
	}
	return e_count;
}
int hour(int x)//�Է���ʱ��ķֶ�
{
	return (x / 100);
}
int minut(int x)//�Է���ʱ��ķֶ�
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
//�ļ���ȡд�뺯��
int ImportFlightDatabase(FlightID* ID)//�����ڿ�ͷѯ���Ƿ�Ҫ�������к������ݿ�,�������ض�ȡ�������
{
	char choice;
	do {
		cout << "����Ĭ�Ϻ�������(1)/�ϴα���ĺ�������(2)/������(N)��" << endl;
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
			while ((c = fgetc(fp)) != ',')//��ȡ����
			{
				ID[FlightIDcount].FlyDay[i] = c;
				i++;
			}
			i = 0;
			while ((c = fgetc(fp)) != ',')//��ȡ��������
			{
				ID[FlightIDcount].DepartureAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].DepartureAirport[i] = '\0';//�ַ�����β
			fscanf_s(fp, "%d", &ID[FlightIDcount].DepartureTime);//��ȡ����ʱ��
			fgetc(fp);
			fscanf_s(fp, "%d", &ID[FlightIDcount].ArrivalTime);//��ȡ����ʱ��
			i = 0;
			fgetc(fp);
			while ((c = fgetc(fp)) != ',')//��ȡ�������
			{
				ID[FlightIDcount].ArrivalAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].ArrivalAirport[i] = '\0';//�ַ�����β
			i = 0;
			while (i < 2)//��ȡ���չ�˾
			{
				c = fgetc(fp);
				ID[FlightIDcount].Carrier[i] = c;
				i++;
			}
			ID[FlightIDcount].Carrier[i] = '\0';//�ַ�����β
			i = 0;
			while ((c = fgetc(fp)) != ',')//��ȡ�����
			{
				ID[FlightIDcount].ID[i] = c;
				i++;
			}
			ID[FlightIDcount].ID[i] = '\0';//�ַ�����β
			i = 0;
			while ((c = fgetc(fp)) != ',')//��ȡ����
			{
				ID[FlightIDcount].AircraftType[i] = c;
				i++;
			}
			ID[FlightIDcount].AircraftType[i] = '\0';//�ַ�����β
			i = 0;
			while (((c = fgetc(fp)) != ','))//��ȡ��λ
			{
				ID[FlightIDcount].Class[i] = c;
				i++;
			}
			ID[FlightIDcount].Class[i] = '\0';//�ַ�����β
			fscanf_s(fp, "%d", &ID[FlightIDcount].TravelTimeHour);//��ȡ����ʱ��
			c = fgetc(fp);//��ȡð��
			fscanf_s(fp, "%2d", &ID[FlightIDcount].TravelTimeMinute);
			ID[FlightIDcount].Price = ID[FlightIDcount].TravelTimeHour * 675 + ID[FlightIDcount].TravelTimeMinute * 11.25;
			FlightIDcount++;
			if ((c = fgetc(fp)) == EOF)break;
		}
		fclose(fp);
		cout << "�ɹ�����" << FlightIDcount << "���������ݣ�" << endl;
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
		cout << "���������ݿ�(A)/���������ݿ�������(B)" << endl;
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
	cout << "�ѳɹ�����" << IDcount << "����������" << endl;
	fclose(fp);
	return IDcount;
}
//��ӡ����
void PrintFlightTitle()//��ӡ������
{
	printf("���\t�����\t\t���ʱ��\t��ɻ���\t�������\t����ʱ��\t����ʱ��\tִ�ɻ���\n");
	return;
}
void PrintFlight(FlightID* ID, int n, int i)//�������飬�����±꣬���
{
	printf("%d\t%s%s\t\t%04d\t\t%s\t\t%s\t\t%04d\t\t%dСʱ%02d����\t%s\n", i, ID[n].Carrier, ID[n].ID, ID[n].DepartureTime, ID[n].DepartureAirport, ID[n].ArrivalAirport, ID[n].ArrivalTime, ID[n].TravelTimeHour, ID[n].TravelTimeMinute, ID[n].AircraftType);
	return;
}
void PrintFlightTicket()
{
	;
}
int PrintSearch(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount)//չʾ��ѯ�Ľ��
{
	int SearchReasultChoice;
	if (SearchCount)
	{
		if (SearchCount == 1)
		{
			cout << "�ɹ��ҵ�һ�����࣡" << endl;
			return SearchReasult[0];
		}
		else
		{
			cout << "��Ϊ���ҵ�" << SearchCount << "������\n" << "��ѡ������Ҫ��ѯ�ĺ�����ţ�" << endl;
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
		cout << "û���ҵ����������ĺ��࣡" << endl;
		return 999;
	}
}
void PrintInformation(FlightID* ID, int IDcount)
{
	cout << "����" << IDcount << "����������" << endl;
	PrintFlightTitle();
	for (int i = 0; i < IDcount; i++)
	{
		PrintFlight(ID, i, i + 1);
	}
}
//���ݴ�������
int SearchFlightID(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ţ����ز��ҵ��������
{
	//��ѯ����ŷ������������һ�ִ����֣���û�к��չ�˾���룬��������¿����������ڶ�����ĸ�����֣����к��չ�˾���룬��������º����Ψһ��
	SearchCount = 0; //��¼�������ĺ������,������
	if (strcmp(search, "AAAA") < 0)//������
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
			char a[12];//�洢���չ�˾+����ŵĺ���
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
int SearchFlightDepartureAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ɵأ����ز��ҵ��������
{
	SearchCount = 0; //��¼�������ĺ������,������
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
int SearchFlightArrivalAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ɵأ����ز��ҵ��������
{
	SearchCount = 0; //��¼�������ĺ������,������
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
	cout << "��������������ţ�";
	cin >> Input;
	if (SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
	{
		cout << "�ظ��ĺ���ţ�����������\n";
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
	cout << "�����뿪�����ڣ�";
	cin >> ID[IDcount].FlyDay;
	cout << "��������ɻ�����";
	cin >> ID[IDcount].DepartureAirport;
	cout << "�����뽵�������";
	cin >> ID[IDcount].ArrivalAirport;
	cout << "���������ʱ�䣺";
	cin >> ID[IDcount].DepartureTime;
	cout << "�����뽵��ʱ�䣺";
	cin >> ID[IDcount].ArrivalTime;
	cout << "���������ʱ�䣨Сʱ����";
	cin >> ID[IDcount].TravelTimeHour;
	cout << "���������ʱ�䣨���ӣ���";
	cin >> ID[IDcount].TravelTimeMinute;
	cout << "������ִ�ɻ��ͣ�";
	cin >> ID[IDcount].AircraftType;
	cout << "�������λ��";
	cin >> ID[IDcount].Class;
	ID[IDcount].Price = ID[IDcount].TravelTimeHour * 675 + ID[IDcount].TravelTimeMinute * 11.25;
	IDcount++;
	cout << "�ѳɹ����ӵ�" << IDcount << "����������" << endl;//��仰���ܺ���Ҫ�ӵ��ϼ��˵�������ͷ
	return IDcount;
}//��ѡ���ܣ������������ݵ���ȷ�ԣ��������̫�����ˣ��Ȳ�����
int SortByDepartureTime(FlightID* ID, int IDcount, int* SortReasult)//ð�����򷨰���ʱ�����򺽰ࣻ
{
	int i;
	//����Ҫ��ʼ��һ�´洢������������
	for (i = 0; i < IDcount; i++)
	{
		SortReasult[i] = i;
	}
	int i1, i2;
	//��дһ��ʱ�����絽����
	//˭��ʱ������������أ��Ͳ�д�ˡ�
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
//��Ʊ��غ���
int Searching(FlightID* ID, FlightTicket* DATA, int daycount)
{
	int i, j, a, f, e, b, r, count = 0;
	for (i = 0; i < 999; i++)
	{
		if ((strcmp(ID[i].ArrivalAirport, custom.destination) == 0)\
			&& (strcmp(ID[i].DepartureAirport, custom.departure) == 0) && (ID[i].FlyDay[custom.flyday] == '1'))//����ʱ����ʼ���ж�ID
		{
			a = JudgeAircraftSizeSeat(JudgeAircraftSize(ID, i));//����ɸѡ�ĺ��ߵķɻ�����λ��
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
				count++;//���������ķɻ���
				for (j = 0; j < count; j++)
				{
					custom.flynumber[j] = i;//ɸѡ�����Ҫ���ID�ż���
					DATA[(daycount - 2) * 999 + i].FirstClassTicketRemain = f;
					DATA[(daycount - 2) * 999 + i].EconomyClassTicketRemain = e;
					if (JudgeAircraftSize(ID, i) == 2)
						DATA[(daycount - 2) * 999 + i].BusinessClassTicketRemain = b;

				}
			}
		}
	}
	return j;//����ID�����ڷ���Ҫ��ķɻ�����
}
void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size)//n��DATA��������ţ�accountΪ�û��˺�,size�Ƿɻ��ͺ��жϽ��
{
	int p_num, i, a, b, c = 0;
	for (i = 0; i < 3; i++)
	{
		if (seat[i] != '/0')
			p_num++;
	}
	if (size == 1)//С�ɻ���Ʊ
	{
		if (p_num == 1)//����
		{
			if (Class = 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				for (a = 0; a < 2; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].FirstClassTicketRemain--;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
						break;
					}

				}
			}
			else//���ò�
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				for (a = 2; a < 32; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].EconomyClassTicketRemain--;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
						break;
					}
				}
			}
		}
		else//˫��
		{
			if (Class = 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 0; a < 2; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
						break;
					}
					else
					{
						cout << "�Բ������޲���λ�ã������¶�Ʊ";
						break;
					}
				}
			}
			else//˫�˾��ò�
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				for (a = 2; a < 32; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].FirstClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
						break;
					}
				}
			}
		}
	}
	else//��ɻ���Ʊ
	{
		if (p_num == 1)
		{
			if (Class = 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				for (a = 0; a < 3; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].FirstClassTicketRemain--;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
						break;
					}

				}
			}
			else if (Class = 'b')
			{
				if (p_num > DATA[n].BusinessClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				for (a = 3; a < 9; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].BusinessClassTicketRemain--;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
						break;
					}
				}
			}
			else//���òն�Ʊ
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				for (a = 9; a < 49; a++)
				{
					if (DATA[n].Seat[a][b] != 0)
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].EconomyClassTicketRemain--;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
						break;
					}
				}
			}
		}
		else//˫��
		{
			if (Class = 'f')
			{
				if (p_num > DATA[n].FirstClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 0; a < 3; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
						break;
					}
					else
					{
						cout << "�Բ������޲���λ�ã������¶�Ʊ";
						break;
					}
				}
			}
			else if (Class = 'b')
			{
				if (p_num > DATA[n].BusinessClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 3; a < 9; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain - 2;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
						break;
					}
					else
					{
						cout << "�Բ������޲���λ�ã������¶�Ʊ";
						break;
					}
				}
			}
			else//˫�˾��ò�
			{
				if (p_num > DATA[n].EconomyClassTicketRemain)
					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
				b = seattranslate(seat, 0);
				c = seattranslate(seat, 1);
				for (a = 9; a < 50; a++)
				{
					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
					{
						DATA[n].Seat[a][b] = account;
						DATA[n].Seat[a][c] = account;
						DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
						break;
					}
					else
					{
						cout << "�Բ������޲���λ�ã������¶�Ʊ";
						break;
					}

				}
			}
		}
	}
}
void Refunding(FlightTicket* DATA, int n, char seat[3], int account, char Class)//��Ʊ
{
	int p_num, i, a, b = 0, c;
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
				if (Class = 'f')
				{
					DATA[n].FirstClassTicketRemain++;
					cout << "���ѳɹ���Ʊ" << endl;
				}
				else if (Class = 'b')
				{
					DATA[n].BusinessClassTicketRemain++;
					cout << "���ѳɹ���Ʊ" << endl;
				}
				else
				{
					DATA[n].EconomyClassTicketRemain++;
					cout << "���ѳɹ���Ʊ" << endl;
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
				if (Class = 'f')
				{
					DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain + 2;
					cout << "���ѳɹ���Ʊ" << endl;
				}
				else if (Class = 'b')
				{
					DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain + 2;
					cout << "���ѳɹ���Ʊ" << endl;
				}
				else
				{
					DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain + 2;
					cout << "���ѳɹ���Ʊ" << endl;
				}
			}
		}
	}
	return;
}