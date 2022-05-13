#include <iostream>
#include <queue>
using namespace std;

priority_queue <pair<int, int>> pq;
vector <pair<int,int>> vec[200005];

int v,e,start;
int line[20005]={0,}; //그래프, 길이값

void dijkstra(){
    pq.push({0,start}); //시작 노트 셋팅
    line[start]=0;
    
    while (!pq.empty()){
        int fnt = -pq.top().first; //길이값 (음수로 정렬)
        int sec = pq.top().second; //정점 번호
        pq.pop();
        
        for (int i=0; i<vec[sec].size(); i++){
            int vfnt = vec[sec][i].first;
            int vsec = vec[sec][i].second;
            
            if (line[vfnt]==-1 || line[vfnt] > fnt+vsec){
                line[vfnt] = fnt+vsec;
                pq.push({-line[vfnt], vfnt});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>v>>e>>start;
    for (int i=0; i<e; i++){
        int x,y,z;
        cin>>x>>y>>z;
        vec[x].push_back({y,z});
    }
    for (int i=1; i<=v; i++) //없는 값으로 초기화.
        line[i]= -1;
    
    dijkstra();
    
    for(int i=1; i<=v; i++){
        if (line[i] == -1)
            cout<<"INF\n";
        else
            cout<<line[i]<<"\n";
    }
        
    return 0;
}

