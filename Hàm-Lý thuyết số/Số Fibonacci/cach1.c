// Kiểm tra số fibonacci bằng vòng lặp
// Như đã đề cập ở mục 1 thì dãy số Fibonacci tăng rất nhanh 
// và chỉ cần tính tới số thứ 92 sẽ đạt tới số Fibonacci lớn nhất mà long long có thể lưu.
// Vì thế để kiểm tra 1 số có phải là số Fibonacci hay không 
// bạn hãy sinh ra các số Fibonacci từ F0 tới F92 và kiểm tra các số mình sinh ra 
// có giống với số cần kiểm tra hay không.
#include <stdio.h>
long long fibonacci(long long n){
    //2 số fibonacci đầu tiên là f0 = 0 và f1=1;
    if(n==0 || n==1){
        return 1;
    }
    long long fn1=0, fn2=1, fn;
    //xét vòng lặp từ số thứ 2 tới số thứ 92(số fibonacci to nhất mà long long có thể lưu trữ)
    for(int i=2; i<=92; i++){
        fn= fn1+fn2;
        if(fn==n){
            return 1;//ktra nếu số nhập vào là số fibonacci thì tức là nó đúng
        }
        //nếu không phải số fibonacci thì dịch sang 2 giá trị tiếp theo của 2 số
        fn1=fn2;
        fn2=fn;
    }
    return 0;
}
int main(){
    long long n=0;
    printf("Nhap vao so nguyen n: ");
    scanf("%lld", &n);
    if(fibonacci(n)){
        printf("YES!\n");
    }else{
        printf("NO!\n");
    }

    return 0;
}
