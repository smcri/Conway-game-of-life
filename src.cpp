/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

char arr[255][255];

int checklife(int x, int y)
{
    int arrcheck[] = {-1,0,1};
    int neigh = 0;
    for(int i = 0;i<3;i++)
    {
       for(int j = 0;j<3;j++)
        {
            if((x+arrcheck[i])<0 || (x+arrcheck[i])>255)
            {
                continue;
            }
            else if((y+arrcheck[j])<0 || (y+arrcheck[j]>255))
            {
                continue;
            }
            
            if((x+arrcheck[i])==x && (y+arrcheck[j])==y)
            {
                continue;
            }
            else
            {
                cout<<"Current cell : "<<x<<" "<<y<<" ";
                cout<<"Checking : "<<x+arrcheck[i]<<" "<<y+arrcheck[j]<<" ";
            }
        }
        cout<<endl;
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
    for(int i = 0;i<255;i++)
    {
        for(int j = 0;j<255;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    for(int i = 0;i<255;i++)
    {
        for(int j = 0;j<255;j++)
        {
            arr[i][j] = ' ';
        } 
    }
    
    int flag;
    arr[126][127] = '8';
    arr[127][127] = '8';
    arr[128][127] = '8';
   while(true)
    {
    for(int k = 0;k<255;k++)
    {
        for(int l = 0;l<255;l++)
        {
            flag = checklife(k,l);
            if(flag == -1)
            {
                if(arr[k][l] != ' ')
                    arr[k][l] = ' ';
            }
            if(flag == 1)
            {
                if(arr[k][l] == ' ')
                    arr[k][l] = '8';
            }
            
        } 
    }
 //   print();
    } 
    
}
