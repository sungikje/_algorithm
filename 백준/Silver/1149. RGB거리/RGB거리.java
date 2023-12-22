import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int min = 2147483647;
        int[][] arr = new int[1001][3];


        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String[] str = br.readLine().split(" ");
            ArrayList<Integer> temp = new ArrayList<>();
            for(String j : str) {
                temp.add(Integer.parseInt(j));
            }
            graph.add(temp);
        }

        arr[0][0] = graph.get(0).get(0);
        arr[0][1] = graph.get(0).get(1);
        arr[0][2] = graph.get(0).get(2);

        for(int i = 1; i < graph.size(); i++){
            arr[i][0] = arr[i-1][1] + graph.get(i).get(0) > arr[i-1][2] + graph.get(i).get(0) ? arr[i-1][2] + graph.get(i).get(0) : arr[i-1][1] + graph.get(i).get(0);
            arr[i][1] = arr[i-1][0] + graph.get(i).get(1) > arr[i-1][2] + graph.get(i).get(1) ? arr[i-1][2] + graph.get(i).get(1) : arr[i-1][0] + graph.get(i).get(1);
            arr[i][2] = arr[i-1][0] + graph.get(i).get(2) > arr[i-1][1] + graph.get(i).get(2) ? arr[i-1][1] + graph.get(i).get(2) : arr[i-1][0] + graph.get(i).get(2);
        }

        for(int i : arr[graph.size()-1]){
            if (i < min) {
                min = i;
            }
        }
        System.out.println(min);
    }
}