

import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        String str2 = "";
        int j = 0;
        for(int i = 0; i<str.length(); i++){
            if (j == 10) {
                System.out.println(str2);
                str2 = "";
                j = 0;
            }
            str2 += str.charAt(i);
            j += 1;
        }
        System.out.println(str2);
    }
}