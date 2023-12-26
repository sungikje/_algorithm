import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        BigInteger[] arr = new BigInteger[10000];

        arr[0] = BigInteger.ONE;
        arr[1] = BigInteger.ONE;

        for(int i = 2; i < 10000; i++){
            arr[i] = arr[i-2].add(arr[i-1]);
        }

        for(int i = 0; i < n; i++){
            String[] temp = br.readLine().split(" ");
            System.out.println("Case #" + (i+1) + ": " + arr[Integer.parseInt(temp[0])-1].mod(new BigInteger(temp[1])));
        }
    }
}