#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include "pt.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////
bool isPerfectSquare(long long int x)
{
   // Find floating point value of
   // square root of x.
   float sr = sqrt(x);
   // If square root is an integer
   return ((sr - floor(sr)) == 0);
}
/////////////////////////////////////////////////////////////////////////////
long long int modulo(long long int a, long long int b, long long int N){
     long long int x=1;
     long long int y=a;
     while (b > 0) {
         if (b%2 == 1) {
             x = (x*y) % N; // multiplying with base
         }
         y = (y*y) % N; // squaring the base
         b /= 2;
     }
     return x % N;
}
/////////////////////////////////////////////////////////////////////////////
long long int findInverse(long long int a, long long int m)
{
     //This is where the magic happens; if there is a common factor, the number will not have an inverse:
     a = a%m;
     for (int x=1; x<m; x++){
         if ((a*x) % m == 1){
           return x;
         }
     }
     cout << "denominator " << a << " has no inverse";
     return 0;
}
/////////////////////////////////////////////////////////////////////////////
pt findPoint(pt& temp, long long int N){
 
     bool notPerfectSquare = true;
     long long int i;
     long long int ySq = 0;
 
     //while (notPerfectSquare && i < 500){
	 for (i = 910; i < 918; i++){
         ySq = modulo(i,3,N) + (3*i) + 47;
         ySq = ySq % N;
 
         if (isPerfectSquare(ySq)) {
             notPerfectSquare = false;
             temp.x = i;
             temp.y = ySq;
         }
 
         //i++;
     }
 
     return temp;
}
/////////////////////////////////////////////////////////////////////////////
double findSlope(pt a, pt b, long long int N){
 
     long long int numerator = 0;
     long long int denominator = 0;
     long long int slope = 0;
 
     //testing to see if the two points are the same:
     //if the same, use the derivative of the function
     if (a.x == b.x && a.y == b.y){
        
         numerator = (3 * pow(a.x,2)) + 1;
        
         numerator = numerator % N;
        
         if (numerator < 0){
             numerator = N + numerator;
         }
       
         denominator = 2*a.y;
         denominator = denominator % N;
        
         if (denominator < 0){
             denominator = N + denominator;
         }
         denominator = findInverse(denominator, N);
         slope = numerator * denominator;
         return slope % N;
     }
 
     //if two points not the same, use the standard slope formula
     else{
         numerator = b.y - a.y;
         numerator = numerator % N;
         if (numerator < 0){
             numerator = N + numerator;
         }
 
         denominator = b.x - a.x;
         denominator = denominator % N;
         if (denominator < 0){
             denominator = N + denominator;
         }
 
         denominator = findInverse(denominator, N);
         slope = numerator * denominator;
 
         return slope % N;
     }
}
/////////////////////////////////////////////////////////////////////////////
pt add(pt& a, pt& b, long long int N){
 
     pt sum(0,0);
     long long int slope = 0;
     long long int temp = 0;
 
     slope = findSlope (a, b, N);
 
     sum.x = modulo(slope, 2, N) -a.x - b.x;
     sum.x = sum.x % N;
     if (sum.x < 0){
         sum.x = N + sum.x;
     }
 
     sum.y = (slope*(a.x - sum.x)) - a.y;
     cout << endl << endl << sum.y << endl;
     sum.y = sum.y % N;
     if (sum.y < 0){
         sum.y = N + sum.y;
     }
 
     return sum;
}
/////////////////////////////////////////////////////////////////////////////
long long int findx3(long long int slope, pt a, pt b, long long int N){
 
  long long int x3 = 0;
  
  x3 = pow(slope,2) - a.x - b.x;
  x3 = x3%N;
  
  if (x3 < 0){
    x3 = N + x3;
  }
 
  return x3 % N; 
}
/////////////////////////////////////////////////////////////////////////////
long long int findy3(long long int slope, long long int x3, pt a, pt b, long long int N){
 
  long long int y3 = 0;
  
  y3 = slope*(a.x - x3);
  y3 = y3 - a.y;
  
  y3 = y3%N;
  if (y3 < 0){
    y3 = N + y3;
  }
 
  return y3 % N; 
}
/////////////////////////////////////////////////////////////////////////////
long long int findYSquared (pt a, long long int N){

	bool isPerfectSquare = true; 
	long long int tempX; 
	long long int ySq; 
	int yCounter = 0; 
	
	for (int i = 0; i < 10; i++){
		
		tempX = modulo(i,3,N) + (3*i) + 47;
		tempX = tempX % N; 
		
		while (yCounter < N){
			
			if (modulo(yCounter,2,N) == tempX) {
				cout << i << " " << yCounter << endl; 
			}
			
			yCounter++; 
		}
		
		yCounter = 0; 
	}
}

/////////////////////////////////////////////////////////////////////////////
int main(){
 
     long long int slope = 0;
     long long int x3 = 0;
     long long int y3 = 0;
     long long int N = 1187;
     pt t1(0,0);
     //pt t2(33054,21887);
 
	 //findYSquared(t1, N);
	 //cout << t1.x << " " << t1.y; 
     //cout << "Please input your N value: ";
     //cin >> N;
    
     //slope = findSlope(t1,t2, N);
     //x3 = findx3(slope, t1, t2, N);
     //y3 = findy3(slope, x3, t1,t2,N);
     
     //cout << "slope = " << slope << endl;
     //cout << "(" << x3 << "," << y3 << ")" << endl;
     
	 for (int i = 0; i < 100; i++){
		if (modulo(674,i,1601) == 257)
			cout << i << " ";
	 }
	 
     return 0;
}