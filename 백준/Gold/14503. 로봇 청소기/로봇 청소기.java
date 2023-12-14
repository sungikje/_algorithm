
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Main {

    static int[][] arr;
    static int n;
    static int m;
    static boolean checkClean(int x, int y){

        if (((0 <= x && x < n) && (0 <= y && y < m)) && arr[x][y] == 0){
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] direArr = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        int x;
        int y;
        int dire;
        int count = 0;

        arr = new int[n][m];

        for(int[] i : arr){
            Arrays.fill(i, 0);
        }

        String[] str2 = br.readLine().split(" ");
        x = Integer.parseInt(str2[0]);
        y = Integer.parseInt(str2[1]);
        dire = Integer.parseInt(str2[2]);

        for(int i = 0; i<n; i++){
            String[] empty = br.readLine().split(" ");
            for(int j = 0; j<empty.length; j++){
                arr[i][j] = Integer.parseInt(empty[j]);
            }
        }

        while(true){
            if(arr[x][y] == 0){
                arr[x][y] = 2;
                count += 1;
            }

            // 하나라도 청소 안되어 있는 경우
            if(checkClean(x-1,y) || checkClean(x,y+1) || checkClean(x+1,y) || checkClean(x,y-1)){
                while(true){
                    dire  = dire - 1 < 0? 3 : dire-1;
                    if(checkClean(x+direArr[dire][0], y+direArr[dire][1])){
                        x = x+direArr[dire][0];
                        y = y+direArr[dire][1];
                        break;
                    }
                }
            } else {
                int oppDire = dire-2 < 0? dire+2 : dire-2;

                if(arr[x+direArr[oppDire][0]][y+direArr[oppDire][1]] != 1){
                    x = x+direArr[oppDire][0];
                    y = y+direArr[oppDire][1];
                } else {
                    break;
                }
            }
        }
        System.out.println(count);

        /*
        방향 = {{-1, 0}, {0, 1}, {1, 0}, [0, -1}}
        현재 바라보는 방향;

        n, m 입력 받음

        현재 위치, 방향 입력 받음

        2차원 배열 n, m 사이즈로 정의

        for n
           배열에 청소, 벽 등 조건 입력 받음


        while true
           if 현재 위치 청소 되지 않은 경우
                청소

           if 현재 상, 하, 좌, 우 청소 유무 판단, 모두 청소 되어있거나 벽인 경우
                현재 바라보는 방향 뒤쪽 벽이 아닌지 판단, 가능한 경우 => 후진하고 continue(초기 시점)
                else
                    break;
           else
                while true
                    현재 바라보는 방향 index - 1, 해당 방향의 앞쪽 칸 청소되지 않은 빈칸인 경우 전진
                        전진한 경우 break
         */
    }
}