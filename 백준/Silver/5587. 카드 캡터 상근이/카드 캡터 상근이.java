import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> sang = new ArrayList<>();
        List<Integer> geun = new ArrayList<>();
        List<Integer> card = new ArrayList<>();
        boolean seq = true;

        int num = Integer.parseInt(br.readLine());

        for(int i = 0; i<num; i++){
            sang.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(sang);
        for(int i = 1; i<=2*num; i++){
            if(!sang.contains(i)){
                geun.add(i);
            }
        }

        while (sang.size() != 0 && geun.size() != 0) {
            if (card.size() == 0) {
                if(seq) {
                    card.add(sang.get(0));
                    sang.remove(0);

                } else {
                    card.add(geun.get(0));
                    geun.remove(0);
                }
            } else {
                if(seq) {
                    for (int i = 0; i<sang.size(); i++){
                        if(sang.get(i) > card.get(0)){
                            card.add(sang.get(i));
                            sang.remove(i);
                            break;
                        }
                    }
                    card.remove(0);
                } else {
                    for (int i = 0; i<geun.size(); i++){
                        if(geun.get(i) > card.get(0)){
                            card.add(geun.get(i));
                            geun.remove(i);
                            break;
                        }
                    }
                    card.remove(0);
                }
            }
            seq = !seq;
        }
        System.out.println(geun.size());
        System.out.println(sang.size());
    }
}
