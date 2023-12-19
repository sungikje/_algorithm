import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = {25, 10, 5, 1};
        int num = Integer.parseInt(br.readLine());
        for(int i = 0; i<num; i++){
            int value = Integer.parseInt(br.readLine());
            for(int j = 0; j<arr.length; j++){
                if(value != 0){
                    System.out.print(value / arr[j] + " ");
                    value %= arr[j];
                } else {
                    System.out.print(0+" ");
                }
            }
            System.out.println();
        }
    }
}