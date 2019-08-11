#include <cstdio>
using namespace std;
int map[9][9];
void print_sudoku(){  
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
bool promising(int x,int y,int n){
    for(int i = 0;i<9;i++){
        if(map[x][i] == n || map[i][y] == n)
            return false;
    }
    int startX = (x/3)*3;
    int startY = (y/3)*3;
    for(int i = startX;i<startX+3;i++){
        for(int j = startY;j<startY+3;j++){
            if(map[i][j] == n)
                return false;
        }
    }
    return true;
}
void sudoku(){
    int x = -1,y = -1;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(map[i][j] == 0){
                x = i,y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    if(x == -1){
        print_sudoku();
    }
    for(int i = 1;i<=9;i++){
        if(promising(x,y,i)){
            map[x][y] = i;
            sudoku();

            map[x][y] = 0;
        }
    }
}
int main(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            scanf("%d",&map[i][j]);
        }
    }
    sudoku();
}
