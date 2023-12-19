

import java.io.*;


public class Main {
    static int logic(String str) {

        int sum = 0;

        for(char a = 'A'; a <= 'Z'; a++){
            if(!str.contains(a+"")){
                sum += (int)a;
            }
        }
        return sum;
    }
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();

        for(int i = 0; i<Integer.parseInt(str); i++){
            System.out.println(logic(br.readLine()));
        }
    }
}