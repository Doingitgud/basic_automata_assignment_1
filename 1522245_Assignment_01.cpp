#include<iostream>
#include <fstream>
using namespace std;
void displayArray(char *A, int s);
void intersectionOperation(char *A, char *B, int x,int y);
void unionOperation(char *A, char *B, int x, int y);
void differenceOperation(char *A, char *B, int x, int y);
void complementOperation(char *A, char *B, int x, int y, char *U);
int main()
{


    char *A,*B;
    char U[]= {'0','1','2','3','4','5','6','7','8','9'};
    cout<<"U = {";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
        {
            cout<<U[i];
        }
        else
        {
            cout<<U[i]<<",";
        }
    }
    cout<<"}"<<endl;
//-----------------------------Set A ---------------------------------------------------------------------------------------
    ifstream inFileA;
    string s="";
    inFileA.open("inputfileA.txt");
    if (!inFileA)
    {
        cout << "File not found in the directory";
    }
    inFileA>>s;
    inFileA.close();
    int i=0, commaCounterA=0, indexSizeA=0, initializerA=0;
    while(s[i]!=NULL)
    {
        i++;
    }
    for(int a=0; a<i; a++)
    {
        if(s[a]==',')
        {
            commaCounterA++;
        }
    }
    indexSizeA=i-commaCounterA;
    A=new char[indexSizeA];
    for(int a=0; a<i; a++)
    {
        if(s[a]!=',')
        {
            A[initializerA]=s[a];
            initializerA++;
        }
    }
    cout<<"A = {";
    displayArray(A,indexSizeA);
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------Set B -------------------------------------------------------------------------------
    ifstream inFileB;
    string t="";
    inFileB.open("inputfileB.txt");
    if (!inFileB)
    {
        cout << "File not found in the directory";
    }
    inFileB>>t;
    inFileB.close();
    int j=0, commaCounterB=0, indexSizeB=0, initializerB=0;
    while(t[j]!=NULL)
    {
        j++;
    }
    for(int a=0; a<j; a++)
    {
        if(t[a]==',')
        {
            commaCounterB++;
        }
    }
    indexSizeB=j-commaCounterB;
    B=new char[indexSizeB];
    for(int a=0; a<j; a++)
    {
        if(t[a]!=',')
        {
            B[initializerB]=t[a];
            initializerB++;
        }
    }
    cout<<"B = {";
    displayArray(B,indexSizeB);

