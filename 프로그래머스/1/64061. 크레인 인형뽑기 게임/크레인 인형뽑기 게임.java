class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int board_value = 0;
        int store_value = 0;
        int k;
        int i;
        int j;
        int[] store = new int[moves.length];
        
        for(i = 0; i < moves.length; i++){
                                                            //board 비어있는 경우 생략
            if(board[board.length-1][moves[i]-1] != 0){       //board에 doll 있는 경우
                 for(j = 0; j < board.length; j++){
                    if(board[j][moves[i]-1] != 0){              //board 꼭대기 찾으면 바로 나와야됨
                        board_value = board[j][moves[i]-1];
                        break;
                    }
                 }
                if(store[0] == 0){      //첫번째 사이클에서 저장소 비어 있는 경우, 저장하고
                    store[0] = board[j][moves[i]-1];
                    board[j][moves[i]-1] = 0;
                }
                else{                   //저장소 비어있지 않은 경우
                    for(k = moves.length-1; k >= 0; k--){       //저장소 꼭대기 위치 찾기
                        if(store[k] != 0){
                            store_value = store[k];
                            break;
                        }
                    }
                    if(board_value == store_value){     //값 같은 경우
                        store[k] = 0;
                        board[j][moves[i]-1] = 0;
                        answer += 2;
                    }
                    else{                                                   //다른 경우
                        store[k+1] = board[j][moves[i]-1];
                        board[j][moves[i]-1] = 0;
                    }
                }
            }
        }
        return answer;
    }
}