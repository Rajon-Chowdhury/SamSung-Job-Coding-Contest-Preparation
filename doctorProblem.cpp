/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and
the edge weights are the probabilities of the doctor going from that division to other connected division but the
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be
staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2

6 10 40
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 10
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 0.774000
3 0.700000
*/


#include<iostream>
using namespace std;
double arr[20][20];
double ans[21]={0.0};
int nodes,time;

void docProblem(int curTime,int curNode,double p){

    if(curTime<=0){
        ans[curNode]+=p;
        return;
    }
    for(int i=1;i<=nodes;i++){
        if(arr[curNode][i]!=0){
            p*=arr[curNode][i];
            docProblem(curTime-10,i,p);
            p/=arr[curNode][i];
        }
    }

}


int main(){
     int t;
     cin>>t;
     while(t--){
        int edges;
        cin>>nodes>>edges>>time;

        for(int i=1;i<=nodes;i++){
             ans[i]=0.0;
            for(int j=1;j<=nodes;j++)
                arr[i][j]=0;
        }
        int from,to;
        double prob;
        for(int i=0;i<edges;i++){
            cin>>from>>to>>prob;
            arr[from][to]=prob;
        }

        docProblem(time,1,1.0);
        double finalProb=0.0;
        int finalDivision=0;
        for(int i=1;i<=nodes;i++){
            if(ans[i]>finalProb){
                finalProb = ans[i];
                finalDivision=i;
            }
        }
        cout << finalDivision << " " << finalProb << "\n";


     }
}
