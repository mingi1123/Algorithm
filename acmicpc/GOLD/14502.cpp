#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N=0,M=0,rc[10][10]={0,};

int bfs(int **map){ //안전영역 크기파악
    int visit[10][10]={0,};
    queue <pair<int,int>> q;
    
    for (int i=0; i<N; i++){ //바이러스 지역 push
        for (int j=0; j<M; j++){
            if (map[i][j] == 2)
                q.push({i,j});
        }
    }

    while (!q.empty()){ //바이러스 spread
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        map[x][y]=2;
        
        if (x!=N-1 && map[x+1][y]==0 && visit[x+1][y]==0){
            visit[x+1][y] = 1;
            q.push({x+1,y});
        }
        if (x!=0 && map[x-1][y]==0 && visit[x-1][y]==0){
            visit[x-1][y] = 1;
            q.push({x-1,y});
        }
        if (y!=M-1 && map[x][y+1]==0 && visit[x][y+1]==0){
            visit[x][y+1] = 1;
            q.push({x,y+1});
        }
        if (y!=0 && map[x][y-1]==0 && visit[x][y-1]==0){
            visit[x][y-1] = 1;
            q.push({x,y-1});
        }
    }
    
//    for (int i=0; i<N; i++){
//        for (int j=0; j<M; j++)
//            cout<<map[i][j];
//        cout<<"\n";
//    }
//    cout<<"\n";
    
    int cnt=0; //안전영역 크기 count
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (map[i][j] == 0)
                cnt++;
//    cout<<cnt<<" ";
    return cnt;
}

int wall(){
    int cnt=0,temp=0;
    int **map;
    map = new int *[10];
    for(int i=0; i<10; i++)
        map[i] = new int[10];
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            map[i][j]=rc[i][j];
    
    int x1,y1,x2,y2,x3,y3;
    for(int i=0; i<(N*M-2); i++){
        x1=i/M; y1=i%M;
        if (map[x1][y1]==0){
            map[x1][y1]=1;
            
            for(int j=i+1; j<(N*M-1); j++){
                x2=j/M; y2=j%M;
                if (map[x2][y2]==0){
                    map[x2][y2]=1;
                    
                    for(int k=j+1; k<(N*M); k++){
                        x3=k/M; y3=k%M;
                        if (map[x3][y3]==0){
                            map[x3][y3]=1;
                            
                            int **cp;
                            cp = new int *[10];
                            for(int o=0; o<10; o++)
                                cp[o] = new int[10];
                            
                            copy(&map[0][0],&map[0][0]+100,&cp[0][0]);
                            
                            temp = bfs(cp);
                            if (cnt < temp)
                                cnt = temp;
                            
//                            for(int o=0; o<N; o++)
//                                  delete [] cp[o];
//                            delete [] cp;
                            
                            map[x3][y3]=0;
                        }
                    }
                    map[x2][y2]=0;
                }
            }
            map[x1][y1]=0;
        }
    }
    return cnt;
}

int main() {
    
    cin>>N>>M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin>>rc[i][j];
            
    cout<<wall();
    return 0;
}

