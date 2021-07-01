#include<iostream>
#include<cstring>
using namespace std;
int get_length(int p[100][100],int,int,int);
int main()
{
    int times;
    cin>>times;

    while(times>0)
    {
        char input1[100];
        char input2[100];
        cin>>input1;
        cin>>input2;
        int m = strlen(input1);
        int n = strlen(input2);

        int c[m+1][n+1];
        int b[100][100];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                c[i][j] = 0;
                b[i][j] = 0;
            }
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(input1[i-1] == input2[j-1])
                {
                    c[i][j] = c[i-1][j-1] + 1;
                    b[i][j] = 0;
                }
                else if(c[i-1][j] >= c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 2;
                }
            }
        }
        int ans = get_length(b,m,n,0);
        cout<<ans<<endl;
        times--;
    }
}
int get_length(int p[100][100],int s,int t,int ans)
{
    if(s == 0 || t == 0)
    {
        return ans;
    }
    if(p[s][t] == 0)
    {
        get_length(p, s-1, t-1, ans+1);
    }
    else if(p[s][t] == 1)
    {
        get_length(p, s-1, t, ans);
    }
    else
    {
        get_length(p, s, t-1, ans);
    }
}
