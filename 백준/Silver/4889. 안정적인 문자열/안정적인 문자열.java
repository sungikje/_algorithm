import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<String> list;
        String s;
        int count;
        int repeat = 1;

        do {
            count = 0;
            s = br.readLine();
            String[] arr = s.split("");
            list = new LinkedList<>();

            for(int i = 0; i < arr.length; i++){
                if (arr[i].equals("{")) {
                    list.add(arr[i]);
                } else {
                    if (list.size() == 0) {
                        list.add("{");
                        count += 1;
                    } else {
                        list.pop();
                    }
                }
            }
            if (s.contains("-")) {
                break;
            }
            System.out.println(repeat + ". " + (count + list.size()/2));
            repeat += 1;
        } while(!s.contains("-"));
    }
}