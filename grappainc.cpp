//load('C:\Users\lenovo\Desktop\Raw_data_recon.mat')
//ksp got by fft of image data
# include <iostream>
# include <vector>
using namespace std;
class complex{
public:
    float x;
    float y;
    complex() {
        x = 0;
        y = 0;
    }
    complex (float a,float b)
    { x = a;
        y = b;}
    complex( complex &a)
    {x = a.x;
        y = a.y;}
    complex conjugate()
    {
    x = x;
    y = -y;
     return *this;}
     void print()
     {cout<<x<<" "<<"+"<<" "<<"i"<<y;
     return;}

friend istream & operator >>(istream &in,complex &a);

};

ostream & operator << (ostream &ost,complex &a)
{ost <<a.x<<" "<<"+"<<" "<<"i"<<a.y<<" ";
return ost;}

istream & operator>>(istream &in,complex &a)
{in >>a.x ;
/*in >>" ";
in >>"+";
in >>" ";
in >>"i";*/
in >>a.y;
/*in >>" ";*/
return in;}

    complex operator + (complex & c,complex & a){
        complex b;
    b.x = c.x+a.x;
    b.y = c.x+a.y;
    return b;}
    complex operator - (complex & c,complex & a){
        complex b;
    b.x = c.x-a.x;
    b.y = c.x-a.y;
    return b;
    }    
        complex operator * (complex & c,complex & a){
        complex b;
    b.x = a.x * c.x- c.y* a.y;
    b.y = c.x*a.y + c.y*a.x;
    return b;
    }
        complex operator / (complex & c,complex & a){
        complex b;
        b.x = (c.x*a.x + c.y*b.y)/(a.x*a.x + a.y*a.y);
        b.y = (a.y*b.x - a.x*b.y)/(a.x*a.x + a.y*a.y);
    return b;
    }
