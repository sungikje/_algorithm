import java.util.*;
class Solution {
    public List<Integer> solution(int[] answers) {
        List<Integer> answer = new ArrayList<>();
        
        int [] answerOne = { 1, 2, 3, 4, 5};
        int [] answerTwo = {2, 1, 2, 3, 2, 4, 2, 5};
        int [] answerThree = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int personOne = 0;
        int personTwo = 0;
        int personThree = 0;
        int [] result = {0, 0, 0};
        
        
        for(int i =0; i<answers.length; i++){
            if(answerOne[personOne] == answers[i]){
                result[0] ++;
            }
            if(answerTwo[personTwo] == answers[i]){
                result[1] ++;
            }
            if(answerThree[personThree] == answers[i]){
                result[2] ++;
            }
            
            personOne ++;
            personTwo ++;
            personThree ++;
            
            if(personOne >= answerOne.length){
                personOne = 0;
            }
            if(personTwo >= answerTwo.length){
                personTwo = 0;
            }
            if(personThree >= answerThree.length){
                personThree = 0;
            }
            
        }
        
        for(int i =0; i<result.length; i++){
            if(result[i] == Arrays.stream(result).max().getAsInt()){
                answer.add(i+1);
            }
        }
        
        return answer;
    }
}