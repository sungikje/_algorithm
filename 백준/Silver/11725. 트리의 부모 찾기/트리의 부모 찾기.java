import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Queue<Integer> q = new LinkedList<>();

        int[] arr = new int[n+1];
        boolean[] visited = new boolean[n+1];
        visited[1] = true;
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

        for(int i = 0; i <= n; i++){
            graph.add(new ArrayList<Integer>());
        }

        for(int i = 0; i < n-1; i++){
            String[] str = br.readLine().split(" ");
            graph.get(Integer.parseInt(str[0])).add(Integer.parseInt(str[1]));
            graph.get(Integer.parseInt(str[1])).add(Integer.parseInt(str[0]));
        }

        for(ArrayList<Integer> a : graph) {
            Collections.sort(a);
        }

        for(int i : graph.get(1)){
            q.add(i);
            arr[i] = 1;
            visited[i] = true;
        }

        while (q.size() > 0) {
            int node = q.poll();
            for(int i : graph.get(node)){
                if (!visited[i]) {
                    q.add(i);
                    arr[i] = node;
                    visited[i] = true;
                }
            }
        }

        for(int i = 2; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
