import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Main {

    static int result;
    static void dfs(ArrayList<ArrayList<Integer>> arr, boolean[][] visited, int x, int y, Stack<int[]> stack){

        int[][] dire = {{-1, 0}, {-1, 1}, {1, 0}, {1, -1}, {0, -1}, {1, 1}, {0, 1}, {-1, -1}};

        visited[x][y] = true;
        stack.push(new int[]{x, y});


        while(stack.size() > 0){
            int[] node = stack.get(stack.size()-1);
            boolean  check = false;
            for(int i = 0; i < dire.length; i++){
                int newX = node[0] + dire[i][0];
                int newY = node[1] + dire[i][1];


                if (0 <= newX && newX < arr.size() && 0 <= newY && newY < arr.get(0).size()) {
//                    System.out.println(arr.size() + "   " + arr.get(0).size());
//                    System.out.println(newX + "   " + newY);
//                    System.out.println(arr.get(newX).get(newY));
//                    System.out.println("=============================");
                    if(!visited[newX][newY] && arr.get(newX).get(newY) == 1){
                        check = true;
                        visited[newX][newY] = true;
                        stack.push(new int[]{newX, newY});
                        break;
                    }
                }
            }
            if(!check){
                stack.pop();
            }
        }
    }
    static void find(ArrayList<ArrayList<Integer>> arr, boolean[][] visited){

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.get(0).size(); j++){
                if (!visited[i][j] && arr.get(i).get(j) == 1) {
                    result += 1;
                    Stack<int[]> stack = new Stack<>();
                    dfs(arr, visited, i, j, stack);
                }
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<ArrayList<Integer>> arr;
        boolean[][] visited;

        while(true){
            result = 0;
            String[] size = br.readLine().split(" ");

            if (size[0].equals("0") && size[1].equals("0")){
                break;
            }

            arr = new ArrayList<>();

            for(int i = 0; i < Integer.parseInt(size[1]); i++) {
                String[] str = br.readLine().split(" ");
                ArrayList<Integer> temp = new ArrayList<>();
                for(String j : str){
                    temp.add(Integer.parseInt(j));
                }
                arr.add(temp);
            }
            visited = new boolean[arr.size()][arr.get(0).size()];
            find(arr, visited);
        }

    }
}