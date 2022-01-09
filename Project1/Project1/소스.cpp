#include<stdio.h>
#include<stdlib.h>


int main(void) {


	int A[28];
	for (int i = 0; i < 28; i++) {

		A[i] = { -1 };
	}

	
	char N[100] = "";
	gets_s(N, sizeof(N));

	int R = 0;
	for (int i = 0; i < 101; i++) {

		if (N[i] == '\0') break;

		if (N[R] == N[i] && N[i] != '1' && N[R] != '1') {

			N[i] = '1';
			R++;

		}



		int k = 0;					// Q는 몇 번째인지를 나타내기ㅏ 위함. k는 for 반복문 사용
		int Q = 0;
		int J = 0;
		for (char a = 'a'; a <= 'z'; a++) {


			if (N[k] == '\0') break;


			if (N[k] == a) {
				A[J] = Q;
				Q++;
				k++;
				a = 'a';
				J = 0;
			}

			else 	J++;

		}



		for (int i = 0; i < 26; i++) {

			printf("%d ", A[i]);


		}
		return 0;
	}
}