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
		 boolean[] visited;
		 int count = 0;
		 
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 StringTokenizer st = null;
		 
		 
		 int number = Integer.parseInt(br.readLine());
		 int repeat = Integer.parseInt(br.readLine());
		 visited = new boolean[number+1];
		 
		 for(int i = 0; i<=number; i++) {
			 graph.add(new ArrayList<Integer>());
		 }
		 
		 for(int i = 0; i<repeat; i++) {
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
		 bfs(graph, visited, 1);
		 for(int i = 2; i<visited.length; i++) {
			 if(visited[i]) {
				 count ++;
			 }
		 }
		 System.out.println(count);
	}
	public static void bfs(List<List<Integer>> graph, boolean[] visited, int start) {
		
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(start);
		visited[start] = true;
		
		while(que.size() != 0) {
			int num = que.poll();
			for(int i = 0; i<graph.get(num).size(); i++) {
				if(!visited[graph.get(num).get(i)]) {
					que.add(graph.get(num).get(i));
					visited[graph.get(num).get(i)] = true;
				}
			}
		}
	}
	
}