-------------------- < Segement Tree > --------------------

// 1. 세그먼트 트리란?
    
// 2. 세그먼트 트리의 기본 원리
    // - 각 노드는 특정 구간을 대표함
    // - 노드들은 이진 트리 구조를 이룸
    //    (부모 노드가 대표하는 구간은 자식 노드 두 개가 대표하는 구간의 합집합)
    // + 수열의 총 길이는 어떤 자연수여도 상관 없지만, 2^k 꼴일 때 비재귀 방식의 구현이 편리해짐
    //    (보통, 원래 수열의 길이 N을 넘는 가장 작은 2^k를 선택)

// 2-1. 세그먼트 트리의 기본 원리 - 구간 쪼개기
    // 길이가 2 이상인 어떤 구간에 대해, 그 구간을 포함하는 가장 아래쪽


    

#include <stdio.h>
