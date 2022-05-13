#include <iostream>
using namespace std;

int n,board[20],g_count = 0;

int check_rowcol(int index, int num)
{
    for (int i=0; i<index; i++)
    {
        if (board[i] == num)
            return 0; //KO
        
    }
    return 1; //OK
}

int check_diagonal(int index, int num)
{
    for (int i=0; i<index; i++)
    {
        if (num - board[i] == index - i || board[i] - num == index - i)
            return 0; //KO
    }
    return 1; //OK
}

void dfs(int index)
{
    if (index == n)
    {
        g_count++;
//        for(int i=0; i<n; i++)
//            cout<<board[i]<<" ";
//        cout<<'\n';
        return ;
    }
    else
    {
        for (int i=0; i<n; i++)
        {
            if (check_rowcol(index,i) != 0 && check_diagonal(index,i) != 0)
            {
                board[index] = i;
                dfs(index + 1);
            }
        }
    }
}

int main() {
    cin>>n;
    dfs(0);
    cout<<g_count;
    return 0;
}

