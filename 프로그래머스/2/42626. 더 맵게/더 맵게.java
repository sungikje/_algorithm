import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        Arrays.sort(scoville);
        
        PriorityQueue<Integer> arr = new PriorityQueue<>();
        for(int i : scoville) arr.add(i);
        
        while(arr.peek() < K) {
            if (arr.size() < 2) {
                answer = -1;
                break;
            }
            int a = arr.poll();
            int b = arr.poll();
            arr.add(a+(b*2));
            answer += 1;
        }
        
        return answer;
    }
}