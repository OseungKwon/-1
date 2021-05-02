#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void input(int arr[2]) {
	for (int i = 0; i < 35; i++) {
		arr[i] = i;
		printf("%d ��° ��: ", arr[i] + 1);
		scanf("%d", &arr[i]);

		if ((i + 1) % 7 == 0)
			printf("\n");
	}

}

void Encryption(int arr[], int row, char key) {
	for (int i = 0; i < row; i++) {
		arr[i] = arr[i] ^ key;
	}
}

void Decrypted(int arr[], int row, char key) {
	for (int i = 0; i < row; i++) {
		arr[i] = arr[i] ^ key;
	}
}

void SwithToArr(FILE* fp, int result[], int row) {

	char buffer[400];
	char* sArr[400] = { NULL, };
	int i = 0;

	fp = fopen("sample.txt", "r");
	fgets(buffer, sizeof(buffer), fp);
	char* ptr = strtok(buffer, " ");

	while (ptr != NULL) {
		sArr[i] = ptr;	//4�ڸ��� �ӽ�����
		i++;
		ptr = strtok(NULL, " ");
	}
	for (int i = 0; i < row; i++)
	{
		if (sArr[i] != NULL) {
			result[i] = atoi(sArr[i]);
		}
	}
	fclose(fp);
}



int main(void) {
	FILE* fp;
	int num[35];
	int result[35];
	int buf[2][2];
	int count = 0;
	int key;

	int row = sizeof(num) / sizeof(num[0]); //�迭 ����ũ�� ���ϱ�

	if ((fp = fopen("sample.txt", "r")) == NULL) {	//���� ���� Ȯ��

		fp = fopen("sample.txt", "w");	//���� ����
		if (fp == NULL) {
			puts("���Ͽ��� ����");
			return -1;
		}

		input(num);

		printf("key�� �Է����ּ���: ");
		scanf("%d", &key);
		Encryption(num, row, key);

		for (int i = 0; i < 35; i++) {
			printf("%d\t", num[i]);
			fprintf(fp, "%d ", num[i]);
		}
		fclose(fp);

	}
	else {
		printf("\n��ȣ�� Ǯ�ڽ��ϴ�\n");
		SwithToArr(fp, result, row);

		printf("key�� �Է����ּ���: ");
		scanf("%d", &key);



		puts("");
		Decrypted(result, row, key);

		while (getchar() != '\n');
		puts("");
		printf("�䱸�ϴ� ���� 2���� �Է��ϼ���: ");
		scanf("%d %d", &buf[0][0], &buf[1][0]);



		for (int i = 0; i < 2; i++) {
			while (buf[i][0] != count) {
				buf[i][1] = result[count];
				count++;
			}

		}
		printf("%d: %d\n%d: %d", buf[0][0], buf[0][1], buf[1][0], buf[1][1]);
	}

	printf("\n");
	system("pause");
	return 0;


}