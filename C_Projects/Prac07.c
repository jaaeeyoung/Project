/*
=======================================================================================================================================
+ 문제 제목 +
=======================================================================================================================================
' 2016년 ☆
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a, b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수,
  solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각 SUN, MON, TUE, WED, THU, FRI, SAT 입니다. 예를 들어 a=5, b=24라면 5월 24일
  은 화요일이므로 문자열 "TUE"를 반환하세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' 2016년은 윤년입니다.
' 윤년은 2월이 29일까지 존재
' 2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다.)
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
' a = 1, b = 31, result = "SUN" O 0
' a = 2, b = 29, result = "MON" O 0
' a = 3, b = 31, result = "THU"   0
' a = 4, b = 30, result = "SAT" O 0
' a = 5, b = 24, result = "TUE" O 
' a = 5, b = 31, result = "TUE"   0
' a = 6, b = 30, result = "THU"   0
' a = 7, b = 31, result = "SUN" O 0
' a = 8, b = 31, result = "WED" O
' a = 9, b = 30, result = "FRI" O 0
' a = 10, b = 31, result = "MON" O 0
' a = 11, b = 30, result = "WED" O 0
' a = 12, b = 31, result = "SAT" O 0
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' 
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-03-14-Sun : 코딩 시작
                   a월 이전까지의 요일 계산
                   a월 b일까지의 요일 계산
                   5월 24일 정답
                   Test Case 9, 13 오답 -> 보완 필요
' 2021-03-16-Tue : 마지막 count%7의 값이 0인 경우 count-1의 값이 존재하지 않아 이를 7로 설정
=======================================================================================================================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *solution(int a, int b)
{
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char *answer = (char *)malloc(sizeof(char) * 3);
    char day[7][3] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int count = 0;

    // answer 배열 0으로 초기화
    for (int i = 0; i < sizeof(answer); i++)
    {
        answer[i] = '\0';
    }

    // a월 이전까지의 요일 계산
    for (int i = 1; i < a; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            for (int j = 1; j <= 31; j++)
            {
                count++;
            }
            count %= 7;
        }
        else if (i == 2)
        {
            for (int j = 1; j <= 29; j++)
            {
                count++;
            }
            count %= 7;
        }
        else
        {
            for (int j = 1; j <= 30; j++)
            {
                count++;
            }
            count %= 7;
        }
    }

    // a월 b일까지의 요일 계산
    for (int i = 1; i <= b; i++)
    {
        count++;
    }
    count %= 7;

    if(count==0){ // count가 0인 경우 count-1의 index가 존재하지 않기 때문에
        count=7; // count를 7로 설정
    }
    answer[0] = day[count - 1][0];
    answer[1] = day[count - 1][1];
    answer[2] = day[count - 1][2];

    return answer;
}

int main(void)
{
    printf("1. answer = %s\n", solution(1, 31));
    printf("2. answer = %s\n", solution(2, 29));
    printf("3. answer = %s\n", solution(3, 31));
    printf("4. answer = %s\n", solution(4, 30));
    printf("5. answer = %s\n", solution(5, 31));
    printf("6. answer = %s\n", solution(6, 30));
    printf("7. answer = %s\n", solution(7, 31));
    printf("8. answer = %s\n", solution(8, 31));
    printf("9. answer = %s\n", solution(9, 30));
    printf("10. answer = %s\n", solution(10, 31));
    printf("11. answer = %s\n", solution(11, 30));
    printf("12. answer = %s\n", solution(12, 31));
}