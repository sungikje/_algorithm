import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static boolean[][] visited;
    static String[][] graph;

    static void dfs(int x, int y, String color, int type) {

        int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visited[x][y] = true;

        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];

            if (0 <= newX && newX < visited.length && 0 <= newY && newY < visited.length) {
                if (type == 0) {
                    if (!visited[newX][newY] && graph[newX][newY].equals(color)) {
                        dfs(newX, newY, color, type);
                    }
                } else {
                    if (!visited[newX][newY]) {
                        if (graph[x][y].equals("R") || graph[x][y].equals("G")) {
                            if (graph[newX][newY].equals("R") || graph[newX][newY].equals("G")) {
                                dfs(newX, newY, color, type);
                            }
                        } else {
                            if (graph[newX][newY].equals(color)) {
                                dfs(newX, newY, color, type);
                            }
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        graph = new String[n][n];
        int[] result = new int[2];
        int count;

        for(int i = 0; i < n; i++){
            String[] temp = br.readLine().split("");
            for(int j = 0; j < temp.length; j++){
                graph[i][j] = temp[j];
            }
        }

//        for(String[] str : graph){
//            System.out.println(Arrays.toString(str));
//        }

        for(int k = 0; k < 2; k++){
            visited = new boolean[n][n];
            count = 0;
            for(int i = 0; i < graph.length; i++){
                for(int j = 0; j < graph.length; j++){
                    if (!visited[i][j]) {
                        count += 1;
                        dfs(i, j, graph[i][j], k);
                    }
                }
            }
            result[k] = count;
        }
        for(int a : result){
            System.out.print(a+" ");
        }
    }
}