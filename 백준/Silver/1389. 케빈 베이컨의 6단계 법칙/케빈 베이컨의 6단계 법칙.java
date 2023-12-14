import javafx.collections.FXCollections;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        int min = 2147483647;
        int people = 0;
        int[][] graph;

        for(int i = 0; i<Integer.parseInt(str[0])+1; i++){
            arr.add(new ArrayList<Integer>());
        }
        graph = new int[arr.size()][arr.size()];

        for (int[] row : graph) {
            Arrays.fill(row, min);
        }

        for(int i = 0; i<Integer.parseInt(str[1]); i++){
            String[] str2 = br.readLine().split(" ");
            arr.get(Integer.parseInt(str2[0])).add(Integer.parseInt(str2[1]));
            arr.get(Integer.parseInt(str2[1])).add(Integer.parseInt(str2[0]));
        }

        for(int i = 0; i<arr.size(); i++){
            Collections.sort(arr.get(i));
        }

        for(int i = 1; i < arr.size(); i++){
            LinkedList<Integer> ink = new LinkedList<Integer>();
            boolean[] visited = new boolean[arr.size()+1];
            int[] dist = new int[arr.size()];

            ink.add(i);
            visited[i] = true;

            while(ink.size() > 0){
                int n = ink.poll();
                graph[n][n] = 0;
//                System.out.println("점 : "+n);
                for(int j = 0; j<arr.get(n).size(); j++){
                    if(!visited[arr.get(n).get(j)]){
                        ink.add(arr.get(n).get(j));
                        visited[arr.get(n).get(j)] = true;
                        if(graph[i][arr.get(n).get(j)] > graph[i][n] + 1){
                            graph[i][arr.get(n).get(j)] = graph[i][n] + 1;
                        }
                    }
                }
//                System.out.println(ink);
            }
        }

//        for(int i = 0; i<graph.length; i++){
//            System.out.println(Arrays.toString(graph[i]));
//        }

        for(int i = 1; i<graph.length; i++){
            int sum = 0;
            for(int j = 1; j<graph.length; j++){
                sum += graph[i][j];
            }
            if(sum < min){
                min = sum;
                people = i;
            }
        }
        System.out.println(people);
    }
}