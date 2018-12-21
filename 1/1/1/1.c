#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _student
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	float avg;
}student;

int main(void)
{
	student data[5];
	FILE *str1;
	FILE *str2;
	int i;

	str1 = fopen("D://gd.txt", "r");
	str2 = fopen("D://go.txt", "w");

	if (str1 == NULL || str2 == NULL)
	{
		printf("檔案開啟失敗\n");
	}
	else
	{
		fprintf(str2, "姓名\t國文\t英文\t數學\t總和\t平均\n");
		for (i = 0; i < 5; i++)
		{
			
			fscanf(str1, "%s", data[i].name);
			fscanf(str1, "%d", &data[i].chinese);
			fscanf(str1, "%d", &data[i].english);
			fscanf(str1, "%d", &data[i].math);

			data[i].sum = data[i].chinese + data[i].english + data[i].math;
			data[i].avg = data[i].sum / 3.0;
			fprintf(str2, "%s\t%d\t%d\t%d\t%d\t%.2f\n",
				data[i].name, data[i].chinese, data[i].english, data[i].math,
				data[i].sum, data[i].avg);
		}
		fclose(str1);
		fclose(str2);
	}
	system("pause");
	return 0;
}