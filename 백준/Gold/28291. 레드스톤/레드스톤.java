import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static int[][] value;
    static int[][] stone;

    static boolean checkBoundary(int x, int y){
        if(0 <= x && x<stone.length && 0 <= y && y < stone[0].length) {
            return true;
        }
        return false;
    }
    static void changeBlock(int x, int y) {
        if(checkBoundary(x, y)){
            value[x][y] = 15;
        }
    }
    static void findMax(int x, int y){
        int[][] dist = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0}};
//        System.out.println("max : " + max);

        for(int i = 0; i<dist.length; i++){
            if (checkBoundary(x+dist[i][0], y+dist[i][1])) {
                if(value[x][y] -1 > value[x+dist[i][0]][y+dist[i][1]]){
                    value[x+dist[i][0]][y+dist[i][1]] = value[x][y] -1;
                }
            }

        }

    }

    public static void main(String[] args) throws IOException {

        /*
        b 0 0
        d d d
        0 0 l

        0 : 아무것도 없음
        1 : dust
        2 : block
        3 : lamp

         2차원 점수 배열 생성
         block => 상, 하, 좌, 우 15로 교체
         dust => (상, 하, 좌, 우 중에 가장 큰 수 -1), 해당 수와 상, 하, 좌, 우 비교하며 더 큰 수로 상, 하, 좌, 우 교체
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] arr = br.readLine().split(" ");
        int x = Integer.parseInt(arr[0]);
        int y = Integer.parseInt(arr[1]);
        stone = new int[x][y];
        value = new int[x][y];
        int repeat = Integer.parseInt(br.readLine());
        ArrayList<int[]> lampList = new ArrayList<int[]>();


        for(int i = 0; i < repeat; i++){
            String[] str = br.readLine().split(" ");
            if (str[0].equals("redstone_dust")) {
                stone[Integer.parseInt(str[1])][Integer.parseInt(str[2])] = 1;
            } else if(str[0].equals("redstone_block")){
                stone[Integer.parseInt(str[1])][Integer.parseInt(str[2])] = 2;
            } else {
                stone[Integer.parseInt(str[1])][Integer.parseInt(str[2])] = 3;
                lampList.add(new int[]{Integer.parseInt(str[1]), Integer.parseInt(str[2])});
            }
        }


        for(int i = 0; i < stone.length; i++){
            for(int j = 0; j < stone[i].length; j++){
                if(stone[i][j] == 2) {
                    changeBlock(i+1, j);
                    changeBlock(i, j+1);
                    changeBlock(i-1, j);
                    changeBlock(i, j-1);
                }
            }
        }

//        for(int[] i : value){
//            System.out.println(Arrays.toString(i));
//        }

//        System.out.println(); System.out.println(); System.out.println();


        for(int i = 0; i < stone.length; i++){
            for(int j = 0; j < stone[i].length; j++){
                if(stone[i][j] == 1){
                    findMax(i, j);
                }
            }
        }

//        for(int[] i : value){
//            System.out.println(Arrays.toString(i));
//        }

        for(int i = 0; i<lampList.size(); i++){
            if(value[lampList.get(i)[0]][lampList.get(i)[1]] <= 0){
                System.out.println("failed");
                return;
            }
        }
        System.out.println("success");
    }
}
