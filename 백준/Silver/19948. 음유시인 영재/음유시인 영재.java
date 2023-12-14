
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        String[] str;
        String[] value;
        int space;
        Stack<String> stack = new Stack<>();

        int count = 0;
        String title = "";
        boolean result = false;

        str = br.readLine().split("");
        space = Integer.parseInt(br.readLine());
        value = br.readLine().split(" ");

        for(int i = 0; i<str.length; i++){
            if(!str[i].equals(" ") && (stack.empty() || stack.peek().equals(" "))) {
                title += str[i].toUpperCase();
                stack.push(str[i]);
            } else if (str[i].equals(" ") && (stack.empty() || !stack.peek().equals(" "))) {
                count += 1;
                stack.push(str[i]);
            }
        }

        if(count > space){
            System.out.println(-1);
        } else {
            stack = new Stack<>();
            for(char i = 'A'; i <= 'Z'; i++){
                int num = (char)(i-65);
                map.put(i,Integer.parseInt(value[num]));
            }

            for(int i = 0; i<str.length; i++){
                if(!str[i].equals(" ") && (stack.empty() || !stack.peek().equals(str[i]))){
                    char key = str[i].toUpperCase().charAt(0);
                    map.put(key, map.get(key)-1);
                    stack.push(str[i]);
                }
            }

            for(int i = 0; i<title.length(); i++){
                char key = title.charAt(i);
                map.put(key, map.get(key)-1);
            }

            for(char i : map.keySet()){
                if(map.get(i) < 0){
                    result = true;
                    break;
                }
            }
            if(result){
                System.out.println(-1);
            } else {
                System.out.println(title);
            }
        }
    }
}