//------------------------------------------------------------------------------------------------------------------------
    cout<<"\nPress U for union operation.";
    cout<<"\nPress I for intersection operation. ";
    cout<<"\nPress D for difference operation ";
    cout<<"\nPress C for complement operation \n";
    char selection;
    cin>>selection;
    if(selection=='U')
    {
        unionOperation(A,B,indexSizeA,indexSizeB);
    }
    else if(selection=='I')
    {
        intersectionOperation(A,B,indexSizeA,indexSizeB);
    }

    else if(selection=='D')
    {
        differenceOperation(A,B,indexSizeA,indexSizeB);
    }
    else if(selection=='C')
    {
        cout<<"Complement operations :  \n";
        complementOperation(A,B,indexSizeA,indexSizeB,U);
    }
    else{
        cout<<"Incorrect input please try again\n";
    }


    return 0;
}
void displayArray(char *A, int s)
{
    for(int i=0; i<s; i++)
    {
        if(i==s-1)
        {
            cout<<A[i];
        }
        else
        {
            cout<<A[i]<<",";
        }
    }
    cout<<"}";
    cout<<endl;
}
void intersectionOperation(char *A, char *B, int x,int y)
{
    int k=0;
    char *intersectionArray;
    if(x<=y)
    {
        intersectionArray=new char[x];
    }
    else
    {
        intersectionArray=new char[y];
    }
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(A[i]==B[j])
            {
                intersectionArray[k]=B[j];
                k++;
            }
        }
    }
    cout<<"Intersection operation  :  ";
    cout<<"A ^ B = {";
    for(int i=0; i<k; i++)
    {
        if(i==k-1)
        {
            cout<<intersectionArray[i];
        }
        else
        {
            cout<<intersectionArray[i]<<",";
        }
    }
    cout<<"}"<<endl;
}
void unionOperation(char *A, char *B, int x, int y)
{
    int k = 0, z = 0;
    char *intersectionArray, *unionArray;

    if (x <= y)
    {
        intersectionArray = new char[x];
    }
    else
    {
        intersectionArray = new char[y];
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (A[i] == B[j])
            {
                intersectionArray[k] = B[j];
                k++;
            }
        }
    }
    if (k == 0)
    {
        z = x + y;
        unionArray = new char[z];
        int l = 0, r = 0;
        for (int i = 0; i < z; i++)
        {
            if (x > i)
            {
                unionArray[i] = A[i];
            }
            else
            {
                unionArray[i] = B[i - x];
            }
        }
        cout<<"A U B = {";
        for (int i = 0; i < z; i++)
        {
            if(i==z-1)
            {
                cout<<unionArray[i];
            }
            else
            {
                cout<<unionArray[i]<<",";
            }
        }
        cout<<"}"<<endl;

    }
    else
    {
        char *copy2B= new char[y - k];
        int m = 0;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (B[i] == intersectionArray[j])
                {
                    break;
                }
                if (j == k - 1)
                {
                    copy2B[m] = B[i];
                    m++;
                }
            }
        }
        z = x +y - k;
        unionArray = new char[z];
        int l = 0, r = 0;
        for (int i = 0; i < z; i++)
        {
            if (x > i)
            {
                unionArray[i] = A[i];
            }
            else
            {
                unionArray[i] = copy2B[i - x];
            }
        }
        cout<<"Union operation :  ";
        cout<<"A U B = {";
        for (int i = 0; i < z; i++)
        {
            if(i==z-1)
            {
                cout<<unionArray[i];
            }
            else
            {
                cout<<unionArray[i]<<",";
            }
        }
        cout<<"}"<<endl;

    }

}
void differenceOperation(char *A, char *B, int x, int y)
{
    int k = 0;
    char *intersectionArray;

    if (x <= y)
    {
        intersectionArray = new char[x];
    }
    else
    {
        intersectionArray = new char[y];
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (A[i] == B[j])
            {
                intersectionArray[k] = B[j];
                k++;
            }
        }
    }
    if (k == 0)
    {
        cout<<"A - B = {";
        for (int i = 0; i < x; i++)
        {
            if (i == x - 1)
            {
                cout<<A[i];
            }
            else
            {
                cout<<A[i]<<",";
            }
        }
        cout<<"}"<<endl;
    }
    else
    {
        char *copy2A = new char[x - k];
        int m = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (A[i] == intersectionArray[j])
                {
                    break;
                }
                if (j == k - 1)
                {
                    copy2A[m] = A[i];
                    m++;
                }
            }
        }
        cout<<"Difference operation :  ";
        cout<<"A - B = {";
        for (int i = 0; i < x - k; i++)
        {
            if (i == x - k - 1)
            {
                cout<<copy2A[i];
            }
            else
            {
                cout<<copy2A[i]<<",";
            }
        }
        cout<<"}"<<endl;
    }

}
void complementOperation(char *A, char *B, int x, int y, char *U)
{
    //-------------------------------------------------------------------------------------------------

    char *copy2A = new char[10-x];
    int m = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (U[i] == A[j])
            {
                break;
            }
            if (j == x - 1)
            {
                copy2A[m] = U[i];
                m++;
            }
        }
    }
    cout<<"A'  = {";
    for (int i = 0; i < 10-x; i++)
    {
        if (i == 10-x- 1)
        {
            cout<<copy2A[i];
        }
        else
        {
            cout<<copy2A[i]<<",";
        }
    }
    cout<<"}"<<endl;
//--------------------------------------------------------------------------------------------------
    char *copy2B= new char[10-y];
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (U[i] == B[j])
            {
                break;
            }
            if (j == y - 1)
            {
                copy2B[n] = U[i];
                n++;
            }
        }
    }
    cout<<"B'  = {";
    for (int i = 0; i < 10-y; i++)
    {
        if (i == 10-y- 1)
        {
            cout<<copy2B[i];
        }
        else
        {
            cout<<copy2B[i]<<",";
        }
    }
    cout<<"}"<<endl;
}
