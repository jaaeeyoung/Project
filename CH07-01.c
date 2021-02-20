// 프로그램 사용자로부터 양의 정수를 하나 입력 받아서, 그 수만큼 "Hello World!"를 출력하는 프로그램 작성
#include <stdio.h>
int main(void)
{
    printf("양의 정수 하나를 입력하세요 >> ");
    int num = 0;
    scanf("%d", &num);
    while(num){
        printf("Hello World!\n");
        num--;
    }
    return 0;
}