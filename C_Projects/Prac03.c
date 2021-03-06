/*
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 피보나치 수는 F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2)가 적용되는 수 입니다.
' 예를 들어
  F(2) = F(0) + F(1) = 0 + 1 = 1
  F(3) = F(1) + F(2) = 1 + 1 = 2
  F(4) = F(2) + F(3) = 1 + 2 = 3
  F(5) = F(3) + F(4) = 2 + 3 = 5
  와 같이 이어집니다.
' 2 이상의 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수, solution을 완성해 주세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' n은 1 이상, 100,000 이하인 자연수입니다.
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
  n   return
  3     2
  5     5
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' 피보니치수는 0번째부터 0, 1, 1, 2, 3, 5, ... 와 같이 이어집니다.
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-03-03-wED : 코딩 시작
                   코드 제출 시 7 ~ 14 실패
=======================================================================================================================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 피보나치 수열을 구하고 n번째 값을 1234567로 나눈 나머지를 구하는 함수
int solution(int n)
{
    int answer = 0;
    if (n<2)
    {
        answer+=n; // 0번째일때 answer=0, 1번째 일 때 answer=1
    }
    else
    {                                                                                   // 그 외에는 피보나치 수열의 직전 값과 전전 값을 더한 것
        answer = ((solution(n - 1) % 1234567) + (solution(n - 2) % 1234567)) % 1234567; // solution(x)의 값이 int 자료형의 범위를 넘지 않도록
    }                                                                                   // (A + B) % C = (A % C) + (B % C) % C 이용
    return answer;                                                                      // 구해진 피보나치 수를 1234567로 나눈 나머지 return
}

int main(void)
{
    int n = 0;
    printf("숫자 n을 입력 >> ");
    scanf("%d", &n);
    printf("%d\n", solution(n));
}