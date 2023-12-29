

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] arr = br.readLine().split(" ");
        ArrayList<String> list = new ArrayList<>();
        String[] _arr = new String[Integer.parseInt(arr[0])-1];
        Arrays.fill(_arr, "");
        String result = "";
        int len = 0;
        int remainder = 0;
        int share = 0;

        for(int i = 0; i < Integer.parseInt(arr[0]); i++){
            String str = br.readLine();
            list.add(str);
            len += str.length();
        }
        share = (Integer.parseInt(arr[1]) - len) / (Integer.parseInt(arr[0]) - 1);
        remainder = (Integer.parseInt(arr[1]) - len) % (Integer.parseInt(arr[0]) - 1);

//        System.out.println("share : " + share);
//        System.out.println("remainder : " + remainder);

        for(int i = 0; i < _arr.length; i++){
            for(int j = 0; j < share; j++) _arr[i] += "_";
        }

        for(int i = 0; i < _arr.length; i++){
            int ch = list.get(i+1).charAt(0);
            if (ch >= 97 && ch <= 122 && remainder > 0) {
                _arr[i] += "_";
                remainder -= 1;
            }
        }

        for(int i = _arr.length-1; i >= 0; i--){
            int ch = list.get(i+1).charAt(0);
            if (ch >= 65 && ch <= 90 && remainder > 0) {
                _arr[i] += "_";
                remainder -= 1;
            }
        }

        for(int i = 0; i < _arr.length; i++){
            result += list.get(i) + _arr[i];
        }
        result += list.get(list.size()-1);

//        System.out.println(Arrays.toString(_arr));
        System.out.println(result);
    }
}