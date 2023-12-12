import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        PriorityQueue<Integer> q = new PriorityQueue<>();
        
        for(int i = 0; i < operations.length; i++){
            String[] str = operations[i].split(" ");
            if (str[0].equals("I")) {
                q.add(Integer.parseInt(str[1]));
            } else if (!str[0].equals("I") && q.size() > 0) {
                if (str[1].contains("-")) {
                    q.remove(Collections.min(q)); 
                } else {
                    q.remove(Collections.max(q));
                }
            }
        }
        
        if (q.size() == 0) {  
            answer[0] = 0;
            answer[1] = 0;
        } else {
            answer[0] = Collections.max(q);
            answer[1] = Collections.min(q);
        }
        
        return answer;
    }
}