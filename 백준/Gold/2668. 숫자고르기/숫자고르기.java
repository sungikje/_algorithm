import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeSet;

public class Main {

    static int[] arr;
    static TreeSet<Integer> tree = new TreeSet<>();

    static int start = 0;

    static void dfs(int node, boolean[] visited, TreeSet<Integer> result){

//        System.out.println("in : " + node);
        if (start == node && result.size() != 0) {
//            System.out.println("확인 : " + tree);
//            System.out.println("result : " + result);
            for(int a : result){
                tree.add(a);
            }
        }

        if (!visited[node]) {
            visited[node] = true;
            result.add(node);
            dfs(arr[node], visited, result);
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        arr = new int[n+1];
        boolean[] visited;

        for(int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
//        System.out.println("Arr : " + Arrays.toString(arr));

        for(int i = 1; i <= n; i++){
            visited = new boolean[n+1];
            start = i;
            dfs(i, visited, new TreeSet<Integer>());
        }
        System.out.println(tree.size());
        for(int a : tree){
            System.out.println(a);
        }
    }
}