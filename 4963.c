#include<stdio.h>
#include<string.h>
int map[51][51];
bool visit[51][51];
int dir[8][2]={{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m;
void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i=0;i<8;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visit[nx][ny]&&map[nx][ny]){
            dfs(nx,ny);
        }
    }
}
int main()
{
    
    while(1){
        scanf("%d %d", &m, &n);
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        if(n==0&&m==0)
            break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d", &map[i][j]);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]&&!visit[i][j]){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}