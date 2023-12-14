import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int count = 0;
        char key = ' ';
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String str = reader.readLine();
        str = str.toUpperCase();

        for(int i = 0; i<str.length(); i++){
            if(map.containsKey(str.charAt(i))){
                int value = map.get(str.charAt(i));
                map.put(str.charAt(i), value+1);
            } else {
                map.put(str.charAt(i), 1);
            }
        }

        int max =  Collections.max(map.values());

        for(char i : map.keySet()){
            if (map.get(i) == max) {
                key = i;
                count += 1;
            }
        }

        if(count == 1){
            System.out.println(key);
        } else {
            System.out.println("?");
        }
    }
}
