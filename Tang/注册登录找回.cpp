//#include"�û���Ϣ��.h"
//void registers();
//void Registers();
//void Input_login();
//void Input_Login();
//void reback();
//void Reback();
//void Enter();
///*��½����*/
//void main()
//{
//	/*���������û�����Ա�˺�������ļ�*/
//	void Create_File();
//	{
//		FILE* fp;
//		FILE* fp2;
//		if ((fp = fopen("users.dat", "rb")) == NULL)                 /*������ļ�������*/
//		{
//			if ((fp = fopen("users.dat", "wb+")) == NULL)
//			{
//				printf("�޷������ļ���\n");
//				exit(0);
//			}
//		}
//		if ((fp2 = fopen("manager.dat", "rb")) == NULL)
//		{
//			if ((fp2 = fopen("manager.dat", "wb+")) == NULL)
//			{
//				printf("�޷������ļ���\n");
//				exit(0);
//			}
//		}
//	}
//	printf("ѡ����:\n1:ע���˺�\t2:��½�˺�\t3:�һ�����\n");
//	int Choose1;
//	int Choose2;
//	scanf("%d", &Choose1);
//	if (Choose1 == 1)
//	{
//		int Choose;
//		printf("1:�û�ע��\t2:����Աע��\n");
//		scanf("%d", &Choose);
//		if (Choose == 1)
//		{
//			registers();
//			printf("�Ƿ��¼��(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_login();
//			else
//				return;
//		}
//		if (Choose == 2)
//		{
//			Registers();
//			printf("�Ƿ��¼��(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_login();
//			else
//				return;
//		}
//	}
//	if (Choose1 == 2)
//	{
//		int Choose;
//		printf("1:�û���¼\t2:����Ա��¼\n");
//		scanf("%d", &Choose);
//		if (Choose == 1)
//			Input_login();
//
//		if (Choose == 2)
//			Input_Login();
//	}
//	if (Choose1 == 3)
//	{
//		int Choose;
//		printf("1:�û������һ�\t2:����Ա�����һ�\n");
//		scanf("%d", &Choose);
//		if (Choose = 1)
//		{
//			reback();
//			printf("�Ƿ��¼��(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_login();
//			else
//				return;
//		}
//		if (Choose = 2)
//		{
//			Reback();
//			printf("�Ƿ��¼��(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_Login();
//			else
//				return;
//		}
//	}
//	return;
//}
///*ע���˺�*/
//void registers()  //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С
//{
//	users a, b;//�ṹ�� The_users ����������
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("��ӭ����ע����棡\n");
//	Sleep(1000);
//	fp = fopen("users.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� ��b
//	printf("�������˺�\n");
//	scanf("%s", &a.id);
//	while (1)
//	{
//		if (strcmp(a.id, b.id)) /*������������*/
//		{
//			if (!feof(fp))    /*���δ���ļ�β*/
//
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//			else
//				break;
//		}
//		else
//
//		{
//			printf("���û����Ѵ��ڣ�������ע�ᣡ\n");
//			Sleep(1000);
//			fclose(fp);
//			return;
//		}
//	}
//	printf("�������û�����\n");
//	scanf("%s", &a.name);
//	printf("�������Ա�(f(Ů)/m(��))��\n");
//	scanf(" %c", &a.sex);
//	do {
//		if (a.sex != 'f' && a.sex != 'm') {
//			printf("�Ա�����������������룡\n");
//			scanf("%c", &a.sex);
//		}
//	} while (a.sex != 'f' && a.sex != 'm');
//	getchar();
//	printf("������绰���룺\n");
//	scanf("%ld", &a.phone);
//	printf("����������\n");
//	scanf(" %s", &a.pwd);
//	printf("��ȷ������\n");
//	scanf(" %s", &temp);
//	int flag = 0;
//	do {
//
//		if (!strcmp(a.pwd, temp))
//		{
//			fp = fopen("users.dat", "ab");
//			fwrite(&a, sizeof(struct The_users), 1, fp);
//			printf("�˺�ע��ɹ������¼��\n");
//			flag = 1;
//			Sleep(500);
//			fclose(fp);
//		}
//		else {
//			printf("�������벻ƥ�䣡���������룡\n");
//			scanf("%s", &a.pwd);
//			printf("��ȷ������\n");
//			scanf("%s", &temp);
//		}
//	} while (flag == 0);
//}
///*����Աע���˺�*/
//void Registers()
//{
//	users a, b;//�ṹ�� The_users ����������
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("��ӭ��������Աע����棡\n");
//	Sleep(1000);
//	fp = fopen("manager.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� ��b
//	printf("�������˺�\n");
//	scanf("%s", &a.id);
//	while (1)
//	{
//		if (strcmp(a.id, b.id)) /*������������*/
//		{
//			if (!feof(fp))    /*���δ���ļ�β*/
//
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//			else
//				break;
//		}
//		else
//
//		{
//			printf("���û����Ѵ��ڣ�������ע�ᣡ\n");
//			Sleep(1000);
//			fclose(fp);
//			return;
//		}
//	}
//	printf("�������û�����\n");
//	scanf("%s", &a.name);
//	printf("�������Ա�(f(Ů)/m(��))��\n");
//	scanf(" %c", &a.sex);
//	do {
//		if (a.sex != 'f' && a.sex != 'm') {
//			printf("�Ա�����������������룡\n");
//			scanf("%c", &a.sex);
//		}
//	} while (a.sex != 'f' && a.sex != 'm');
//	getchar();
//	printf("������绰���룺\n");
//	scanf("%ld", &a.phone);
//	printf("����������\n");
//	scanf(" %s", &a.pwd);
//	printf("��ȷ������\n");
//	scanf(" %s", &temp);
//	int flag = 0;
//	do {
//
//		if (!strcmp(a.pwd, temp))
//		{
//			fp = fopen("manager.dat", "ab");
//			fwrite(&a, sizeof(struct The_users), 1, fp);
//			printf("�˺�ע��ɹ������¼��\n");
//			flag = 1;
//			Sleep(500);
//			fclose(fp);
//		}
//		else {
//			printf("�������벻ƥ�䣡���������룡\n");
//			scanf("%s", &a.pwd);
//			printf("��ȷ������\n");
//			scanf("%s", &temp);
//		}
//	} while (flag == 0);
//}
///*��¼ϵͳ*/
//void Input_login()
//{
//	users a, b;//����ṹ��The_users����
//
//	FILE* fp;
//	printf("��ӭ������¼���棡\n");
//	Sleep(1000);
//	fp = fopen("users.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b
//	printf("�������˺�\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //����д��û���
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //����ļ�û�ж���                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("���������˺�\n");
//				scanf("%s", &a.id);
//				if (strcmp(a.id, b.id) == 0)         //����д��û���
//				{
//					break;
//				}
//				else
//				{
//					if (!feof(fp))  //����ļ�û�ж���                            
//
//					{
//						fread(&b, sizeof(struct The_users), 1, fp);
//					}
//					else
//						printf("�����������Σ����Ƴ�������������");
//					return;
//				}
//
//			}
//		}
//	}
//	printf("����������\n");
//	scanf("%s", &a.pwd);
//	do {
//
//		if (strcmp(a.pwd, b.pwd) == 0)            /*�������ƥ��*/
//
//		{
//			fclose(fp);
//			printf("��¼�ɹ�,��ӭʹ��!");
//			Sleep(500);
//		}
//		else
//		{
//			printf("���벻��ȷ!��������������\n");
//			scanf("%s", &a.pwd);
//		}
//	} while (strcmp(a.pwd, b.pwd) == 0);
//
//}
///*����Ա��½ϵͳ*/
//void Input_Login()
//{
//	users a, b;//����ṹ��The_users����
//
//	FILE* fp;
//	printf("��ӭ��������Ա��¼���棡\n");
//	Sleep(1000);
//	fp = fopen("manager.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b
//	printf("�������˺�\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //����д��û���
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //����ļ�û�ж���                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("���������˺�\n");
//				scanf("%s", &a.id);
//				if (strcmp(a.id, b.id) == 0)         //����д��û���
//				{
//					break;
//				}
//				else
//				{
//					if (!feof(fp))  //����ļ�û�ж���                            
//
//					{
//						fread(&b, sizeof(struct The_users), 1, fp);
//					}
//					else
//						printf("�����������Σ����Ƴ�������������");
//					return;
//				}
//
//			}
//		}
//	}
//	printf("����������\n");
//	scanf("%s", &a.pwd);
//	do {
//
//		if (strcmp(a.pwd, b.pwd) == 0)            /*�������ƥ��*/
//
//		{
//			fclose(fp);
//			printf("��¼�ɹ�,��ӭʹ��!");
//			Sleep(500);
//		}
//		else
//		{
//			printf("���벻��ȷ!��������������\n");
//			scanf("%s", &a.pwd);
//		}
//	} while (strcmp(a.pwd, b.pwd) == 0);
//
//}
///*�һ�����*/
//void reback()
//{
//	users a, b;//�ṹ�� The_users ����������
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("��ӭ�����һ�������棡\n");
//	Sleep(1000);
//	fp = fopen("users.dat", "r");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b
//	printf("�������˺�\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //����д��û���
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //����ļ�û�ж���                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("���û��������ڣ����������룡\n");
//				Sleep(500);
//				fclose(fp);
//				return;
//			}
//		}
//	}
//	printf("������绰���룺\n");
//	scanf("%ld", &a.phone);
//	do {
//		if (a.phone != b.phone) {
//			printf("�绰��������������������룡\n");
//			scanf("%ld", &a.phone);
//		}
//	} while (a.phone != b.phone);
//	printf("���������ǣ�%s", b.pwd);
//	Sleep(3000);
//}
///*����Ա�һ�����*/
//void Reback()
//{
//	users a, b;//�ṹ�� The_users ����������
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("��ӭ��������Ա�һ�������棡\n");
//	Sleep(1000);
//	fp = fopen("manager.dat", "r");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b
//	printf("�������˺�\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //����д��û���
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //����ļ�û�ж���                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("���û��������ڣ����������룡\n");
//				Sleep(500);
//				fclose(fp);
//				return;
//			}
//		}
//	}
//	printf("������������\n");
//	scanf("%s", &a.name);
//	do {
//		if (strcmp(a.name, b.name)) {
//			printf("��������������������룡\n");
//			scanf("%s", &a.name);
//		}
//	} while (strcmp(a.name, b.name));
//	printf("������绰���룺\n");
//	scanf("%ld", &a.phone);
//	do {
//		if (a.phone != b.phone) {
//			printf("�绰��������������������룡\n");
//			scanf("%ld", &a.phone);
//		}
//	} while (a.phone != b.phone);
//	printf("���������ǣ�%s", b.pwd);
//	Sleep(3000);
//}
///*��Ϣ¼��*/
//void Enter()
//{
//	users a;//�ṹ��  The_users����������
//	Message n;// ��Ϣ�������������
//	FILE* fp;
//	char temp[20];
//	printf("��¼����Ϣ\n");
//	Sleep(1000);
//	fp = fopen("user.dat", "rb");
//	fread(&a, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� ��b
//	printf("���������֤���룺\n");
//	scanf("%d", &n.IdCard);
//	while (1)
//	{
//		if (strcmp(n.IdCard, a.message->IdCard) == 0)
//		{
//			if (!feof(fp))  //����ļ�û�ж���                            
//
//			{
//				fread(&a, sizeof(struct The_users), 1, fp);
//			}
//			else
//			{
//				printf("�����֤�ѱ�ע�ᣬ����������:\n");
//				scanf("%d", &n.IdCard);
//				Sleep(1000);
//				fclose(fp);
//				break;
//			}
//		}
//		else
//			break;
//	};
//	strcpy(a.message->IdCard, n.IdCard);
//	printf("����������:\n");
//	scanf("%s", &n.name);
//	strcpy(a.message->name, n.name);
//	printf("������绰����:\n");
//	scanf("%s", &n.TelNum);
//	strcpy(a.message->TelNum, n.TelNum);
//};