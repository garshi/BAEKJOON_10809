#include<stdio.h>


int main(void) {


	int A[28];										// a ~ z까지의 순서 표시를 위한 배열


	for (int i = 0; i < 28; i++) {					// A[] 배열을 전부 -1로 통일시키기 위한 반복문

		A[i] =  -1 ;
	}


	char N[102];								// 입력받을 문자열
	fgets(N, sizeof(N), stdin); 						// 문자열 입력 받기

	int R = 0;                  // R번째 문자를 기준으로 i(반복문)번째 문자와 중복되는지 확인하기 위한 숫자 
	int k = 0;				    // k는 for 반복문에서 사용

	int J = 0;



	for (int i = 1; i < 121; i++) {					// 앞의 숫자와 중복되는 숫자를 제외하는 반복문
	

		if ((N[R] == N[i] && N[i] != '1')) {			// R번째 문자를 i를 이용하여 a~ z까지 전부 비교
															//이때 i번쨰나 R번째 문자가 1이면 정지하기
			
			N[i] = '1';												//문자열 중 i번째 문자는 중복되므로 문자를
																	// 1로 바꾸어 없는 문자 취급

		}
		if (N[R] == '1') {
			R++;
			i = R;
		}
		if (N[i] == '\0') {

			R++;                                   // i번째 문자가 \0이라면, R번째 문자의 중복 확인 종료
			i = R;                             // R번째 문자확인 종료후 R+1번째 문자의 중복확인을 위해 i = R로 초기화
		}
		// 문자의 끝에서 반복문 return 
		
		if (N[R] == '\0') break;                      //확인하고 있는 R번째 문자가 '\0'이라면 반복문 중지
		


	}
	
	


	for (char a = 'a'; a <= 'z'; a++) {                              // 입력받은 문자열에 있는 알파벳을 판명하는 반복문
																			   // 변수는 a > z

		if (N[k] == '\0') break;                                       // k번째 문자가 \0일시 종료

		if (N[k] == '1') {

			k++;
			a = 'a';                                                    // Q+1번째 문자를 다시 a부터 시작해서 비교
			a--;
	
		}																// k번째 문자가 1일시 다음 문자 확인하기
		else if (N[k] == a) {       
																	 // 만약에 N[k]가 기호(a)일시
		
			
			A[J] = k;                                                   // Q번째에 있는 알파벳 , A[J] (알파벳 문자열) 
																		//   > Q번째에 있다를 나타내기 위해 A[J] = Q

		                                                       // Q번째 문자열에 있는 문자 판별 완료, 
																		//  이후 Q+1번째 문자열 판별을 위한 세팅

			k++;                                                        // K번째에 있는 문자열 판별 완료, K+1확인 >> 
																		// 이거 Q로 그냥 통일 시켜도 되나

			a = 'a';                                                    // Q+1번째 문자를 다시 a부터 시작해서 비교
			a--;
			J = 0;                                                      // J는 알파벳 순서(a번째 = 0번째) 초기화
		}

		else 	J++;                                                   // a와 동일하지 않은 문자라고 판단시 
																			 //   a+1 문자와 비교    

	}



	for (int i = 0; i < 26; i++) {
		printf("%d ", A[i]);                                       // 결과값 출력

	}

}
	

