import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static boolean result = false;
    static void dfs(int point, boolean[] visited, ArrayList<ArrayList<Integer>> graph, int depth) {

        if (depth >= 4) {
            result = true;
            return;
        }

        for(int i = 0; i < graph.get(point).size(); i++){
            if (!visited[graph.get(point).get(i)]) {
                visited[graph.get(point).get(i)] = true;
                dfs(graph.get(point).get(i), visited, graph, depth+1);
                visited[graph.get(point).get(i)] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        boolean[] visited;

        String[] num = br.readLine().split(" ");

        for(int i = 0; i <Integer.parseInt(num[0]); i++){
            graph.add(new ArrayList<Integer>());
        }

        for(int i = 0; i <Integer.parseInt(num[1]); i++){
            String[] temp = br.readLine().split(" ");
            graph.get(Integer.parseInt(temp[0])).add(Integer.parseInt(temp[1]));
            graph.get(Integer.parseInt(temp[1])).add(Integer.parseInt(temp[0]));
        }

        visited = new boolean[Integer.parseInt(num[0])];
        
        for(int i = 0; i < Integer.parseInt(num[0]); i++){
            visited[i] = true;
            dfs(i, visited, graph, 0);
            visited[i] = false;
            if(result){
                break;
            }
        }
        System.out.println(result? 1 : 0);
    }
}