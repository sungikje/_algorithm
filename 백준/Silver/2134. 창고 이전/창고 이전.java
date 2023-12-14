import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> nBuilding = new ArrayList<>();
        ArrayList<Integer> mBuilding = new ArrayList<>();

        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int k = Integer.parseInt(str[2]);
        int sumN = 0;
        int sumM = 0;
        long result = 0;
        int sum;

        for(int i = 0; i<n; i++){
            nBuilding.add(Integer.parseInt(br.readLine()));
            sumN += nBuilding.get(i);
        }

        for(int i = 0; i<m; i++){
            mBuilding.add(Integer.parseInt(br.readLine()));
            sumM += mBuilding.get(i);
        }

        sum = sumN>sumM? sumM:sumN;
        sumN = sum;
        sumM = sum;

        for(int i = 0; sumN > 0; i++){
            if(sumN >= nBuilding.get(i)){
                result += nBuilding.get(i)*(i+1);
                sumN -= nBuilding.get(i);
            } else{
                result += sumN*(i+1);
                sumN = 0;
            }
        }

        for(int i = 0; sumM > 0; i++){
            if(sumM >= mBuilding.get(i)){
                result += mBuilding.get(i)*(i+1);
                sumM -= mBuilding.get(i);
            } else{
                result += sumM*(i+1);
                sumM = 0;
            }
        }
        System.out.println(sum+" "+result);
    }
}