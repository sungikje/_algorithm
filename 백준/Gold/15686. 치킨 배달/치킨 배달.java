import javafx.collections.FXCollections;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static ArrayList<int[]> home = new ArrayList<int[]>();
    static ArrayList<int[]> store = new ArrayList<int[]>();
    static int min = 2147483647;
    static void dfs(ArrayList<Integer> arr, boolean[] visited, int size, int m, int cur){
        if(arr.size() == m){
            int sum = 0;
            for(int j = 0; j<home.size(); j++){
                int dist = 2147483647;
                for(int i = 0; i<arr.size(); i++){
                    if(dist > Math.abs(store.get(arr.get(i))[0] - home.get(j)[0]) + Math.abs(store.get(arr.get(i))[1] - home.get(j)[1])) {
                        dist = Math.abs(store.get(arr.get(i))[0] - home.get(j)[0]) + Math.abs(store.get(arr.get(i))[1] - home.get(j)[1]);
                    }
                }
                sum += dist;
            }

            if(sum < min){
                min = sum;
            }
            return;
        }

        for(int i = cur; i<size; i++){
            if(!visited[i]){
                arr.add(i);
                visited[i] = true;
                dfs(arr, visited, size, m, i+1);
                visited[i] = false;
                arr.remove(arr.size()-1);
            }
        }
    }
    public static void main(String[] args) throws IOException {


        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();

        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);


        for(int i = 0; i<n; i++){
            arr.add(new ArrayList<Integer>());
        }

        for(int i = 0; i<n; i++){
            String[] str2 = br.readLine().split(" ");
            for(int j = 0; j<str2.length; j++){
                arr.get(i).add(Integer.parseInt(str2[j]));
            }
        }

        for(int i = 0; i<arr.size(); i++){
            for(int j = 0; j<arr.size(); j++){
                if(arr.get(i).get(j) == 1){
                    home.add(new int[] {i+1,j+1});
                } else if(arr.get(i).get(j) == 2){
                    store.add(new int[] {i+1,j+1});
                }
            }
        }
        for(int i = 0; i<store.size(); i++){
            ArrayList<Integer> empty = new ArrayList<Integer>();
            boolean[] visited = new boolean[store.size()];
            visited[i] = true;
            empty.add(i);
            dfs(empty, visited, store.size(), m, i+1);
            visited[i] = false;
        }
        System.out.println(min);
    }
}