import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        List<ArrayList<Character>> peoples = new ArrayList<ArrayList<Character>>();
        ArrayList<Character> empty = new ArrayList<Character>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String result = "";
        int max = 0;

        for(int i = 0; i<5; i++){
            String str = br.readLine();
            empty.clear();
            for(int j = 0; j<str.length(); j++){
                empty.add(str.charAt(j));
            }
            peoples.add((ArrayList<Character>) empty.clone());
            if(max < str.length()){
                max = str.length();
            }
        }

        String[] arr = new String[max];
        for(int i = 0; i<max; i++){
            arr[i] = "";
        }

        for(int i = 0; i<5; i++){
            for(int j = 0; j<peoples.get(i).size(); j++){
                arr[j] += peoples.get(i).get(j);
            }
        }

        for(int i = 0; i<arr.length; i++){
            result += arr[i];
        }
        System.out.println(result);
    }
}
