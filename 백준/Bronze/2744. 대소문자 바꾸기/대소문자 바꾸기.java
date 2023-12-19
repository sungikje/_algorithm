

import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        String str2 = "";
        while(str != null){

            for(int i = 0; i < str.length(); i++){
                int a = (int)str.charAt(i);
                if (a < 97) {
                    a += 32;
                } else {
                    a -= 32;
                }
                str2 += (char)(a+0);
            }
            System.out.println(str2);
            str2 = "";
            str = br.readLine();

        }
    }
}