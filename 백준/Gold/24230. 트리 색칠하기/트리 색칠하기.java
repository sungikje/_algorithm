import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean[] visited;
    static String[] colors;
    static int count;

    static void dfs(int node) {

        visited[node] = true;

        for(int i = 0; i < graph.get(node).size(); i++){
            if(!visited[graph.get(node).get(i)]){
                if (!colors[node-1].equals(colors[graph.get(node).get(i)-1])) {
                    count += 1;
                }
                dfs(graph.get(node).get(i));
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        colors = br.readLine().split(" ");
        visited = new boolean[n + 1];

        for(int i = 0; i <= n; i++){
            graph.add(new ArrayList<Integer>());
        }

        for(int i = 0; i < n-1; i++){
            String[] temp = br.readLine().split(" ");
            graph.get(Integer.parseInt(temp[0])).add(Integer.parseInt(temp[1]));
            graph.get(Integer.parseInt(temp[1])).add(Integer.parseInt(temp[0]));
        }

        if (!colors[0].equals("0")) {
            count = 1;
        } else {
            count = 0;
        }
        dfs(1);

        System.out.println(count);

    }
}