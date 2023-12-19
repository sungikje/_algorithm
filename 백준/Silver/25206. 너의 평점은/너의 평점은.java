

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        /**
         * 20줄 입력 받으면서
         * split으로 나누고
         *
         */


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int count = 1;
        double sum = 0;
        int all = 0;

        for(int i = 0; i<20; i++){
            String[] arr = br.readLine().split(" ");
            switch(arr[2]) {
                case "A+":
                    count += 1;
                    sum += 4.5*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("4.5 : "+4.5*Double.parseDouble(arr[1]));
                    break;
                case "A0":
                    count += 1;
                    sum += 4.0*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("4.0 : "+4.0*Double.parseDouble(arr[1]));
                    break;
                case "B+":
                    count += 1;
                    sum += 3.5*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("3.5 : "+3.5*Double.parseDouble(arr[1]));
                    break;
                case "B0":
                    count += 1;
                    sum += 3.0*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("3.0 : "+3.0*Double.parseDouble(arr[1]));
                    break;
                case "C+":
                    count += 1;
                    sum += 2.5*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("2.5 : "+2.5*Double.parseDouble(arr[1]));
                    break;
                case "C0":
                    count += 1;
                    sum += 2.0*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("2.0 : "+2.0*Double.parseDouble(arr[1]));
                    break;
                case "D+":
                    count += 1;
                    sum += 1.5*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("1.5 : "+1.5*Double.parseDouble(arr[1]));
                    break;
                case "D0":
                    count += 1;
                    sum += 1.0*Double.parseDouble(arr[1]);
                    all += Double.parseDouble(arr[1]);
//                    System.out.println("1.0 : "+1.0*Double.parseDouble(arr[1]));
                    break;
                case "F":
                    count += 1;
                    all += Double.parseDouble(arr[1]);
                    break;
            }
//            System.out.println("sum : " + sum);
//            System.out.println("all : " + all);
//            System.out.println();
//            System.out.println();
//            System.out.println();
        }
//        System.out.println("최종 : " + sum);
//        System.out.println("count : " + count);
        System.out.println(sum/all);
    }
}