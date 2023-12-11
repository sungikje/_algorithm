import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = -1;

        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        
        temp.add(N);
        dp.add(temp);
        
        temp = new ArrayList<>();
        temp.add(N+N);
        temp.add(N-N);
        temp.add(N*N);
        temp.add(N/N);
        temp.add(N*11);
        dp.add(temp);
        
        if (N == number) {
            answer = 1;
        } else if (dp.get(dp.size()-1).indexOf(number) != -1) {
            answer = 2;
        } else {
            for(int i = 2; i < 9; i++){
                temp = new ArrayList<>();
                String str = "";
                
                for(int j = 0; j < i; j++){
                    for(int k : dp.get(j)){
                        for(int z : dp.get(i-j-1)){
                            temp.add(z+k);
                            temp.add(z-k);
                            temp.add(z*k);
                            if (z != 0 && k != 0) {
                                temp.add(z/k);
                            }
                        }
                    }
                }
                Set<Integer> set = new HashSet<>(temp);
                temp = new ArrayList<>(set);
                
                for(int j = 0; j <= i; j++){
                    str += Integer.toString(N);
                }
                temp.add(Integer.parseInt(str));
                dp.add(temp);
                
                if (dp.get(dp.size()-1).indexOf(number) != -1) {
                    System.out.println(dp.get(dp.size()-1).indexOf(number));
                    answer = i + 1;
                    return answer;
                }
                    
            }
        }
        return answer;
    }
}