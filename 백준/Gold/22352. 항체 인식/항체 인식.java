import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static boolean[][] afterVisited;
    static boolean[][] beforeVisited;
    static int[][] beforeGraph;
    static int[][] afterGraph;
    static int beforeCount;
    static int afterCount;
    static void dfs(int x, int y, int num, String type){
        int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        if (type.equals("after")) {
            afterVisited[x][y] = true;
        } else {
            beforeVisited[x][y] = true;
        }

        for(int i = 0; i < dire.length; i++){
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];

            if (0 <= newX && newX < beforeGraph.length && 0 <= newY && newY < beforeGraph[0].length) {
                if (type.equals("after")) {
                    if (!afterVisited[newX][newY] && afterGraph[newX][newY] == num) {
                        afterCount += 1;
                        dfs(newX, newY, num, "after");
                    }
                } else {
                    if (!beforeVisited[newX][newY] && beforeGraph[newX][newY] == num) {
                        beforeCount += 1;
                        dfs(newX, newY, num, "before");
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] st = br.readLine().split(" ");

        int count = 0;

        beforeGraph = new int[Integer.parseInt(st[0])][Integer.parseInt(st[1])];
        afterGraph = new int[Integer.parseInt(st[0])][Integer.parseInt(st[1])];
        beforeVisited = new boolean[Integer.parseInt(st[0])][Integer.parseInt(st[1])];
        afterVisited = new boolean[Integer.parseInt(st[0])][Integer.parseInt(st[1])];

        for(int i = 0; i < Integer.parseInt(st[0]); i++){
            String[] temp = br.readLine().split(" ");
            for(int j = 0; j < temp.length; j++){
                beforeGraph[i][j] = Integer.parseInt(temp[j]);
            }
        }

        for(int i = 0; i < Integer.parseInt(st[0]); i++){
            String[] temp = br.readLine().split(" ");
            for(int j = 0; j < temp.length; j++){
                afterGraph[i][j] = Integer.parseInt(temp[j]);
            }
        }

        for(int i = 0; i < Integer.parseInt(st[0]); i++){
            for(int j = 0; j < Integer.parseInt(st[1]); j++){
                beforeCount = 0;
                afterCount = 0;
                if (!beforeVisited[i][j] && beforeGraph[i][j] != afterGraph[i][j]) {
                    count += 1;
                    dfs(i, j, afterGraph[i][j], "after");
                    dfs(i, j, beforeGraph[i][j], "before");
                }
                if (count > 1 || beforeCount > afterCount) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
    }
}