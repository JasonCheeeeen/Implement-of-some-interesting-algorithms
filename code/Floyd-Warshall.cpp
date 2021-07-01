#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool isnotexist(char alp[26], char c)
{
    char* p = find(alp, alp + 26, c);
    if(p == alp+26)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#define INF 9999
int main()
{
    int ver,edge;
    cin>>ver>>edge;
    char title[edge][2];
    int titlenum[edge];
    char alp[26] = {};
    int cc = 0;
    for(int i=0;i<edge;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>title[i][j];
        }
        cin>>titlenum[i];
        if(isnotexist(alp,title[i][0]))
        {
            alp[cc] = title[i][0];
            cc++;
        }
        if(isnotexist(alp,title[i][1]))
        {
            alp[cc] = title[i][1];
            cc++;
        }
    }
    int graph[ver][ver];
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            if(i==j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = INF;
            }
        }
    }

    for(int i=0;i<edge;i++)
    {
        int goal1,goal2;
        for(int j=0;j<ver;j++)
        {
            if(alp[j] == title[i][0])
            {
                goal1 = j;
            }
            if(alp[j] == title[i][1])
            {
                goal2 = j;
            }
        }
        graph[goal1][goal2] = titlenum[i];
    }

    for (int k=0;k<ver;k++)
    {
        for (int i=0;i<ver;i++)
        {
            for (int j=0; j<ver;j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j] && graph[i][k] < INF && graph[k][j] < INF)
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i=0;i<ver;i++)
    {
        for (int j=0;j<ver;j++)
        {
            if (graph[i][j] == INF)
            {
                if(j==ver-1)
                {
                    cout<<"INF";
                }
                else
                {
                    cout<<"INF"<<" ";
                }
            }
            else
            {
                if(j==ver-1)
                {
                    cout<<graph[i][j];
                }
                else
                {
                    cout<<graph[i][j]<<" ";
                }
            }
        }
        cout<<"\n";
    }
}
