class Solution {
    public String solution(int[] food) {
        String answer = "";
        
        
        for(int i = 1; i < food.length; i++){
            food[i] /= 2;;
        }
        
        for(int i = 1; i < food.length; i++){
            for(int j = 0; j < food[i]; j++){
                answer += i;
            }
        }
        answer += "0";
        for(int i = food.length-1; i > 0; i--){
            for(int j = 0; j < food[i]; j++){
                answer += i;
            }
        }
            
        return answer;
    }
}