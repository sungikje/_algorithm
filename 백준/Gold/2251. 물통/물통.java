
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.TreeSet;
import java.io.BufferedReader;

public class Main {
	
	static int fullA;
	static int fullB;
	static int fullC;
	static TreeSet<Integer> result = new TreeSet<>();
	
	static void dfs(int a, int b, int c, boolean[][][] visited) {
		
		if(!visited[a][b][c]) {
			visited[a][b][c] = true;
			if (a == 0) {
				result.add(c);
			}
		} else {
			return;
		}
		
		if (a > 0) {
			if (fullB - b > a) {
				dfs(0, b + a, c, visited);
			} else {
				dfs(a-(fullB-b), fullB, c, visited);
			}
			
			if (fullC - c > a) {
				dfs(0, b, c + a, visited);
			} else {
				dfs(a-(fullC-c), b, fullC, visited);
			}
		}
		
		if (b > 0) {
			if (fullA - a > b) {
				dfs(a + b, 0, c, visited);
			} else {
				dfs(fullA, b-(fullA-a), c, visited);
			}
			
			if (fullC - c > b) {
				dfs(a, 0, c + b, visited);
			} else {
				dfs(a, b-(fullC-c), fullC, visited);
			}
		}
		
		if (c > 0) {
			if (fullA - a > c) {
				dfs(a + c, b, 0, visited);
			} else {
				dfs(fullA, b, c-(fullA-a), visited);
			}
			
			if (fullB - b > c) {
				dfs(a, b + c, 0, visited);
			} else {
				dfs(a, fullB, c-(fullB-b), visited);
			}
		}
	}

	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		boolean[][][] visited = new boolean[201][201][201];
		String[] temp = br.readLine().split(" ");
		
		fullA = Integer.parseInt(temp[0]);
		fullB = Integer.parseInt(temp[1]);
		fullC = Integer.parseInt(temp[2]);
		
		dfs(0, 0, fullC, visited);
		
		Iterator iter = result.iterator();	
		while(iter.hasNext()) {
		    System.out.print(iter.next()+" ");
		}
		
	}
}
