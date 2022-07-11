/*

Given a graph print either of the set of the vertices that are colored with the same color. And if the graph is not bipartite print “-1”.
Test cases also included cases when a graph is not connected.


https://gist.github.com/gunpreet34/c47f05ff80c75bfd13453f73f4727bcb
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
3
0 1 0
0 0 1
1 0 0

*/

#include<iostream>
using namespace std;
int n;
int arr[100][100]={0};

bool isBipartite(int i,int color[]){
      bool flag=true;
      for(int j=0;j<n;j++){
          if(arr[i][j]==1){
             if(color[j]==-1){
                color[j]=1-color[i];
                flag = flag & isBipartite(j,color);
             }
             else if(color[i]==color[j]){
                return false;
             }
          }
      }
      return flag;
}

int main(){
    cin >> n;//No of nodes in graph
    int color[n];//For coloring of graph

    for(int i=0;i<n;i++){
    	color[i] = -1;
        for(int j=0;j<n;j++){
            cin >> arr[i][j];//Input graph adjacency matrix
        }
    }

    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=0;
            if(!isBipartite(i,color)){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
	for(int i=0;i<n;i++){
		if(color[i] == 0){
			cout << i << " ";//Print all nodes with color 0
		}
	}

    return 0;
}

