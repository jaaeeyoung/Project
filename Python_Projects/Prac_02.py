'''
=======================================================================================================================================
+ 문제 +
=======================================================================================================================================
스킬트리
=======================================================================================================================================
+ 문제 설명 +
=======================================================================================================================================
' 선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.
' 예를 들어 선행 스킬 순서가 스파크 > 라이트닝 볼트 > 썬더 일 때, 썬더를 배우려면 먼저 라이트닝 볼트를 배워야하고, 라이트닝 볼트를 배우려면 먼
  저 스파크를 배워야 합니다.
' 위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 스파크 > 힐링 > 라이트닝 볼트 > 썬더 와 같은 스킬트리는 가능하지
  만, 썬더 > 스파크 나 라이트닝 볼트 > 스파크 > 힐링 > 썬더 와 같은 스킬트리는 불가능합니다.
' 선행 스킬 순서 skill과 유저들이 만든 스킬트리를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는 solution
  함수를 작성해주세요.
=======================================================================================================================================
+ 제한 사항 +
=======================================================================================================================================
' 스킬은 알파벳 대문자로 표기하며, 모든 문자열은 알파벳 대문자로만 이루어져있습니다.
' 스킬 순서와 스킬트리는 문자열로 표기합니다.
' 예를 들어, C > B > D 라면 "CBD"로 표기합니다.
' 선행 스킬 순서 skill의 길이는 1 이상 26 이하이며, 스킬은 중복해 주어지지 않습니다.
' skill_trees는 길이 1 이상 20 이하인 배열입니다.
' skill_trees의 원소는 스킬을 나타내는 문자열입니다.
' skill_trees의 원소는 길이가 2 이상 26 이하인 문자열이며, 스킬이 중복해 주어지지 않습니다.
=======================================================================================================================================
+ 입출력 예 +
=======================================================================================================================================
' skill : "CBD"
' skill_trees : ["BACDE", "CBADF", "AECB", "BDA"]
' return : 2
=======================================================================================================================================
+ 입출력 예 설명 +
=======================================================================================================================================
' "BACDE" : B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트리입니다.
' "CBADF" : 가능한 스킬트리입니다.
' "AECB" : 가능한 스킬트리입니다.
' "BDA" : B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트리입니다.
=======================================================================================================================================
+ 수정 기록 +
=======================================================================================================================================
' 2021-03-13-Sat : 코딩 시작
=======================================================================================================================================
'''

def solution(skill, skill_trees):
    answer = 0
    temp = [[0] * len(skill_trees[0]) for _ in range(len(skill_trees))]

    # skill_trees중 skill과 같은 원소가 있다면 temp에 추가
    for i in range(len(skill_trees)):
        for j in range(len(skill_trees[i])):
            for k in range(len(skill)):
                if skill_trees[i][j]==skill[k]:
                    temp.append(skill_trees[i][j])

    for i in range(skill_trees):
        for j in range(skill_trees[i]):
            print(temp,' ')

    return answer

solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]) # 2
# solution("CBD", ["CAD"]) # 0
# solution("CBD", ["AEF", "ZJW"]) # 2
# solution("REA", ["REA", "POA"]) # 1
# solution("CBDK", ["CB", "CXYB", "BD", "AECD", "ABC", "AEX", "CDB", "CBKD", "IJCB", "LMDK"]) # 4
# solution("BDC", ["AAAABACA"]) # 0
# solution("CBD", ["C", "D", "CB", "BDA"]) # 2