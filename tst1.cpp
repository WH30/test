#include<iostream>
#include<vector>
using namespace std;

    int profit(vector<int>& v) 
    {
        if(v.size()==0)
        return 0;
       // vector<int>  v;
        //for(int i=1;i<prices.size();i++)
          //  v.push_back(prices[i]-prices[i-1]);
        //int m=v[0];
        int n=0;
        if(v[0]<0)
        v[0]=0;
        int m=v[0];
        for(int j=1;j<v.size();j++)
        {
            v[j]=v[j]+v[j-1];
            if(v[j]<0)
            v[j]=0;
            m=max(m,v[j]);
        }

        return m;
        
    }

        int maxProfit(vector<int>& prices) 
    {
        if(prices.size()==0||prices.size()==1 )
        return 0;
        vector<int>  v;
        int left=0,right=0,m=0;
        m=profit(v);
        for(int i=1;i<prices.size();i++)
            v.push_back(prices[i]-prices[i-1]);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<0)
            {
                left=0;right=0;
                vector<int> r;vector<int> l;
                if(i==0)
                {
                    r.assign(v.begin()+i+1,v.end());
                    right=profit(r);
                }
                else if(i==v.size()-1)
                {
                    l.assign(v.begin(),v.begin()+i);
                    left=profit(l);
                }
                else
                {
                    r.assign(v.begin()+i+1,v.end());
                    right=profit(r);                
                    l.assign(v.begin(),v.begin()+i);
                    left=profit(l);
                }
                m=max(left+right,m);
            }
        }
        return m;
    }