/*
https://www.careercup.com/question?id=5707238197952512
https://practice.geeksforgeeks.org/problems/how-to-solve-this-bfs-problem-asked-in-samsung
https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092
1 Bsed -> https://sapphireengine.com/@/4q0evk - Ajay Verma
0 Bsed -> https://sapphireengine.com/@/iha4kq - Thusoo
*/

/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.
Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road.
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them
Input -
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1
Output -
1
2
2
12
15
4
*/

#include<iostream>
using namespace std;
const int mx=20;
int a[mx][mx],vis[mx][mx];
int dis[mx][mx][mx];

int n,m;
struct R{
  int x,y;
};
R rare[mx];

bool isValid(int x,int y){

   return ((x>=0 && x<=n)&&(y>=0 && y<=n) && a[x][y]);
}

void dfs(int x,int y,int cost,int rareNum){
     if(!isValid(x,y)) return;
     if(dis[x][y][rareNum]<cost&&vis[x][y]) return;

     vis[x][y]=1;
     dis[x][y][rareNum]=cost;

     dfs(x,y-1,cost+1,rareNum);
     dfs(x,y+1,cost+1,rareNum);
     dfs(x+1,y,cost+1,rareNum);
     dfs(x-1,y,cost+1,rareNum);

}

int main()
{
    int t;
    cin>>t;
    while(t--){

        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>rare[i].x>>rare[i].y;
            --rare[i].x,--rare[i].y;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int k=0;k<m;k++){

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    vis[i][j]=0;
            }
            dfs(rare[k].x,rare[k].y,0,k);

        }
        int mn=999999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(a[i][j]==0) continue;
                 int curmx=-1;
                for(int k=0;k<m;k++){
                   curmx=max(curmx,dis[i][j][k]);
                }
                mn=min(mn,curmx);
            }
        }
        cout<<mn<<endl;
    }
}

























/*
#include<iostream>
using namespace std;
int row,col;
int a[100][100],visited[100][100],loc[100][2];
int sol=999999;
bool issafe(int x,int y) {
	return (x>=0 && x<row && y>=0 && y<col && a[x][y]==1 && visited[x][y]==0);
}
bool research(int x,int y,int x1,int y1,int count) {
	if(x==x1 && y==y1) {
		visited[x][y]=1;
		if(sol>count) {
			sol=count;
		}
		return true;
	}
	if(issafe(x,y)) {
		visited[x][y]=1;
		if(research(x,y-1,x1,y1,count+1)==true) {
			return true;
		}
		if(research(x,y+1,x1,y1,count+1)==true) {
			return true;
		}
		if(research(x-1,y,x1,y1,count+1)==true) {
			return true;
		}
		if(research(x+1,y,x1,y1,count+1)==true) {
			return true;
		}
	}
	return false;
}
int main() {
	int t,index=1;
	cin>>t;
	while(t--) {
		cin>>row>>col;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				cin>>a[i][j];
				visited[i][j]=0;
			}
		}
		int rare;
		cin>>rare;
		for(int i=0;i<rare;i++) {
			cin>>loc[i][0]>>loc[i][1];
		}
		int longest=0,flag=0,long_index=0,maxdist[row*col];
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(a[i][j]==1) {
					for(int k=0;k<rare;k++) {
						if(research(loc[k][0],loc[k][1],i,j,0)==true) {
							if(longest<sol) {
								longest=sol;
							}
							sol=INT_MAX;
						}
						else {
							flag=1;
							break;
						}
					//	memset(visited,0,sizeof(visited));
						for(int i=0;i<row;i++) {
							for(int j=0;j<col;j++) {
								visited[i][j]=0;
							}
						}
					}
					if(flag==0) {
						maxdist[long_index]=longest;
						long_index++;
					}
					else {
						flag=0;
					}
					longest=0;
				}
			}
		}
		int j=0;
		for(int i=1;i<long_index;i++) {
			if(maxdist[i]<maxdist[j]) {
				j=i;
			}
		}
		cout<<"#"<<index<<" "<<maxdist[j]<<endl;
		index++;
	}
	return 0;
}

*/

///A Research team want to establish a research center in a region where they found some rare-elements.They want to make it closest to all the rare-elements as close as possible so that they can reduce overall cost of research over there.It is given that all the rare-element’s location is connected by roads.It is also given that Research Center can only be build on road.Team decided to assign this task to a coder.If you feel you have that much potential…Here is the Task :- Find the shortest of the longest distance of research center from given locations of rare-elements.
///locations are given in the matrix cell form where 1 represents roads and 0 no road…
///number of rare-element and their location was also given(number<=5)
///and order of square matrix was less than equal to (20).
