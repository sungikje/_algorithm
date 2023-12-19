import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;


public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        ArrayList<String[]> arr = new ArrayList<String[]>();
        ArrayList<String[]> result = new ArrayList<String[]>();
        LinkedList<int[]> line;
        int startRow = 0;
        int endRow = Integer.parseInt(str[0])-1;
        int startColumn = 0;
        int endColumn = Integer.parseInt(str[1])-1;

        int min = Integer.parseInt(str[0]) > Integer.parseInt(str[1])? Integer.parseInt(str[1]) : Integer.parseInt(str[0]);

        for(int i = 0; i<Integer.parseInt(str[0]); i++){
            arr.add(br.readLine().split(" "));
            result.add(new String[Integer.parseInt(str[1])]);
        }

        for(int i = 0; i<min/2; i++){
            int x = i;
            int y = i;

            line = new LinkedList<int[]>();

            while(true){
                line.add(new int[]{x, y});
                if(x == startRow+1 && y == startColumn){
                    break;
                }
                if(x == i && y<endColumn){
                    y += 1;
                } else if (x < endRow && y == endColumn){
                    x += 1;
                } else if(x == endRow && y > startColumn){
                    y -= 1;
                } else if(x > startRow && y == startColumn){
                    x -= 1;
                }
            }

            for(int j = 0; j<line.size(); j++){
                int rotIndex = Integer.parseInt(str[2]) % line.size();
                if(j - rotIndex < 0){
                    rotIndex = line.size() - (rotIndex - j);
                    result.get(line.get(rotIndex)[0])[line.get(rotIndex)[1]] = arr.get(line.get(j)[0])[line.get(j)[1]];
                } else {
                    result.get(line.get(j-rotIndex)[0])[line.get(j-rotIndex)[1]] = arr.get(line.get(j)[0])[line.get(j)[1]];
                }
            }

            startRow += 1;
            endRow -= 1;
            startColumn += 1;
            endColumn -= 1;
        }

        for(String[] i : result){
            for(String j : i){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}