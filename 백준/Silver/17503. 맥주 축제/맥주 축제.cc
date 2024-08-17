/*
N일 동안 맥주 축제

K 종류의 맥주 무료 제공
  선호도, 도수 레벨 존재
    도수 레벨이 간 레벨보다 높으면 맥주병 발병

하루에 맥주 1병 가능, 받았던 종류 다시 받을 수 없음

N일 동안 참가해 N 종류의 맥주를 마시려 함

맥주 N개의 선호도 M 을 넘으려함

입력
  N M K
  for K (선호도, 도수 레벨)

1. 입력 받는 코드 세팅

# 알고리즘
  선호도 M을 넘길 수 있는지
    없다면 : -1 출력
    넘길 수 있다면 최소한으로 간에 데미지 주는 경우로

  간 데미지를 infinity로 세팅
  조합 진행
    if 1st index >= M && 2st sum < demage 조건으로 최신화

  :::::::::::::: 조합으로 해결하려다가 메모리 초과 발생

  우선 순위 큐 이용
    도수 기준 오름차순 정렬
    선호도 만족할 때 까지 맥주 추가하면서 확인
  ref : https://jinho9610.tistory.com/36

sort의 경우 less-than, 작다를 기준으로 하기에 a < b : a가 더 작을 수록 우선순위
priority queue의 경우는 기본적으로 greater-than, 내림차순으로 정렬된 힙을 제공하고 있기 때문에 오름차순으로 정렬하고자 할 땐 a < b의 반대인 a > b 정의 필요
  sort와는 다르게  a < b : 큰 값 b가 작은 값 a 보다 우선 순위라는 의미, 이는 큰 값이 큐의 우선 순위가 되며 최대 힙을 의미(내림차순)

sort는 less-than, a를 기준으로 a > b, a가 큰 경우 우선 순위 = 내림차순
priority queue의 경우 greater-than, a를 기준으로 a < b, a보다 큰 수들을 우선 순위 = 내림차순
  a > b, a 보다 작은 순들을 우선 순위 = 오름차순
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

int n, m, k;
struct cmp {
  bool operator()(int a, int b) {
    return a > b;
  }
};

bool _operator(std::pair<int, int> p1, std::pair<int, int> p2) {
  return p1.second < p2.second;
}

int main() { 
  std::vector< std::pair<int, int> > beers;
  std::priority_queue<int, std::vector<int>, cmp> pq;
  int preference = 0;
  std::cin >> n >> m >> k;

  for(int i = 0; i < k; i++) {
    int a, b;
    std::cin >> a >> b;
    beers.push_back(std::make_pair(a, b));
  }

  sort(beers.begin(), beers.end(), _operator);

  // std::cout << "beers" << std::endl;
  // for(std::pair<int, int> i : beers) {
  //   std::cout << i.first << "  " << i.second << std::endl;
  // }
  // std::cout << std::endl;

  for(auto beer : beers) {
    pq.push(beer.first);
    preference += beer.first;

    if (pq.size() > n) {
      preference -= pq.top();
      pq.pop();
    }
    if (pq.size() == n && preference >= m) {
      std::cout << beer.second << std::endl;
      return 0;
    } 
  }
  std::cout << -1 << std::endl;

}