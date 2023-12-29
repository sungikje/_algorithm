import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int len = Integer.parseInt(br.readLine());
        String target = br.readLine();
        int count = 0;
        int result = 0;


        for(int i = 0; i < len - 2; i++){
//            System.out.print(target.charAt(i));
//            System.out.print(target.charAt(i+1));
//            System.out.print(target.charAt(i+2));
            if (target.charAt(i) == 'I' && target.charAt(i+1) == 'O' && target.charAt(i+2) == 'I') {
                count += 1;
                if (count == n) {
                    count--;
                    result += 1;
                }
                i ++;
            } else {
                count = 0;
            }
//            System.out.println();
//            System.out.println();
//            System.out.println();
        }

        System.out.println(result);
    }
}