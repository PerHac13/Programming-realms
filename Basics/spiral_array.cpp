#include<iostream>

using namespace std;

int main(){
    int c,r;

    cout<<"Enter number row and column: ";
    cin>>r>>c;

    int a[r][c];

    cout<<"Enter the array below:"<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }

    //spiral order print
    int rs=0,re=r-1,cs=0,ce=c-1;

    while(rs<=re && cs<=ce){

        // for row start
        for (int i=cs;i<=ce;i++){
            cout<<a[rs][i]<<" ";
        }
        rs++;

        //for column end
        for(int j=rs;j<=re;j++){
            cout<<a[j][ce]<<" ";
        }
        ce--;

        //for row end
        for(int i=ce;i>=cs;i--){
            cout<<a[re][i]<<" ";
        }
        re--;

        //for column start
        for(int j=re;j>=rs;j--){
            cout<<a[j][cs]<<" ";
        }
        cs++;

    }


    return 0;
}