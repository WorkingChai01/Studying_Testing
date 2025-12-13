#include <iostream>

int const length = 200000;
int input,temp,digit;
int i,j;
long long sum[length],cal[length];
int main(){
    std::cin>>input;
    sum[0]=1;
    for(i=2;i<=input;i++){
        for(j=0;j<length;j++){
            sum[j]*=i;
            if(sum[j]>=10){
                temp=sum[j]/10;
                cal[j+1]+=temp;
                sum[j]-=temp*10;
            }
        }
        for(j=0;j<length;j++){
            sum[j]+=cal[j];
            cal[j]=0;
            if(sum[j]>=10){
                temp=sum[j]/10;
                sum[j+1]+=temp;
                sum[j]-=temp*10;
            }
        }
        for(j=0;j<length;j++){
            if(sum[j]!=0){
                digit=j+1;
            }
        }
    }
    for(i=digit;i>0;i--){
        std::cout<<sum[i-1];
    }
    std::cout<<std::endl;
}