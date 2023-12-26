import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[][] arr = new int[n+2][1];
        int[] dp = new int[n+2];

        for(int i = 0; i < n; i++){
            String[] temp = br.readLine().split(" ");

            arr[i+1] = new int[]{Integer.parseInt(temp[0]), Integer.parseInt(temp[1])};

        }
//        for(int[] a : arr) {
//            System.out.println(Arrays.toString(a));
//        }
//        System.out.println();
//        System.out.println();
//        System.out.println();
        for(int i = 1; i <= n; i++){
            if (i + arr[i][0] <= n+1){
                int value = dp[i] + arr[i][1] > dp[i + arr[i][0]] ? dp[i] + arr[i][1] : dp[i + arr[i][0]];
                for(int j = (i + arr[i][0]); j <= n + 1; j++){
                    dp[j] = value > dp[j] ? value : dp[j];
                }
            }
        }
//        System.out.println(Arrays.toString(dp));
        System.out.println(dp[dp.length - 1]);
        /*
        1일부터 순차적으로 종료하는 일이 N보다 작다면
        종료하는 일 DP vs value 진행해서 종료하는 일 DP 큰 값으로 수정
        이 때 종료하는 일 이후에 DP들은 위에 작업에 해당하는 값 맞춰줘야된다
         */


    }
}