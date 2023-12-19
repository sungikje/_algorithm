

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        int temp = 0;
        /**
         * 1. 메모리 초과
         *      뒷자리부터 세자리씩 끊어서 추가하고(저장하고), 역순으로 출력하는 로직
         */
        for(int i = 0; i<str.length(); i++){

            if (str.charAt(i) == '1') {
                temp += Math.pow(2, (str.length()-(i+1)) % 3);
            }

            if((str.length() - (i+1)) % 3 == 0){
                System.out.print(temp);
                temp = 0;
            }
        }
    }
}