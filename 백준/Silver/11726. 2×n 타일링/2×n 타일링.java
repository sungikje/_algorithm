import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> arr = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());

        arr.add(1);
        arr.add(2);

        for(int i = 2; i <= n; i++){
            arr.add((arr.get(i-2) + arr.get(i-1))%10007);
        }

        System.out.println(arr.get(n-1));
    }
}