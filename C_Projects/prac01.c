/*
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 정수 배열 numbers가 주어집니다.
' numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를
  완성해주세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' numbers의 길이는 2이상 100이하입니다.
' numbers의 모든 수는 0이상 100이하입니다.
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-02-20-Sat : 코딩 시작
                   배열의 모든 값 합계 코딩
                   오름차순 정렬
' 2021-03-02-Tue : 주석 추가 -> 보완 필요
                   main함수와 solution 함수로 구분
                   헤더 파일 <stdbool.h>, <stdlib.h> 추가
=======================================================================================================================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len*100); // 결과 배열
    int count = 0; // 합계 구할 때 합계가 저장될 answer배열의 위치
    int flag=0;

    int cnt = 0;
    int tmp = 0;

    // 배열의 모든 값 합계 구하기
    for (int i = 0; i < numbers_len; i++)
    {
        for (int j = 0; j < numbers_len; j++)
        {
            for (int k = j + 1; k < numbers_len; k++)
            {
                answer[count] = numbers[j] + numbers[k];
                count++;

                for (int l = 0; l < count; l++)
                {
                    if (answer[l] == answer[count - 1])
                    {
                        if (l != count - 1)
                        {

                            answer[count - 1] = 0;
                            count--;
                            flag=1;
                        }
                    }
                }
            }
        }
    }

    // answer 배열 오름차순 정렬
    while (1)
    {
        cnt = 0;
        if (flag == 1)
        {
            for (int i = 0; i < count-1; i++)
            {
                if (answer[i] > answer[i + 1])
                {
                    tmp = answer[i];
                    answer[i] = answer[i + 1];
                    answer[i + 1] = tmp;
                    cnt++;
                }
            }
        }
        else if (flag == 0)
        {
            for (int i = 0; i < count-2; i++)
            {
                if (answer[i] > answer[i + 1])
                {
                    tmp = answer[i];
                    answer[i] = answer[i + 1];
                    answer[i + 1] = tmp;
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {
            break;
        }
    }

    for(int i=0;i<count;i++){
        printf("%d ", answer[i]);
    }

    return answer;
}

int main(void)
{
    int numbers[100] = {0}; // 입력 배열
    int numbers_len = 0; // 입력 배열의 길이

    printf("배열의 길이를 입력 >> ");
    scanf("%d", &numbers_len);

    printf("숫자를 입력 >> ");
    for (int i = 0; i < numbers_len; i++)
    {
        scanf("%d", &numbers[i]);
    }

    solution(numbers, numbers_len);
    
    return 0;
}