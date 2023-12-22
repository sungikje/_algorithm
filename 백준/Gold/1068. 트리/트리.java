import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Main {

    static int result = 0;

    static void dfs(ArrayList<ArrayList<Integer>> graph, boolean[] visited, int start, int remove) {

        Stack<Integer> stack = new Stack<>();

        visited[start] = true;
        stack.push(start);

        while(stack.size() > 0) {
            boolean check = false;
            int node = stack.get(stack.size()-1);
            for(int i = 0; i < graph.get(node).size(); i++){
                if(!visited[graph.get(node).get(i)]){
                    visited[graph.get(node).get(i)] = true;
                    stack.push(graph.get(node).get(i));
                    check = true;
                    break;
                }
            }
            if (!check) {
                if (graph.get(stack.get(stack.size()-1)).size() == 0 && stack.get(stack.size()-1) != remove) {
                    result += 1;
                }
                stack.pop();
            }
        }

    }

    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());
        int start = 0;
        boolean[] visited = new boolean[n];

        for(int i = 0; i < n; i++){
            graph.add(new ArrayList<Integer>());
        }

        String[] str = br.readLine().split(" ");

        int remove = Integer.parseInt(br.readLine());

        for(int i = 0; i < str.length; i++) {

            if(Integer.parseInt(str[i]) == -1) {
                start = i;
            } else if (i != remove) {
                graph.get(Integer.parseInt(str[i])).add(i);
            }
        }

        graph.set(remove, new ArrayList<Integer>());
        
        dfs(graph, visited, start, remove);

        System.out.println(result);
    }
}