#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
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

int main()
{
    char orii;
    char endd;
    int nums;
    cin>>orii;
    cin>>endd;
    cin>>nums;

    char title[nums][2];
    int titlenum[nums];
    char alp[26];
    int cc = 0;
    for(int i=0;i<nums;i++)
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

    int dist[strlen(alp)];
    for(int i=0;i<strlen(alp);i++)
    {
        if(alp[i] == orii)
        {
            dist[i] = 0;
        }
        else
        {
            dist[i] = INT_MAX;
        }
    }

    for(int i=0;i<strlen(alp);i++)
    {
        for(int j=0;j<nums;j++)
        {
            if(alp[i] == title[j][0])
            {
                int goal;
                for(int l=0;l<strlen(alp);l++)
                {
                    if(title[j][1] == alp[l])
                    {
                        goal = l;
                        int isdist = dist[i] + titlenum[j];
                        if(isdist < dist[goal])
                        {
                            dist[goal] = isdist;
                        }
                    }
                }
            }
        }
        for(int a=i;a<strlen(alp)-1;a++)
        {
            for(int b=a+1;b<strlen(alp);b++)
            {
                if(dist[a]>dist[b])
                {
                    swap(dist[a],dist[b]);
                    swap(alp[a],alp[b]);
                }
            }
        }

    }
    for(int i=0;i<strlen(alp);i++)
    {
        if(alp[i] == endd)
        {
            cout<<dist[i];
        }
    }
}
