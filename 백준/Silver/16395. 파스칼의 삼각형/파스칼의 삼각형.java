import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] temp = br.readLine().split(" ");

        LinkedList<LinkedList<Integer>> pascal = new LinkedList<>();

        for(int i = 0; i <= Integer.parseInt(temp[0]); i++){
            pascal.add(new LinkedList<Integer>());
        }
        pascal.get(0).add(1);
        pascal.get(1).add(1);
        pascal.get(1).add(1);

        for(int i = 2; i < pascal.size(); i++){
            pascal.get(i).add(1);
            for(int j = 1; j < i-1; j++){
                pascal.get(i).add(pascal.get(i-1).get(j-1) + pascal.get(i-1).get(j));
            }
            pascal.get(i).add(1);
        }

        System.out.println(pascal.get(Integer.parseInt(temp[0])).get(Integer.parseInt(temp[1])-1));

    }
}