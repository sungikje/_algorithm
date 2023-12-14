import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int findSum(ArrayList<Integer> arr, int num) {
        int sum = 0;
        for(int i = 0; i<num; i++){
            sum += arr.get(i);
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {

        List<Integer> floor = new ArrayList<Integer>();
        List<Integer> arc = new ArrayList<Integer>();
        List<ArrayList<Integer>> peoples = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> empty = new ArrayList<Integer>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i<n; i++){
            floor.add(Integer.parseInt(br.readLine()));
            arc.add(Integer.parseInt(br.readLine()));
        }

        int maxFloor = Collections.max(floor);
        int maxArc = Collections.max(arc);

        for(int i = 0; i<maxArc; i++){
            empty.add(i+1);
        }
        peoples.add((ArrayList<Integer>) empty.clone());

        for(int i = 0 ; i<maxFloor; i++){
            empty.clear();
            for(int j = 0; j<maxArc; j++){
                if(j == 0){
                    empty.add(1);
                } else {
                    empty.add(findSum(peoples.get(i) , j+1));
                }
            }
            peoples.add((ArrayList<Integer>) empty.clone());
        }
        for(int i = 0; i<floor.size(); i++) {
            System.out.println(peoples.get(floor.get(i)).get(arc.get(i)-1));
        }

    }
}
