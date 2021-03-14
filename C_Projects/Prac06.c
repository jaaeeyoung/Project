/*
=======================================================================================================================================
+ 문제 제목 +
=======================================================================================================================================
' 3진법 뒤집기 ☆☆
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해
  주세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' n은 1 이상 100,000,000 이하인 자연수입니다.
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
' n = 45, result = 7
' n = 125, result = 229
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' n(10진법) : 45, n(3진법) : 1200, 앞뒤 반전(3진법) : 0021, 10진법으로 표현 = 7
' n(10진법) : 125, n(3진법) : 11122, 앞뒤 반전(3진법) : 22111, 10진법으로 표현 = 229
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-03-14-Sun : 코딩 시작
                   3진법 변환
                   10진법 변환
=======================================================================================================================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int third[100]={0};
    int i=0;
    int count=0;

    // n을 3진법으로 변환
    while(1){
        third[i]=n%3;
        n=n/3;
        i++;
        count++;
        if(n==0){
            break;
        }
    }

    // third 배열에서 count 횟수만큼의 숫자 빼고 모두 10진법으로 표현
    for(int i=0;i<count;i++){
        if(third[i]==0){ // third배열의 원소가 0이면 다음 원소 검사
            continue;
        }

        // 각 원소의 자리에 맞는 pow(3, x) 함수
        for(int j=0;j<count-i-1;j++){
            third[i]=third[i]*3;
        }
        answer+=third[i];
    }

    return answer;
}

int main(void){
    printf("%d", solution(125));
}