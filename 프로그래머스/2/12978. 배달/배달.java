import java.util.*;

class Solution {
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        
        int[][] graph = new int[N+1][N+1];
        
        for(int[] a : graph){
            Arrays.fill(a, 1000000000);
        }
        
        for(int i = 0; i < graph.length; i++){
            graph[i][i] = 0;
        }
        
        for(int i = 0; i < road.length; i++){
            if (graph[road[i][0]][road[i][1]] > road[i][2]) {
                graph[road[i][0]][road[i][1]] = road[i][2];
                graph[road[i][1]][road[i][0]] = road[i][2];
            }
        }
        
        for(int m = 1; m <= N; m++){
            for(int s = 1; s <= N; s++){
                for(int e = 1; e <= N; e++){
                    int min = graph[s][e] > (graph[s][m] + graph[m][e]) ? graph[s][m] + graph[m][e] : graph[s][e];
                    graph[s][e] = min;
                }
            }
        }
        
        // for(int[] a : graph){
        //     System.out.println(Arrays.toString(a));
        // }
        
        for(int i = 0; i <= N; i++){
            if (graph[1][i] <= K) {
                answer += 1;
            }
        }
        

        return answer;
    }
}