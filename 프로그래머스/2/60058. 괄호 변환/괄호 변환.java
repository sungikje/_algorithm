import java.util.*;

class Solution {
    static String answer = "";
    public String solution(String p) {
        answer = divP(p);
        return answer;
    }
    
    static boolean checkTrue(String p) {
        LinkedList<Character> list = new LinkedList<>();
        for(int i = 0; i < p.length(); i++){
            if (p.charAt(i) == '(') {
                list.add('(');
            } else {
                if (list.size() == 0) {
                    return false;
                } else {
                    list.remove(list.size()-1);
                }
            }
        }
        return true;
    }
    
    static String divP(String p) {
        if (p.equals("")) {
            return "";
        }
            
        int left = 0;
        int right = 0;
        int point = 0;
        for(int i = 0; i < p.length(); i++){
            if (p.charAt(i) == '(') {
                left += 1;
            } else {
                right += 1;
            }
            if (left != 0 && left == right) {
                point = i;
                break;
            }
        }
        String u = p.substring(0, point+1);
        String v = p.substring(point+1, p.length());
        
        if (checkTrue(u)) {
            return u + divP(v);
        } else {
            String str = "(";
            String revU = "";
            str += divP(v);
            str += ")";
            revU = u.substring(1, u.length()-1);
            
            for (int i = 0; i < revU.length(); i++){
                if (revU.charAt(i) == ')') {
                    str += "(";
                } else {
                    str += ")";
                }
            }
            return str;
        }
    } 
}