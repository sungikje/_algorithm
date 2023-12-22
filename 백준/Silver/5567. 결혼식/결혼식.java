import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class Main {

    static HashSet<Integer> result = new HashSet<>();
    static void dfs(int point, ArrayList<ArrayList<Integer>> graph, boolean[] visited, int depth){

        if (depth > 2) {
            return;
        }

        if (point != 1) {
            result.add(point);
        }

        visited[point] = true;

        for(int i = 0; i < graph.get(point).size(); i++){
            if (!visited[graph.get(point).get(i)]){
                visited[graph.get(point).get(i)] = true;
                dfs(graph.get(point).get(i), graph, visited, depth+1);
                visited[graph.get(point).get(i)] = false;
            }
        }
    }
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));

        int n = Integer.parseInt(br.readLine());
        int g = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        boolean[] visited = new boolean[n+1];

        for(int i = 0; i <= n; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < g; i++){
            String[] str = br.readLine().split(" ");
            graph.get(Integer.parseInt(str[0])).add(Integer.parseInt(str[1]));
            graph.get(Integer.parseInt(str[1])).add(Integer.parseInt(str[0]));
        }

        for(int i = 0; i < n; i++){
            Collections.sort(graph.get(i));
        }

        dfs(1, graph, visited, 0);
        System.out.println(result.size());
    }
}