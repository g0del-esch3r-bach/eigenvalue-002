#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include "../eigen-3.4.0/Eigen/Dense"
#include "../eigen-3.4.0/Eigen/Eigenvalues"
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
float numedge(int A[][100],int N){
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
string outputstr(int N,float a){
    int M;
    M=1000*a;
    if (M<10){
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a0.00"+to_string(M)+".txt";
    }
    else if (M<100){
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a0.0"+to_string(M)+".txt";
    }
    else if (M<1000){
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a0."+to_string(M)+".txt";
    }
    else{
        return "bestgraph/bg"+to_string(N)+"/g"+to_string(N)+"a1.000.txt";
    }
}
int main(){
    int N,M,k,i,j;
    float cost,alpha,mincost;
    N=3; //<----------------------- FREE VARIABLES;
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
        cost=3*alpha*eigen2(B,N)/((float)(N+1))+2*(1-alpha)*numedge(B,N)/((float)(N*(N-1)));
        // ^ COST FUNCTION; DEFINITELY CHANGE THIS
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