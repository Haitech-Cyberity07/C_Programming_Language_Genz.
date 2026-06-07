//Chỉ cần duyệt từ 1 đến n/2 vì các ước của n ngoại trừ chính nó ra thì đều nhỏ hơn n/2
#include <stdio.h>
int sumIntegers (int n){
    int sum = n;
    for(int i=1; i<=n/2; i++){
        if(n%i==0){
            sum+=i;
        }
    }
    return sum;
}
int countIntegers(int n){
    int count = 1;
    for(int i=1; i<=n/2; i++){
        if(n%i==0){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    printf("Enter the integer: ");
    scanf("%d", &n);
    printf("Sum of the divisors of %d is: %d\n", n, sumIntegers(n));
    printf("The number of the divisors of %d is: %d\n", n, countIntegers(n));
    
    return 0;
}