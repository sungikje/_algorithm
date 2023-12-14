import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static boolean checkNum(int size, int x, int y, List<String []> arr){
        int move = size;
        if (arr.get(x)[y].equals(arr.get(x+size)[y]) && arr.get(x)[y+size].equals(arr.get(x+size)[y+size])) {
            if(arr.get(x)[y].equals(arr.get(x)[y+size])){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String []> arr = new ArrayList<>();

        String[] num = br.readLine().split(" ");
        int size = Integer.parseInt(num[0]) <= Integer.parseInt(num[1])? Integer.parseInt(num[0]) : Integer.parseInt(num[1]);
        int max = 0;

        for(int i = 0; i<Integer.parseInt(num[0]); i++){
            String[] str = br.readLine().split("");
            arr.add(str);
        }


        for(int i = 0; i<size; i++){
            for(int j = 0; j < Integer.parseInt(num[0])-i; j++){
                for(int k = 0; k < Integer.parseInt(num[1])-i; k++){
                    if(checkNum(i, j, k, arr)){
                        max = i+1;
                    }
                }
            }
        }
        System.out.println(max*max);
    }
}
