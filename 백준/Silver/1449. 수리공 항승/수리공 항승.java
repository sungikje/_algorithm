import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Iterator iter;

        String[] str1 = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");

        TreeSet<Integer> set = new TreeSet<Integer>();
        ArrayList<Integer> arr = new ArrayList<Integer>();

        int len = Integer.parseInt(str1[1]);
        int tape = 0;

        for(int i = 0; i<str2.length; i++){
            set.add(Integer.parseInt(str2[i]));
        }

        iter = set.iterator();

        while(iter.hasNext()){
            arr.add((Integer) iter.next());
        }

//        System.out.println(arr);

        for(int i = 0; i<arr.size()-1; i++){
            if(arr.get(i+1) - arr.get(i) + 1 <= len){
                len -= (arr.get(i+1) - arr.get(i));
            } else {
//                System.out.println("tape 추가 : " + i);
                len = Integer.parseInt(str1[1]);
                tape += 1;
            }
        }
        System.out.println(tape+1);

    }
}