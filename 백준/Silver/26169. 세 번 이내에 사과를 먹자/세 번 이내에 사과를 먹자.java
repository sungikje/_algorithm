import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static int result = 0;
    static void dfs(int x, int y, ArrayList<ArrayList<Integer>> arr, int count, int work) {

        int[][] dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        if (arr.get(x).get(y) == 1){
            count += 1;
        }

        if (work == 3) {
            if (count >= 2){
                result = 1;
            }
            return;
        }

        for (int i = 0; i < dire.length; i++) {
            int newX = x + dire[i][0];
            int newY = y + dire[i][1];

            if (0 <= newX && newX < 5 && 0 <= newY && newY < 5) {
                if (arr.get(newX).get(newY) != -1) {
                    arr.get(x).set(y, -1);
                    dfs(x + dire[i][0], y + dire[i][1], arr, count, work + 1);
                    arr.get(x).set(y, 0);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<ArrayList<Integer>> map = new ArrayList<>();

        for(int i = 0; i< 5; i++){
            ArrayList<Integer> arr = new ArrayList<>();
            String[] str = br.readLine().split(" ");
            for(int j = 0; j<str.length; j++){
                arr.add(Integer.parseInt(str[j]));
            }
            map.add(arr);
        }

        String[] loc = br.readLine().split(" ");

        dfs(Integer.parseInt(loc[0]), Integer.parseInt(loc[1]), map, 0, 0);
        System.out.println(result);
    }
}

