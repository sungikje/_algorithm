import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

    public static void main(String[] args) throws IOException {

        /*
n, m 입력 받고

n까지 붙이는 수의 길이 m보다 큰 경우
    자릿수 측정, 길이 : (9 * (10*(측정된 자릿수 -1))) + ((n - (10 * 측정된 자릿수) + 1) * 측정된 자릿수)

    자릿수 체크 - 어느 구간 인지

    일의 자리 수인 경우
        m 출력

    아닌 경우
        m -= 이전 자리수까지의 길이

        m % 현재 자릿수 == 0
            m/(현재 자릿수-1) 마지막 글자 출력
        else
            m/현재 자릿수 (m%현재 자릿수) 인덱스 출력

아닌 경우
    print -1

자릿수 1(1~9) : 9 * 1
자릿수 2(10~99) : 90 * 2 => 180
자릿수 3(100~999) : 900 * 3 => 2700
4 : 9000 * 4
5 : 90000 * 5


자릿수 6(100000~999999) : 900000
         */

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int len = 0;

        for (int i = 1; i < str[0].length(); i++) {
            len += 9 * Math.pow(10, i - 1) * i;
        }

        len += ((n - Math.pow(10, str[0].length() - 1)) + 1) * str[0].length();

        if (m > len) {
            System.out.println(-1);
        } else {
            if (m < 10) {
                System.out.println(m);
            } else {
                int i = 1;
                
                while(true){
                    if (m - (9 * Math.pow(10, i - 1)) * (i) < 0){
                        break;
                    } else {
                        m -= (9 * Math.pow(10, i - 1)) * (i);
                    }
                    i += 1;
                }

                if(m % i == 0){
                    String result = Integer.toString((int) Math.pow(10, i - 1) + (m/i - 1));
                    System.out.println(result.charAt(result.length()-1));
                } else {
                    String result = Integer.toString((int) Math.pow(10, i - 1) + (m/i));
                    System.out.println(result.charAt((m%i)-1));
                }
            }
        }
    }
}