import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int path = 0;
        int sum = 0;
        int x = 1;
        int y = 1;

        while(sum < num){
            path++;
            sum += path;
        }
        if (path% 2 == 0) {
            y = path;
            for(int i = 1; i< num-(sum-path); i++){
                x += 1;
                y -= 1;
            }
        } else {
            x = path;
            for(int i = 1; i< num-(sum-path); i++){
                x -= 1;
                y += 1;
            }
        }
        System.out.println(x+"/"+y);
    }
}
