#include <iostream> 
using namespace std; 
int fibo_rec(int n) 
{ 
 if(n == 0){ 
 return 0; 
 } 
 else if(n == 1){ 
 return 1; 
 } 
 else{ 
 return fibo_rec(n-2) + fibo_rec(n-1); 
 } 
} 
int fib_iter(int n){ 
 int n1=0,n2=1,n3,i; 
 cout<<n1<<" "<<n2<<" "; 
 for(i=2;i<n;++i) 
 { 
 n3=n1+n2; 
 cout<<n3<<" "; 
 n1=n2; 
 n2=n3; 
 } 
} 
int main() { 
 int number; 
 cout<<"Enter the number of elements: "; 
 cin>>number; 
 cout<<"Fibonacci Series Using Recursion"<<endl; 
 for(int i = 0; i < number; i++) 
 { 
 cout << fibo_rec(i) << " "; 
 } 
 cout<<endl<<"Fibonacci Series Using Iteration"<<endl; 
 fib_iter(number); 
 return 0; 
 } 