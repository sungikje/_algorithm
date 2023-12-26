import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        long sum = 0;

        long[][] dp = new long[n][11];

        for(int i = 1; i < 10; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < 10; j++){
                if (j == 0) {
                    dp[i][j] = dp[i-1][1]%1000000000;
                } else if (j == 9) {
                    dp[i][j] = dp[i-1][8]%1000000000;
                } else {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
                }
            }
        }

//        for(long[] a : dp){
//            System.out.println(Arrays.toString(a));
//        }

        for(long a : dp[n-1]){
            sum += a;
        }
        System.out.println(sum%1000000000);
    }
}