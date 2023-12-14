import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int count = 0;
    static int day;
    static int goalScore;
    static void dfs(int d, int sum, int[][] score, int preJ){

        if(d == day){
            if(goalScore <= sum){
                count ++;
            }
            return;
        } else {
            for(int i = 0; i<score.length; i++){
                for(int j = 0; j<score[i].length; j++){
                    int preSum = sum;
                    if (j == preJ){
                        preSum += score[i][j]/2;
                    } else {
                        preSum += score[i][j];
                    }
                    dfs(d+1, preSum, score, j);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] score = new int[2][3];

        String[] input = br.readLine().split(" ");
        day = Integer.parseInt(input[0]);
        goalScore = Integer.parseInt(input[1]);

        for (int i = 0; i < 2; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < str.length; j++) {
                score[i][j] = Integer.parseInt(str[j]);
            }
        }

        dfs(0, 0, score, -1);

        System.out.println(count);

        /*
        매일 같은 일을 할 수도 있다




         */
    }
}

