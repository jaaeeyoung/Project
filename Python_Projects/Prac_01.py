'''
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
                   주석 처리 -> 보완 필요
                   Test 7 오류 -> 보완 필요
                   효율성 테스트 0점 -> 보완 필요
' 2021-03-03-Wed : 필요 없는 변수 제거
                   주석 처리
                   사용자 정의함수 solution 생성
=======================================================================================================================================
'''


def solution(prices):
    answer = []  # 결과 배열

    for i in range(len(prices)):  # answer 리스트 0으로 prices의 길이와 동일한 길이만큼 채워주기
        answer.insert(i, 0)

    for i in range(len(prices)):  # i = 주식 가격

        if i == len(prices):  # i의 index 번호가 prices 배열의 길이와 같으면
            answer.insert(i, 0)  # 해당 index의 값을 0으로 바꾸고
            break  # for문 나감

        for j in range(i+1, len(prices)):
            if prices[i] <= prices[j]:  # i번째 원소가 j번째 원소 보다 작거나 같으면 가격이 떨어지지 않았기 때문에
                answer[i] += 1

            else:
                answer[i] += 1
                break

    return(answer)


prices = input('주식 가격을 입력하세요 >> ').split()
print(solution(prices))
