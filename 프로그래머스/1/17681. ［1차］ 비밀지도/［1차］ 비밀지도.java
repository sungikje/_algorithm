class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        for(int i = 0; i < n; i++) {
        	String empty1 = changeBinary(Integer.toBinaryString(arr1[i]), n);
        	String empty2 = changeBinary(Integer.toBinaryString(arr2[i]), n);
        	String ans = "";
        	for(int j = 0; j < n; j++) {	
        		if(empty1.charAt(j) == '1' || empty2.charAt(j) == '1') {
        			ans += "#";
        		}
        		else {
        			ans += " ";
        		}
        	}
        	answer[i] = ans;
        }
        
        return answer;
    }
    
    static String changeBinary(String str, int n) {
		
		String pulsZero = "";
		
		if(str.length() == n) {
			return str;
		}
		else {
			for(int i = 0; i<n-str.length(); i++) {
				pulsZero += "0";
			}
			return pulsZero+str;
		}
	}
}