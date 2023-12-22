import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

public class Main {

    static ArrayList<ArrayList<Integer>> map = new ArrayList<>();
    static boolean[][] visited;
    static int num = 0;

    static ArrayList<Integer> numList = new ArrayList<>();

    public static void find(int x, int y){

        int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Stack<int[]> stack = new Stack<>();

        visited[x][y] = true;
        stack.push(new int[]{x, y});
        int depth = 1;

        while(stack.size() > 0) {
            int[] node = stack.get(stack.size()-1);
            boolean check = false;
            for(int[] k : dire) {
                int newX = node[0] + k[0];
                int newY = node[1] + k[1];
                if (0 <= newX && newX < map.size() && 0 <= newY && newY < map.size()) {
                    if (!visited[newX][newY] && map.get(newX).get(newY) == 1) {
                        stack.push(new int[]{newX, newY});
                        visited[newX][newY] = true;
                        check = true;
                        depth += 1;
                        break;
                    }
                }
            }
            if (!check) {
                stack.pop();
            }
        }
        numList.add(depth);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        visited = new boolean[n][n];

        for(int i = 0; i < n; i++){
            String[] str = br.readLine().split("");
            ArrayList<Integer> temp = new ArrayList<Integer>();
            for(String j : str){
                temp.add(Integer.parseInt(j));
            }
            map.add(temp);
        }



        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map.size(); j++){
                if (!visited[i][j] && map.get(i).get(j) == 1) {
                    num += 1;
                    find(i, j);
                }
            }
        }
        System.out.println(num);
        Collections.sort(numList);
        for(int i : numList){
            System.out.println(i);
        }
    }
}