#include <iostream>
#include <map>
#include <memory>

using namespace std;

struct Node {
  string name;
  map<string, unique_ptr<Node> > child;

  Node(string str) : name(str) {}
};

void printTree(Node* node, int depth = 0) {
  for(auto& child : node->child) {
    for(int i = 0; i < depth; i++){
      cout << "--";
    }
    cout << child.first << endl;
    printTree(child.second.get(), depth + 1);
  }
}

Node* createOrFindNode(map<string, unique_ptr<Node> >& child, string name) {
  if (child.find(name) == child.end()) {
    child[name] = make_unique<Node>(name);
  } 
  return child[name].get();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  auto root = make_unique<Node>("root");
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int m;
    string prev, curr;
    cin >> m >> prev;

    Node* prev_node = createOrFindNode(root->child, prev);
    for(int i = 0; i < m-1; i++) {
      cin >> curr;
      prev_node = createOrFindNode(prev_node->child, curr);
      prev = curr;
    }
  }
  printTree(root.get());
}

/*

DFS로 풀까 고민했지만 노드의 중복이 가능하기에 패스
unique_ptr 이용해 진행

처음에 make_unique를 매번 진행하는 방식으로 작성, 이는 노드를 매번 초기화하기 때문에 하나의 노드에서 여러 노드가 불가능한 구조 발생
  => 해당 노드가 있는 경우 make_unique가 아니라 기존 노드가 사용하는 방식으로 진행

node 기본 구조
  node - node
       ㄴ node
       ㄴ node
         ...

  node - node 형태는 map을 이용해 여러 node를 포함하며 unique_ptr 이용해서 연결
  
참고
  1. 우선순위 큐의 경우 출력하면서 길이가 변하기 때문에 for보다는 while문으로 출력하는게 유용
  2. unique_ptr 접근 시 get() 이용
    unique_ptr은 메모리의 소유권을 갖고 있으며 일반 포인터와 다르게 복사할 수 없고 이동만 가능하다
    내부적으로 메모리 관리와 관련된 추가 정보를 유지하며 직접적인 메모리 접근이 불가하다
    unique_ptr은 객체의 생명 주기가 자동으로 관리되며 메모리가 자동 해제되지만 포인터 연산을 지원하지 않음
      때문에 원래의 포인터를 이용해 직접 제어가 필요할 땐 get() 메서드를 이용
*/