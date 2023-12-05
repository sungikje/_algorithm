class Solution {
    static int answer = 0;
    public int solution(int[] numbers, int target) {
        
        findTarget(numbers, target, 0, 0);
        return answer;
    }
    
    public void findTarget(int[] numbers, int target, int sum, int index){
        if(index == numbers.length){
            if(sum == target){
                answer ++;
            }
        }
        else{
            findTarget(numbers, target, sum+numbers[index], index+1);
            findTarget(numbers, target, sum-numbers[index], index+1);
        }
    }
}