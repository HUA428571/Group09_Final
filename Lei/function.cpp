////b19030334����Զ[�����ÿ͵Ĵ󲿷ֹ���]:��Ʊ����Ʊ����ǩ��ѡ�����漰�������
////��Ʊ��ѯ�������ѯ������[����ͻ�]; �ÿͶ�Ʊ����
//#include<iostream>
//#include <windows.h>
//#include"function.h"
//using namespace std;
//int j = 0;
//#ifdef structdefine
//#define structdefine
//typedef struct flightid //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
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
//#endif // !struct
//static flightid id[999];//Ĭ�����洢999������ ȫ�ֱ������к������ɷ���
//static flightticket data[366][999];//�洢һ��ĺ�������
//void prebooking();
//void head();
//int datetransfer(int year, int month, int day);//�仯Ϊ����
//int weekdaytransfer(int year, int month, int day);//�仯Ϊ������
//int judgeaircraftsize(flightid* id, int n);//�жϻ���
//int order();//ϵͳѡ�����
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