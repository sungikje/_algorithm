import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean[][] visited = new boolean[5][5];
    static int min = Integer.MAX_VALUE;

    static void dfs(int x, int y, int depth, int apple) {
        int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        if (graph.get(x).get(y) == 1) {
            apple += 1;
            if (apple == 3) {
                if (min > depth) {
                    min = depth;
                    return;
                }
            }
        }

        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];
            if (0 <= newX && newX < 5 && 0 <= newY && newY < 5) {
                if (!visited[newX][newY] && graph.get(newX).get(newY) != -1) {
                    visited[newX][newY] = true;
                    dfs(newX, newY, depth + 1, apple);
                    visited[newX][newY] = false;
                }
            }
        }

    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] loc = new int[2];

        for(int i = 0; i < 5; i++){
            graph.add(new ArrayList<>());
            String[] temp = br.readLine().split(" ");
            for(String a : temp){
                graph.get(i).add(Integer.parseInt(a));
            }
        }

        String[] temp = br.readLine().split(" ");
        loc[0] = Integer.parseInt(temp[0]);
        loc[1] = Integer.parseInt(temp[1]);

        visited[loc[0]][loc[1]] = true;
        dfs(loc[0], loc[1], 0, 0);

        if (min == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }
}