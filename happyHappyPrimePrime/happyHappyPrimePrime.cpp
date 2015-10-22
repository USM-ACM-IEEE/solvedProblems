#include <cstdlib>
#include <iostream>

using namespace std;



bool isHappy(int num)
{
     //will irerate num to one digit
     int sum =0; //sum of squares of digits
     
     while(true)
     {
       while(num>0)
       {
        sum += (num%10) * (num%10); 
        num /= 10;
       }
       if(sum<10) return (sum==1);
        
        num = sum;    
        sum =0;
     }
}

void primes(bool isPrime[]) // p size is 10,001
{
     //initialize
     isPrime[0]=isPrime[1]=false; 
     for(int i=2; i<=100000; i++) isPrime[i]=true; 
     int sieve = 2; 
     while (sieve < 50000)
     {
           for(int i=2; i*sieve <=100000; i++)
           {
                    isPrime[i*sieve]=false; 
           }
           while(isPrime[++sieve]==false);
     } 
}
     
     
int small(int num)
{
    int sum=0;
       while(num>0)
       {
        sum += (num%10) * (num%10); 
        num /= 10;
       }   
    return sum;
}



int main(int argc, char *argv[])
{
   //primes upto 100,000 
   bool isPrime[100001]; 
   primes(isPrime); 
   
   //happy numbers upto 324
   bool happy[325];
   for(int i=0; i<=324; i++)
   {
           happy[i]=isHappy(i);
   }
   
   
   
   //take test cases
   int t, trash, num, smallNum;
   bool yes; 
   cin >> t; 
   for(int i=1; i<=t; i++)
   {
            cin >> trash >> num; 
            smallNum = small(num);
            yes = isPrime[num] && happy[smallNum]; 
            cout << trash << " " << num << " " ; 
            if(yes) cout <<"YES\n";
            else cout << "NO\n";   
   }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
