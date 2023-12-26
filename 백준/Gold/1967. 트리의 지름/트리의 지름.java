import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;


public class Main {

    static ArrayList<Node>[] graph;
    static int[] dist;
    static boolean[] visited;
    static class Node {
        int n;
        int cost;

        public Node(int n, int cost){
            this.n = n;
            this.cost = cost;
        }

        @Override
        public String toString(){
            return "(" + this.n + " " + this.cost + ")";
        }
    }

    static void dijkstra(int start){
        PriorityQueue<Node> q = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
        q.add(new Node(start, 0));
        dist[start] = 0;

        while (!q.isEmpty()){
            Node now = q.poll();

            if (!visited[now.n]) {
                visited[now.n] = true;
            }

            for(Node next : graph[now.n]) {
                if (!visited[next.n] && dist[next.n] > now.cost + next.cost) {
                    dist[next.n] = now.cost + next.cost;
                    q.add(new Node(next.n, dist[next.n]));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int index = 0;
        int max;

        graph = new ArrayList[n + 1];

        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < n - 1; i++){
            String[] temp = br.readLine().split(" ");
            graph[Integer.parseInt(temp[0])].add(new Node(Integer.parseInt(temp[1]), Integer.parseInt(temp[2])));
            graph[Integer.parseInt(temp[1])].add(new Node(Integer.parseInt(temp[0]), Integer.parseInt(temp[2])));
        }
        
        dist = new int[n + 1];
        for(int k = 0; k < dist.length; k++){
            dist[k] = Integer.MAX_VALUE;
        }

        visited = new boolean[n + 1];
        dijkstra(1);

        max = 0;
        for(int i = 1; i < dist.length; i++){
            if (dist[i] >= max) {
                index = i;
                max = dist[i];
            }
        }

        dist = new int[n + 1];
        for(int k = 0; k < dist.length; k++){
            dist[k] = Integer.MAX_VALUE;
        }

        visited = new boolean[n + 1];
        dijkstra(index);

        max = 0;
        for(int i = 1; i < dist.length; i++){
            if (dist[i] >= max) {
                max = dist[i];
            }
        }
        
        System.out.println(max);
    }
}