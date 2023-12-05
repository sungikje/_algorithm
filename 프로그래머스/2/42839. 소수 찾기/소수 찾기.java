import java.util.*;
class Solution {
    
    static List<Integer> finalResult = new ArrayList<>();	
    
    public int solution(String numbers) {
        int answer = 0;
        String[] numbersEmpty = numbers.split("");
        int[] arr = new int[numbersEmpty.length];
        int[] result = new int[arr.length];
		boolean[] visited = new boolean[arr.length];
        
        
        for(int i = 0; i<numbersEmpty.length; i++){
            arr[i] = Integer.parseInt(numbersEmpty[i]);
        }
        
        for(int i = 0; i<arr.length; i++) {
			permutation(arr, result, visited, 0, i+1);
		}
        answer = finalResult.size();
        
        return answer;
    }
    static void permutation(int[] arr, int[] result, boolean[] visited, int depth, int r) {
		
		if(depth == r) {
			String checkResult = "";
			for(int i =0; i<r; i++) {
				checkResult += Integer.toString(result[i]);
			}
			if(prime(Integer.parseInt(checkResult)) && !(finalResult.contains(Integer.parseInt(checkResult)))) {
				
				finalResult.add(Integer.parseInt(checkResult));
				return;
			}
		}
		for(int i =0; i<arr.length; i++) {
			if(!visited[i]) {
				visited[i] = true;
				result[depth] = arr[i];
				permutation(arr, result, visited, depth+1,r);
				visited[i] = false;
			}
		}
	}
	
	
	static boolean prime(int num) {
		
		if(num >= 2) {
			for(int i = 2; i< num; i++) {
				if(num % i == 0) {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
}