import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            int t = Integer.parseInt(br.readLine());
            if (t == 1) {
                System.out.println(1);
            } else if (t == 2) {
                System.out.println(2);
            } else if (t == 3) {
                System.out.println(4);
            } else {
                int[] dp = new int[t+1];
                dp[0] = 1;
                dp[1] = 2;
                dp[2] = 4;
                for(int j = 3; j < t; j++){
                    dp[j] = dp[j-3] + dp[j-2] + dp[j-1];
                }
                System.out.println(dp[dp.length-2]);
            }
        }
    }
}