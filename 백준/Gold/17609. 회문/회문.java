import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int checkPalindrome(String str, int left, int right, boolean check) {

        while (right > left) {
            if (str.charAt(left) == str.charAt(right)) {
                left += 1;
                right -= 1;
            } else {
                if (check) {
                    return 2;
                } else {
                    if (checkPalindrome(str, left + 1, right, true) == 1 || checkPalindrome(str, left, right - 1, true) == 1) {
                        return 1;
                    } else {
                        return 2;
                    }
                }
            }
        }
        if (check) {
            return 1;
        } else {
            return 0;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String str = br.readLine();
            System.out.println(checkPalindrome(str, 0, str.length() - 1, false));
        }
    }
}
