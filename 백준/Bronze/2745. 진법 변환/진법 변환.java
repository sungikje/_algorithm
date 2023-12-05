import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	
	public static void main(String[] args) throws IOException  {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine()," ");
		int result = 0;
		
		String front = st.nextToken();
		int back = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i<front.length(); i++) {
			
			if((int)front.charAt(i) >= 65) {
				result += ((int)front.charAt(i)-55) * (int)Math.pow(back, front.length()-i-1);
			}
			else {
				result += Character.getNumericValue(front.charAt(i)) * (int)Math.pow(back, front.length()-i-1);
			}
		}
		System.out.println(result);
	}
}