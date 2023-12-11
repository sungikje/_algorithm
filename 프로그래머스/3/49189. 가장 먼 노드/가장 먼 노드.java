import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int[] dist = new int[n+1];
        boolean[] visited = new boolean[n+1];
        Arrays.fill(dist, 0);
        
        for(int i = 0; i <= n; i++){
            graph.add(new ArrayList<Integer>());
        }
        
        
        for(int i = 0; i < edge.length; i++){
            graph.get(edge[i][0]).add(edge[i][1]);
            graph.get(edge[i][1]).add(edge[i][0]);
        }
        
        for(ArrayList<Integer> a : graph){
            Collections.sort(a);
        }
        
        LinkedList<Integer> q = new LinkedList<>();
        
        visited[1] = true;
        for(int a : graph.get(1)){
            q.add(a);
            visited[a] = true;
            dist[a] = 1;
        }
        
        while(q.size() > 0) {
            int node = q.pop();
            int distance = dist[node];
            for(int a : graph.get(node)){
                if (!visited[a]) {
                    q.add(a);
                    dist[a] = distance + 1;
                    visited[a] = true;
                }
            }
        }
        
        int max = 0;
        
        for(int i = 0; i < dist.length; i++){
            if (dist[i] > max) {
                max = dist[i];
            }
        }
        
        for(int i = 0; i < dist.length; i++){
            if (dist[i] == max) {
                answer += 1;
            }
        }
        
        
        return answer;
    }
}