import java.util.*;
class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<Integer>();
        List<Integer> time = new ArrayList<Integer>();
        Integer num = 0;
        
        for(int i = 0; i < progresses.length; i++){
            num = (int)Math.ceil((100-progresses[i]) / (double)speeds[i]);
            
            if(time.size() == 0){
                time.add(num);
            }
            
            else{
                
                if(time.get(0) < num){
                    answer.add(time.size());
                    time = new ArrayList<Integer>();
                    time.add(num);
                }
                else{
                    time.add(num);
                }
            }
        }
        if(time.size() != 0){
            answer.add(time.size());
        }
        return answer;
    }
}