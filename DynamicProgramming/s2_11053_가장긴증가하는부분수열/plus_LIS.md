# 부분 수열이란?
- 본래 수열에서 일부 숫자를 지워 만들 수 있는 수열

<br>

# LIS란?
- Logest Increasing Subsequence
- 가장 긴 증가하는 부분 수열
- 오름차순으로 증가하는 부분 수열 중에서 가장 긴 (원소의 개수가 많은) 수열을 의미

<br>

# LIS 구하는 두 가지 방법
- DP를 사용하는 알고리즘 (O(N^2))
  - dp[i] = (0 ~ (i - 1)번째 인덱스 중 i번째 수보다 작은 수들에 대하여, 이 수들로 끝나는 가장 긴 증가하는 부분 수열의 길이의 최댓값 + 1)
  - 최종 LIS 길이는 dp값들 중 가장 큰 값
- Binary Search(이분 탐색)을 사용하는 알고리즘 (O(NlogN))


<br>
.  
.  
.  
The update will continue...
