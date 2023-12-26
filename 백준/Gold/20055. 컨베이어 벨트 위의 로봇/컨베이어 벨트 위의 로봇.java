import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] armor;
    static boolean[] robot;
    static boolean checkArmor(int[] ist, int n){
        int count = 0;

        for(int i = 0; i < ist.length; i++){
            if (ist[i] == 0) {
                count += 1;
                if (count >= n) {
                    return true;
                }
            }
        }
        return false;
    }

    static void moveArmor(){
        int temp = armor[armor.length - 1];
        for(int i = armor.length - 2; i >= 0; i--){
            armor[i + 1] = armor[i];
        }
        armor[0] = temp;
    }

    static void moveRobot(){
        boolean temp = robot[robot.length - 1];
        for(int i = robot.length - 2; i >= 0; i--){
            robot[i + 1] = robot[i];
        }
        robot[0] = temp;
    }

    public static void main(String[] args) throws Exception {

        int result = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");

        armor = new int[Integer.parseInt(str[0])*2];
        robot = new boolean[Integer.parseInt(str[0])];

        for(int i = 0; i < str2.length; i++){
            armor[i] = Integer.parseInt(str2[i]);
        }

        while(true){
            result += 1;

            moveArmor();
            moveRobot();
            robot[robot.length - 1] = false;

            for(int i = Integer.parseInt(str[0]) - 2; i >= 0; i--){
                if (robot[i] & !robot[i+1] & armor[i+1] > 0) {
                    robot[i+1] = true;
                    robot[i] = false;
                    armor[i+1] = armor[i+1] - 1;
                }
            }
            robot[robot.length - 1] = false;

            if (armor[0] > 0 && !robot[0]) {
                robot[0] = true;
                armor[0] = armor[0] - 1;
            }

            if (checkArmor(armor, Integer.parseInt(str[1]))) {
                System.out.println(result);
                return;
            }
        }
    }
}