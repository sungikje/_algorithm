import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) throws IOException {
        /*
        n 입력 받음

        for n
            작업 입력 받음
            배열 길이 입력 받고
            문자열 입력 받음 -> 문자열로 입력 받고 앞뒤 잘라서 , 기준 분리

            for 작업 길이
                r인 경우 reverse
                d인 경우
                    제거 가능한 인덱스면 앞에 제거
                    그 외 error 출력
                    문자열 작업 후에 배열 출력
        */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stringBuilder;
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String work = br.readLine();
            int len = Integer.parseInt(br.readLine());
            String value = br.readLine();
            value = value.substring(1, value.length()-1);
//            Deque<String> arr = new ArrayDeque<>(Arrays.asList(value.split(",")));
            Deque<String> arr = new ArrayDeque<>();
            for(String j : value.split(",")){
                arr.add(j);
            }
            int start = 0;



            boolean check = false;
            for(int j = 0; j<work.length(); j++){
                if(work.charAt(j) == 'R'){
                    start += 1;
                } else {
                    if(arr.size() > 0){
                        if(start == 0 || start % 2 == 0){
                            arr.pollFirst();
                        } else {
                            arr.pollLast();
                        }
                    } else {
                        check = true;
                        break;
                    }
                }
            }

            if(check){
                System.out.println("error");
            } else {
                if(arr.size() > 0){
                    if(start == 0 || start % 2 == 0){
                        stringBuilder = new StringBuilder();
                        Iterator<String> iterator = arr.iterator();
                        stringBuilder.append("[");
                        while (iterator.hasNext()) {
                            stringBuilder.append(iterator.next()).append(",");
                        }
                        stringBuilder.deleteCharAt(stringBuilder.length()-1);
                        stringBuilder.append("]");
                        System.out.println(stringBuilder);

                    } else {

                        stringBuilder = new StringBuilder();
                        Iterator<String> reverseIterator = arr.descendingIterator();
                        stringBuilder.append("[");
                        while (reverseIterator.hasNext()) {
                            stringBuilder.append(reverseIterator.next()).append(",");
                        }
                        stringBuilder.deleteCharAt(stringBuilder.length()-1);
                        stringBuilder.append("]");
                        System.out.println(stringBuilder);

                    }
                } else {
                    if(len > 0){
                        System.out.println("[]");
                    } else {
                        System.out.println("error");
                    }
                }
            }
        }
    }
}