#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void input(int arr[2]) {
	for (int i = 0; i < 35; i++) {
		arr[i] = i;
		printf("%d 번째 수: ", arr[i] + 1);
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
		sArr[i] = ptr;	//4자리수 임시저장
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

	int row = sizeof(num) / sizeof(num[0]); //배열 세로크기 구하기

	if ((fp = fopen("sample.txt", "r")) == NULL) {	//파일 유무 확인

		fp = fopen("sample.txt", "w");	//파일 실행
		if (fp == NULL) {
			puts("파일오픈 실패");
			return -1;
		}

		input(num);

		printf("key를 입력해주세요: ");
		scanf("%d", &key);
		Encryption(num, row, key);

		for (int i = 0; i < 35; i++) {
			printf("%d\t", num[i]);
			fprintf(fp, "%d ", num[i]);
		}
		fclose(fp);

	}
	else {
		printf("\n암호를 풀겠습니다\n");
		SwithToArr(fp, result, row);

		printf("key를 입력해주세요: ");
		scanf("%d", &key);



		puts("");
		Decrypted(result, row, key);

		while (getchar() != '\n');
		puts("");
		printf("요구하는 수를 2개를 입력하세요: ");
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