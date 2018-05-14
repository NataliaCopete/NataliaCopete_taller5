#include <iostream>
#include<math.h>


using std::cout;
using std::endl;


int main(){

double L=5;
double l=2;
double d =1; 
double h=5.0/512.0;
 int N=2*(L/h)*(L/h);
int fc=512;
int it=0;




double **g1= new double *[fc];


double **g= new double *[fc];
double **cx= new double *[fc-1];
double **cy= new double *[fc-1];


for (int i=0;i<fc;i++){
g[i]= new double[fc];
}
for (int i=0;i<fc;i++){
g1[i]= new double[fc];
}

for (int i=0;i<fc-1;i++){
cx[i]= new double[fc-1];
}

for (int i=0;i<fc-1;i++){
cy[i]= new double[fc-1];
}

for (int i=0;i<fc;i++){
g[0][i]=0;
g[fc-1][i]=0;
g1[0][i]=0;
g1[fc-1][i]=0;


}

for (int i=0;i<fc;i++){
g[i][0]=0;
g[i][fc-1]=0;
g1[i][0]=0;
g1[i][fc-1]=0;


}


for(int i=1;i<fc-1;i++){
  for (int j=1;j<fc-1;j++){
     if(i>204 && i<307 && j>152 && j<359){
      g[i][j]=100.0;
     g1[i][j]=100.0;
     
     }

  else{
g[i][j]=0.0;
     g1[i][j]=0.0;
     
}

    }
 }

for(int i=153;i<359;i++)
{
g[204][i]=50.0;
g1[204][i]=50.0;
}

for(int i=153;i<359;i++)
{
g[307][i]=50.0;
g1[307][i]=50.0;
}


while(it<N){
for(int i=1;i<fc-1;i++){
for (int j=1;j<fc-1;j++){ 
  g[i][j]= (g1[i][j+1]+g1[i][j-1]+ g1[i+1][j]+g1[i-1][j])*0.25;
  
}
}


for (int i=0;i<fc;i++)
{
for (int j=0;j<fc;j++){ 
g1[i][j]=g[i][j];
}
}

it=it+1;
}


for (int i=0;i<fc-1;i++)
{
for (int j=0;j<fc-1;j++){ 
cy[i][j]=(g[i+1][j]-g[i][j])/h;
}
}

for (int i=0;i<fc-1;i++)
{
for (int j=0;j<fc-1;j++){ 
cx[i][j]=(g[i][j+1]-g[i][j])/h;
}
}

for (int i=0;i<fc;i++)
{
for (int j=0;j<fc;j++){ 
cout<<g[i][j]<<endl;
}
}

return 0;
}
