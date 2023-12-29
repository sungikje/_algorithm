

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int check = 0;

    static void find(String str, String target){
        if (check == 1) {
            return;
        }

        if (str.equals(target)){
            check = 1;
            return;
        }

        if (target.length() < str.length()) {
            return;
        }

        if (target.charAt(target.length() - 1) == 'A') {
            find(str, target.substring(0, target.length()-1));
        } else {
            String target2 = "";
            for(int i = target.length() - 2; i >= 0; i--) target2 += target.charAt(i);
            find(str, target2);
        }

    }

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        String target = br.readLine();

        find(str, target);
        System.out.println(check);
    }
}