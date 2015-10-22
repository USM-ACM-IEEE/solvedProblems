#include <cstdlib>
#include <iostream>

using namespace std;



bool isHappy(int num)
//Determines if a given number is happy
{
     //will irerate num to one digit
     int sum =0; //sum of squares of digits
     
     while(true)
     {
       while(num>0)
        //While there are still digits
       {
        sum += (num%10) * (num%10); 
        num /= 10;
       }
       if(sum<10) return (sum==1);
       //If the sum has fallen bellow ten return if it is happy or not
        
        num = sum;    
        sum =0;
     }
}

void primes(bool isPrime[]) // p size is 10,001
//uses teh sieve method to find the primes in the range
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
//This will run one round of the happiness algorithm discribed in the problem
{
    int sum=0;
       while(num>0)
       {
        sum += (num%10) * (num%10);
        //This adds the square of the first digit
        num /= 10;
        //Takes the digit that was just added off
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
            //Runs the algorithm once to ensure the number is within our range of generated happy numbers
            
            yes = isPrime[num] && happy[smallNum]; 
            cout << trash << " " << num << " " ; 
            if(yes) cout <<"YES\n";
            else cout << "NO\n";   
   }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
