import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int value;
        BigInteger tempDist = new BigInteger("0");
        BigInteger oil = new BigInteger("0");

        String[] str1 = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");

        value = Integer.parseInt(str2[0]);

        for(int i = 0; i < str2.length-1; i++){
            if (value > Integer.parseInt(str2[i])) {
                BigInteger temp = new BigInteger(Integer.toString(value));
                oil = oil.add(tempDist.multiply(temp));
                value = Integer.parseInt(str2[i]);
                tempDist = new BigInteger(str1[i]);
            } else {
                BigInteger temp = new BigInteger(str1[i]);
                tempDist = tempDist.add(temp);
            }
        }
//        System.out.println("value : " + value);
//        System.out.println("tempDist : " + tempDist);
        System.out.println((oil.add(tempDist.multiply(new BigInteger(Integer.toString(value))))));
    }
}