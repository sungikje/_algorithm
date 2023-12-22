import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
	
	static int[][] graph;
	static boolean[] visited;
	static ArrayList<ArrayList<Integer>> node;
	
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] n = br.readLine().split(" ");
		String[] temp;
		
		node = new ArrayList<>();
		graph = new int[Integer.parseInt(n[0])+1][Integer.parseInt(n[0])+1];
		visited = new boolean[Integer.parseInt(n[0]+1)];
		
		for(int[] a : graph) {
			Arrays.fill(a, 1000000);
		}
		
//		for(int i = 0; i <= Integer.parseInt(n[0]); i++) {
//			node.add(new ArrayList<Integer>());
//		}
		
		for(int i = 0; i < Integer.parseInt(n[0])-1; i++) {
			temp = br.readLine().split(" ");
			
//			node.get(Integer.parseInt(temp[0])).add(Integer.parseInt(temp[1]));
//			node.get(Integer.parseInt(temp[1])).add(Integer.parseInt(temp[0]));
			graph[Integer.parseInt(temp[0])][Integer.parseInt(temp[1])] = Integer.parseInt(temp[2]);
			graph[Integer.parseInt(temp[1])][Integer.parseInt(temp[0])] = Integer.parseInt(temp[2]);
		}
//		for(int[] a : graph) {
//			System.out.println(Arrays.toString(a));
//		}
		for(int i = 1; i < graph.length; i++) {
			for(int j = 1; j < graph.length; j++) {
				for(int k = 1; k < graph.length; k++) {
					graph[j][k] = graph[j][i] + graph[i][k] > graph[j][k] ? graph[j][k] : graph[j][i] + graph[i][k];
				}
			}
		}
//		System.out.println();
//		System.out.println();
//		for(int[] a : graph) {
//			System.out.println(Arrays.toString(a));
//		}
		
		for(int i = 0; i < Integer.parseInt(n[1]); i++) {
			temp = br.readLine().split(" ");
			System.out.println(graph[Integer.parseInt(temp[0])][Integer.parseInt(temp[1])]);
		}
	}

}