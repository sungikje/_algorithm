import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> in = new ArrayList<>();
        ArrayList<String> out = new ArrayList<>();
        int count = 0;

        for(int i = 0; i < n; i++){
            in.add(br.readLine());
        }

        for(int i = 0; i < n; i++){
            out.add(br.readLine());
        }

        for(int i = 0; i < out.size(); i++){
            int inT = in.indexOf(out.get(i));
            for(int j = 0; j < inT; j++){
                if (out.indexOf(in.get(j)) > i) {
                    count += 1;
                    break;
                }
            }
        }
        System.out.println(count);
    }
}