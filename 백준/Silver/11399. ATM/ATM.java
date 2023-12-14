import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] arr = new int[str.length];
        int[] result = new int[str.length];
        boolean[] visited = new boolean[str.length];


        for(int i = 0; i<str.length; i++){
            arr[i] = Integer.parseInt(str[i]);
        }

        Arrays.sort(arr);

        int[] sumArr = new int[arr.length];
        int sum = 0;
        sumArr[0] = arr[0];
        for(int i = 1; i<arr.length; i++) {
            int emptySum = 0;
            for (int j = 0; j <= i; j++) {
                emptySum += arr[j];
            }
            sumArr[i] = emptySum;
        }

        for(int i = 0; i<arr.length; i++){
            sum += sumArr[i];
        }

        System.out.println(sum);
    }
}