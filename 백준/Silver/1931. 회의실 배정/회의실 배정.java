import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = 1;

        int n = Integer.parseInt(br.readLine());

        int[][] arr = new int[n][2];

        for(int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");

            arr[i][0] = Integer.parseInt(str[0]);
            arr[i][1] = Integer.parseInt(str[1]);
        }

        Arrays.sort(arr, new Comparator<int[]>(){
            public int compare(int[] s1, int[] s2){
                if (s2[1] == s1[1]) {
                    return s1[0] - s2[0];
                } else {
                    return s1[1] - s2[1];
                }
            }
        });

        int cur = arr[0][1];
        for(int i = 1; i < n; i++){
            if (arr[i][0] >= cur) {
                cur = arr[i][1];
                count += 1;
            }
        }
        System.out.println(count);
    }
}

