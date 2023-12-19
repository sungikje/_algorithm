import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Integer> arr;
        int n = 1;

        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr = new ArrayList<>();
            for(int i = 0; i<3; i++){
                arr.add(Integer.valueOf(st.nextToken()));
            }
            if(arr.get(0) == 0){
                break;
            }
            int a = arr.get(0) * (arr.get(2)/arr.get(1));
            arr.set(2, arr.get(2) % arr.get(1));
            int b = arr.get(0) > arr.get(2)? arr.get(2) : arr.get(0);
            System.out.println("Case " + n + ": " + (a+b));
            n += 1;
        }
    }
}