import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public ArrayList<String> solution(String[] players, String[] callings) {
        ArrayList<String> answer = new ArrayList<String>();
        
        Map<String, Integer> keyPlayer = new HashMap<String, Integer>();
        Map<Integer, String> keyRank = new HashMap<Integer, String>();
        
        for(int i = 0; i < players.length; i++){
            keyPlayer.put(players[i], i);
            keyRank.put(i, players[i]);
        }
        
        for(int i = 0; i < callings.length; i++){
            int lank = keyPlayer.get(callings[i]);
            String before = keyRank.get(lank-1);
            int beforeLank = keyPlayer.get(before);
            
            keyPlayer.put(callings[i], beforeLank);
            keyRank.put(beforeLank, callings[i]);
            
            keyPlayer.put(before, lank);
            keyRank.put(lank, before);
            
        }
        
        for(int i = 0; i<keyRank.size(); i++){
            answer.add(keyRank.get(i));
        }
        
        return answer;
    }
}