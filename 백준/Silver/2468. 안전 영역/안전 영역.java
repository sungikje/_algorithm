

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
	
	static ArrayList<ArrayList<Integer>> tempGraph;
	static boolean[][] visited;
	static int max = 1;
	
	static void dfs1(int height, int x, int y) {
		
		int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		visited[x][y] = true;
		
		if (tempGraph.get(x).get(y) <= height) {
			tempGraph.get(x).set(y, -1);
		}
		
		
		for(int i = 0; i < dire.length; i++) {
			if (0 <=  dire[i][0] + x &&  dire[i][0] + x < tempGraph.size() && 0 <= dire[i][1] + y &&  dire[i][1] + y < tempGraph.size()) {
				if (!visited[dire[i][0] + x][dire[i][1] + y]) {
					dfs1(height, dire[i][0] + x, dire[i][1] + y );
				} else {
					return;
				}
			}
		}
	}
	
	static void dfs2(int x, int y) {
		int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		visited[x][y] = true;
		
		for(int i = 0; i < dire.length; i++) {
			if (0 <=  dire[i][0] + x &&  dire[i][0] + x < tempGraph.size() && 0 <= dire[i][1] + y &&  dire[i][1] + y < tempGraph.size()) {
				if (!visited[dire[i][0] + x][dire[i][1] + y] && tempGraph.get(dire[i][0] + x).get(dire[i][1] + y) != -1) {
					dfs2(dire[i][0] + x, dire[i][1] + y );
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
		
		int n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n; i++) {
			String[] str = br.readLine().split(" ");
			ArrayList<Integer> temp = new ArrayList<>();
			for(String s : str) {
				temp.add(Integer.parseInt(s));
			}
			graph.add(temp);
		}
		
		for(int i = 1; i <= 100; i++) {
			visited = new boolean[n][n];
			tempGraph = new ArrayList<>(graph);
			
//			i = 4;
			for(int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (!visited[j][k]) {
						dfs1( i, j, k);
					}
				}
			}
//			for(ArrayList<Integer> a : tempGraph) {
//				System.out.println(a);
//			}
//			for(boolean[] a : visited) {
//				System.out.println(Arrays.toString(a));
//			}
			
			visited = new boolean[n][n];
			int check = 0;
			for(int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (!visited[j][k] && tempGraph.get(j).get(k) != -1) {
						check += 1;
						dfs2(j, k);
					}
				}
			}
			if (check > max) {
				max = check;
			}
			
		}
		System.out.println(max);
	}

}