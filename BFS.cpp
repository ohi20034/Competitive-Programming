 #include<bits/stdc++.h>
using namespace std;
vector< int > adjList[10000],vec,level_print[10000];
int dist[10000],path[10000],level_count;
int n,e,u,v,v1,v2;
void path_track(int x)
{
     int parent = path[x];
     if(path[x]==x)return ;
     vec.push_back(parent);
     path_track(parent);
 }
void bfs(int source)
{
    level_count=0;
    int i;
    queue< int > q;
    q.push(source);
    dist[source] = 0;
    path[source] = source;

        while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(i=0;i< adjList[parent].size();i++)
        {
            int child = adjList[parent][i];

            if(dist[child]>dist[parent]+1)
            {
                dist[child] = dist[parent]+1;

              //  cout<<child<<endl;
                level_print[dist[parent]+1].push_back(child);
              //  cout<<level_print

                  //find level of each node
                q.push(child);
                path[child] = parent;
                level_count=dist[child];
              //  cout<<level_count<<endl;
                 //for level count
            }
        }
    }
}
int main()
{
    int source,i,j;
    cin>>n;
    cin>>e;
    for(i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
        path[i] = -1;
    }
   while(e--)
    {
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    cin>>source;
    level_print[0].push_back(source);
    bfs(source);
    cout<<endl;
    printf("From the source:%d\n",source);
    cout<<endl;
    for(i=0; i<n; i++)
    {

        if(i!=source)
        {
            if(path[i]!=-1)
            {

                 vec.push_back(i);
                 path_track(i);
                 reverse(vec.begin(),vec.end());
                 printf("Minimum %d edges needed to reach %d\n",dist[i],i);
                 cout<<"Path taken:"<<" ";
                 //cout<<endl;
                 for(int i=0; i<vec.size(); i++)
                    cout <<vec[i]<< " " ;
                    cout <<endl;
                    vec.clear();
            }
            else
                printf("%d is not reachable.\n",i);
                cout<<endl;
        }
    }
    cout<<"Bonus: "<<endl;
    for(i=0;i<=level_count;i++)
    {
        //cout<<level_count<<endl;
        cout<<"Level "<<i+1<<":";
        for(j=0;j<level_print[i].size();j++)
         {
             cout<<level_print[i][j]<<",";
         }
        cout<<endl;
    }
    return 0;
}
