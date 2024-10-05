board = [" "] * 9
def display_board():
    print("-" * 13)
    print("|", board[0], "|", board[1], "|", board[2], "|")
    print("-" * 13)
    print("|", board[3], "|", board[4], "|", board[5], "|")
    print("-" * 13)
    print("|", board[6], "|", board[7], "|", board[8], "|")
    print("-" * 13)

def check_winner(player):
    if board[0] == board[1] == board[2] == player or \
        board[3] == board[4] == board[5] == player or \
        board[6] == board[7] == board[8] == player:
             return True
    if board[0] == board[1] == board[2] == player or \
        board[3] == board[4] == board[5] == player or \
        board[6] == board[7] == board[8] == player:
            return True
    if board[0] == board[4] == board[8] == player or \
        board[2] == board[4] == board[6] == player:
            return True
    return False

def make_move(player):
    while True:
        position = int(input("Выбери клетку от 0 до 8 : "))
        if position >= 0 and position < 9 and board[position] == " ":
            board[position] = player
            break
        else:
            print("Позиция не принята, так как введёная позиция меньше 0 или больше 8 или занята!")

def play_game():
    current_player = "X"
    while True:
            display_board()
            make_move(current_player)
            if check_winner(current_player) :
                print("Игрок", current_player, "победил!")
                break

            if current_player == "X":
                current_player = "O"
            else:
                current_player = "X"

play_game()



