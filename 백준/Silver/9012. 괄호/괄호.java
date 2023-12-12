import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    static String checkVps(String str) {
        Stack<String> stack = new Stack<>();

        for(int i = 0; i < str.length(); i++){
            if (str.charAt(i) == '(') {
                stack.add("(");
            } else {
                if (stack.size() == 0) {
                    return "NO";
                } else {
                    stack.pop();
                }
            }
        }

        return stack.size() == 0 ? "YES" : "NO";
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            System.out.println(checkVps(br.readLine()));
        }
    }
}
