import java.util.Arrays;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        int end = 0;
        
        Arrays.sort(targets, (o1, o2) -> o1[1] - o2[1] == 0 ? o1[0] - o2[0] : o1[1] - o2[1]);
        
        for(int[] a : targets) {
            if (a[0] >= end) {
                end = a[1];
                answer += 1;
            }
        }
        return answer;
    }
}