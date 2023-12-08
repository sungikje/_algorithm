

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static boolean check = false;
    static void findYn(String str, String target){
//        System.out.println("기준 : " + str);
//        System.out.println("변화 : " + target);
//        System.out.println();
//        System.out.println();
//        System.out.println();
        if (check) {
            return;
        }

        if (str.length() > target.length()) {
            return;
        } else if (str.length() == target.length()) {
            if (str.equals(target)) {
                check = true;
            } else {

            }
        } else {
            if (target.charAt(target.length()-1) == 'A') {
                findYn(str, target.substring(0, target.length()-1));
            }

            String s = "";
            for(int i = target.length()-1; i >= 0; i--){
                s += target.charAt(i);
            }
            if (s.charAt(s.length()-1) == 'B')  {
                findYn(str, s.substring(0, s.length()-1));
            }

        }
    }
    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        String target = br.readLine();

        findYn(str, target);

        if (check) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}