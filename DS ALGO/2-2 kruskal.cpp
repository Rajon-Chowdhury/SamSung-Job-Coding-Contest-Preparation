        #include<bits/stdc++.h>
        using namespace std;

        struct edge{
        int u,v,w;

        };

        bool operator < (edge a, edge b){

        return a.w<b.w;
        }

        vector<edge>e;

        int p[100];

        int find(int x){
        if(p[x]==x)return x;

        return p[x]=find (p[x]);
        }

        int kruskal(){

        sort(e.begin(),e.end());
        int sz=e.size();

        int ans=0;

        cout<<"path of MST"<<endl;

        for(int i=0;i<sz;i++){


            if(find(e[i].u)  != find(e[i].v)){

                //cout<<"path of MST"<<endl;

                    cout<<e[i].u<<"-->"<<e[i].v<<endl;
                p[p[e[i].u]] = p[e[i].v];
                ans+=e[i].w;
            }
        }

        printf("cost of MST = %d\n",ans);
        }

        int main()
        {
            int n;
            edge ed;
            for(int i=0;i<200;i++)
                p[i]=i;
            //cout<<"Enter number of edge: \n";

            cin>>n;

           // cout<<"Enter node1 node 2 && edge"<<endl;


            for(int i=0;i<n;i++){
                cin>>ed.u>>ed.v>>ed.w;
                e.push_back(ed);
            }

            kruskal();

            return 0;
        }

