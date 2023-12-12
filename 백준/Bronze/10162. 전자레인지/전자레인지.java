import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] micro = {300, 60, 10};
        int[] arr = new int[3];

        if (n % 10 != 0) {
            System.out.println(-1);
        } else {
            while(n > 0) {
                for(int i = 0; i < micro.length; i++){
                    if (n >= micro[i]) {
                        int share = n / micro[i];
                        arr[i] += share;
                        n %= micro[i];
                    }
                }
            }
            for(int i : arr) {
                System.out.print(i+" ");
            }
        }
    }
}
