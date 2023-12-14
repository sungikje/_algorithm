import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        BigInteger  n = new BigInteger(str);

        if(n.compareTo(new BigInteger("1")) == 0){
            System.out.println(1);
        } else if(n.compareTo(new BigInteger("2")) == 0) {
            System.out.println(2);
        } else{
            System.out.println(n.add(n).subtract(new BigInteger("2")));
        }
    }
}