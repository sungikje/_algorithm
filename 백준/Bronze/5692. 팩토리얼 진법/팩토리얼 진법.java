import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Main {
	
	public static void main(String[] args) throws Exception {
		 
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 
		 List<String> arr = new ArrayList<String>();
		 String number = br.readLine();
		 arr.add(number);
		 while(!number.equals("0")) {
			 number = br.readLine();
			 arr.add(number);
		 }
		 returnResult(arr);
	}
	
	public static void returnResult(List<String> arr) {
		
		int result = 0;
		
		for(int j = 0; j<arr.size(); j++) {
			result = 0;
			if(arr.get(j).equals("0")) {
				return;
			}
			else {
				for(int i = 0; i<arr.get(j).length(); i++) {
					result += Character.getNumericValue(arr.get(j).charAt(i)) * factorial(arr.get(j).length()-i); 
				}
			}
			System.out.println(result);
		}
	}
	
	
	public static int factorial(int number) {
		if(number  == 1) {
			return 1;
		}
		else {
			return number * factorial(number-1);
		}
	}
}