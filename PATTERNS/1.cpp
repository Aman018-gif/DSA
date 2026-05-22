#include<bits/stdc++.h>
using namespace std;
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

void pattern3(int n){
    for(int i=0;i<n;i++){
        int k=1;
        for(int j =0;j<=i;j++){
            cout<<k <<" ";
            k++;
        }
    cout<<endl;
    }
}

void pattern4(int n){
    int k=1;
    for(int i=0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<k;
        }
    k++;
    cout<<endl;
    }
}

void pattern5(int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<n-i;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

void pattern6(int n){
    for(int i=0;i<n;i++){
        int k=1;
        for(int j =0;j<n-i;j++){
            cout<<k;
            k++;
        }
    cout<<endl;
    }
}

void pattern7(int n){
    for(int i=0;i<n;i++){
    cout<<string(n-i-1,' ')<<string(2*i+1,'*')<<string(n-i-1,' ');
    cout<<endl;
    }
}

void pattern8(int n){
    for(int i=0;i<n;i++){
    cout<<string(i,' ')<<string(2*n-2*i-1,'*')<<string(i,' ');
    cout<<endl;
    }
}

void pattern9(int n){
    for(int i=0;i<n;i++){
    cout<<string(n-i-1,' ')<<string(2*i+1,'*')<<string(n-i-1,' ');
    cout<<endl;
    }

    for(int i=0;i<n;i++){
    cout<<string(i,' ')<<string(2*n-2*i-1,'*')<<string(i,' ');
    cout<<endl;
    }
}

void pattern10_01(int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<"*";
        }
    cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j =1;j<n-i;j++){
            cout<<"*";
        }
    cout<<endl;
    }

}

void pattern10_02(int n){
    for(int i=0;i<2*n-1;i++){
        int stars =i;
        int j=0;
        if(i>=n){
            stars = 2*n-i-1;
            j=1;
        }
        for(;j<stars;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

void pattern11(int n){
    for(int i=0;i<n;i++){
        int start;
        if(i%2==0) start=1;
        else start=0;
        for(int j =0;j<=i;j++){
            cout<<start << " ";
            if(start) start=0;
            else start =1;
        }
    cout<<endl;
    }
}

void pattern12(int n){
    int space= 2*(n-1);
    for(int i=1;i<=n;i++){
        for(int j =1;j<=i;j++){
            cout<<j;
        }
        for(int j =1;j<=space;j++){
            cout<<" ";
        }
        for(int j =i;j>=1;j--){
            cout<<j;
        }
    cout<<endl;
    space-=2;
    }
}

void pattern13(int n){
    int k=1;
    for(int i=0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<k <<" ";
            k++;
        }
    cout<<endl;
    }
}

void pattern14(int n){
    for(int i=0;i<n;i++){
        char k='A';
        for(int j =0;j<=i;j++){
            cout<<k <<" ";
            k++;
        }
    cout<<endl;
    }
}

void pattern15(int n){
    for(int i=0;i<n;i++){
        char k='A';
        for(int j =0;j<=n-i-1;j++){
            cout<<k <<" ";
            k++;
        }
    cout<<endl;
    }
}

void pattern16(int n){
    char k='A';
    for(int i=0;i<n;i++){
        for(int j =0;j<=i;j++){
            cout<<k <<" ";
        }
        cout<<endl;
        k++;
    }
}

void pattern17(int n){
    for(int i=1;i<=n;i++){
        char k='A';
    for(int j=0;j<n-i-1;j++){
        cout<<" ";
    }
    for(int j=1;j<=2*i+1;j++){
        cout<<k;
        if(j<=i) k++;
        else k--;

    }
    for(int j=0;j<n-i-1;j++){
        cout<<" ";
    }
    cout<<endl;
    }
}

void pattern18(int n){

    for(int i=1;i<=n;i++){
    char k='A';
    k+=n;
    k-=i;
        for(int j =1;j<=i;j++){
            cout<<k <<" ";
            k++;
        }
        cout<<endl;
        
    }
}


void pattern19(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*i;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
    if(i!=n-1)
    cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*n-2*i;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
    cout<<endl;
    }

}

void pattern20(int n){
    int space = 2*(n-1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int j=0;j<space;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
    space -=2;
    cout<<endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*i;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

void pattern21(int n){
    for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
        if(i==0||i==n-1||j==0||j==n-1)
        cout<<"*";
        else
        cout<<" ";
    }
    cout<<endl;

}
}

void pattern22(int n){
    for(int i=0;i<2*n-1;i++){
    for(int j =0;j<2*n-1;j++){
        int b = 2*n-1-1;
        int k;
        k = min({i,j,b-i,b-j});
        cout<<4-k;
    }
    cout<<endl;

}
}
int main(){
    int n;
    cout << "Enter no of lines";
    cin >>n;
    pattern22(n);
    return 0;
}