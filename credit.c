#include <cs50.h>
#include <stdio.h>


int get_int_len (long value);
bool checksum(long ccn);

int main(void)
{
   //request credit card number
   long ccNumber=get_long("Number:");
  int ccNumberLength= get_int_len(ccNumber);
   //determine if valid
        if(ccNumberLength==13||ccNumberLength==16||ccNumberLength==15){
        //validate checksum and print credit card brand
            if(checksum(ccNumber)==true){
                if((ccNumber>=4e12 && ccNumber < 5e12) || (ccNumber>=4e15 && ccNumber < 5e15) ){
                    printf("VISA\n");
                }else if((ccNumber >=34e13 && ccNumber< 35e13) || (ccNumber >= 37e13 && ccNumber<38e13)){
                    printf("AMEX\n");
                }else if((ccNumber>= 51e14 && ccNumber< 56e14)){
                    printf("MASTERCARD\n");
                }else{
                    printf("INVALID\n");
                }
            }else{
                printf("INVALID\n");
            }
        }else{
            printf("INVALID\n");
        }
}

//function to determine length of card number
int get_int_len (long value){
  int l=1;
  while(value>9){ l++; value/=10; }
  return l;
}

//function to determine if credit card number is valid
bool checksum(long ccn){

   int sum=0;
   for (int i=0;ccn !=0;i++,ccn/=10)
   {
       if(i % 2==0)
       {
           sum += ccn % 10;
       }else
       {
           int digit = 2 * (ccn % 10);
           sum += digit/10 + digit%10;
       }

   }
    return (sum % 10)==0;
}

