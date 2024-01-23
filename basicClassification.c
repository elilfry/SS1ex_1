#include <stdio.h>



//is strong

int isStrong(int num){

int temp=num;
int tempNum = 0;
int sumOfFact =0;

while (temp != 0){


tempNum =temp%10;
sumOfFact = sumOfFact +factorial(tempNum);
temp = temp /10; 


}

// num%10 gets the right digits
//num /10 delete the right number



if (num == sumOfFact){
    return 1;
}
    return 0;
}


int factorial(int num){
int fact =1;

for(int i =1;i<=num;i++){
    fact = fact * i;
}
    return fact;
}
/* is prime */

int  isPrime(int number) {

if (number <= 1){
    return 0;
}
for( int i =2;i <number;i++){ //there is more efficiency way
    if(number % i == 0){
        return 0;
    }
}

return 1 ;
}



int main() {
    int num;

    // Get a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);



    // Call the function and print the result
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    if (isStrong(num)) {
        printf("%d is a strong number.\n", num);
    } else {
        printf("%d is not a strong number.\n", num);
    }



}
