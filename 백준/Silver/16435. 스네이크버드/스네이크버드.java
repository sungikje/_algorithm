import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int len;
        String[] str1 = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");

        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i<str2.length; i++){
            arr.add(Integer.parseInt(str2[i]));
        }

        Collections.sort(arr);

        len = Integer.parseInt(str1[1]);

        for(int i = 0; i<Integer.parseInt(str1[0]); i++){
            if(arr.get(i) <= len) {
                len += 1;
            }
        }
        System.out.println(len);
    }
}