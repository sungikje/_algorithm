import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> wine = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());

        if (n == 1) {
            System.out.println(br.readLine());
            return;
        } else if (n == 2) {
            int a = Integer.parseInt(br.readLine());
            int b = Integer.parseInt(br.readLine());
            System.out.println(a+b);
            return;
        } 

        for(int i = 0; i < n; i++){
            wine.add(Integer.parseInt(br.readLine()));
        }

        result.add(wine.get(0));
        result.add(wine.get(0) + wine.get(1));

        result.add(max(max(wine.get(0) + wine.get(2), wine.get(1) + wine.get(2)), result.get(1)));

        for(int i = 3; i < wine.size(); i++){
            int a = result.get(i-3) + wine.get(i-1) + wine.get(i);
            int b = result.get(i-2) + wine.get(i);

            result.add(max(max(a, b), result.get(i-1)));
        }
        System.out.println(result.get(result.size()-1));
    }
}