int main(){
int i = 0;
vector<complex> kspace[256][256][2];
vector<complex> ksp[256][256][2];
for (int i = 0; i < 256; ++i)
{
    for (int j = 0; j < 256; ++j)
    {
        for (int k = 0; k < 2; ++k)
        {
            cin >> ksp[i][j][k];
        }
    }
}
while (i < 100)
    {if (i % 2 ==0)
        {for(int j = 0; j < 256 ; j++)
            {kspace[i][j][0] = ksp[i][j][0];
                kspace[i][j][1] = ksp[i][j][1];}
        }
    else
        {for(int j = 0; j < 256 ; j++)
            {kspace[i][j][0] = ksp[i][j][0];
                kspace[i][j][1] = ksp[i][j][1];}
            }
    i = i + 1;}
for (int i = 100; i< 156;i++)
    {for(int j = 0; j<256;j++)
        {for(int l = 0; l<2;l++)
            {kspace[i][j][l] = ksp[i][j][l];}}}
/*for j=101:156
    kspace(j,:,:) = ksp(j,:,:);*/


int i = 156;
while (i < 256)
    {if (i % 2 ==1)
        {for(int j = 0; j < 256 ; j++)
            {kspace[i][j][0] = ksp[i][j][0];
                kspace[i][j][1] = ksp[i][j][1];}
        }
    else
        {for(int j = 0; j < 256 ; j++)
            {kspace[i][j][0] = ksp[i][j][0];
                kspace[i][j][1] = ksp[i][j][1];}
            }
    i = i + 1;}

 float weights[][][];

for(int m=0;m<256;m++)
    {for (int j =100; j <156 ;j++){
             if ((m >1) && (m < 256))
             {output[j-100][0] = kspace[j][m][0];
                output[j-100][0] = kspace[j][m][0];
             input[j-100][1] = kspace[j-1][m-1][1];
             input[j-100][2] = kspace[j-1][m][1];
             input[j-100][3] = kspace[j-1][m+1][1];
             input[j-100][4] = kspace[j+1][m-1][1];
             input[j-100][5] = kspace[j+1][m][1];
             input[j-100][6] = kspace[j+1][m+1][1];
             input[j-100][7] = kspace[j-1][m-1][2];
             input[j-100][8]= kspace[j-1][m][2];
             input[j-100][9]= kspace[j-1][m+1][2];
             input[j-100][10] = kspace[j+1][m-1][2];
             input[j-100][11] = kspace[j+1][m][2];
             input[j-100][12] = kspace[j+1][m+1][2];}
             
        else if (m ==1)
                   {output[j-100][0] = kspace[j][m][0];
                output[j-100][0] = kspace[j][m][0];
             input[j-100][1] = 0;
             input[j-100][2] = kspace[j-1][m][1];
             input[j-100][3] = kspace[j-1][m+1][1];
             input[j-100][4] = 0;
             input[j-100][5] = kspace[j+1][m][1];
             input[j-100][6] = kspace[j+1][m+1][1];
             input[j-100][7] = 0;
             input[j-100][8]= kspace[j-1][m][2];
             input[j-100][9]= kspace[j-1][m+1][2];
             input[j-100][10] = 0;
             input[j-100][11] = kspace[j+1][m][2];
             input[j-100][12] = kspace[j+1][m+1][2];}
             
        else if (m==256)
                {output[j-100][0] = kspace[j][m][0];
                output[j-100][0] = kspace[j][m][0];
             input[j-100][1] = kspace[j-1][m-1][1];
             input[j-100][2] = kspace[j-1][m][1];
             input[j-100][3] = 0;
             input[j-100][4] = kspace[j+1][m-1][1];
             input[j-100][5] = kspace[j+1][m][1];
             input[j-100][6] = 0;
             input[j-100][7] = kspace[j-1][m-1][2];
             input[j-100][8]= kspace[j-1][m][2];
             input[j-100][9]= 0;
             input[j-100][10] = kspace[j+1][m-1][2];
             input[j-100][11] = kspace[j+1][m][2];
             input[j-100][12] = 0;}}

    /*ans = (inv(((input)')*(input)))*(((input)')*(output));
    weights(:,:,m) = ans;*/
}
                                                      



for(int m=0; m <256;m++){
for ( int i = 0; i < 100 ; i++){
        if (i % 2 ==1)
            {for(int j=0; j< 256; j++)
                {for (int m = 0; m< 2; m++)
                    {final[i][j][m] = kspace [i][j][m];}}
            }
        else
              {  in[1][2] = kspace[i-1][m][1];
                in[1][8]= kspace[i-1][m][2];
                in[1][5] = kspace[i+1][m][1];
                in[1][11] = kspace[i+1][m][2];

            if (m >1 && m < 256)
                {in[1][1] = kspace[i-1][m-1][1];
                in[1][10] = kspace[i+1][m-1][2];
                in[1][7] = kspace[i-1][m-][2];
                in[1][4] = kspace[i+1][m-1][1];
               in[1][3] = kspace[i-1][m+1][1];
               in[1][6] = kspace[i+1][m+1][1];
                in[1][9] = kspace[i-1][m+1][2];
                in[1][12] = kspace[i+1][m+1][2];}
            else if (m==1)
                {in[1][3] = kspace[i-1][m+1][1];
               in[1][6]= kspace[i+1][m+1][1];
                in[1][9] = kspace[i-1][m+1][2];
                in[1][12] = kspace[i+1][m+1][2];
                in[1][1] = 0;
                in[1][10] = 0;
                in[1][7]= 0;
                in[1][4] = 0;}
            else if (m == 256)
                {in[1][1] = kspace[i-1][m-1][1];
                in[1][10] = kspace[i+1][m-1][2];
                in[1][7] = kspace[i-1][m-1][2];
                in[1][4] = kspace[i+1][m-1][1];
                   in[1][3] = 0;
               in[1][6] = 0;
                in[1][9] = 0;
                in[1][12] = 0;}}
        final(i,m,:) = (in)*(weights(:,:,m));

    for ( int i = 100; i<156;i++)
        {final[j][m][0] = kspace[j][m][0];
            final[j][m][1] = kspace[j][m][1];}


    for ( int i = 156; i<256;i++)
        {if (i % 2 ==0)
            {for(int j=0; j< 256; j++)
                {for (int z = 0; z< 2; z++)
                    {final[i][j][z] = kspace [i][j][z];}}
                }
        else
               { in[1][2] = kspace[i-1][m][1];
                in[1][8]= kspace[i-1][m][2];
                in[1][5] = kspace[i+1][m][1];
                in[1][11] = kspace[i+1][m][2];
            if (m >1 && m < 256)
               {in[1][1] = kspace[i-1][m-1][1];
                in[1][10] = kspace[i+1][m-1][2];
                in[1][7] = kspace[i-1][m-][2];
                in[1][4] = kspace[i+1][m-1][1];
               in[1][3] = kspace[i-1][m+1][1];
               in[1][6] = kspace[i+1][m+1][1];
                in[1][9] = kspace[i-1][m+1][2];
                in[1][12] = kspace[i+1][m+1][2];}
            else if (m==1)
                {in[1][3] = kspace[i-1][m+1][1];
               in[1][6]= kspace[i+1][m+1][1];
                in[1][9] = kspace[i-1][m+1][2];
                in[1][12] = kspace[i+1][m+1][2];
                in[1][1] = 0;
                in[1][10] = 0;
                in[1][7]= 0;
                in[1][4] = 0;}
            elseif (m == 256)
                {in[1][1] = kspace[i-1][m-1][1];
                in[1][10] = kspace[i+1][m-1][2];
                in[1][7] = kspace[i-1][m-1][2];
                in[1][4] = kspace[i+1][m-1][1];
                   in[1][3] = 0;
               in[1][6] = 0;
                in[1][9] = 0;
                in[1][12] = 0;}}

        final(i,m,:) = (in)*(weights(:,:,m));

//combin = sqrt((pehla.*pehla + dusra.*dusra));
//final1 = (ifft((pehla)));
//final2 = (ifft((dusra)));
for(int i=0;i<256;i++)
{for(int j=0;j<256;j++)
{combine[i][j] = sqrt((final[i][j][0])*(final[i][j][0]) + (final[i][j][1])*(final[i][j][1])) ;
}
}

}