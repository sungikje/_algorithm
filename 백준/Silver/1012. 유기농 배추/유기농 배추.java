import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    static boolean[][] visited;
    static int result;


    static void dfs(int x, int y, int[][] loc, Stack<int[]> stack){

        int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visited[x][y] = true;
        stack.push(new int[]{x, y});

        while(stack.size() > 0){
            boolean check = false;
            int[] node = stack.get(stack.size()-1);
            for(int i = 0; i < dire.length; i++){
                int newX = node[0] + dire[i][0];
                int newY = node[1] + dire[i][1];
                if (0 <= newX && newX < loc.length && 0 <= newY && newY < loc[0].length) {

                    if (!visited[newX][newY] && loc[newX][newY] == 1) {
//                        System.out.println("진행 : " + newX + "   " + newY);
//                        for(int[] k : stack){
//                            System.out.println(Arrays.toString(k));
//                        }
                        check = true;
                        stack.push(new int[]{newX, newY});
                        visited[newX][newY] = true;
                        break;
                    }
                }
            }
            if (!check) {
                stack.pop();
            }
        }
    }

    static void find(boolean[][] visited, int[][] loc, int n) {

        for(int i = 0; i < visited.length; i++){
            for(int j = 0; j < visited[0].length; j++){
                if (!visited[i][j]) {
                    if (loc[i][j] == 1) {
                        result += 1;
//                        System.out.println(n + "   들어감 : " + i + "  " + j);
                        Stack<int[]> stack = new Stack<>();
                        dfs(i, j, loc, stack);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] loc;

        for(int i = 0; i < n; i++){
            String[] var = br.readLine().split(" ");
            visited = new boolean[Integer.parseInt(var[0])][Integer.parseInt(var[1])];
            loc = new int[Integer.parseInt(var[0])][Integer.parseInt(var[1])];
            result = 0;
            for(int j = 0; j < Integer.parseInt(var[2]); j ++){
                String[] str = br.readLine().split(" ");
                loc[Integer.parseInt(str[0])][Integer.parseInt(str[1])] = 1;
            }
//            System.out.println("그래프====================================================");
//            for(int[] k : loc) {
//                System.out.println(Arrays.toString(k));
//            }
//            System.out.println("=========================================================");
            find(visited, loc, i);
            System.out.println(result);
        }
    }
}