#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


void printFood(vector<vector<int> > food) {
  for(int i = 0; i < food.size(); i++) {
    for(int j = 0; j < food.size(); j++) {
      cout << food[i][j] << " ";
    }
    cout << endl;
  }
}

void printTrees(vector<vector<vector<int> > > trees) {
  for(int i = 0; i < trees.size(); i++) {
    for(int j = 0; j < trees.size(); j++) {
      for(int k = 0; k < trees[i][j].size(); k++) {
        cout << trees[i][j][k] << " ";
      }
      cout << "-";
    }
    cout << endl;
  }
}


bool compare(int a, int b) {
  return a < b;
}

void springSummer(vector<vector<int> >& food, vector<vector<int> >&  deathFood, vector<vector<vector<int> > >& trees) {
  for(int i = 0; i < food.size(); i++) {
    for(int j = 0; j < food.size(); j++) {
      if ((trees[i][j]).size() > 0) {
        sort(trees[i][j].begin(), trees[i][j].end(), compare);
        
        for(int k = 0; k < trees[i][j].size(); k++){
          if (food[i][j] >= trees[i][j][k]) {
              food[i][j] -= trees[i][j][k];
              trees[i][j][k] += 1;
          } else {
              deathFood[i][j] += trees[i][j][k] / 2;
              trees[i][j].erase(trees[i][j].begin() + k);
              k--;  // Adjust index after erase
          }
      }
      }
    }
  }
  // cout << "==================" << endl;
  // cout << "spring food" << endl;
  // printFood(food);
  // cout << "==================" << endl;
  // cout << "spring deathFood" << endl;
  // printFood(deathFood);
  // cout << "==================" << endl;
  // cout << "spring trees" << endl;
  // printTrees(trees);

  for(int i = 0; i < food.size(); i++) {
    for(int j = 0; j < food.size(); j++) {
      food[i][j] += deathFood[i][j];
      deathFood[i][j] = 0;
    }
  }
  // cout << "==================" << endl;
  // cout << "spring food" << endl;
  // printFood(food);
}

void fall(vector<vector<vector<int> > >& trees) {

  int arr[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

  for(int i = 0; i < trees.size(); i++) {
    for(int j = 0; j < trees.size(); j++) {
      if (trees[i][j].size() > 0) {
        for(int k = trees[i][j].size()-1; k >= 0; k--){
          if (trees[i][j][k] % 5 == 0) {
            // cout << "tree : " << trees[i][j][k] << "    i : " << i << "   j : " << j << endl;
            for(int z = 0; z < 8; z++) {
              if ((0 <= i + arr[z][0] && i + arr[z][0] < trees.size()) && (0 <= j + arr[z][1] && j + arr[z][1] < trees.size())) {
                // cout << "x : " << i + arr[z][0] << "   y : " << j + arr[z][1] << endl;
                trees[i + arr[z][0]][j + arr[z][1]].push_back(1);
              }
            }
          }
        }
      } 
    }
  }
}

void winter(vector<vector<int> > addFood, vector<vector<int> >& food) {
  for(int i = 0; i < food.size(); i++) {
    for(int j = 0; j < food.size(); j++) {
      food[i][j] += addFood[i][j];
    }
  }
  // cout << endl;
  // cout << endl;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  int cnt = 0;

  cin >> n >> m >> k;

  vector<vector<int> > food(n, vector<int>(n, 0));
  vector<vector<int> > addFood(n, vector<int>(n, 0));
  vector<vector<int> > deathTree(n, vector<int>(n, 0));
  vector<vector<vector<int> > > trees(n, vector<vector<int> >(n, vector<int>()));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int n;
      cin >> n;
      food[i][j] = 5;
      addFood[i][j] = n;
    }
  }

  // cout << endl;
  // cout << "out food" << endl;
  // printFood(food);
  // cout << "end food" << endl;

  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    trees[x-1][y-1].push_back(z);
  }


  // cout << "out trees" << endl;
  // printTrees(trees);
  // cout << "end trees" << endl;

  for(int i = 0; i < k; i++) {
    springSummer(food, deathTree, trees);
    fall(trees);
    winter(addFood, food);
  }

  for(int i = 0; i < trees.size(); i++) {
    for(int j = 0; j < trees.size(); j++) {
      // cout << "i : " << i << "   j : " << j << endl;
      cnt += trees[i][j].size();
    }
  }

  // cout << "=====================================" << endl;
  // printTrees(trees);
  cout << cnt << endl;
}

/*
(r, c) : 행렬
N : 행렬 갯수
M : 나무 구매 갯수
K : 년

vec - vec : 양분 2차원 배열
arr - arr - vec : 2차원 배열, 각 요소는 vec 존재하는 나무
vec - vec : 죽은 나무들 양분, /2로 들어가며 k 감소 시 양분 배열에 추가 필요 


봄 : 양분 먹고 나이 1 증가
  나이 어린 나무부터 양분 먹음
  양분 없으면 바로 죽음
  => if vector size > 0 작은 순으로 정렬
  => 순차대로 양분 먹음, 양분 못먹는 다음 index부터는 /2(버림)해서 저장

여름 : 봄에 죽은 나무가 양분으로 변함
  죽은 나무 /2만큼 양분으로 추가, 소수점 아래 버림
  => 저장한 /2 배열, 양분 배열로 추가

가을 : 나무 번식
  나이가 5배수여야되며 인접한 칸에 나이가 1인 나무가 생김
  => 가장 큰 = 정렬 된 나무들 중 가장 마지막 index가 5의 배수이면 주변에 나무 1씩 추가

겨울 : 땅에 양분 추가
  이게 입력 받은 2차원 배열
###########################################################
###########################################################
###########################################################

배열에 대해 다시 생각
int arr[2], 이는 배열의 요소가 int라는 의미이고 
vector<int> arr[2], 이는 배열의 요소가 int type의 vector라는 의미
  때문에 vector<int> arr[2][2], 2차원 배열이며 각 요소들은 vector
  [
    [
      [], [], []
    ]
  ]

2차원 배열의 경우도 결국 메모리에 연속적으로 저장되는 형태이기에 포인터 변수 이용하면 
1차원 배열처럼 접근 가능하다

문제 제대로 읽자, 처음에 5 시작이다
*/