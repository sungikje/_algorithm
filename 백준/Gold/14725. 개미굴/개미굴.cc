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

참고
    1. 우선순위 큐의 경우 출력하면서 길이가 변하기 때문에 for보다는 while문으로 출력하는게 유용
*/