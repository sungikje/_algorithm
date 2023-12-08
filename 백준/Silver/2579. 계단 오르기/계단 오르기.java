import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Main {
	
	static String answer = "";
	
	public static void main(String[] args) throws IOException  {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		List<Integer> arr = new ArrayList<Integer>();
		
		for(int i = 0; i<n; i++) {
			arr.add(Integer.parseInt(br.readLine()));
		}
		
		int[] dp = new int[arr.size()];
		
		if(n == 1) {
			dp[0] = arr.get(0);
		}
		else if(n==2) {
			dp[0] = arr.get(0);
			dp[1] = Math.max(arr.get(0)+arr.get(1), arr.get(1));
		}
		else {
			dp[0] = arr.get(0);
			dp[1] = Math.max(arr.get(0)+arr.get(1), arr.get(1));
			dp[2] = Math.max(arr.get(0)+arr.get(2), arr.get(1)+arr.get(2));
			for(int i = 3; i<n; i++) {
				dp[i] = Math.max(dp[i-2]+arr.get(i), dp[i-3]+arr.get(i-1)+arr.get(i)); 
			}
		}
		System.out.println(dp[n-1]);
	}
}