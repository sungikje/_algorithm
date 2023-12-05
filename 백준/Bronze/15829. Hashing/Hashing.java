import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	
	public static void main(String[] args) throws IOException  {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int n = Integer.parseInt(br.readLine());
		String str = br.readLine();
		long r = 1;
		long result = 0;
		
		for(int i = 0; i<n; i++) {
			result += (((int)str.charAt(i)-96)%1234567891) * r;
			r = (r*31)%1234567891;
		}
		System.out.println(result%1234567891);
	}
}