import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;


public class Main {

    static ArrayList<String[]> arr = new ArrayList<String[]>();
    static boolean[][] visited;
    static int count = 0;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int sumW = 0;
        int sumB = 0;


        for(int i = 0; i<m; i++){
            String[] str = br.readLine().split("");
            arr.add(str);
        }

        visited = new boolean[m][n];

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                count = 0;
                LinkedList<int[]> empty = new LinkedList<int[]>();
                if(!visited[i][j] && arr.get(i)[j].equals("W")){
                    empty.add(new int[]{i, j});
                    count += 1;
                    visited[i][j] = true;
                    while(empty.size() > 0){
                        int[] arrE = empty.poll();
                        if(((0<= (arrE[0]-1) && (arrE[0]-1)<m) && (0 <= arrE[1] && arrE[1] < n)) && !visited[arrE[0]-1][arrE[1]]){
                            if(arr.get(arrE[0]-1)[arrE[1]].equals("W")){
                                empty.add(new int[]{arrE[0]-1, arrE[1]});
                                count += 1;
                                visited[arrE[0]-1][arrE[1]] = true;
                            }
                        }
                        if(((0<= arrE[0] && arrE[0]<m) && (0 <= arrE[1]-1 && arrE[1]-1< n)) && !visited[arrE[0]][arrE[1]-1] ){
                            if(arr.get(arrE[0])[arrE[1]-1].equals("W")){
                                empty.add(new int[]{arrE[0], arrE[1]-1});
                                count += 1;
                                visited[arrE[0]][arrE[1]-1] = true;
                            }
                        }
                        if(((0<= arrE[0]+1 && arrE[0]+1<m) && (0 <= arrE[1] && arrE[1]< n)) && !visited[ arrE[0]+1][arrE[1]]){
                            if(arr.get(arrE[0]+1)[arrE[1]].equals("W")){
                                empty.add(new int[]{arrE[0]+1, arrE[1]});
                                count += 1;
                                visited[arrE[0]+1][arrE[1]] = true;
                            }
                        }
                        if(((0<= arrE[0] && arrE[0]<m) && (0 <= arrE[1]+1 && arrE[1]+1< n)) && !visited[arrE[0]][arrE[1]+1]){
                            if(arr.get(arrE[0])[arrE[1]+1].equals("W")){
                                empty.add(new int[]{arrE[0], arrE[1]+1});
                                count += 1;
                                visited[arrE[0]][arrE[1]+1] = true;
                            }
                        }
                    }
                }
                sumW += count*count;
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                count = 0;
                LinkedList<int[]> empty = new LinkedList<int[]>();
                if(!visited[i][j] && arr.get(i)[j].equals("B")){
                    empty.add(new int[]{i, j});
                    count += 1;
                    visited[i][j] = true;
                    while(empty.size() > 0){
                        int[] arrE = empty.poll();
                        if(((0<= (arrE[0]-1) && (arrE[0]-1)<m) && (0 <= arrE[1] && arrE[1]< n)) && !visited[arrE[0]-1][arrE[1]]){
                            if(arr.get(arrE[0]-1)[arrE[1]].equals("B")){
                                empty.add(new int[]{arrE[0]-1, arrE[1]});
                                count += 1;
                                visited[arrE[0]-1][arrE[1]] = true;
                            }
                        }
                        if(((0<= arrE[0] && arrE[0]<m) && (0 <= arrE[1]-1 && arrE[1]-1< n)) && !visited[arrE[0]][arrE[1]-1] ){
                            if(arr.get(arrE[0])[arrE[1]-1].equals("B")){
                                empty.add(new int[]{arrE[0], arrE[1]-1});
                                count += 1;
                                visited[arrE[0]][arrE[1]-1] = true;
                            }
                        }
                        if(((0 <= arrE[0]+1 && arrE[0]+1<m) && (0 <= arrE[1] && arrE[1]< n)) && !visited[ arrE[0]+1][arrE[1]]){
                            if(arr.get(arrE[0]+1)[arrE[1]].equals("B")){
                                empty.add(new int[]{arrE[0]+1, arrE[1]});
                                count += 1;
                                visited[arrE[0]+1][arrE[1]] = true;
                            }
                        }
                        if(((0<= arrE[0] && arrE[0]<m) && (0 <= arrE[1]+1 && arrE[1]+1< n)) && !visited[arrE[0]][arrE[1]+1]){
                            if(arr.get(arrE[0])[arrE[1]+1].equals("B")){
                                empty.add(new int[]{arrE[0], arrE[1]+1});
                                count += 1;
                                visited[arrE[0]][arrE[1]+1] = true;
                            }
                        }
                    }
                }
                sumB += count*count;
            }
        }
        System.out.println(sumW+" "+sumB);
    }
}