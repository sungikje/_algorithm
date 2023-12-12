import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        ArrayList<Integer> arr = new ArrayList<>();
        
        Arrays.sort(score);
        
        for(int i = score.length - 1; i >= 0; i--){
            if ((score.length - i) % m == 0) {
                arr.add(score[i]);
            }
        }
        
        for(int a : arr) {
            answer += a * m;
        }
        
        return answer;
    }
}