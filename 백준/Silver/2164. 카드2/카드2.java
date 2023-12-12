import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Queue<Integer> arr = new LinkedList<>();

        for(int i = 0; i < n; i++){
            arr.add(i+1);
        }

        while(arr.size() > 1) {
            arr.poll();
            arr.add(arr.poll());
        }
        System.out.println(Collections.max(arr));
    }
}
