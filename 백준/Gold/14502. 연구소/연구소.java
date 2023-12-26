import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int result = 0;
    static int count = 0;
    static void combWall(int[][] graph, boolean[][] visited, int depth){

        if (depth == 3) {
            spread(graph);
            return;
        }

        for(int i = 0; i < graph.length; i++){
            for(int j = 0; j < graph[i].length; j++){
                if (!visited[i][j] && graph[i][j] == 0) {
                    visited[i][j] = true;
                    graph[i][j] = 1;
                    combWall(graph, visited, depth + 1);
                    visited[i][j] = false;
                    graph[i][j] = 0;
                }
            }
        }
    }

    static void spread(int[][] graph) {
        int[][] spreadGraph = new int[graph.length][graph[0].length];
        boolean[][] visited = new boolean[graph.length][graph[0].length];
        count = 0;

        for(int i = 0; i < graph.length; i++){
            spreadGraph[i] = graph[i].clone();
        }

        for(int i = 0; i < graph.length; i++){
            for(int j = 0; j < graph[i].length; j++){
                if (spreadGraph[i][j] == 2) {
                    spreadPlay(i, j, spreadGraph, visited);
                }
            }
        }

        visited = new boolean[graph.length][graph[0].length];

        for(int i = 0; i < graph.length; i++){
            for(int j = 0; j < graph[i].length; j++){
                if (spreadGraph[i][j] == 0 && !visited[i][j]) {
                    count += 1;
                    checkSafe(i, j, spreadGraph, visited);
                }
            }
        }
        
        if (count > result) {
            result = count;
        }

    }

    static void spreadPlay(int x, int y, int[][] graph, boolean[][] visited) {
        int[][] dire = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        visited[x][y] = true;

        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];
            if (0 <= newX && newX < graph.length && 0 <= newY && newY < graph[0].length) {
                if (!visited[newX][newY] && graph[newX][newY] != 1) {
                    graph[newX][newY] = 2;
                    spreadPlay(newX, newY, graph, visited);
                }
            }
        }
    }

    static void checkSafe(int x, int y, int[][] graph, boolean[][] visited) {
        int[][] dire = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        visited[x][y] = true;

        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];
            if (0 <= newX && newX < graph.length && 0 <= newY && newY < graph[0].length) {
                if (graph[newX][newY] == 0 && !visited[newX][newY]) {
                    count += 1;
                    checkSafe(newX, newY, graph, visited);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        int[][] graph = new int[Integer.parseInt(str[0])][Integer.parseInt(str[1])];
        boolean[][] visited = new boolean[Integer.parseInt(str[0])][Integer.parseInt(str[1])];

        for(int i = 0; i < Integer.parseInt(str[0]); i++){
            String[] temp = br.readLine().split(" ");
            for(int j = 0; j < Integer.parseInt(str[1]); j++){
                graph[i][j] = Integer.parseInt(temp[j]);
            }
        }

        combWall(graph, visited, 0);
        System.out.println(result);

    }
}