import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int[][] graph;
    static int[][] seaGraph;
    static boolean[][] visited;

    static int findSea(int x, int y) {

        int[][] dire = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int count = 0;
        
        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];
            if (0 <= newX && newX < graph.length && 0 <= newY && newY < graph[i].length) {
                if (graph[newX][newY] == 0) {
                    count += 1;
                }
            }
        }

        return count;
    }

    static void dfs(int x, int y) {

        int[][] dire = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        visited[x][y] = true;

        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];
            if ((0 <= newX && newX < graph.length) && (0 <= newY && newY < graph[i].length)) {
                if (!visited[newX][newY] && graph[newX][newY] != 0) {
                    dfs(newX, newY);
                }
            }
        }


    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        int time = 0;

        graph = new int[Integer.parseInt(str[0])+1][Integer.parseInt(str[1])+1];
        seaGraph = new int[Integer.parseInt(str[0])+1][Integer.parseInt(str[1])+1];


        for(int i = 0; i < Integer.parseInt(str[0]); i++){
            String[] temp = br.readLine().split(" ");
            for(int j = 0; j < temp.length; j++) {
                graph[i][j] = Integer.parseInt(temp[j]);
            }
        }

        while (true) {
            boolean check = false;
            int count = 0;

            for(int i = 0; i < graph.length; i++){
                for(int j = 0; j < graph[i].length; j++){
                    //                System.out.println("확인 ㅣ " + i + "   " + j);
                    if (graph[i][j] != 0) {
                        seaGraph[i][j] = findSea(i, j);
                    }
                }
            }
            
            visited = new boolean[Integer.parseInt(str[0])+1][Integer.parseInt(str[1])+1];
            for(int i = 0; i < graph.length; i++){
                for(int j = 0; j < graph[i].length; j++){
                    if (graph[i][j] != 0) {
                        check = true;
                    }
                    if (!visited[i][j] && graph[i][j] != 0) {
                        count += 1;
                        dfs(i, j);
                    }
                }
            }
            if (!check) {
                System.out.println(0);
                return;
            }
            if (count >= 2) {
                System.out.println(time);
                return;
            }

            for(int i = 0; i < graph.length; i++){
                for(int j = 0; j < graph[i].length; j++){
                    if (graph[i][j] - seaGraph[i][j] < 0) {
                        graph[i][j] = 0;
                    } else {
                        graph[i][j] -= seaGraph[i][j];
                    }
                }
            }

            time += 1;
        }
    }
}