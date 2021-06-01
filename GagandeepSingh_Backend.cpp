#include <bits/stdc++.h>
using namespace std;

bool findIntersection(vector<int>t1, vector<int> t2)
{
    for(auto x: t1)
    {
        if(find(t2.begin(),t2.end(),x) == t2.end())
        return false;
    }
    return true;
}


bool bfs(vector<int> g[] , int node, int x,vector<int> inf,int n)
{
    vector<bool>visit(n+1,false);
    std::queue<int> q;
    q.push(node);
    visit[node]=true;
    
    int i=0,temp;
    
    vector<int> v;
    v.push_back(node);
    
    while( !q.empty())
    {
      temp = q.front();
      q.pop();
      vector<int> res;
      for(auto it: g[temp])
      {
          if(visit[it]==false)
          {
              visit[it]=true;
              q.push(it);
              res.push_back(it);
          }
      }
      
      if(res.size()!=0)
      { 
          for(auto j : res)
          v.push_back(j);
          i++;
         if(i>=x)
           break;
          
      }
	  
    }
 
   if(findIntersection(inf, v))
    return true;
   
   return false;
}

int main() {

    int n,h,x;
    cin>>n>>h>>x;
    int temp,t2;
    vector<int> infected;
    for(int i=0;i<h;i++)
    {
        cin>>temp;
        infected.push_back(temp);
    }
    
    vector<int> graph[n+1];
    for(int i=0;i<n-1;i++)
    {   
        cin>>temp>>t2;
        graph[temp].push_back(t2);
        graph[t2].push_back(temp);
    }
    
    int count=0;
    for(int i=1;i<=n;i++)
    {
        
       if(bfs(graph,i,x,infected,n))
       count++;
    }
    
    cout<<"The number of possible epicenters is :: "<<count;
    
    return 0;
}

