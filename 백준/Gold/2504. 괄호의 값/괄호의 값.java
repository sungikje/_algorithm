
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;


public class Main {
    public static void main(String[] args) throws IOException {

        /*
        2504번

        1. 올바른 괄호열의 확인
            올바른 괄호열이 라는 것은 (), [] 처럼 완벽한 형태의 괄호이거나 올바른 괄호들을 포함하고 있는 경우
                이는 스택을 이용했을 때 (, [ 인 경우는 적재, ), ]인 경우는 스택 최상위에서 반대 짝을 없애는 행위를 통해 없앨 수 있다
            스택을 이용해 오른쪽으로 열린 경우만 적재, 그 외는 스택 상태로 판단
            연산이 모두 끝났을 때 스택 내용이 존재하는 경우 올바른 괄호열 X
        2. 괄호열의 숫자를 어느 지점부터 계산하는지
            우리도 알다시피 () or [] 처럼 직접 마주보고 있는 지점부터 계산하는 것이 우선이며
            분배 법칙을 이용해 계산할 수 있다
                분배 법칙을 이용할 때 이전 형태와 현재 형태가 (), [] 형태로 합쳐지는 경우에만 결과값에 추가해주면 된다
         */

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        Stack<Character> stack = new Stack<Character>();
        int result = 0;
        int value = 1;


        for(int i = 0; i<str.length(); i++){
//            System.out.println(i);
            if (str.charAt(i) == '(') {
//                System.out.println("A");
                stack.add(str.charAt(i));
                value *= 2;
            } else if (str.charAt(i) == '[') {
//                System.out.println("B");
                stack.add(str.charAt(i));
                value *= 3;
            } else if(str.charAt(i) == ')') {
//                System.out.println("C");
                if(stack.empty()){
                    System.out.println(0);
                    return;
                } else {
                    if (str.charAt(i-1) == '(') {
                        result += value;
                    } else {
                        if (stack.peek() != '('){
                            System.out.println(0);
                            return;
                        }
                    }
                }
                value /= 2;
                stack.pop();
            } else if(str.charAt(i) == ']') {
//                System.out.println("D");
                if(stack.empty()){
                    System.out.println(0);
                    return;
                } else {
                    if (str.charAt(i-1) == '[') {
                        result += value;
                    } else {
                        if (stack.peek() != '['){
                            System.out.println(0);
                            return;
                        }
                    }
                }
                value /= 3;
                stack.pop();
            }
//            System.out.println("stack : " + stack);
//            System.out.println("result : " + result);
//            System.out.println("value : " + value);
//            System.out.println();System.out.println();System.out.println();
        }
        if(stack.size() > 0){
            System.out.println(0);
            return;
        }
        System.out.println(result);

        
        
        
    }
}