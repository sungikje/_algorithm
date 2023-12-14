
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String[] str;
        List<List<Integer>> arr = new ArrayList<>();
        int maxX = 0;
        int maxY = 0;
        int count = 0;


        for(int i = 0; i<4; i++){
            str = br.readLine().split(" ");
            List<Integer> emptyArr = new ArrayList<Integer>();

            for(int j = 0; j<str.length; j++){
                emptyArr.add(Integer.parseInt(str[j]));
            }
            arr.add(emptyArr);
        }

        for(int i = 0; i<4; i++){
            for(int j = 0; j<2; j++){
                if(arr.get(i).get(j) > maxX){
                    maxX = arr.get(i).get(j);
                }
            }
            for(int j = 2; j<arr.get(i).size(); j++){
                if(arr.get(i).get(j) > maxY){
                    maxY = arr.get(i).get(j);
                }
            }
        }

        int size = maxX < maxY? maxY:maxX;

        boolean[][] result = new boolean[size+1][size+1];

        for(int i = 0; i < 4; i++){
            for(int j = arr.get(i).get(0); j < arr.get(i).get(2); j++){
                for(int k = arr.get(i).get(1); k < arr.get(i).get(3); k++){
                    result[j][k] = true;
                }
            }
        }

        for(int i = 0; i < result.length; i++){
//            System.out.println(Arrays.toString(result[i]));
            for(int j = 0; j < result.length; j++){
                if(result[i][j] == true){
                    count += 1;
                }
            }
        }
        System.out.println(count);



        /*
        입력받은 좌표들 x, y 분류해 저장

        최대 x, 최대 y로 형성된 2차원 배열 false로 초기화

        입력받은 좌표들 특정 구간들 true로 변경

        2차원 배열 true 갯수 반환

        1 2 4 4
        2 3 5 7
        3 1 6 5
        7 3 8 6
         */



    }
}

