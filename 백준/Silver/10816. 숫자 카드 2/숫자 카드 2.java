import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws Exception {

		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 StringTokenizer st = null;
		 StringBuilder sb = new StringBuilder();
		 HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		 int num = 0;
		 
		 
		 int n = Integer.parseInt(br.readLine());
		 st = new StringTokenizer(br.readLine()," ");
		 for(int i =0; i<n; i++) {
			 num = Integer.parseInt(st.nextToken());
			 map.put(num, map.getOrDefault(num, 0)+1);
		 }
		 
		 
		 
		 
		 int m = Integer.parseInt(br.readLine());
		 st = new StringTokenizer(br.readLine()," ");
		 
		 for(int i =0; i<m; i++) {
			 num = Integer.parseInt(st.nextToken());
			 
			 sb.append(map.getOrDefault(num, 0)).append(' ');
		 }
		 System.out.println(sb);
		 
	}

}