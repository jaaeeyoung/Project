/*
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 정수 배열 numbers가 주어집니다.
' numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록
  solution 함수를 완성해주세요.
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
=======================================================================================================================================
*/

#include <stdio.h>
int main(void)
{
    int numbers[4] = {0};
    int result[100] = {0};
    int numbers_len = 0;
    int count = 0;

    int cnt = 0;
    int tmp = 0;
    int flag = 0;

    printf("숫자를 입력 >> ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &numbers[i]);
    }

    numbers_len = sizeof(numbers) / 4;
    // 배열의 모든 값 합계 구하기
    for (int i = 0; i < numbers_len; i++)
    {
        for (int j = 0; j < numbers_len; j++)
        {
            for (int k = j + 1; k < numbers_len; k++)
            {
                result[count] = numbers[j] + numbers[k];
                count++;

                for (int l = 0; l < count; l++)
                {
                    if (result[l] == result[count - 1])
                    {
                        if (l != count - 1)
                        {

                            result[count - 1] = 0;
                            count--;
                            flag = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", result[i]);
    }

    // result 배열 오름차순 정렬
    while (1)
    {
        cnt = 0;
        if (flag == 1)
        {
            for (int i = 0; i < count-1; i++)
            {
                if (result[i] > result[i + 1])
                {
                    tmp = result[i];
                    result[i] = result[i + 1];
                    result[i + 1] = tmp;
                    cnt++;
                    printf("count = %d\n", cnt);
                }
            }
        }
        else if (flag == 0)
        {
            for (int i = 0; i < count - 2; i++)
            {
                if (result[i] > result[i + 1])
                {
                    tmp = result[i];
                    result[i] = result[i + 1];
                    result[i + 1] = tmp;
                    cnt++;
                    printf("count = %d\n", cnt);
                }
            }
        }

        if (cnt == 0)
        {
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}