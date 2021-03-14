/*
=======================================================================================================================================
+ 문제 제목 +
=======================================================================================================================================
' 큰 수 만들기 ☆☆
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
' 예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24]를 만들 수 있습니다. 이 중 가장 큰 숫자는 94입니다.
' 문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k개의 수를 제거했을 때 만들 수 있는 수
  중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
' k는 1이상 number의 자릿수 미만인 자연수입니다.
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
' number : "1924", k : 2, return : "94"
' number : "1231234", k : 3, return : "3234"
' number : "4177252841", k : 4, return : "775841"
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' 
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-03-13-Sat : 코딩 시작
                   number 배열의 자리가 변하지 않도록 다시 코딩해야함
                   가능한 숫자의 유형 모두 구하는 for문 재코딩 필요
' 2021-03-14-Sun : 코딩 처음부터 다시 시작
                   number 배열 숫자로 바꾸기 성공
                   숫자를 한 글자씩 split 배열에 저장
                   split 배열 순서 원위치
=======================================================================================================================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *number, int k)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char *answer = (char *)malloc(sizeof(int) * (sizeof(number) - k));
    int num = 0;
    int split[4]={0};
    int temp = 0;
    int i = 0;
    int new_temp[2]={0};

    // number 배열로 int형으로 변환
    num = atoi(number);

    // num을 숫자 하나씩 배열에 저장 (거꾸로)
    while (1)
    {
        split[i] = num % 10;
        num /= 10;
        i++;
        if (num < 10)
        {
            split[i] = num;
            break;
        }
    }

    // split 배열 순서 원위치
    for(int i=0;i<sizeof(split)/8;i++){
        temp=split[i];
        split[i]=split[sizeof(split)/4-i-1];
        split[sizeof(split)/4-i-1]=temp;
    }

    // split 출력
    for (int i = 0; i < sizeof(split) / 4; i++)
    {
        printf("split[%d] = %d\n", i, split[i]);
    }

    // 배열의 수를 sizeof(split)/4-k 자리수로 만들어 새로운 배열에 저장
    while(1){
        
    }

    return answer;
}

int main(void)
{
    printf("%s\n", solution("1249", 2));
}