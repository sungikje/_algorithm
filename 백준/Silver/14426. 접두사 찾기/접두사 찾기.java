import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashSet<String> set = new HashSet<>();
        int count = 0;
        String[] arr = br.readLine().split(" ");

        for(int i = 0; i < Integer.parseInt(arr[0]); i++){
            String str = br.readLine();
            for(int j = 1; j <= str.length(); j++){
                set.add(str.substring(0, j));
            }
        }
        for(int i = 0 ; i < Integer.parseInt(arr[1]); i++){
            String str = br.readLine();
            if (set.contains(str)) {
                count += 1;
            }
        }
         System.out.println(count);
    }
}
