import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeSet;

public class Main {

    static int min;
    static int max;

    static boolean check = false;

    static String[][] graph;
    static TreeSet<String> path = new TreeSet<>();

    static void dfs(int x, int y, String str, int depth){

        int[][] dire = {{0, 1}, {1, 0}};

        if (depth >= graph.length*2-1) {
            return;
        }

        if (x == graph.length - 1 && y == graph.length - 1) {
            path.add(str);
//            System.out.println(str);
            return;
        }

        for(int i = 0; i < dire.length; i++){
            int newX = x+dire[i][0];
            int newY = y+dire[i][1];
            if (0 <= newX && newX < graph.length && 0 <= newY && newY < graph.length) {
//                System.out.println(newX + "   " + newY);
                dfs(newX, newY, str + graph[newX][newY], depth + 1);
//                System.out.println();
            }
        }

    }

    static void find(String s){
        int n = Character.getNumericValue(s.charAt(0));

        for(int i = 1; i < s.length(); i+=2){
            int r = Character.getNumericValue(s.charAt(i+1));
            if (s.charAt(i) == '+') {
                n += r;
            } else if (s.charAt(i) == '-') {
                n -= r;
            } else {
                n *= r;
            }
        }
        if (!check) {
            max = n;
            min = n;
            check = true;
        }

        if (n > max) {
            max = n;
        }
        if (n < min) {
            min = n;
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        graph = new String[n][n];

        for(int i = 0 ; i < n; i++){
            String[] temp = br.readLine().split(" ");
            for(int j = 0; j < n; j++){
                graph[i][j] = temp[j];
            }
        }

//        for(String[] s : graph){
//            System.out.println(Arrays.toString(s));
//        }

        dfs(0, 0, graph[0][0], 0);
//        System.out.println(path);

        for(String s : path){
            find(s);
        }
        System.out.println(max + " " + min);
    }
}