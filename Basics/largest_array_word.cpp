#include<iostream>

using namespace std;

int main(){

    int n;
    cin>> n;
    
    cin.ignore();
    char arr[n+1];
    
    cin.getline(arr,n);
    cin.ignore();

    int i=0,curlen=0,maxlen=0,st=0,maxst=0;

    while (1){

        if(arr[i]==' ' || arr[i]=='\0'){

            if(curlen>maxlen){
                maxlen=curlen;
                maxst=st;
            }

            curlen=0;
            st=i+1;
        }
        else
        curlen++;

        if(arr[i]=='\0')
            break;

            i++;
    }

    cout<<maxlen<<endl;
    for(int j=0;j<maxlen;j++){
        cout<<arr[j+maxst];
    }

    return 0;
}