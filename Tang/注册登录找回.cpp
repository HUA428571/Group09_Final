//#include"用户信息表.h"
//void registers();
//void Registers();
//void Input_login();
//void Input_Login();
//void reback();
//void Reback();
//void Enter();
///*登陆界面*/
//void main()
//{
//	/*创建储存用户管理员账号密码的文件*/
//	void Create_File();
//	{
//		FILE* fp;
//		FILE* fp2;
//		if ((fp = fopen("users.dat", "rb")) == NULL)                 /*如果此文件不存在*/
//		{
//			if ((fp = fopen("users.dat", "wb+")) == NULL)
//			{
//				printf("无法建立文件！\n");
//				exit(0);
//			}
//		}
//		if ((fp2 = fopen("manager.dat", "rb")) == NULL)
//		{
//			if ((fp2 = fopen("manager.dat", "wb+")) == NULL)
//			{
//				printf("无法建立文件！\n");
//				exit(0);
//			}
//		}
//	}
//	printf("选择功能:\n1:注册账号\t2:登陆账号\t3:找回密码\n");
//	int Choose1;
//	int Choose2;
//	scanf("%d", &Choose1);
//	if (Choose1 == 1)
//	{
//		int Choose;
//		printf("1:用户注册\t2:管理员注册\n");
//		scanf("%d", &Choose);
//		if (Choose == 1)
//		{
//			registers();
//			printf("是否登录？(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_login();
//			else
//				return;
//		}
//		if (Choose == 2)
//		{
//			Registers();
//			printf("是否登录？(1/0)\n");
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
//		printf("1:用户登录\t2:管理员登录\n");
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
//		printf("1:用户密码找回\t2:管理员密码找回\n");
//		scanf("%d", &Choose);
//		if (Choose = 1)
//		{
//			reback();
//			printf("是否登录？(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_login();
//			else
//				return;
//		}
//		if (Choose = 2)
//		{
//			Reback();
//			printf("是否登录？(1/0)\n");
//			scanf("%d", &Choose2);
//			if (Choose2 == 1)
//				Input_Login();
//			else
//				return;
//		}
//	}
//	return;
//}
///*注册账号*/
//void registers()  //按结构体的大小，一次写入或者读入1个结构体大小
//{
//	users a, b;//结构体 The_users 重命名定义
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("欢迎来到注册界面！\n");
//	Sleep(1000);
//	fp = fopen("users.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 到b
//	printf("请输入账号\n");
//	scanf("%s", &a.id);
//	while (1)
//	{
//		if (strcmp(a.id, b.id)) /*如果两串不相等*/
//		{
//			if (!feof(fp))    /*如果未到文件尾*/
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
//			printf("此用户名已存在！请重新注册！\n");
//			Sleep(1000);
//			fclose(fp);
//			return;
//		}
//	}
//	printf("请输入用户名：\n");
//	scanf("%s", &a.name);
//	printf("请输入性别(f(女)/m(男))：\n");
//	scanf(" %c", &a.sex);
//	do {
//		if (a.sex != 'f' && a.sex != 'm') {
//			printf("性别输入错误！请重新输入！\n");
//			scanf("%c", &a.sex);
//		}
//	} while (a.sex != 'f' && a.sex != 'm');
//	getchar();
//	printf("请输入电话号码：\n");
//	scanf("%ld", &a.phone);
//	printf("请输入密码\n");
//	scanf(" %s", &a.pwd);
//	printf("请确认密码\n");
//	scanf(" %s", &temp);
//	int flag = 0;
//	do {
//
//		if (!strcmp(a.pwd, temp))
//		{
//			fp = fopen("users.dat", "ab");
//			fwrite(&a, sizeof(struct The_users), 1, fp);
//			printf("账号注册成功，请登录！\n");
//			flag = 1;
//			Sleep(500);
//			fclose(fp);
//		}
//		else {
//			printf("两次密码不匹配！请重新输入！\n");
//			scanf("%s", &a.pwd);
//			printf("请确认密码\n");
//			scanf("%s", &temp);
//		}
//	} while (flag == 0);
//}
///*管理员注册账号*/
//void Registers()
//{
//	users a, b;//结构体 The_users 重命名定义
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("欢迎来到管理员注册界面！\n");
//	Sleep(1000);
//	fp = fopen("manager.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 到b
//	printf("请输入账号\n");
//	scanf("%s", &a.id);
//	while (1)
//	{
//		if (strcmp(a.id, b.id)) /*如果两串不相等*/
//		{
//			if (!feof(fp))    /*如果未到文件尾*/
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
//			printf("此用户名已存在！请重新注册！\n");
//			Sleep(1000);
//			fclose(fp);
//			return;
//		}
//	}
//	printf("请输入用户名：\n");
//	scanf("%s", &a.name);
//	printf("请输入性别(f(女)/m(男))：\n");
//	scanf(" %c", &a.sex);
//	do {
//		if (a.sex != 'f' && a.sex != 'm') {
//			printf("性别输入错误！请重新输入！\n");
//			scanf("%c", &a.sex);
//		}
//	} while (a.sex != 'f' && a.sex != 'm');
//	getchar();
//	printf("请输入电话号码：\n");
//	scanf("%ld", &a.phone);
//	printf("请输入密码\n");
//	scanf(" %s", &a.pwd);
//	printf("请确认密码\n");
//	scanf(" %s", &temp);
//	int flag = 0;
//	do {
//
//		if (!strcmp(a.pwd, temp))
//		{
//			fp = fopen("manager.dat", "ab");
//			fwrite(&a, sizeof(struct The_users), 1, fp);
//			printf("账号注册成功，请登录！\n");
//			flag = 1;
//			Sleep(500);
//			fclose(fp);
//		}
//		else {
//			printf("两次密码不匹配！请重新输入！\n");
//			scanf("%s", &a.pwd);
//			printf("请确认密码\n");
//			scanf("%s", &temp);
//		}
//	} while (flag == 0);
//}
///*登录系统*/
//void Input_login()
//{
//	users a, b;//定义结构体The_users别名
//
//	FILE* fp;
//	printf("欢迎来到登录界面！\n");
//	Sleep(1000);
//	fp = fopen("users.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b
//	printf("请输入账号\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //如果有此用户名
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //如果文件没有读完                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("重新输入账号\n");
//				scanf("%s", &a.id);
//				if (strcmp(a.id, b.id) == 0)         //如果有此用户名
//				{
//					break;
//				}
//				else
//				{
//					if (!feof(fp))  //如果文件没有读完                            
//
//					{
//						fread(&b, sizeof(struct The_users), 1, fp);
//					}
//					else
//						printf("错误输入两次，请推出程序再启动。");
//					return;
//				}
//
//			}
//		}
//	}
//	printf("请输入密码\n");
//	scanf("%s", &a.pwd);
//	do {
//
//		if (strcmp(a.pwd, b.pwd) == 0)            /*如果密码匹配*/
//
//		{
//			fclose(fp);
//			printf("登录成功,欢迎使用!");
//			Sleep(500);
//		}
//		else
//		{
//			printf("密码不正确!请重新输入密码\n");
//			scanf("%s", &a.pwd);
//		}
//	} while (strcmp(a.pwd, b.pwd) == 0);
//
//}
///*管理员登陆系统*/
//void Input_Login()
//{
//	users a, b;//定义结构体The_users别名
//
//	FILE* fp;
//	printf("欢迎来到管理员登录界面！\n");
//	Sleep(1000);
//	fp = fopen("manager.dat", "rb");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b
//	printf("请输入账号\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //如果有此用户名
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //如果文件没有读完                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("重新输入账号\n");
//				scanf("%s", &a.id);
//				if (strcmp(a.id, b.id) == 0)         //如果有此用户名
//				{
//					break;
//				}
//				else
//				{
//					if (!feof(fp))  //如果文件没有读完                            
//
//					{
//						fread(&b, sizeof(struct The_users), 1, fp);
//					}
//					else
//						printf("错误输入两次，请推出程序再启动。");
//					return;
//				}
//
//			}
//		}
//	}
//	printf("请输入密码\n");
//	scanf("%s", &a.pwd);
//	do {
//
//		if (strcmp(a.pwd, b.pwd) == 0)            /*如果密码匹配*/
//
//		{
//			fclose(fp);
//			printf("登录成功,欢迎使用!");
//			Sleep(500);
//		}
//		else
//		{
//			printf("密码不正确!请重新输入密码\n");
//			scanf("%s", &a.pwd);
//		}
//	} while (strcmp(a.pwd, b.pwd) == 0);
//
//}
///*找回密码*/
//void reback()
//{
//	users a, b;//结构体 The_users 重命名定义
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("欢迎来到找回密码界面！\n");
//	Sleep(1000);
//	fp = fopen("users.dat", "r");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b
//	printf("请输入账号\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //如果有此用户名
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //如果文件没有读完                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("此用户名不存在，请重新输入！\n");
//				Sleep(500);
//				fclose(fp);
//				return;
//			}
//		}
//	}
//	printf("请输入电话号码：\n");
//	scanf("%ld", &a.phone);
//	do {
//		if (a.phone != b.phone) {
//			printf("电话号码输入错误！请重新输入！\n");
//			scanf("%ld", &a.phone);
//		}
//	} while (a.phone != b.phone);
//	printf("您的密码是：%s", b.pwd);
//	Sleep(3000);
//}
///*管理员找回密码*/
//void Reback()
//{
//	users a, b;//结构体 The_users 重命名定义
//	FILE* fp;
//	char temp[20];
//	int count = 0;
//	printf("欢迎来到管理员找回密码界面！\n");
//	Sleep(1000);
//	fp = fopen("manager.dat", "r");
//
//	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b
//	printf("请输入账号\n");
//	scanf("%s", &a.id);
//
//	while (1)
//	{
//		if (strcmp(a.id, b.id) == 0)         //如果有此用户名
//		{
//			break;
//		}
//
//		else
//		{
//			if (!feof(fp))  //如果文件没有读完                            
//
//			{
//				fread(&b, sizeof(struct The_users), 1, fp);
//			}
//
//			else
//			{
//				printf("此用户名不存在，请重新输入！\n");
//				Sleep(500);
//				fclose(fp);
//				return;
//			}
//		}
//	}
//	printf("请输入姓名：\n");
//	scanf("%s", &a.name);
//	do {
//		if (strcmp(a.name, b.name)) {
//			printf("姓名输入错误！请重新输入！\n");
//			scanf("%s", &a.name);
//		}
//	} while (strcmp(a.name, b.name));
//	printf("请输入电话号码：\n");
//	scanf("%ld", &a.phone);
//	do {
//		if (a.phone != b.phone) {
//			printf("电话号码输入错误！请重新输入！\n");
//			scanf("%ld", &a.phone);
//		}
//	} while (a.phone != b.phone);
//	printf("您的密码是：%s", b.pwd);
//	Sleep(3000);
//}
///*信息录入*/
//void Enter()
//{
//	users a;//结构体  The_users重命名定义
//	Message n;// 信息表的重命名定义
//	FILE* fp;
//	char temp[20];
//	printf("请录入信息\n");
//	Sleep(1000);
//	fp = fopen("user.dat", "rb");
//	fread(&a, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 到b
//	printf("请输入身份证号码：\n");
//	scanf("%d", &n.IdCard);
//	while (1)
//	{
//		if (strcmp(n.IdCard, a.message->IdCard) == 0)
//		{
//			if (!feof(fp))  //如果文件没有读完                            
//
//			{
//				fread(&a, sizeof(struct The_users), 1, fp);
//			}
//			else
//			{
//				printf("该身份证已被注册，请重新输入:\n");
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
//	printf("请输入姓名:\n");
//	scanf("%s", &n.name);
//	strcpy(a.message->name, n.name);
//	printf("请输入电话号码:\n");
//	scanf("%s", &n.TelNum);
//	strcpy(a.message->TelNum, n.TelNum);
//};