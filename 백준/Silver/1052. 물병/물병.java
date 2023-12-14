import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");

        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);


        int result = 0;
        
        if(n <= k){
            System.out.println(0);
            return;
        }

        while(true){
            int empty = n;
            int count = 0;

            while(empty > 0){
                if(empty % 2 != 0){
                    count += 1;
                }
                empty /= 2;
            }
            
            if(count <= k){
                break;
            }
            n += 1;
            result += 1;
        }
        System.out.println(result);
    }
}