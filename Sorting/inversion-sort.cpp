#include <iostream> 
using namespace std;
int merge(int a[],int start,int end){
  int mid = (start+end)/2;
  int i = start;
  int j = mid+1;
  int k = start;
  int temp[1000];
  int count = 0;

  while(i<=mid && j<=end){
    if(a[i]<=a[j]){
      temp[k] = a[i];
      k++;
      i++;
    }else{
      temp[k++] = a[j++];
      count = count + mid-i+1; 
    }
  }
  while (i<=mid)
  {
    temp[k++]  = a[i++];
  }
  while (j<=end)
  {
    temp[k++]  = a[j++];
  }

  for (int i = start; i <= end; i++)
  {
    a[i] = temp[i];
  }   
  return count;

}
int inversionCount(int a[],int start,int end){
  if(start>=end){
    return 0;
  }
  int mid = (start+end)/2;
  int x = inversionCount(a,start,mid);
  int y = inversionCount(a,mid+1,end);
  int z = merge(a,start,end);
  return x+y+z;
}

int main(){
  int n,a[100];
  cin>>n;
  for(int i =0;i<n;i++){
    cin>>a[i];
  }
  cout<<"Total No. of pairs : "<<inversionCount(a,0,n-1);
 return  0;
}