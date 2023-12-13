import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        HashSet<String> set = new HashSet<>(Arrays.asList(report));
        ArrayList<String> list = new ArrayList<>(set);
        HashMap<String, Integer> complain = new HashMap<>();
        ArrayList<String> result = new ArrayList<>();
        
        for(int i = 0; i < list.size(); i++){
            String[] str = list.get(i).split(" ");
            if (!complain.containsKey(str[1])) {
                complain.put(str[1], 1);
            } else {
                complain.put(str[1], complain.get(str[1]) + 1);
            }
        }
        
        for(int i = 0; i < id_list.length; i++){
            result.add(id_list[i]);
        }
        
        for(int i = 0; i < list.size(); i++){
            String[] str = list.get(i).split(" ");
            if (complain.get(str[1]) >= k) {
                answer[result.indexOf(str[0])] += 1;
            }
        }
        
        return answer;
    }
}