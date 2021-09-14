'''
=======================================================================================================================================
+ 문제 +
=======================================================================================================================================
시저 암호 ☆
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 합니다. 예를 들어 "AB"는 1만큼 밀면 
  "BC"가 되고, 3만큼 밀면 "DE"가 됩니다. "z"는 1만큼 밀면 "a"가 됩니다. 문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수, 
  solution을 완성해 보세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' 공백은 아무리 밀어도 공백입니다.
' s는 알파벳 소문자, 대문자, 공백으로만 이루어져 있습니다.
' s의 길이는 8000이하입니다.
' n은 1 이상, 25이하인 자연수입니다.
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
s	    n	result
"AB"	1	"BC"
"z"	    1	"a"
"a B z"	4	"e F d"
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' 
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-09-14-TUE : 문제 파악
                   완성
=======================================================================================================================================
'''

def solution(s, n):
    answer = ''
    s = list(s)
    for i in range(len(s)):
        if s[i] != ' ':
            if s[i].islower() == True:
                if ord(s[i]) + n > ord('z'):
                    s[i] = chr(ord('a') + (n - (ord('z') - ord(s[i])) - 1))
                else:
                    s[i] = chr(ord(s[i]) + n)
            else:
                if ord(s[i]) + n > ord('Z'):
                    s[i] = chr(ord('A') + (n - (ord('Z') - ord(s[i])) - 1))
                else:
                    s[i] = chr(ord(s[i]) + n)

    answer = ''.join(s)

    return answer

#print(solution("AB", 1)) # "BC"
#print(solution("z", 1)) # "a"
#print(solution("a B z", 4)) # "e F d"
#print(solution('AaZz', 25)) # 'ZzYy'
print(solution('bC', 25)) # 
# a b c d e f g h i j k l m n o p q r s t u v w x y z
# 