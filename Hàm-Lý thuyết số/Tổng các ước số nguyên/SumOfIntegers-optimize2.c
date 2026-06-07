#include <stdio.h>
#include <math.h>

int sumInt(int n){
    int sum=0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            sum+=i;//tong cac uoc dau tien
            if(i!=n/i){
                sum+=n/i;//cac uoc tuong tu
            }
        }
    }
    return sum;
}
int countInt(int n){
    int count=0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            count++;//tong cac uoc dau tien
            if(i!=n/i){
                count++;//cac uoc tuong tu
            }
        }
    }
    return count;
}
int main(){
    int n;
    printf("Enter the integer: ");
    scanf("%d", &n);
    printf("Sum of the divisors of %d is: %d\n", n, sumInt(n));
    printf("The number of the divisors of %d is: %d\n", n, countInt(n));
    
    return 0;
}