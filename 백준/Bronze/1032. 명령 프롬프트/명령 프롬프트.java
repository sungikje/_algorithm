

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;


public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> arr = new ArrayList<String>();
        String result = "";
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            arr.add(br.readLine());
        }

        for (int i = 0; i < arr.get(0).length(); i++) {
            ArrayList<Character> temp = new ArrayList<Character>();
            for (int j = 0; j<arr.size(); j++){
                temp.add(arr.get(j).charAt(i));
            }
            int len = temp.size();
            Set<Character> set = new HashSet<>(temp);
            if (set.size() != 1)  {
                result += "?";
            } else {
                result += temp.get(0);
            }
        }
        System.out.println(result);
    }
}