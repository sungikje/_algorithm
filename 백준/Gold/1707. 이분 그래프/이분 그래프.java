import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Main {
    static boolean result;
    static int[] visited;
    static ArrayList<ArrayList<Integer>> graphAll;

    static void dfs(int start, ArrayList<ArrayList<Integer>> graph) {
        Stack<Integer> stack = new Stack<>();

        visited[start] = 1;
        stack.push(start);

        while(stack.size() > 0) {

            boolean check = false;
            int node = stack.get(stack.size()-1);
            for(int i : graph.get(node)){
                if(visited[i] == 0){
                    stack.push(i);
                    visited[i] = visited[node] == 1? 2 : 1;
                    check = true;
                    break;
                } else {
                    if (visited[node] == visited[i]) {
                        result = true;
                        return;
                    }
                }
            }
            if (!check) {
                stack.pop();
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");

            ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

            for(int j = 0; j <= Integer.parseInt(str[0]); j++) {
                graph.add(new ArrayList<Integer>());
            }

            for(int j = 0; j < Integer.parseInt(str[1]); j++) {
                String[] temp = br.readLine().split(" ");
                graph.get(Integer.parseInt(temp[0])).add(Integer.parseInt(temp[1]));
                graph.get(Integer.parseInt(temp[1])).add(Integer.parseInt(temp[0]));
            }

            visited = new int[graph.size()+1];
            graphAll = new ArrayList<>();
            result = false;

            for(int k = 1; k < graph.size(); k++){
                if (visited[k] == 0) {
                    dfs(k, graph);
                }
            }

            if (result) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}