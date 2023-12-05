import java.util.ArrayList;
import java.util.List;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        List<Integer> truckWeights = new ArrayList<>();    
        List<Integer> bridge = new ArrayList<>();   
        List<Integer> time = new ArrayList<>();
        Integer runTime = 1;
        
        // 트럭 무게 int[] => List<Integer> 변환
        for(int i = 0; i<truck_weights.length; i++){
            truckWeights.add(truck_weights[i]);
        }
        
        
        while(true){
            //차가 통과한 경우 birdge에서 제거
            if((bridge.size() != 0) && (time.size() != 0)){
                while(time.get(0) + bridge_length == runTime){
                    bridge.remove(0);
                    time.remove(0);
                    
                    // while 조건 때문에 time 길이 0인 경우 index out of bound 발생하기에 break point 생성
                    if(time.size() == 0) {
                	 break;
                    }
                }
            }
            
            // 다리가 견딜 수 있는 무게인 경우 차량 다리 올라감
            if(sumOfBridge(bridge) + truckWeights.get(0) <= weight){
                bridge.add(truckWeights.get(0));
                time.add(runTime);
                truckWeights.remove(0);
            }
            
            // 종료 조건
            if(truckWeights.size() == 0){
                    break;
            }
            runTime ++;
        }
        
        return runTime + bridge_length;
    }
    
    // List 합 구하는 logic
    public static int sumOfBridge(List<Integer> bridge){
        Integer sum = 0;
        for(int i = 0; i< bridge.size(); i++){
            sum += bridge.get(i);
        }
        return sum;
    }
}