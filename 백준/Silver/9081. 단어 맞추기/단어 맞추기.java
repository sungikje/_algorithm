import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static void work(String str) {
        int[] arr = new int[str.length()];
        int index = 0;
        int secondIndex = arr.length-1;
        String result = "";

        for(int i = 0; i < arr.length; i++){
            arr[i] = str.charAt(i);
        }

        for(int i = 0; i < arr.length-1; i++){
            if (arr[i] < arr[i + 1]) index = i;
        }

        int min = 40;
        boolean check = false;
        for(int i = arr.length-1; i > index; i--){
            if (arr[i] > arr[index] && arr[i] - arr[index] < min) {
                min = arr[i] - arr[index];
                secondIndex = i;
                check = true;
            }
        }

        if (check) {
            int temp = arr[index];
            arr[index] = arr[secondIndex];
            arr[secondIndex] = temp;

            for(int i = 0; i <= index; i++){
                result += (char)arr[i];
            }

            int[] arr2 = Arrays.copyOfRange(arr, index+1, arr.length);

            Arrays.sort(arr2);

            for(int i = 0; i < arr2.length; i++){
                result += (char)arr2[i];
            }
        } else {
            for(int i = 0; i < arr.length; i++){
                result += (char)arr[i];
            }
        }
        System.out.println(result);
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            work(br.readLine());
        }
    }
}