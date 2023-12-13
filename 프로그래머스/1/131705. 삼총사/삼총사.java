class Solution {
    static int answer = 0;
    static void comb(int[] number, boolean[] visited, int start, int depth, int r) {
        if (depth == r) {
            int sum = 0;
            for(int i = 0; i < visited.length; i++) {
                if (visited[i]) { sum += number[i]; }
            }
            if (sum == 0) {
                answer += 1;
            }
            return;
        }
        
        for(int i = start; i < number.length; i++){
            if (!visited[i]) {
                visited[i] = true;
                comb(number, visited, i+1, depth + 1, r);
                visited[i] = false;
            }
        }
        
    }
    public int solution(int[] number) {
        boolean[] visited = new boolean[number.length];
        
        comb(number, visited, 0, 0, 3);
        
        return answer;
    }
}