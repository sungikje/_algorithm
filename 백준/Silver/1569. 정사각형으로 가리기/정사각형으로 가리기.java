import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean checkPoint(ArrayList<Integer> x, ArrayList<Integer> y, int pointX, int pointY, int len) {


        int maxX = pointX + len > pointX ? pointX + len : pointX;
        int minX = pointX + len > pointX ? pointX : pointX + len;
        int maxY = pointY + len > pointY ? pointY + len : pointY;
        int minY = pointY + len > pointY ? pointY : pointY + len;

        for (int i = 0; i < x.size(); i++) {
//            System.out.println(x.get(i)+"   " + y.get(i));
//            System.out.println(pointX +"        " + pointY);
            if ((minX <= x.get(i) && x.get(i) <= maxX) && (minY == y.get(i) || maxY == y.get(i))) {
                continue;
            } else if ((minY <= y.get(i) && y.get(i) <= maxY) && (minX == x.get(i) || maxX == x.get(i))) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> x = new ArrayList<Integer>();
        ArrayList<Integer> y = new ArrayList<Integer>();
        int maxX = -2147483648;
        int maxY = -2147483648;
        int minX = 2147483647;
        int minY = 2147483647;
        int len;

        for(int i = 0; i<n; i++){
            String[] str = br.readLine().split(" ");
            x.add(Integer.parseInt(str[0]));
            y.add(Integer.parseInt(str[1]));
        }

        for(int i = 0; i<x.size(); i++){
            if(maxX < x.get(i)){
                maxX = x.get(i);
            }
            if(maxY < y.get(i)){
                maxY = y.get(i);
            }
            if(minX > x.get(i)){
                minX = x.get(i);
            }
            if(minY > y.get(i)){
                minY = y.get(i);
            }
        }

        len = maxX - minX > maxY - minY ? maxX - minX : maxY - minY;


        if (checkPoint(x, y, minX, minY, len) || checkPoint(x, y, maxX, minY, len) || checkPoint(x, y, minX, maxY, len) || checkPoint(x, y, maxX, maxY, -len)) {
            System.out.println(len);
        } else {
            System.out.println(-1);
        }


        /*
        꼭짓점 4개 (minX, minY), (minX, maxY), (maxX, minY), (maxX, minY)
        각 축의 최대, 최소는 포인트를 기준으로 설정된 것이며 정사각형 형태로 더 큰 경우도 존재(포인트들만 모두 변에 포함된다면)

        4가지 경우 중에 1가지라도 충족하면 사각형 위에 위치할 수 있는 점
            1. minX와 일치하면서 minY~maxY의 범위인 경우
            2. maxX와 일치하면서 inY~maxY의 범위인 경우
            3. minY와 일치하면서 minX~maxX의 범위인 경우
            4. maxY와 일치하면서 minX~maxX의 범위인 경우

         근데 여기서 요점은 점 기준으로 min, max를 따졌고 실질적인 정사각형은 더 클수도 있다는 것(문제 조건 상 작을 수는 없다)
        
         */
    }
}
