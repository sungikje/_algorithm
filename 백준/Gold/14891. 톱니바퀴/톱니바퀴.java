import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;


public class Main {
    static ArrayList<String[]> arr = new ArrayList<String[]>();
    static int[] toothPointer = {0, 0, 0, 0};
    static int[] changeTooth(int tooth, int dire, int[] direList){
        int standardT = tooth;
        int standardD = dire;
        while(true){
            if(tooth - 1 >= 0){
                if(!arr.get(tooth)[(6+toothPointer[tooth])%8].equals(arr.get(tooth-1)[(2+toothPointer[tooth-1])%8])){
                    direList[tooth-1] = dire == -1? 1 : -1;
                    dire = direList[tooth-1];
                    tooth -= 1;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        while(true){
            if(standardT + 1 < 4){
                if(!arr.get(standardT)[(2+toothPointer[standardT])%8].equals(arr.get(standardT+1)[(6+toothPointer[standardT+1])%8])){
                    direList[standardT+1] = standardD == -1? 1 : -1;
                    standardD = direList[standardT+1];
                    standardT += 1;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        return direList;
    }
    public static void main(String[] args) throws IOException {

        /*

        회전하기 전 톱니 생김새를 기준으로 인접한 톱니 부분이 극이 다르면 반대 방향으로 회전
        포인트는 회전하기 전 톱니의 상태를 기준으로

        3 구간을 비교하는 것이 관건
        0번째 톱니 3번째 - 1번째 톱니 6번째
        1번째 톱니 3번째 - 2번째 톱니 6번째
        2번째 톱니 3번째 - 3번째 톱니 6번째

        4개 포인터 {0, 0, 0, 0}

        {{2, 6}, {2, 6}, {2, 6}}

        시계 방향(1), 반시계 방향(-1)

        각 톱니들 맨 상단 포인터 4개
        각 톱니들 맨 상단 포인터 기준으로 좌 우 포인터 8개(+2, +6)


        회전 방향 {0, 0, 0, 0}
        회전하는 톱니 기준 작은 것 존재하는 경우
            while(현재 톱니보다 작은게 존재하는 경우)
                회전하는 톱니(포인터+2) 작은 톱니(작은 톱니 포인터 +6) 다른 경우
                    회전방향[작은 톱니] 회전하는 톱니 반대 방향
                    현재 톱니 = 작은 톱니
        회전하는 톱니 기준 큰 것 존재하는 경우
            <작은 경우랑 똑같이 큰 경우로>
            회전하는 톱니(포인터+2) 작은 톱니(큰 톱니 포인터 +6) 다른 경우
                회전방향[큰 톱니] 회전하는 톱니 반대 방향

        */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = 0;

        for(int i = 0; i<4; i++){
            String[] empty = br.readLine().split("");
            arr.add(empty);
        }
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i<n; i++){
            String[] empty = br.readLine().split(" ");
            int tooth = Integer.parseInt(empty[0])-1;
            int dire = Integer.parseInt(empty[1]);
            int[] direList = {0, 0, 0, 0};
            direList[tooth] = dire;
            direList = changeTooth(tooth, dire, direList);
            for(int j = 0; j<direList.length; j++){
                if(direList[j] > 0){
                    if(toothPointer[j] == 0){
                        toothPointer[j] = 7;
                    } else {
                        toothPointer[j] -= 1;
                    }
                } else if(direList[j] < 0){
                    if(toothPointer[j] == 7){
                        toothPointer[j] = 0;
                    } else {
                        toothPointer[j] += 1;
                    }
                }
            }
        }

        for(int i = 0; i< arr.size(); i++){
            if(arr.get(i)[toothPointer[i]].equals("1")){
                result += Math.pow(2, i);
            }
        }
        System.out.println(result);
    }
}