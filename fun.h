#include <iostream>
#include <string.h>
#ifndef STRUCT
#define STRUCT
typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
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
#endif // !STRUCT

using namespace std;
int WeekDayTransfer(int year, int month, int day);//ʹ�ò��չ�ʽת������������
int DateTransfer(int year, int month, int day);//�������ڶ�Ӧ����
int JudgeAircraftSize(FlightID* ID, int n);//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
int JudgeAircraftSizeSeat(int n);
int FirstClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge);//ͷ�Ȳն�Ʊ����
int EconomyClassTicketRemain(FlightTicket* DATA, int daycount, int i, int judge);//���òն�Ʊ����
int hour(int x);//�Է���ʱ��ķֶ�
int minut(int x);//�Է���ʱ��ķֶ�
int seattranslate(char seat[3], int n);
//�ļ���ȡд�뺯��
int ImportFlightDatabase(FlightID* ID);//�����ڿ�ͷѯ���Ƿ�Ҫ�������к������ݿ�,�������ض�ȡ�������
int SaveFlightDatabase(FlightID* ID, int IDcount);
//��ӡ����
void PrintFlightTitle();//��ӡ������
void PrintFlight(FlightID* ID, int n, int i);//�������飬�����±꣬���
void PrintFlightTicket();
int PrintSearch(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount);//չʾ��ѯ�Ľ��
void PrintInformation(FlightID* ID, int IDcount);
//���ݴ�����
int SearchFlightID(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount);//���Һ���ţ����ز��ҵ��������
int SearchFlightDepartureAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount);//���Һ���ɵأ����ز��ҵ��������
int SearchFlightArrivalAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount);//���Һ���ɵأ����ز��ҵ��������
int NewFlight(FlightID* ID, int& IDcount);
int SortByDepartureTime(FlightID* ID, int IDcount, int* SortReasult);//ð�����򷨰���ʱ�����򺽰ࣻ
int DeleteFlight(FlightID* ID, FlightTicket* DATA, int& IDcount, int Delete);
//��Ʊ��غ���
int Searching(FlightID* ID, FlightTicket* DATA, int daycount);
void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size);//n��DATA��������ţ�accountΪ�û��˺�,size�Ƿɻ��ͺ��жϽ��
void Refunding(FlightTicket* DATA, int n, char seat[3], int account, char Class);