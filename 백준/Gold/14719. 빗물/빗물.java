

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Main {
    public static void main(String[] args) throws IOException {

        /*
        결국 감소 <=> 증가 변화하는 구간에서 빗물이 고임
            이 때 감소 => 증가, 증가 => 감소 변화 중에 결론적으로 더 작은 부분으로 고임

        감소, 증가, 증가 감소

        A 감소 ==== 증가 ==== 다시 B 감소하는 시점
        A랑 B 중에 더 작은 사이즈 만큼



        감소인지 증가인지 나타내는 변수

        h, w 입력 받음

        w 길이만큼 배열 크기


        for w 길이
            전 보다 작으면서 감소가 아닌 경우
                감소로 바꾸고 인덱스 기록
            전보다 큰 경우
                증가로 교체

         for 기록한 인덱스
            첫번째 or 두번째 더 작은 값
            첫번째 ~ 두번째
                더 작은 값 - 해당 인덱스의 값 > 0 경우만 빗물로 체크
         
         증가 => 감소, 감소 => 증감 하는 포인트를 다 찾아서
         해당 포인트들 중간 값들 작은거 삭제하면서 마지막에 남은 포인트들 기준으로 진행
         */

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean dire = false;    // true는 증가
        int result = 0;
        String[] str = br.readLine().split(" ");

        String[] temp = br.readLine().split(" ");
        ArrayList<Integer> arr = new ArrayList<Integer>();
        ArrayList<Integer> point = new ArrayList<Integer>();

        for(int i = 0; i<temp.length; i++){
            arr.add(Integer.parseInt(temp[i]));
        }

        for(int i = 1; i<arr.size()-1; i++){
            int left = 0;
            int right = 0;
            for(int j = 0; j<i; j++){
                if(arr.get(j) > left){
                    left = arr.get(j);
                }
            }
            for(int j = i; j<arr.size(); j++){
                if(arr.get(j) > right) {
                    right = arr.get(j);
                }
            }
            int num = right > left? left : right;
//            System.out.println("left : " + left);
//            System.out.println("right : " + right);
//            System.out.println("num : " + num);
//            System.out.println();System.out.println();System.out.println();
            result += num - arr.get(i) > 0? num - arr.get(i) : 0;
        }
        System.out.println(result);
    }
}