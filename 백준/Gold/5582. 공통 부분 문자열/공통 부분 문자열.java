import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();

        int[][] num = new int[str1.length()+1][str2.length()+1];

        int max = 0;

        for(int i = 1; i <= str1.length(); i++){
            for(int j = 1; j <= str2.length(); j++){
                if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    num[i][j] = num[i-1][j-1] + 1;
                    if (max < num[i][j]) {
                        max = num[i][j];
                    }
                } else {
                    num[i][j] = 0;
                }
            }
        }

        System.out.println(max);

    }
}
