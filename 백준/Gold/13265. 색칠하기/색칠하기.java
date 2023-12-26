import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visited;

    static int[] colors;
    static boolean check;

    static void dfs(int node, int color){

        visited[node] = true;
        colors[node] = color;

        for(int i = 0; i < graph.get(node).size(); i++){
            if (!visited[graph.get(node).get(i)]) {
                dfs(graph.get(node).get(i), color == 1? 0 : 1);
            }
            else {
                if (colors[graph.get(node).get(i)] == color) {
                    check = true;
                    return;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String[] temp = br.readLine().split(" ");

            graph = new ArrayList<>();
            visited = new boolean[Integer.parseInt(temp[0]) + 1];
            colors = new int[Integer.parseInt(temp[0]) + 1];
            check = false;

            for(int j = 0; j <= Integer.parseInt(temp[0]); j++){
                graph.add(new ArrayList<>());
            }

            for(int j = 0; j < Integer.parseInt(temp[1]); j++){
                String[] temp2 = br.readLine().split(" ");
                graph.get(Integer.parseInt(temp2[0])).add(Integer.parseInt(temp2[1]));
                graph.get(Integer.parseInt(temp2[1])).add(Integer.parseInt(temp2[0]));
            }

            for(ArrayList<Integer> a : graph){
                Collections.sort(a);
            }

            for(int j = 1; j < graph.size(); j++){
                if (!visited[j]) {
                    dfs(j, 0);
                }
            }

            if (check) {
                System.out.println("impossible");
            } else {
                System.out.println("possible");
            }

        }
    }
}