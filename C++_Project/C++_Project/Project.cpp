/*	������Ʈ �̸� : Project.c
	�ۼ��� : �̻��
	�й� : 20145150
	�а� : ����ƮIOT
	�ۼ���¥ : 2018.11.29 ~ 12.11
	������Ʈ ���� : ���̿������� ����ؼ� �ڽ��� ���ϴ� ���Ͽ� �������� �����Ҷ� �� �����쿡 �ʿ��� ������ �� ���� ����� �м��Ͽ� �˷��ִ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS //scanf������ ��� �Ͽ����ϴ�.

#include <stdio.h> 
#include <windows.h> //gotoxy���
#include<math.h> //sin�Լ� ���
#include<time.h> //�������� �ޱ� ���� ���
#include<stdlib.h> //�����Լ� ���
#include<string.h> //strcmp���

void gotoxy(int x, int y); //�����ġ ��ȯ �Լ�
void Biorhythm_Information(int *born_year, int *born_month, int *born_day, int* year, int*month); //���̿��������� ���� �����Է� �Լ�
int Biorhythm_Result(char arr[][3], int *born_year, int *born_month, int *born_day, int* year, int*month, int month_size); //���̿����� ��� ��� �� �׷��� ����� ���� �� �� �� ��ȯ �Լ�
int total_days(int year, int month, int day); //�� �������� �ϼ� ��� �Լ�
char bio_status(int v, int mod); //������ ������ ����⸦ ����ϱ� ���� �Լ�
void Biorhythm_Graph(int total_day); //�׷��� ��� �Լ�
void Schedule_rhythm(char arr_rythm[][20], char arr_scehdule[][20], int month_size, int month, int start, int end); //�������� �Է¹ޱ� ���� �Լ�
void Biorhythm_Analyses(char arr_rythm[][20], char arr_scehdule[][20], char arr[][3], int start, int end); //������� ���̿������� �м��Ͽ� ����� ����ϴ� �Լ�

int main(int argc, char argv[]) {

	char arr[31][3] = { 0 }; //���̿����� �迭
	char arr_rythm[31][20] = { 0 }; //�����쿡 �ʿ��� ����迭
	char arr_scehdule[31][20] = { 0 }; //������ �迭
	const char *Menu[] = { "1.���� �Է�","2.���̿����� ��� ��� ","3.�׷��� ���","4.������ �Է� ","5.��� �м�","6.����" }; //menu ������ �迭
	char ch = 'Y'; //���α׷� ��� �ؼ� ������ ���� ����
	int menu; //�޴� ����
	int born_year, born_month, born_day = 0; //�������
	int year, month, day = 0; //���̿����� ������� ��¥
	int total_day; //���ϼ�
	int months_size[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //�Ŵ� �ϼ��� �ٸ��Ƿ� �迭�� �����ؼ� ó��
	int runCount1, runCount2, runCount3; //������ �޴��� Ȯ���ϱ� ���� ����
	int start, end; //Ž���� ���ϴ� ���� ���� �� ��

	while (ch == 'Y' || ch == 'y')
	{
		system("cls"); //cmd �ʱ�ȭ

		gotoxy(40, 10); //��� ��ġ ���� �� �޴� ���
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 11);
		printf("��       ���̿�����  ���α׷�         ��\n");
		gotoxy(40, 12);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 13);
		printf("��%-36s��\n", Menu[0]);
		gotoxy(40, 14);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 15);
		printf("��%-36s��\n", Menu[1]);
		gotoxy(40, 16);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 17);
		printf("��%-36s��\n", Menu[2]);
		gotoxy(40, 18);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 19);
		printf("��%-36s��\n", Menu[3]);
		gotoxy(40, 20);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 21);
		printf("��%-36s��\n", Menu[4]);
		gotoxy(40, 22);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 23);
		printf("��%-36s��\n", Menu[5]);
		gotoxy(40, 24);
		printf("����������������������������������������������������������������������������\n");
		gotoxy(40, 25);

		printf(" �޴� ���� : ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			system("cls");
			Biorhythm_Information(&born_year, &born_month, &born_day, &year, &month); //������� �� ������� ��� �Է�
			runCount1 = 0; //�����ߴ��� Ȯ��
			runCount1++;
		}
		else if (menu == 2)  //1���� �������� ��쿡�� ���డ��
		{
			if (runCount1 == 1)
			{
				system("cls");
				total_day = Biorhythm_Result(arr, &born_year, &born_month, &born_day, &year, &month, months_size[month - 1]); //���̿����� ������� �׷��� ����� ���� �� �ϼ��� ��ȯ �ޱ�
				runCount2 = 0; //�����ߴ��� Ȯ��
				runCount2++;
			}
			else
			{
				gotoxy(40, 26);
				printf("���̿����� ����� �������� ������ �Է��ϼ���. \n");
				gotoxy(40, 27);
			}
		}
		else if (menu == 3)
		{
			if (runCount2 == 1 && runCount1 == 1) //1�� 2���� �������� ��쿡�� ���డ��
			{
				system("cls");
				Biorhythm_Graph(total_day); //���̿����� �׷�������
			}
			else
			{
				gotoxy(40, 26);
				printf("�׷��� ����� �������� ������ �Է��ϰ� ������ �޴��� �����Ͻÿ�. \n");
				gotoxy(40, 27);
			}
		}
		else if (menu == 4)
		{
			if (runCount1 == 1) //1���� �������� ��쿡�� ���డ��
			{
				system("cls");
				gotoxy(35, 12);
				printf("�������� �Է� �� ���� ���� �Է��ϼ��� : ");
				scanf("%d", &start);
				gotoxy(35, 13);
				printf("�������� �Է� �� �� ���� �Է��ϼ��� : ");
				scanf("%d", &end);

				Schedule_rhythm(arr_rythm, arr_scehdule, months_size[month - 1], month, start, end); //������ �Է�
				runCount3 = 0;
				runCount3++;
			}
			else
			{
				gotoxy(40, 26);
				printf("������ ������ �Է��ϱ� ���� ���̿����� ������ �Է��ϼ���. \n");
				gotoxy(40, 27);
			}
		}
		else if (menu == 5)
		{
			if (runCount2 == 1 && runCount1 == 1 && runCount3 == 1) //�޴� 1�� 2�� 4�� ���� ���� ��쿡�� ���డ��
			{
				system("cls");
				Biorhythm_Analyses(arr_rythm, arr_scehdule, arr, start, end);
			}
			else
			{
				gotoxy(40, 26);
				printf("�м��� �ϱ����� ���̿����� ������ ������ �׸��� �������� �Է��ϼ���. \n");
				gotoxy(40, 27);
			}
		}
		else if (menu == 6) //����
		{
			break;
		}
		else //�̿��� ���� �Է��Ͽ��� ���
		{
			gotoxy(40, 26);
			printf("�� �� �Է��ϼ̽��ϴ�. \n");
			gotoxy(40, 27);
		}

		printf("���̿����� ���α׷��� ��� ���� �Ͻðڽ��ϱ�? Y/N : "); //2�� �����ϰ� N������ ����� ����
		scanf(" %c", &ch);
	}
	return 0;
}

void gotoxy(int x, int y) //�����ġ ��ȯ �Լ�
{
	COORD Pos = { x - 1 , y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Biorhythm_Information(int *born_year, int *born_month, int *born_day, int* year, int*month) //������� �� ���̿����� ������� ��� �Է�
{
	gotoxy(35, 12);
	printf("================================================\n");
	gotoxy(35, 13);
	printf("�¾ �⵵�� �Է��ϼ��� : ");
	scanf("%d", born_year);
	gotoxy(35, 14);
	printf("�¾ ���� �Է��ϼ��� : ");
	scanf("%d", born_month);
	gotoxy(35, 15);
	printf("�¾ ���� �Է��ϼ��� : ");
	scanf("%d", born_day);
	gotoxy(35, 16);
	printf("================================================\n");
	gotoxy(35, 17);
	printf("���̿������� ������� �⵵�� �Է��ϼ���. ");
	scanf("%d", year);
	gotoxy(35, 18);
	printf("���̿������� ������� ���� �Է��ϼ���. ");
	scanf("%d", month);
	gotoxy(35, 19);
	printf("================================================\n");
	printf("\n");
	gotoxy(35, 21);

}

int Biorhythm_Result(char arr[][3], int *born_year, int *born_month, int *born_day, int *year, int *month, int month_size) //���̿� ���� �������
{
	int i;
	int k = 9;
	int Sum_Bornday, Sum_Nowday; //1��1��1�� ���� �¾�� ���̿����� ������� �� ������ �ϼ��� ���� �� ����
	int total; //���ϼ� ����
	int physical, emotion, intellect; //��ü,����,�������� ����
	int temp; //���ϼ� ���� ��ȭ �ϹǷ� ��ȯ�� ���� ���ϼ� �ӽ����� ����

	Sum_Bornday = total_days(*born_year, *born_month, *born_day); //1��1��1�Ϻ��� ������ϱ����� �ϼ�
	Sum_Nowday = total_days(*year, *month, 1); //1��1��1�Ϻ��� ���̿����� ������� �� ������ �ϼ�
	total = Sum_Nowday - Sum_Bornday; //���� ���� �¾ ������ ���̿����� ������� �� ������ �ϼ��� ����
	temp = total; //���� ����

	gotoxy(30, 8);
	printf("������ < - > , ������ < + > , ����� < D > \n");

	printf("\n");

	for (i = 1; i <= month_size; i++)
	{

		physical = total % 23; //��ü������ �ֱ�� 23��
		emotion = total % 28; //���������� �ֱ�� 28��
		intellect = total % 33; //���������� �ֱ�� 33��

		gotoxy(15, k++);

		printf("%d�� %2d��", *month, i); //���� ���

		arr[i][0] = bio_status(physical, 23); //������ ������ ����� �Ǵ� �Ŀ� ��ȣ �Է�
		arr[i][1] = bio_status(emotion, 28); //������ ������ ����� �Ǵ� �Ŀ� ��ȣ �Է�
		arr[i][2] = bio_status(intellect, 33); //������ ������ ����� �Ǵ� �Ŀ� ��ȣ �Է�

		printf(" \t ��ü:%2d < %c > ", physical, arr[i][0]); //������
		printf(" \t ����:%2d < %c > ", emotion, arr[i][1]);
		printf(" \t ����:%2d < %c > \n", intellect, arr[i][2]);

		total++; //���� �Ϸ� ����
	}

	printf("\n");
	gotoxy(15, ++k);

	return temp; //�� �� �� ��ȯ
}

int total_days(int year, int month, int day) //���� �� ��� �Լ�
{

	int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //�� ������ ������ �ϼ� �迭
	int i;
	int total = 0;

	total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400; //�⸶���� �ϼ��� ��ġ�� ���� ����

	if (!(year % 4) && (year % 100) || !(year % 400)) //��ġ�� ���� ���� ��¥ ���� �� ��쿡 �ϼ� �ϳ� ����
	{
		months[1]++;
	}

	for (i = 0;i < month - 1;i++) //������ �ϼ� ����
	{
		total += months[i];
	}

	total += day; //�ϼ� ��ŭ �ϼ� ����

	return total;
}

char bio_status(int v, int mod)
{
	char result;
	double r;

	r = sin(v*3.141592 / (mod / 2.0)); //sin((���̿����� �� * ������) / (�ֱ�/2))

	if (r < -0.2) //-0.2���� ���� ��� ������
	{
		result = '-';
	}
	else if ((-0.2 <= r) && (r <= 0.2)) //-0.2 �� 0.2 ���� �� ��� �����
	{
		result = 'D';
	}
	else
	{
		result = '+'; //0.2�̻��� ��� ������
	}
	return result; //��� ��ȣ ��ȯ
}

void Biorhythm_Graph(int total_day) //�׷��� ��� �Լ�
{
	double r[32], r1[32], r2[32]; //
	int physical, emotion, intellect;
	int i, y;

	for (i = 1; i <= 30; i++)
	{
		physical = total_day % 23;
		emotion = total_day % 28;
		intellect = total_day % 33;

		r[i] = sin(physical*3.141592 / (23 / 2.0));
		r1[i] = sin(emotion*3.141592 / (28 / 2.0));
		r2[i] = sin(intellect*3.141592 / (33 / 2.0));

		total_day++;
	}

	gotoxy(1, 5);
	printf("            [ (* : ��ü),(- : ����),(+ : ����) ] \n");
	gotoxy(1, 6);
	printf("===============================================================\n");

	for (i = 0; i <= 60; i++) //�߾����� �� ������ �Ʒ��� ��� �׳� ������ ���� �� �ϰ�� �׳� ������ ����
	{
		gotoxy(i, 20);
		printf("-");
	}
	printf("0");
	for (i = 1; i <= 30; i++)
	{
		y = 20 - 10 * r[i];
		gotoxy(i * 2, y); //��ü ���� �׷��� 
		printf("*");
		y = 20 - 10 * r1[i];
		gotoxy(i * 2, y); //���� ���� �׷���
		printf("-");
		y = 20 - 10 * r2[i];
		gotoxy(i * 2, y); //���� ���� �׷���
		printf("+");
	}

	gotoxy(1, 34);
	printf("===============================================================\n");
	gotoxy(1, 35);
}

void Schedule_rhythm(char arr_rythm[][20], char arr_scehdule[][20], int month_size, int month, int start, int end) //�������Է� �޴� �Լ�
{
	int i;
	int k = 16;

	gotoxy(35, 14);
	if (end > month_size) { //������� ������ �̹� �� �ϼ� ���� ������ ���� �̻��ϰ� �����Ƿ� �̹��� �ϼ��� ����
		printf("�� ��¥�� �̹� �� �ϼ� ���� �����Ƿ� �� ��¥�� �̹� �� �ϼ��� ��ü�ϰڽ��ϴ�. \n");
		end = month_size;
	}

	gotoxy(35, 15);
	printf("============================================================\n");
	for (i = start; i <= end; i++) //�������� �Է¹ް� �׿� �ʿ��� ���� �Է¹���
	{
		gotoxy(35, k++);
		printf("%d�� %d���� �������� �Է��ϼ��� : ", month, i);
		scanf("%s", arr_scehdule[i]);
		gotoxy(35, k++);
		printf("�� �� �߿��� ���� ����(��ü/����/����)�� �Է��ϼ��� : ");
		scanf("%s", arr_rythm[i]);
		gotoxy(35, k++);
		printf("\n");
	}
	gotoxy(35, k++);
	printf("============================================================\n");
	gotoxy(35, k++);

}

void Biorhythm_Analyses(char arr_rythm[][20], char arr_scehdule[][20], char arr[][3], int start, int end) //��� �м��Լ�
{
	int i;
	int k = 13;
	int num;
	int runCount1 = 0, runCount2 = 0; //�����ߴ��� Ȯ�� �ϴ� ����
	const char *physical[] = { "������ Ÿ��" , "�౸ �ϱ�" , "�޸���" ,  //����,���������� ���� ��ü������ �� ���� ��� �������� ���� ���� �� �迭�� �� ������ ��ġ�� �ִ� �ൿ�� ��õ��
						 "����ϱ�" , "�� �ϱ�" , "�߱� �ϱ�" ,
						 "�ｺ �ϱ�" , "�ٳѱ� �ϱ�" , "���� �ϱ�" };
	const char *emotion[] = { "���� ���" , "��ȭ ����", "ī�� ����" ,  //��ü.���������� ���� ���������� �� ���� ��� �������� ���� ���� �� �迭�� �� ������ ��ġ�� �ִ� �ൿ�� ��õ��
						"��å �ϱ�" , "����Ʈ �ϱ�","�� ���� �ϱ�",
						"���� ����", "���� ����", "ģ���� ������" };
	const char *intellect[] = { "���� �����ϱ�", "���� �����ϱ�", "���� �����ϱ�",   //��ü.���������� ���� ���������� �� ���� ��� �������� ���� ���� �� �迭�� �� ������ ��ġ�� �ִ� �ൿ�� ��õ��
						  "C��� �����ϱ�", "�ڹ� �����ϱ�", "�˰��� �����ϱ�",
						  "���� �ϱ�" , "�ڰ��� �����ϱ�", "���м��� �б�" };

	srand((int)time(NULL)); //�õ� ���� ��� ��ȭ������

	gotoxy(30, 12);
	printf("============================================================\n");
	for (i = start; i <= end; i++) //������� ������ �ʿ��� ����� �� �� ���� ������ �� �� �м���� ���
	{
		if (strcmp(arr_rythm[i], "��ü") == 0) //��ü ������ �ʿ��� ���� ���
		{
			if (arr[i][0] == '-')  //��ü������ �ʿ������� ��ü������ �ʿ��� ���� �ϱ⿡ ������ �ϰ�� 
			{
				if (arr[i][1] == '+') //��ü������ �� ������ ���������� ���� ���
				{
					num = rand() % 9;  //���� �� �ޱ�
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���̰� ���������� �����Ƿ� %s �ϴ� ���� ��õ�帳�ϴ�! \n", arr_scehdule[i], emotion[num]); //���� emotion�迭�� ���� �� index�� �ִ� �ൿ ��õ
					runCount1++; //���� Ȯ��
				}
				if (arr[i][2] == '+') //��ü������ �� ������ ���������� ���� ���
				{
					num = rand() % 9;  //���� �� �ޱ�
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���̰� ���������� �����Ƿ� %s �ϴ� ���� ��õ�帳�ϴ�! \n", arr_scehdule[i], intellect[num]); //���� intellect�迭�� ���� �� index�� �ִ� �ൿ ��õ
					runCount2++;
				}
				if (runCount1 == 0 && runCount2 == 0) //��ü���뵵 �������̰� �ٸ� ���뵵 �����Ⱑ ���� ���
				{
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���Դϴ�!! �����Ͻʽÿ�!! \n", arr_scehdule[i]);
				}
				runCount1 = 0; //���� Ȯ�� ������ �ʱ�ȭ������
				runCount2 = 0; //���� Ȯ�� ������ �ʱ�ȭ������
			}
			else if (arr[i][0] == 'D') //��ü������ �ʿ������� ��ü������ �ʿ��� ���� �ϱ⿡ ����� �ϰ�� 
			{
				gotoxy(30, k++);
				printf("%s �ϱ⿡�� ���ǰ� �ʿ��� ���Դϴ�! \n", arr_scehdule[i]);
			}
			else //��ü������ �ʿ��ϰ� ������ �ϰ��
			{
				gotoxy(30, k++);
				printf("%s �ϱ⿡ �� ���� ���Դϴ�! \n", arr_scehdule[i]);
			}
		}
		else if (strcmp(arr_rythm[i], "����") == 0) //���� ������ �ʿ��� ���� ���
		{
			if (arr[i][1] == '-') //���������� �ʿ������� ���������� �ʿ��� ���� �ϱ⿡ ������ �ϰ�� 
			{
				if (arr[i][0] == '+') //��ü������ ������� ��ü������ �ʿ�� �ϴ� Ȱ���� ��õ
				{
					num = rand() % 9; //���� �� �ޱ�
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���̰� ��ü������ �����Ƿ� %s  �ϴ� ���� ��õ�帳�ϴ�! \n", arr_scehdule[i], physical[num]);  //���� physical�迭�� ���� �� index�� �ִ� �ൿ ��õ
					runCount1++; //���� Ȯ��
				}
				if (arr[i][2] == '+') //���������� ������� ���������� �ʿ�� �ϴ� Ȱ���� ��õ
				{
					num = rand() % 9; //���� �� �ޱ�
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���̰� ���������� �����Ƿ� %s �ϴ� ���� ��õ�帳�ϴ�! \n", arr_scehdule[i], intellect[num]);  //���� intellect�迭�� ���� �� index�� �ִ� �ൿ ��õ
					runCount2++; //���� Ȯ��
				}
				if (runCount1 == 0 && runCount2 == 0) //�������뵵 �������̰� �ٸ� ���뵵 �����Ⱑ ���� ���
				{
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���Դϴ�!! �����Ͻʽÿ�!! \n", arr_scehdule[i]);
				}
				runCount1 = 0;
				runCount2 = 0;
			}
			else if (arr[i][1] == 'D')  //���������� �ʿ������� ��ü������ �ʿ��� ���� �ϱ⿡ ����� �ϰ�� 
			{
				gotoxy(30, k++);
				printf("%s �ϱ⿡�� ���ǰ� �ʿ��� ���Դϴ�! \n", arr_scehdule[i]);
			}
			else  //���������� �ʿ��ϰ� ������ �ϰ�� 
			{
				gotoxy(30, k++);
				printf("%s �ϱ⿡ �� ���� ���Դϴ�! \n", arr_scehdule[i]);
			}
		}
		else //���� ������ �ʿ��� ���� ���
		{
			if (arr[i][2] == '-') //���������� �ʿ������� ���������� �ʿ��� ���� �ϱ⿡ ������ �ϰ�� 
			{
				if (arr[i][0] == '+')  //��ü������ ������� ��ü������ �ʿ�� �ϴ� Ȱ���� ��õ
				{
					num = rand() % 9;  //���� �� �ޱ�
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���̰� ��ü������ �����Ƿ� %s �ϴ� ���� ��õ�帳�ϴ�! \n", arr_scehdule[i], physical[num]);  //���� physical�迭�� ���� �� index�� �ִ� �ൿ ��õ
					runCount1++; //���� Ȯ��
				}
				if (arr[i][1] == '+')  //���������� ������� ���������� �ʿ�� �ϴ� Ȱ���� ��õ
				{
					num = rand() % 9;  //���� �� �ޱ�
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���̰� ���������� �����Ƿ� %s �ϴ� ���� ��õ�帳�ϴ�! \n", arr_scehdule[i], emotion[num]);  //���� emotion�迭�� ���� �� index�� �ִ� �ൿ ��õ
					runCount2++; //���� Ȯ��
				}
				if (runCount1 == 0 && runCount2 == 0) //�������뵵 �������̰� �ٸ� ���뵵 �����Ⱑ ���� ���
				{
					gotoxy(30, k++);
					printf("%s �ϱ⿡�� ������ ���Դϴ�!! �����Ͻʽÿ�!! \n", arr_scehdule[i]);
				}
				runCount1 = 0;
				runCount2 = 0;
			}
			else if (arr[i][2] == 'D') //���������� �ʿ������� ��ü������ �ʿ��� ���� �ϱ⿡ ����� �ϰ�� 
			{
				gotoxy(30, k++);
				printf("%s �ϱ⿡�� ���ǰ� �ʿ��� ���Դϴ�! \n", arr_scehdule[i]);
			}
			else  //���������� �ʿ��ϰ� ������ �ϰ��
			{
				gotoxy(30, k++);
				printf("%s �ϱ⿡ �� ���� ���Դϴ�! \n", arr_scehdule[i]);
			}
		}
	}
	gotoxy(30, k++);
	printf("============================================================\n");
	gotoxy(30, k++);
}