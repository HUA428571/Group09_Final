//#include <iostream>
//#include <string.h>
//using namespace std;
//typedef struct Flightid //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
//{
//	char carrier[4] = { 'x','x','x','x' };						//���չ�˾����������д��ĸ��ʾ
//	char id[8] = { 'x','x' ,'x' ,'x','x','x' ,'x' ,'x' };								//�����
//	char flyday[8] = { 'x','x' ,'x' ,'x' ,'x' ,'x' ,'x' ,'x' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ1��������Ϊ0
//	char departureairport[8] = { 'x','x','x' ,'x' ,'x' ,'x' ,'x' ,'x' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
//	char arrivalairport[8] = { 'x','x' ,'x' ,'x' ,'x' ,'x' ,'x' ,'x' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
//	int departuretime = 2500;					//����ʱ�̣�������
//	int arrivaltime = 2500;					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
//	int traveltimehour = 0;//����ʱ��(ʱ)
//	int traveltimeminute = 0;//����ʱ��(��)
//	int price = 0;
//	char aircrafttype[4] = { 'x','x' ,'x' };					//�ɻ��ͺţ������롣eg 787��350
//	char Class[4] = { 'x','x' ,'x' ,'x' };							//��λ�����ջ����գ�ע���β��\0��
//}flightid;
//
//typedef struct flightticket //ÿ�ջ�Ʊ���
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
//int JudgeAircraftSize(FlightID* ID, int n)//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
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
//int FirstClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//ͷ�Ȳն�Ʊ����
//{
//	int m, n, f_count = 0;
//	if (judge == 1)
//	{
//		for (m = 0; m < 4; m++)
//		{
//			for (n = 0; n < 2; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
//					f_count++;//��������
//			}
//		}
//	}
//	else
//	{
//		for (m = 0; m < 4; m++)
//		{
//			for (n = 0; n < 3; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
//					f_count++;//��������
//			}
//		}
//	}
//	return f_count;
//}
//int BusinessClassTicketRemain(FlightTicket* DATA, int daycount, int i)//���������
//{
//	int m, n, b_count = 0;
//	for (m = 0; m < 6; m++)
//	{
//		for (n = 0; n < 6; n++)
//		{
//			if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
//				b_count++;//��������
//		}
//	}
//	return b_count;
//}
//int EconomyClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge)//���òն�Ʊ����
//{
//	int m, n, e_count = 0;
//	if (judge == 1)
//	{
//		for (m = 0; m < 6; m++)
//		{
//			for (n = 0; n < 30; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
//					e_count++;//��������
//			}
//		}
//	}
//	else
//	{
//		for (m = 0; m < 10; m++)
//		{
//			for (n = 0; n < 40; n++)
//			{
//				if (DATA[(daycount - 2) * 999 + i].Seat[m][n] != 0)//�ж��Ƿ�����
//					e_count++;//��������
//			}
//		}
//	}
//	return e_count;
//}
//
//int WeekDayTransfer(int year, int month, int day)//ʹ�ò��չ�ʽת������������
//{
//	int week = 0;
//	int century = year / 100;//ע�����ʵ��������ݵ�ǰ��λ������������
//	year = year % 100;//��ݵĺ���λ
//	if (month == 1 || month == 2)//�·ݵķ�ΧΪ3-14������1��2�±����13��14��
//	{
//		month += 12;
//		year--;
//	}
//	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
//	week = week % 7;
//	return (week >= 0) ? week : (7 + week);
//}
//
//int DateTransfer(int year, int month, int day)//�������ڶ�Ӧ����
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
//	printf("���\t�����\t\t���ʱ��\t��ɻ���\t�������\t����ʱ��\t����ʱ��\tִ�ɻ���\t���òռ۸�\tʣ����λ��\n");
//	return;
//}
//int hour(int x)//�Է���ʱ��ķֶ�
//{
//	return (x / 100);
//}
//int minut(int x)//�Է���ʱ��ķֶ�
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
//void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size)//n��DATA��������ţ�accountΪ�û��˺�,size�Ƿɻ��ͺ��жϽ��
//{
//	int p_num, i, a, b, c = 0;
//	for (i = 0; i < 3; i++)
//	{
//		if (seat[i] != '/0')
//			p_num++;
//	}
//	if (size == 1)//С�ɻ���Ʊ
//	{
//		if (p_num == 1)//����
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 0; a < 2; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].FirstClassTicketRemain--;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
//						break;
//					}
//
//				}
//			}
//			else//���ò�
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 2; a < 32; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].EconomyClassTicketRemain--;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
//						break;
//					}
//				}
//			}
//		}
//		else//˫��
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 0; a < 2; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
//						break;
//					}
//					else
//					{
//						cout << "�Բ������޲���λ�ã������¶�Ʊ";
//						braek;
//					}
//				}
//			}
//			else//˫�˾��ò�
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 2; a < 32; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].FirstClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
//						break;
//					}
//				}
//			}
//		}
//	}
//	else//��ɻ���Ʊ
//	{
//		if (p_num == 1)
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 0; a < 3; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].FirstClassTicketRemain--;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
//						break;
//					}
//
//				}
//			}
//			else if (Class = 'b')
//			{
//				if (p_num > DATA[n].BusinessClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 3; a < 9; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].BusinessClassTicketRemain--;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
//						break;
//					}
//				}
//			}
//			else//���òն�Ʊ
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				for (a = 9; a < 49; a++)
//				{
//					if (DATA[n].Seat[a][b] != 0)
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].EconomyClassTicketRemain--;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << "��" << endl;
//						break;
//					}
//				}
//			}
//		}
//		else//˫��
//		{
//			if (Class = 'f')
//			{
//				if (p_num > DATA[n].FirstClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 0; a < 3; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].FirstClassTicketRemain = DATA[n].FirstClassTicketRemain - 2;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
//						break;
//					}
//					else
//					{
//						cout << "�Բ������޲���λ�ã������¶�Ʊ";
//						braek;
//					}
//				}
//			}
//			else if (Class = 'b')
//			{
//				if (p_num > DATA[n].BusinessClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 3; a < 9; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain - 2;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
//						break;
//					}
//					else
//					{
//						cout << "�Բ������޲���λ�ã������¶�Ʊ";
//						braek;
//					}
//				}
//			}
//			else//˫�˾��ò�
//			{
//				if (p_num > DATA[n].EconomyClassTicketRemain)
//					cout << "�Բ������Ķ�Ʊ��Ϣ����" << endl;
//				b = seattranslate(seat, 0);
//				c = seattranslate(seat, 1);
//				for (a = 9; a < 50; a++)
//				{
//					if ((DATA[n].Seat[a][b] != 0) && (DATA[n].Seat[a][c] != 0))
//					{
//						DATA[n].Seat[a][b] = account;
//						DATA[n].Seat[a][c] = account;
//						DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain - 2;
//						cout << "������λλ��" << a + 1 << "�ţ�" << seat[0] << seat[1] << "��" << endl;
//						break;
//					}
//					else
//					{
//						cout << "�Բ������޲���λ�ã������¶�Ʊ";
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
//					cout << "���ѳɹ���Ʊ" << endl;
//				}
//				else if (Class = 'b')
//				{
//					DATA[n].BusinessClassTicketRemain++;
//					cout << "���ѳɹ���Ʊ" << endl;
//				}
//				else
//				{
//					DATA[n].EconomyClassTicketRemain++;
//					cout << "���ѳɹ���Ʊ" << endl;
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
//					cout << "���ѳɹ���Ʊ" << endl;
//				}
//				else if (Class = 'b')
//				{
//					DATA[n].BusinessClassTicketRemain = DATA[n].BusinessClassTicketRemain + 2;
//					cout << "���ѳɹ���Ʊ" << endl;
//				}
//				else
//				{
//					DATA[n].EconomyClassTicketRemain = DATA[n].EconomyClassTicketRemain + 2;
//					cout << "���ѳɹ���Ʊ" << endl;
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