import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int max(int a, int b){
        if (a > b) {
            return a;
        }
        return b;
    }
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n+1];

        String[] temp = br.readLine().split(" ");
        dp[1] = Integer.parseInt(temp[0]);

        for(int i = 1; i < dp.length; i++){
            for(int j = 1; j <= i; j++){
                dp[i] = max(dp[i-j] + Integer.parseInt(temp[j-1]), dp[i]);
            }
        }
        System.out.println(dp[dp.length-1]);

    }
}