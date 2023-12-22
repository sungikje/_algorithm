import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static void dfs(int node, boolean[] visited, ArrayList<ArrayList<Integer>> graph){

        visited[node] = true;

        for(int i = 0; i < graph.get(node).size(); i++){
            if(!visited[graph.get(node).get(i)]){
                visited[graph.get(node).get(i)] = true;
                dfs(graph.get(node).get(i), visited, graph);
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] init = br.readLine().split(" ");

        boolean[] visited = new boolean[Integer.parseInt(init[0]) + 1];
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int count = 0;

        for(int i = 0; i <= Integer.parseInt(init[0]); i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < Integer.parseInt(init[1]); i++){
            String[] temp = br.readLine().split(" ");
            graph.get(Integer.parseInt(temp[0])).add(Integer.parseInt(temp[1]));
            graph.get(Integer.parseInt(temp[1])).add(Integer.parseInt(temp[0]));
        }

        for(int i = 1; i < visited.length; i++){
            if (!visited[i]) {
                dfs(i, visited, graph);
                count += 1;
            }
        }
        System.out.println(count);
    }
}