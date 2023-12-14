import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] loc = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        boolean[] result = new boolean[9];


        String[] str = br.readLine().split(" ");
        int size = Integer.parseInt(str[0]);
        int queenNum = Integer.parseInt(str[1]);

        str = br.readLine().split(" ");
        int[] king = {Integer.parseInt(str[0]), Integer.parseInt(str[1])};


        for(int i = 0; i<queenNum; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < loc.length; j++) {
                if(((king[0] + loc[j][0] <= size) && (0 < king[0] + loc[j][0])) && ((king[1] + loc[j][1] <= size) && (0 < king[1] + loc[j][1]))){
                    if ((Integer.parseInt(str[0]) == (king[0] + loc[j][0])) || (Integer.parseInt(str[1]) == (king[1] + loc[j][1]))) {
                        result[j] = true;
                    }
                    if ((Integer.parseInt(str[0]) - (king[0] + loc[j][0])) * (Integer.parseInt(str[0]) - (king[0] + loc[j][0])) == (Integer.parseInt(str[1]) - (king[1] + loc[j][1])) * (Integer.parseInt(str[1]) - (king[1] + loc[j][1]))) {
                        result[j] = true;
                    }
                } else {
                    result[j] = true;
                }
            }
        }
        if(result[4]){
            for(int i = 0; i<result.length; i++){
                if((i != 4 && !result[i])){
                    System.out.println("CHECK");
                    return;
                }
            }
            System.out.println("CHECKMATE");
        } else {
            for(int i = 0; i<result.length; i++){
                if((i != 4 && !result[i])){
                    System.out.println("NONE");
                    return;
                }
            }
            System.out.println("STALEMATE");
        }
    }
}
