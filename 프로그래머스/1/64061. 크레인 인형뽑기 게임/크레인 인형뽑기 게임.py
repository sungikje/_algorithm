def solution(board, moves):
    answer = 0
    
    ist = []

    for i in range(len(moves)):
        j = 0
        while j<len(board):
            if board[j][moves[i]-1] != 0:
                break
            j += 1

        if board[len(board)-1][moves[i]-1] != 0 :
            if len(ist) == 0:
                ist.append(board[j][moves[i]-1])
                board[j][moves[i]-1] = 0
            else:
                if ist[len(ist)-1] != board[j][moves[i]-1]:
                    ist.append(board[j][moves[i]-1])
                    board[j][moves[i]-1] = 0
                else:
                    del ist[len(ist)-1]
                    board[j][moves[i]-1] = 0
                    answer += 2
    print(answer)
    # return answer
    
    
    
    return answer