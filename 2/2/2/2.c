#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct clientData
{
	int accNum;
	char lastName[15];
	char firstName[10];
	double balence;
};

int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0;
	struct clientData client = { 0,"","",0.0 };

	pRead = fopen("D://cr.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}
	pWrite = fopen("D://cr_bin.txt", "wb");
	if (NULL == pWrite)
	{
		fclose(pRead);
		return 0;
	}

	while (!feof(pRead))
	{
		fscanf(pRead, "%d%s%s%lf", &client.accNum, client.lastName, client.firstName, &client.balence);
		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balence);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("�HŪ����r�ɪ�ACSII��ơA����s�G�i��ۮ��ɮ�\n\n");
	system("pause");
	printf("\nŪ���G�i�����ɮסA�î榡�Ʀp�U:\n");
	if ((cfPtr = fopen("d://cr_bin.txt", "rb")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "acct", "Last Name", "First Name", "Balance");
		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balence);
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);
	}
	system("pause");
	return 0;
}
