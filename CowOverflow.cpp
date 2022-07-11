/*
https://www.careercup.com/question?id=5166688897073152
http://forums.codeguru.com/showthread.php?560529-Core-Java-programming
https://codereview.stackexchange.com/questions/136165/the-thirsty-crow
*/

/*
There are N pots. Every pots has some water in it. They may be partially filled.
Every pot is associated with overflow number O which tell how many minimum no. of stones required
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.
Array of overflow no--. {1,...,On}
Number of pots--n
No of pots to overflow-- k
Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1).
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.


Sample Test Case 1
Sample Input: {5,58}, 1
Sample Output: 10

Sample Test Case 2
Sample Input: {65,69}, 1
Sample Output: 69

*/

#include<iostream>
using namespace std;
int arr[100];
int n,k;

void bubble_sort(){

  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[i]){
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }
  }

}

int cow_overflow(){
    int tmp[n+5];
    tmp[0]=arr[0];
    for(int i=1;i<n;i++){
        tmp[i]=arr[i]-arr[i-1];
    }
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=(tmp[i]*(n-i));
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cin>>k;
    bubble_sort();
    cout<<cow_overflow()<<endl;


}
















/*

#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

void merger(int *overflow_numbers, int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i]=overflow_numbers[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=overflow_numbers[m+1+j];
    }


    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            overflow_numbers[k]=L[i];
            i++;
        }else{
            overflow_numbers[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        overflow_numbers[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        overflow_numbers[k]=R[j];
        k++;
        j++;
    }
}


void merge_sort(int *overflow, int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        merge_sort(overflow, l, m);
        merge_sort(overflow, m+1, r);
        merger(overflow, l, m, r);
    }
}

int minCrowPotStoneSameer(int *arr){
	int stone = 0, index = 0, left = n, prev = 0;

	for(int i=1; i<=k; i++){
		stone += left * (arr[index] - prev);
	    left--;
	    prev += arr[index]-prev;
	    index++;
	}

   	return stone;
}

int minCrowPotStoneFirst(int *overflow){
	int result = 0;
	for(int i=0 ; i<k ;i++){
		int min = overflow[i];
		for(int j=i; j<n; j++){
			overflow[j] = overflow[j] - min;
			result = result + min;
		}
	}
	return result;
}

int minCrowPotStoneSecond(int *overflow_numbers){
    int total_stones=0;

    for(int i=n-1; i>0; i--){
        overflow_numbers[i] = max(0,overflow_numbers[i]-overflow_numbers[i-1]);
    }

    for(int i=0; i<k; i++){
        total_stones+=(overflow_numbers[i]*(n-i));
    }
    return total_stones;
}

int main(){
	cin >> n;
	int *arr = new int[n + 1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin >> k;

    merge_sort(arr, 0, n-1);

	cout << minCrowPotStoneSameer(arr);
	return 0;
}
*/
