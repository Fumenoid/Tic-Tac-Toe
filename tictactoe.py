import sys 
import random

initboard=[['|','1','|','2','|','3','|'],['|','4','|','5','|','6','|'],['|','7','|','8','|','9','|']]
board={1:' ',2:' ',3:' ',4:' ',5:' ',6:' ',7:' ',8:' ',9:' '}

def printdefaultboard():
    print("\n-------------")
    for x in range(3):
        for y in range(7):
            print(initboard[x][y]+" ", end="")
        print("\n-------------")

def printboard():
    print("\n-------------")
    for x in range(1, 8, 3):
        print("| "+board[x]+" |"+" "+board[x+1]+" |"+" "+board[x+2]+" |", end="")
        print("\n-------------")
    
def checkgame():
    for x in range(1, 8, 3):
        if (board[x]==board[x+1] and board[x+1]==board[x+2] and board[x]!=' '):
            if board[1]=='X':
                print("\nPlayer 1 wins !!, Congrats!\n")
                sys.exit()
            else:
                print("\nPlayer 2 wins !!, Congrats!\n")
                sys.exit()
    for x in range(1, 4, 1):
        if (board[x]==board[x+3] and board[x+3]==board[x+6] and board[x]!=' '):
            if board[1]=='X':
                print("\nPlayer 1 wins !!, Congrats!\n")
                sys.exit()
            else:
                print("\nPlayer 2 wins !!, Congrats!\n")
                sys.exit()
    if (board[1]==board[5] and board[5]==board[9] and board[1]!=' '):
        if board[1]=='X':
            print("\nPlayer 1 wins !!, Congrats!\n")
            sys.exit()
        else:
            print("\nPlayer 2 wins !!, Congrats!\n")
            sys.exit()
    if (board[7]==board[5] and board[5]==board[3] and board[7]!=' '):
        if board[1]=='X':
            print("\nPlayer 1 wins !!, Congrats!\n")
            sys.exit()
        else:
            print("\nPlayer 2 wins !!, Congrats!\n")
            sys.exit()
            
def putvalue(playerno, x):
    if playerno==1:
        board[x]='X'
    else:
        board[x]='O'

def playerturn(playerno):
    if playerno==1:
        print("\nPlayer 1 turn")
        print("Enter the position where you wanna place X")
    else:
        print("\nPlayer 2 turn")
        print("Enter the position where you wanna place Y")
    while True:
        x=int(input())
        if board[x]==' ':
            break
        else:
            print("That position is already filled, please re-enter some other value")
    putvalue(playerno, x)
    
print('''Tic - Tac - Toe
Hope you both know the rules, its a two player game, wish you both luck :)
Which player gets first turn, is chosen by random\n''')
printdefaultboard()
print("\nAbove is the position map, enter it on your turn")
x=random.randint(1,2)
if x==1:
    while True:
        playerturn(1)
        printboard()
        checkgame()
        playerturn(2)
        printboard()
        checkgame()
else:
    while True:
        playerturn(2)
        printboard()
        checkgame()
        playerturn(1)
        printboard()
        checkgame()

""" Yo, It's a 
Multi line comment"""