import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String[]> graph = new ArrayList<>();
        ArrayList<int[]> sumGraph = new ArrayList<>();
        int max = 0;

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String[] str = br.readLine().split(" ");
            graph.add(str);
            sumGraph.add(new int[str.length]);
        }

        sumGraph.get(0)[0] = Integer.parseInt(graph.get(0)[0]);

        for(int i = 1; i < graph.size(); i++){
            for(int j = 0; j < graph.get(i).length; j++){

                if (j == 0) {
                    sumGraph.get(i)[j] = sumGraph.get(i-1)[j] + Integer.parseInt(graph.get(i)[j]);
                } else if (j == graph.get(i).length-1) {
                    sumGraph.get(i)[j] = sumGraph.get(i-1)[j-1] + Integer.parseInt(graph.get(i)[j]);
                } else {
                    int leftValue = Integer.parseInt(graph.get(i)[j]) + sumGraph.get(i-1)[j-1];
                    int rightValue = Integer.parseInt(graph.get(i)[j]) + sumGraph.get(i-1)[j];
                    sumGraph.get(i)[j] =  leftValue > rightValue ? leftValue : rightValue;
                }
            }
        }
        for(int[] i : sumGraph){
            for(int j : i){
                if (max < j) {
                    max = j;
                }
            }
        }
        System.out.println(max);
    }
}