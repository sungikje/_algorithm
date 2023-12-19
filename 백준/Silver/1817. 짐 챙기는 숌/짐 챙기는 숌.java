import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str1 = br.readLine().split(" ");
        if (str1[0].equals("0")) {
            System.out.println(0);
        } else {
            String[] str2 = br.readLine().split(" ");

            int box = 0;
            int curBox = 0;

            for(int i = 0; i < Integer.parseInt(str1[0]); i++){
                if(curBox + Integer.parseInt(str2[i]) <= Integer.parseInt(str1[1])){
                    curBox += Integer.parseInt(str2[i]);
                } else {
                    box += 1;
                    curBox = Integer.parseInt(str2[i]);
                }
            }

            System.out.println(curBox != 0? box + 1 : box);
        }
    }
}