#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
void printmatrix(int arr[][3]) {
    printf("\n");
    for(int x=0;x<3;x++){
        printf("---------------------\n");
        for(int y=0;y<3;y++){
            printf("|  %c  |", ((char)(arr[x][y])));
        }
        printf("\n");
    }
    printf("---------------------\n");
}
void player(int arr[][3],int c,int pn) {
    int x,y;
    printf("\n");
    if (c==0) {
        printf("Player's turn... \n");
    } 
    else {
        printf("Player %d turn... \n", pn);
    }
    printf("Enter the co-ordinate of position you want too place X\n");
    L1:printf("Enter x's cordinate(1-3): ");
    scanf("%d", &x);
    printf("Enter y's cordinate(1-3): ");
    scanf("%d", &y);
    x-=1;
    y-=1;
    if((x<3&&x>=0)&&(y<3&&y>=0)){
    if(arr[x][y]==32) {
        if(c==0){
            arr[x][y]=88;
        }
        else {
        if(pn==1){
            arr[x][y]=88;
        } else {
            arr[x][y]=79;
        }
        }
    } else{
        printf("\nThe co-ordinate %d,%d is already filled\n", x+1, y+1);
        printf("Please re-enter the values\n");
        goto L1;
    }
    } else
    {
        printf("\nThe co-ordinate %d,%d are out of playing field\n", x+1, y+1);
        printf("Please re-enter the values\n");
        goto L1;
    }
    printmatrix(arr);
        if (c==0) {
        printf("Player's turn has ended..\n\n");;
    } 
    else {
        printf("Player %d turn has ended..\n\n", pn);
    }
}
void fumesroid(int arr[][3]){
    printf("\n");
    printf("Computer's turn... \n");
    printf("Thinking...\n");
    int x,y;
    L2:x=rand()%3;
    y=rand()%3;
    if(arr[x][y]==32) {
        arr[x][y]=79;
    } else{
        goto L2;
    }
    sleep(2);
    printmatrix(arr);
    printf("Computer's turn has ended..\n\n");
}
int checkdraw(int arr[][3]){
    int counter=0;
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            if(arr[x][y]==32){
                counter+=1;
            }
        }
    }
    if(counter==0){
        return 1;
    }
}
int check(int arr[][3],int c) {
    for(int x=0;x<3;x++) {
    if((arr[x][0]==arr[x][1])&&(arr[x][0]==arr[x][2])) {
        if(arr[x][0]==88) {
            if(c==0){
            printf("\n\nCongrats, Player won this match !!\n");
            } else{
            printf("\n\nCongrats player 1,you won this match !!\n");  
            }
            return 1;
        } 
        if(arr[x][0]==79) {
            if(c==0){
            printf("\n\nDuhh, Computer won this match !!\n");
            } else{
            printf("\n\nCongrats player 2,you won this match !!\n");   
            }
            return 1;
        } 
    }
    }
    for(int y=0;y<3;y++) {
    if((arr[0][y]==arr[1][y])&&(arr[0][y]==arr[2][y])) {
        if(arr[0][y]==88) {
            if(c==0){
            printf("\n\nCongrats, Player won this match !!\n");
            } else{
            printf("\n\nCongrats player 1,you won this match !!\n");  
            }
            return 1;
        } 
        if(arr[0][y]==79) {
            if(c==0){
            printf("\n\nDuhh, Computer won this match !!\n");
            } else{
            printf("\n\nCongrats player 2,you won this match !!\n");   
            }
            return 1;
        } 
    }
    }
    int d=checkdraw(arr);
    if(d==1){
        printf("Oooh.. It's a draw !!!");
        return 1;
    }
    if((arr[0][0]==arr[1][1])&&(arr[0][0]==arr[2][2])){
        if(arr[1][1]==88) {
            if(c==0){
            printf("\n\nCongrats, Player won this match !!\n");
            } else{
            printf("\n\nCongrats player 1,you won this match !!\n");  
            }
            return 1;
        } 
        if(arr[1][1]==79) {
            if(c==0){
            printf("\n\nDuhh, Computer won this match !!\n");
            } else{
            printf("\n\nCongrats player 2,you won this match !!\n");   
            }
            return 1;
        }
    }
    else if((arr[2][0]==arr[1][1])&&(arr[2][0]==arr[0][2])){
        if(arr[1][1]==88) {
            if(c==0){
            printf("\n\nCongrats, Player won this match !!\n");
            } else{
            printf("\n\nCongrats player 1,you won this match !!\n");  
            }
            return 1;
        } 
        if(arr[1][1]==79) {
            if(c==0){
            printf("\n\nDuhh, Computer won this match !!\n");
            } else{
            printf("\n\nCongrats player 2,you won this match !!\n");   
            }
            return 1;
        }
    }
    else {
    return 0;
    }
}
int main() {
    int arr[3][3];
    int itsgame=0;
    char mode;
    printf("\n..Welcome to Tic-Tac-Toe..\n");
    printf("We hope you already know the rules :P\n");
    printf("Enter 's/S' for singleplayer mode or 'm/M' for multiplayer mode\n");
    scanf("%c", &mode);
    printf("Here is the co-ordinate map for user-reference :)\n");
    printf("\n");
    for(int y=0;y<3;y++){
        printf("---------------------------\n");
        for(int z=0;z<3;z++){
            printf("|  %d,%d  |", y+1, z+1);
        }
        printf("\n");
    }
    printf("---------------------------\n");
    sleep(2);
    //initializing empty array...
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            arr[x][y]=32;
        }
    }
    srand(time(0));
    if(mode=='s'||mode=='S') {
    while(itsgame!=1) {
        player(arr, 0, 0);
        itsgame=check(arr, 0);
        if(itsgame==1){
            break;
        }
        fumesroid(arr);
        itsgame=check(arr, 0);
    }
    }
    else if(mode=='m'||mode=='M'){
        int count=1;
    while(itsgame!=1) {
        player(arr, 1, 1);
        itsgame=check(arr, 1);
        if(itsgame==1){
            break;
        }
        player(arr, 1, 2);
        itsgame=check(arr, 1);
    }
    }
    return 0;
}