import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<BigInteger> arr = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());



        arr.add(new BigInteger("0"));
        arr.add(new BigInteger("1"));

        for(int i = 2; i <= n; i++){
            arr.add(arr.get(i-1).add(arr.get(i-2)));
        }

//        System.out.println(arr);
        System.out.println(arr.get(n));
    }
}