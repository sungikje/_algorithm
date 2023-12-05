import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] arr = new String[n];

        for(int i = 0; i < n; i++){
            arr[i] = br.readLine();
        }
        Arrays.sort(arr, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2) {
                return s1.length() - s2.length();
            }
        });

        for(int i = 0; i < arr.length; i++){
            boolean check = false;
            for(int j = i+1; j < arr.length; j++){
                if (arr[j].indexOf(arr[i]) == 0) {
                    check = true;
                    break;
                }
            }
            if (check) {
                n -= 1;
            }
        }
        System.out.println(n);
    }
}