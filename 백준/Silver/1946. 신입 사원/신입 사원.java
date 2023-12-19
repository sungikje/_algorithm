import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int find(ArrayList<int[]> arr){

        int max = arr.size()+1;
        int count = 0;

        Collections.sort(arr, new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2){
                return o1[0] - o2[0];
            }
        });

//        for(int[] i : arr) {
//            System.out.println(Arrays.toString(i));
//        }

        for(int i = 0; i < arr.size(); i++){
            if(arr.get(i)[1] < max) {
                max = arr.get(i)[1];
                count += 1;
            }
        }
//        System.out.println();
//        System.out.println();
//        System.out.println();

        return count;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());


        for(int i = 0; i < n; i++){
            ArrayList<int[]> arr = new ArrayList<>();
            int m = Integer.parseInt(br.readLine());
            for(int j = 0; j < m; j++){
                String[] str = br.readLine().split(" ");
                arr.add(new int[]{Integer.parseInt(str[0]), Integer.parseInt(str[1])});
            }
            System.out.println(find(arr));
        }
    }
}

