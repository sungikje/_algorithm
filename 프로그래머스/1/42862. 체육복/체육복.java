import java.util.*;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int count = 0;
		int i = 0;
		int j = 0;
		int answer = 0;
		
        //이거 때문에 계속 90이였음
        Arrays.sort(lost);
        Arrays.sort(reserve);
        
		for(i = 0; i<reserve.length; i++) {
			for(j = 0; j<lost.length; j++) {
				if(reserve[i] == lost[j]) {
					reserve[i] = -3;
					lost[j] = -10;
				}
			}
		}
		for(i = 0; i<reserve.length; i++) {
			for(j = 0; j<lost.length; j++) {
                if(reserve[i]>0){
                    if((reserve[i]-1 == lost[j]) || ((reserve[i]+1 == lost[j]))){
                        reserve[i] = -1;
					    lost[j] = -10;
                    }
                }
			}
		}
		for(i = 0; i<lost.length; i++) {
			if(lost[i] != -10) {
				count++;
			}
		}
		
		answer = n - count;
		return answer;
    }
}