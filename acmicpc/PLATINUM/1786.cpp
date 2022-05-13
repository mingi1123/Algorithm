#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//char s[1000005],p[1000005];
string s,p;
int fail[1000005]={0,},cnt=0;
queue <int> q;

void failfun(){
    for(int i=1,j=0; i<p.length(); i++){
        while (j>0 && p[i]!=p[j]){
            j=fail[j-1];
        }
        if (p[i]==p[j])
            fail[i]=++j;
        else
            fail[i]=0;
    }
}

void kmp(){
    for (int i=0,j=0; i<s.length(); i++){
        while(j>0 && s[i]!=p[j]){
            j=fail[j-1];
        }
        if(s[i]==p[j]){
            if (j == (p.length()-1)){
                q.push(i-p.length()+2);
                cnt++;
                j = fail[j];
            }
            else
                j++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    getline(cin,s);
    getline(cin,p);
    
    failfun();
    kmp();
    
    cout<<cnt<<"\n";
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}

