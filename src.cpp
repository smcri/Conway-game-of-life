/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define side 10

char arr[side][side];

int checklife(int x, int y)
{
    int arrcheck[] = {-1,0,1};
    int neigh = 0;
    for(int i = 0;i<3;i++)
    {
       for(int j = 0;j<3;j++)
        {
            if((x+arrcheck[i])<0 || (x+arrcheck[i])>=side)
            {
                continue;
            }
            else if((y+arrcheck[j])<0 || (y+arrcheck[j]>=side))
            {
                continue;
            }
            
            if((x+arrcheck[i])==x && (y+arrcheck[j])==y)
            {
                continue;
            }
            else
            {
               //cout<<"Current cell : "<<x<<" "<<y<<" ";
               //cout<<"Checking : "<<x+arrcheck[i]<<" "<<y+arrcheck[j]<<" ";
               if(arr[x+arrcheck[i]][y+arrcheck[j]] != '.')
                    neigh++;
            }
        }
        //cout<<endl;
    }
    if(neigh<2)
        return -1;
    else if(neigh == 2)
        return 0;
    else if( neigh == 3)
        return 1;
    else if(neigh>3)
        return -1;
}
void print()
{
    for(int i = 0;i<side;i++)
    {
        for(int j = 0;j<side;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    for(int i = 0;i<side;i++)
    {
        for(int j = 0;j<side;j++)
        {
            arr[i][j] = '.';
        } 
    }
    
    int flag;
    arr[1][1] = '8';
    arr[1][2] = '8';
    arr[1][3] = '8';
    //print();
   while(true)
    {
        cout << "\033[2J\033[1;1H";
    for(int k = 0;k<side;k++)
    {
        for(int l = 0;l<side;l++)
        {
            flag = checklife(k,l);
            if(flag == -1)
            {
                if(arr[k][l] != '.')
                    arr[k][l] = '.';
            }
            if(flag == 1)
            {
                if(arr[k][l] == '.')
                    arr[k][l] = '8';
            }
            
        } 
    }
 //   usleep(33333);
    print();
    }
    
}
