/*
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 초 단위로 기록된 주식 가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를
  완성하세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
' prices의 길이는 2 이상 100,000 이하입니다.
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
' prices = [1, 2, 3, 2, 3]
' return = [4, 3, 1, 1, 0]
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' 1초 시점의 \1은 끝까지 가격이 떨어지지 않았습니다.
' 2초 시점의 \2은 끝까지 가격이 들어지지 않았습니다.
' 3초 시점의 \3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
' 4초 시점의 \2은 1초간 가격이 떨어지지 않았습니다.
' 5초 시점의 \3은 0초간 가격이 떨어지지 않았습니다.
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-03-02-Tue : 코딩 시작
                   코딩한 부분 주석 처리
                   입력을 [1, 2, 3, 2, 3]으로 했을 때 [4, 3, 2, 1, 0]으로 출력되는 오류 (세 번째 원소 오답) -> 보완 필요
=======================================================================================================================================
*/

#include <stdio.h>
int main(void)
{
    int prices[100000] = {0}; // 주식 가격
    int prices_len = 0;       // 주식 가격의 길이
    int count = 0;            // 주식 가격이 떨어지지 않는 시간을 count
    int answer[100000] = {0}; // 결과 배열

    // 주식 가격의 길이 입력
    printf("주식 가격의 길이를 입력 >> ");
    scanf("%d", &prices_len);
    // 주식 가격 입력
    printf("주식 가격을 입력 >> ");
    for (int i = 0; i < prices_len; i++)
    {
        scanf("%d", &prices[i]);
    }

    // 주식 가격 크기 비교
    for (int i = 0; i < prices_len; i++)
    {
        count = 0;
        for (int j = i + 1; j < prices_len; j++) // 현재 원소와 다음 원소의 크기 비교
        {
            if (i <= j) // 현재 원소의 크기가 다음 원소의 크기보다 작거나 같으면
            {
                count++; // 가격이 떨어지지 않아 숫자 count
            }
        }
        answer[i] = count; // 해당 원소의 위치에 가격이 떨어지지 않은 횟수 저장
    }

    // 결과 출력
    for (int i = 0; i < prices_len; i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}