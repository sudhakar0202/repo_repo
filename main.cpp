#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> dp;
    for (int i = 0; i < 5; i++)
    {   
        vector<int>v(3, -1);
        dp.push_back(v);
    }

     for(auto ve:dp){
        for(int val:ve){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
    // vector<vector<int>>v={{1,2,3},{4,5,6}};
    //  memset(&v,-1,24);
    // cout<<sizeof(v)<<endl;
    // for(auto ve:v){
    //     for(int val:ve){
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }
}