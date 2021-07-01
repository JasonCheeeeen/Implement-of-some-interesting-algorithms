#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// append procedure into queue
queue<int> app(queue<int> m,int n[9])
{
    int iscopy[9];
    int iszero;

    // find space which is zero
    for(int i=0;i<9;i++)
    {
        iscopy[i] = n[i];
        if(iscopy[i] == 0)
        {
            iszero = i;
        }
    }

    //up
    if(iszero == 3 || iszero == 4 || iszero == 5 || iszero == 6 || iszero == 7 || iszero == 8)
    {
        int up[9] = {0};
        for(int i=0;i<9;i++)
        {
            up[i] = n[i];
        }
        swap(up[iszero],up[iszero-3]);
        for(int i=0;i<9;i++)
        {
            m.push(up[i]);
        }
    }

    //right
    if(iszero == 0 || iszero == 1 || iszero == 3 || iszero == 4 || iszero == 6 || iszero == 7)
    {
        int up[9] = {0};
        for(int i=0;i<9;i++)
        {
            up[i] = n[i];
        }
        swap(up[iszero],up[iszero+1]);
        for(int i=0;i<9;i++)
        {
            m.push(up[i]);
        }
    }

    //down
    if(iszero == 0 || iszero == 1 || iszero == 2 || iszero == 3 || iszero == 4 || iszero == 5)
    {
        int up[9] = {0};
        for(int i=0;i<9;i++)
        {
            up[i] = n[i];
        }
        swap(up[iszero],up[iszero+3]);
        for(int i=0;i<9;i++)
        {
            m.push(up[i]);
        }
    }

    //left
    if(iszero == 1 || iszero == 2 || iszero == 4 || iszero == 5 || iszero == 7 || iszero == 8)
    {
        int up[9] = {0};
        for(int i=0;i<9;i++)
        {
            up[i] = n[i];
        }
        swap(up[iszero],up[iszero-1]);
        for(int i=0;i<9;i++)
        {
            m.push(up[i]);
        }
    }
    return m;
}

// check goal or not
void del(queue<int> m, int goal, int pro_value[100], int c)
{
    int print[9]; // save the former nine number
    bool check = true;
    int sum = 0;
    for(int i=0;i<9;i++)
    {
        int p = m.front();
        sum = sum * 10 + p;
        m.pop();
        print[i] = p;
    }

    // check this number has been test or not
    for(int i=0;i<c;i++)
    {
        if(pro_value[i] == sum)
        {
            check = false;
        }
    }

    if(sum == goal)
    {
        for(int i=0;i<9;i++)
        {
            if(i%3 == 2)
            {
                cout<<print[i]<<endl;
            }
            else
            {
                cout<<print[i]<<" ";
            }
        }
    }
    else if(check == false)
    {
        m = app(m, print);
        del(m, goal, pro_value, c);
    }
    else
    {
        pro_value[c] = sum;
        c++;
        m = app(m, print);
        for(int i=0;i<9;i++)
        {
            if(i%3 == 2)
            {
                cout<<print[i]<<endl;
            }
            else
            {
                cout<<print[i]<<" ";
            }
        }
        del(m, goal, pro_value, c);
    }
}
int main()
{
    queue<int> q;
    queue<int> w;

    // origin
    for(int i=0;i<9;i++)
    {
        int in;
        cin>>in;
        q.push(in);
    }

    // goal
    for(int i=0;i<9;i++)
    {
        int in;
        cin>>in;
        w.push(in);
    }

    //transform to number
    int ans = 0;
    for(int i=0;i<9;i++)
    {
        int q = w.front();
        ans = 10 * ans + q; // transform to number(easy to check)
        w.pop();
    }

    //save exist numbers
    int probable[100], c = 0;
    del(q, ans, probable, 0);
}

