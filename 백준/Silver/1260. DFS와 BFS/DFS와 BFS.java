import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
	
	public static void main(String[] args) throws Exception {

		 List<Integer> empty = new ArrayList<Integer>();
		 List<List<Integer>> graph = new ArrayList<List<Integer>>();
		 List<Integer> num = new ArrayList<Integer>();
		 boolean[] visited;
		 
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 StringTokenizer st = null;
		 
		 
		 st = new StringTokenizer(br.readLine()," ");
		 int n = st.countTokens();
		 for(int i =0; i<n; i++) {
			 num.add(Integer.parseInt(st.nextToken()));
		 }
		 
		 
		 // graph 구조 만들려고 넣을 때 생성자 넣어야지 객체 넣으면 참조 주소로 운영됨
		 // 처음에 empty 자체를 넣었었다
		 for(int i = 0; i<num.get(0)+1; i++) {
			 graph.add(new ArrayList<Integer>());
		 }
		 
		 visited = new boolean[graph.size()];
		 
		 for(int i = 0; i<num.get(1); i++) {
			 st = new StringTokenizer(br.readLine()," ");
			 for(int j = 0; j<2; j++) {
				 empty.add(Integer.parseInt(st.nextToken()));
			 }
			 
			 graph.get(empty.get(0)).add(empty.get(1));
			 graph.get(empty.get(1)).add(empty.get(0));
			 empty = new ArrayList<Integer>();
		 
		 }
		 for(int i = 0; i<graph.size(); i++) {
			 graph.get(i).sort(Comparator.naturalOrder());
		 }
		 dfs(graph, visited, num.get(2));
		 visited = new boolean[graph.size()];
		 System.out.println();
		 bfs(graph, visited, num.get(2));
	}
	public static void bfs(List<List<Integer>> graph, boolean[] visited, int start) {
		
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(start);
		visited[start] = true;
		
		while(que.size() != 0) {
			int num = que.poll();
			System.out.print(num+" ");
			for(int i = 0; i<graph.get(num).size(); i++) {
				if(!visited[graph.get(num).get(i)]) {
					que.add(graph.get(num).get(i));
					visited[graph.get(num).get(i)] = true;
				}
			}
		}
	}
	
	public static void dfs(List<List<Integer>> graph, boolean[] visited, int start) {
		
		System.out.print(start+" ");
		visited[start] = true;
		for(int i = 0; i<graph.get(start).size(); i++) {
			if(!visited[graph.get(start).get(i)]) {
				visited[graph.get(start).get(i)] = true;
				dfs(graph, visited, graph.get(start).get(i));
			}
		}
		
	}
}