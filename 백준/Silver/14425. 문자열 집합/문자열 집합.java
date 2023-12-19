

import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {

        /**
         * contains() 이용해 하나하나 비교했는데 시간초과
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = 0;

        String[] str = br.readLine().split(" ");
        String[] strArr = new String[Integer.parseInt(str[0])];

        for(int i = 0; i < Integer.parseInt(str[0]); i++){
            strArr[i] = br.readLine();
        }
        for(int i = 0; i < Integer.parseInt(str[1]); i++){
            String temp = br.readLine();
            for(int j = 0; j<strArr.length; j++){
                if(strArr[j].equals(temp)){
                    count += 1;
                }
            }
        }
        System.out.println(count);
    }
}