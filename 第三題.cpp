#include<stdio.h>
#include <stdio.h>

struct clientData
{
	unsigned int StuNum;      // 4 bytes
	char Name[20];        // 20 bytes
	float average;       // 4 byte float , 8 bytes double
};

void CreateBlankFile(void);
void KeyInData(void);
void OutputFile(void);

int main(void)
{
	FILE* cfPtr;
	errno_t err;   // fopen_s
	int SelectFunction;
	// Open for read (will fail if file "crt_fopen_s.c" does not exist)


	printf("Select funtion (1:create blank file,2:Key in data, 3:Print file data, 0: Exit Program\n");
	scanf_s("%d", &SelectFunction);
	printf("\n");
	while (SelectFunction != 0)
	{
		if (SelectFunction == 1)
			CreateBlankFile();
		if (SelectFunction == 2)
			KeyInData();
		if (SelectFunction == 3)
			OutputFile();

		printf("Select funtion (1:create blank file,2:Key in data, 3:Print file data, 0: Exit Program\n");
		scanf_s("%d", &SelectFunction);
		printf("\n");
	}
}

void CreateBlankFile(void)
{
	FILE* cfPtr;
	errno_t err;   // fopen_s


	if ((err = fopen_s(&cfPtr, "accounts.dat", "wb")) != 0)
		puts("File could not be opened.");
	else
	{
		struct clientData blankClient = { 0,"" , 0.0 };

		for (unsigned int i = 1; i <= 100; ++i)
		{
			fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);  //將一個為原組為計的區塊資料寫到檔案中
		}

		fclose(cfPtr);
	}


}


void KeyInData(void)
{
	FILE* cfPtr;
	errno_t err;   // fopen_s

	if ((err = fopen_s(&cfPtr, "accounts.dat", "rb+")) != 0)
	{
		puts("File could not be opened.");
	}
	else
	{
		struct clientData client = { 0,"",0.0 };

		printf("Enter student number (1 to 100, 0 to end input:)");
		scanf_s("%d", &client.StuNum);

		while (client.StuNum != 0)
		{
			// printf("%s", "Enter lastname ,firstname,balance:");


			printf("%s", "Enter Name: ");
			scanf_s("%s", client.Name, 20);
			printf("\n");

			printf("%s", "Enter average: ");
			scanf_s("%f", &client.average);
			printf("\n");



			fseek(cfPtr, (client.StuNum - 1) * sizeof(struct clientData), SEEK_SET);
			fwrite(&client, sizeof(struct clientData), 1, cfPtr);
			printf("%s", "Enter student number: ");
			scanf_s("%d", &client.StuNum);
		}
		fclose(cfPtr);
	}

}
void OutputFile(void)
{
	FILE* cfPtr;
	errno_t err;

	if ((err = fopen_s(&cfPtr, "accounts.dat", "rb")) != 0)
	{
		puts("File could not be opened.");
	}

	else
	{
		printf("Student Number         Name         Average \n");
	}

	while (!feof(cfPtr))
	{
		struct clientData client = { 0,"",0.0 };

		int result = fread(&client, sizeof(struct clientData), 1, cfPtr);

		if (result != 0)
		{
			printf("%10d%18s%15.3f\n", client.StuNum, client.Name, client.average);
		}
	}
	fclose(cfPtr);
}