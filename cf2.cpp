#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include "eigen-3.4.0/Eigen/Dense"
#include "eigen-3.4.0/Eigen/Eigenvalues"
using Eigen::MatrixXd;
using Eigen::VectorXcd;
using namespace std;
float eigen2(int A[][100],int N){
    int i,j,k;
    vector<float>V;
    MatrixXd L(N,N);
    VectorXcd EV;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=N-1;j=j+1){
            if (i!=j){
                L(i,j)=-A[i][j];
            }
            if (i==j){
                L(i,j)=0;
                for (k=0;k<=N-1;k=k+1){
                L(i,j)+=A[i][k];
                }
            }
        }
    }
    EV=L.eigenvalues();
    V.clear();
    for (i=0;i<=N-1;i=i+1){
        V.push_back(EV(i).real());
    }
    sort(V.begin(),V.end());
    return V[1];
}
float edges(int A[][100],int N){
    int i,j;
    float edges;
    edges=0;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=i-1;j=j+1){
            edges+=(float)A[i][j];
        }
    }
    return edges;
}
string inputstr(int N){
    return "gooddata/o"+to_string(N)+".txt";
}
string outputstr(int N){
    return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"b.txt";
}
int main(){
    int N,M,k,i,j;
    float cost,mincost;
    N=5; //<----------------------- FREE VARIABLE
    mincost=100000;
    freopen(inputstr(N).c_str(),"r",stdin);
    freopen(outputstr(N).c_str(),"w",stdout);
    cin>>N>>M;
    cout<<"N = "<<N<<endl;
    vector<int>V;
    int A[M][N][N],B[N][100];
    for (k=0;k<=M-1;k=k+1){
        for (i=0;i<=N-1;i=i+1){
            for (j=0;j<=N-1;j=j+1){
                cin>>A[k][i][j];
                B[i][j]=A[k][i][j];
            }
        }
        ///////////////////////////////////////////////////////////////////
        cost=23*edges(B,N)/(N-1)-eigen2(B,N)*eigen2(B,N); // <----- NEW COST METRIC!/
        /////////////////////////////////////////////////////////////////
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