#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int minNum(int threshold, vector<int> points) {
    int num = 1;
    int min = points[0];
    int suspect = -1;
    
    for(int i = points.size()-1 ; i >=0; i--)
    {
        if(min+threshold > points[i])
        {    
            suspect = i;
            num++;
            break;
        }
    }    
    if(suspect != -1)     
    { 
        suspect++;
        
        while (suspect - 2 > 0)
        {   
            num ++;
            suspect = suspect - 2;
        }
    }
    else 
    {
        return points.size();    
    }
    
    return num;
}
int main()
{
    vector<int>A{10,82,112,134,178,206,229,238,278,293,335};
    
    cout<<minNum(650,A)<<endl;    
}