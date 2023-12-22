import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Integer> standard = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());

        result.add(1);
        result.add(3);

        for(int i = 2; i <= n; i++) {
            result.add((2*result.get(i-2) + result.get(i-1))%10007);
        }
        System.out.println(result.get(n-1));
    }
}