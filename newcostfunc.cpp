#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
float avgdist(int A[][100],int N){
    int D[N][N],i,j,k;
    float ans;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=N-1;j=j+1){
            if (i==j){
                D[i][j]=0;
            }
            else if (A[i][j]==1){
                D[i][j]=1;
            }
            else {
                D[i][j]=100000;
            }
        }
    }
    for (k=0;k<=N-1;k=k+1){
        for (i=0;i<=N-1;i=i+1){
            for (j=0;j<=N-1;j=j+1){
                if (D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
    ans=0;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=i-1;j=j+1){
            ans+=D[i][j];
        }
    }
    ans=2*(float)ans/((float)(N*(N-1)));
    return ans;
}
float numedge(int A[][100],int N){
    int i,j;
    float ans;
    ans=0;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=i-1;j=j+1){
            ans+=(float)A[i][j];
        }
    }
    return ans;
}
string inputstr(int N){
    return "gooddata/o"+to_string(N)+".txt";
}
string outputstr(int N,float a){
    int M;
    M=1000*a;
    if (a==0){
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a0.000.txt";
    }
    else if (a==1){
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a1.000.txt";
    }
    else {
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a0."+to_string(M)+".txt";
    }
}
int main(){
    int N,M,k,i,j;
    float cost,alpha,mincost;
    N=6; //<----------------------- FREE VARIABLES;
    alpha=0.701; //<---------------- SUBJECT TO CHANGE
    mincost=100000;
    freopen(inputstr(N).c_str(),"r",stdin);
    freopen(outputstr(N,alpha).c_str(),"w",stdout);
    cin>>N>>M;
    cout<<"N = "<<N<<endl<<"alpha = "<<alpha<<endl;
    vector<int>V;
    int A[M][N][N],B[N][100];
    for (k=0;k<=M-1;k=k+1){
        for (i=0;i<=N-1;i=i+1){
            for (j=0;j<=N-1;j=j+1){
                cin>>A[k][i][j];
                B[i][j]=A[k][i][j];
            }
        }
        cost=3*alpha*avgdist(B,N)/((float)(N+1))+2*(1-alpha)*numedge(B,N)/((float)(N*(N-1)));
        if (cost<mincost){
            mincost=cost;
            V.clear();
            V.push_back(k);
        }
        else if (cost==mincost){
            V.push_back(k);
        }
    }
    cout<<"min. cost = "<<mincost<<endl<<endl<<V.size()<<" graph(s) minimizing cost"<<endl<<"=========================";
    for (i=0;i<=floor(log10(V.size()));i=i+1){
        cout<<"=";
    }
    cout<<endl;
    for (i=0;i<=V.size()-1;i=i+1){
        cout<<V[i]<<endl;
        for (j=0;j<=N-1;j=j+1)
        {
            for (k=0;k<=N-1;k=k+1)
            {
                cout<<A[V[i]][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}