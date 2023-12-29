import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static LinkedList<Integer> width;
    static LinkedList<Integer> height;

    static int x;
    static int y;

    static String[] init;

    static int[][] map;
    static void moveDice(String type) {
//        System.out.println("======================================");
//        System.out.println("type : " + type);
        switch(type){
            case "1":
                if (0 <= x && x < Integer.parseInt(init[0]) && 0 <= y+1 && y+1 < Integer.parseInt(init[1])) {

                    width.addFirst(height.pollLast());
                    height.addLast(width.pollLast());

                    y += 1;
                    height.set(1, width.get(1));
                    if (map[x][y] == 0) {
                        map[x][y] = height.get(3);
                    } else {
                        height.set(3, map[x][y]);
                        map[x][y] = 0;
                    }
                    System.out.println(height.get(1));
                }
                break;
            case "2":
                if (0 <= x && x < Integer.parseInt(init[0]) && 0 <= y-1 && y-1 < Integer.parseInt(init[1])) {

                    width.addLast(height.pollLast());
                    height.addLast(width.pollFirst());

                    y -= 1;
                    height.set(1, width.get(1));
                    if (map[x][y] == 0) {
                        map[x][y] = height.get(3);
                    } else {
                        height.set(3, map[x][y]);
                        map[x][y] = 0;
                    }
                    System.out.println(height.get(1));
                }
                break;
            case "3":
                if (0 <= x-1 && x-1 < Integer.parseInt(init[0]) && 0 <= y && y < Integer.parseInt(init[1])) {
                    height.add(height.poll());
                    x -= 1;

                    if (map[x][y] == 0) {
                        map[x][y] = height.get(3);
                    } else {
                        height.set(3, map[x][y]);
                        map[x][y] = 0;
                    }
                    width.set(1, height.get(1));
                    System.out.println(height.get(1));
                }
                break;
            case "4":
                if (0 <= x+1 && x+1 < Integer.parseInt(init[0]) && 0 <= y && y < Integer.parseInt(init[1])) {
                    height.addFirst(height.pollLast());
                    x += 1;

                    if (map[x][y] == 0) {
                        map[x][y] = height.get(3);
                    } else {
                        height.set(3, map[x][y]);
                        map[x][y] = 0;
                    }
                    width.set(1, height.get(1));
                    System.out.println(height.get(1));
                }
                break;
        }
//        System.out.println(height);
//        System.out.println(width);
//        System.out.println("======================================");
    }
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        width = new LinkedList<>(Arrays.asList(0, 0, 0));
        height = new LinkedList<>(Arrays.asList(0, 0, 0, 0));
        init = br.readLine().split(" ");
        String[] move;
        x = Integer.parseInt(init[2]);
        y = Integer.parseInt(init[3]);

        map = new int[Integer.parseInt(init[0])][Integer.parseInt(init[1])];

        for(int i = 0; i < Integer.parseInt(init[0]); i++){
            String[] temp = br.readLine().split(" ");
            for(int j = 0; j < temp.length; j++){
                map[i][j] = Integer.parseInt(temp[j]);
            }
        }

        move = br.readLine().split(" ");

        if (map[x][y] == 0) {
            map[x][y] = height.get(3);
        } else {
            height.set(3, map[x][y]);
        }

        for(int i = 0; i < move.length; i++){
            moveDice(move[i]);
        }
    }
}