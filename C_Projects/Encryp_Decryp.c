/*
=======================================================================================================================================
+ 프로그램 설명 +
=======================================================================================================================================
' 암호화 및 복호화 프로그램
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' 
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-06-17-THU : 코딩 시작
                   파일 입출력 구현
                   파일의 내용 추출 구현
=======================================================================================================================================
+ 참고 +
=======================================================================================================================================
' 파일 입출력 기본 함수 설명 :
  https://m.blog.naver.com/vjhh0712v/221498090408
' C언어 유니코드 사용법 :
  https://insalat.tistory.com/1
=======================================================================================================================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{

    setlocale(LC_ALL, "");
    /*
    LC_ALL(locale all)은 매크로 상수
    "" : 해당 환경의 로케일을 따르겠다는 의미
    */

    FILE *fp;
    char file_buff[100];
    //char *plain_text=malloc(sizeof(file_buff)*10);
    wchar_t *plain_text=Lmalloc(sizeof(file_buff)*10);
    char temp;


    printf("sizeof(plain_text) = %d\n", sizeof(plain_text));
    //printf("strlen(plain_text) = %d\n", strlen(plain_text));
    memset(plain_text, 0, sizeof(plain_text)); // plain_text를 0으로 초기화

    fp = fopen("test.txt", "r");
    /*
    FILE *fopen(const char *name, const char *mode)
    : 파일 열기를 실패하면 NULL 반환
    ' name : 파일의 이름, 경로
    ' mode : 설졍
      r : 읽기모드로 파일 열기
      w : 쓰기 모드로 파일 생성, 파일이 존재하면 기존 내용이 지워짐
      a : 추가 모드로 파일 생성, 파일이 있으면 데이터가 끝에 추가됨
      r+ : 읽기와 쓰기 모드로 파일 열기, 파일이 반드시 존재해야함
      w+ : 읽기와 쓰기 모드로 파일을 생성, 파일이 존재하면 새 데이터가 기존 데이터를 덮어씀
      a+ : 읽기와 추가 모드로 파일 열기, 파일이 존재하면 데이터가 파일 끝에 추가됨, 읽기는 어떤 위치에서나 가능
      b+ : 이진 파일 모드로 파일 열기
    */

    // 파일 열기를 성공했는지 실패했는지 여부 확인
    if (fp == NULL)
    {
        printf("파일열기 실패\n");
    }
    else
    {
        printf("파일열기 성공\n");
    }

    // 파일 불러오기
    while (fgets(file_buff, sizeof(file_buff), fp) != NULL)
    { // 파일을 한 줄씩 읽어옴
        printf("%s", file_buff);
        //printf("plain_text : %s\n", plain_text);
        strcat(plain_text, file_buff);           // plain_text 뒤에 file_buff를 붙임
        memset(file_buff, 0, sizeof(file_buff)); // file_buff를 0으로 초기화
    }

    fclose(fp);
    /*
    int fclose(FILE *stream)
    : 정상적으로 파일을 닫는 경우 0 반환, 실패한 경우 -1 반환
    */

    //printf("\n1\nplain_text :\n%s\n", plain_text);
    wprintf(L"\n1\nplain_text :\n%s\n", plain_text);
    //printf("%c%c%c%c%c%c%c", plain_text[0], plain_text[1], plain_text[2], plain_text[3], plain_text[4], plain_text[5], plain_text[6]);

    for (int i = 0; i < strlen(plain_text) / 2; i++)
    {
        temp = plain_text[i];
        plain_text[i] = plain_text[strlen(plain_text) - 1];
        plain_text[strlen(plain_text) - 1] = temp;
    }

    wprintf(L"\n1\nplain_text :\n%s\n", plain_text);
    
    return 0;
}