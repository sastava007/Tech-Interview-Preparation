#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 16

using namespace std;

void ReadMatrix(double**,int);
void WriteMatrix(double**,int);

void MatrixAdd(double **A, double **B, double **Result, int N);
void MatrixSubtrac(double **A, double **B, double **Result, int N);

void StrassenAlgorithm(double **A, double **B, double **C, int N);


/* For taking input from standard input(keyboard)*/
void ReadMatrix(double A[][SIZE],int N)
{
    int i,j;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
}

/*For printing the matrix in standard output(console)*/
void WriteMatrix(double A[][SIZE], int N)
{
    int i, j;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%0.1lf \t", A[i][j]);
        }
        printf("\n");
    }
}

/*This function will add two square matrix*/
void MatrixAdd(double A[][SIZE], double B[][SIZE], double Result[][SIZE], int N)
{
    int i, j;

    for(i=0; i< N; i++)
    {
        for(j=0; j<N; j++)
        {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }

}

/*This function will subtract one  square matrix from another*/
void MatrixSubtrac(double A[][SIZE], double B[][SIZE], double Result[][SIZE], int N)
{
    int i, j;

    for(i=0; i< N; i++)
    {
        for(j=0; j<N; j++)
        {
            Result[i][j] = A[i][j] - B[i][j];
        }
    }
}


/*This is the strassen algorithm. (Divide and Conqure)*/
void StrassenAlgorithm(double A[][SIZE], double B[][SIZE], double C[][SIZE], int N)
{
    // trivial case: when the matrice is 1 X 1:
    if(N == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // other cases are treated here:
    else
    {
        int Divide  = (int)(N/2);

        double A11[SIZE][SIZE], A12[SIZE][SIZE], A21[SIZE][SIZE], A22[SIZE][SIZE];
        double B11[SIZE][SIZE], B12[SIZE][SIZE], B21[SIZE][SIZE], B22[SIZE][SIZE];
        double C11[SIZE][SIZE], C12[SIZE][SIZE], C21[SIZE][SIZE], C22[SIZE][SIZE];
        double P1[SIZE][SIZE], P2[SIZE][SIZE], P3[SIZE][SIZE], P4[SIZE][SIZE], P5[SIZE][SIZE], P6[SIZE][SIZE], P7[SIZE][SIZE];
        double AResult[SIZE][SIZE], BResult[SIZE][SIZE];

        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < Divide; i++)
        {
            for (j = 0; j < Divide; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + Divide];
                A21[i][j] = A[i + Divide][j];
                A22[i][j] = A[i + Divide][j + Divide];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + Divide];
                B21[i][j] = B[i + Divide][j];
                B22[i][j] = B[i + Divide][j + Divide];
            }
        }

        // Calculating p1 to p7:
        /*For details -- Introduction to Algorithms 3rd Edition by CLRS*/

        MatrixAdd(A11, A22, AResult, Divide);   // a11 + a22
        MatrixAdd(B11, B22, BResult, Divide);   // b11 + b22
        StrassenAlgorithm(AResult, BResult, P1, Divide);  // p1 = (a11+a22) * (b11+b22)

        MatrixAdd(A21, A22, AResult, Divide);   // a21 + a22
        StrassenAlgorithm(AResult, B11, P2, Divide); // p2 = (a21+a22) * (b11)

        MatrixSubtrac(B12, B22, BResult, Divide); // b12 - b22
        StrassenAlgorithm(A11, BResult, P3, Divide); // p3 = (a11) * (b12 - b22)

        MatrixSubtrac(B21, B11, BResult, Divide); // b21 - b11
        StrassenAlgorithm(A22, BResult, P4, Divide); // p4 = (a22) * (b21 - b11)

        MatrixAdd(A11, A12, AResult, Divide); // a11 + a12
        StrassenAlgorithm(AResult, B22, P5, Divide); // p5 = (a11+a12) * (b22)

        MatrixSubtrac(A21, A11, AResult, Divide); // a21 - a11
        MatrixAdd(B11, B12, BResult, Divide); // b11 + b12
        StrassenAlgorithm(AResult, BResult, P6, Divide); // p6 = (a21-a11) * (b11+b12)

        MatrixSubtrac(A12, A22, AResult, Divide); // a12 - a22
        MatrixAdd(B21, B22, BResult, Divide); // b21 + b22
        StrassenAlgorithm(AResult, BResult, P7, Divide); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        MatrixAdd(P3, P5, C12, Divide); // c12 = p3 + p5
        MatrixAdd(P2, P4, C21, Divide); // c21 = p2 + p4

        MatrixAdd(P1, P4, AResult, Divide); // p1 + p4
        MatrixAdd(AResult, P7, BResult, Divide); // p1 + p4 + p7
        MatrixSubtrac(BResult, P5, C11, Divide); // c11 = p1 + p4 - p5 + p7

        MatrixAdd(P1, P3, AResult, Divide); // p1 + p3
        MatrixAdd(AResult, P6, BResult, Divide); // p1 + p3 + p6
        MatrixSubtrac(BResult, P2, C22, Divide); // c22 = p1 + p3 - p2 + p6


        // Grouping the results obtained in a single matrice:

        for (i = 0; i < Divide ; i++)
        {
            for (j = 0 ; j < Divide ; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + Divide] = C12[i][j];
                C[i + Divide][j] = C21[i][j];
                C[i + Divide][j + Divide] = C22[i][j];
            }
        }

    }

}

/*The main function*/
int main()
{
    double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int i,j;
    int N,M,Count = 0;

    printf("What Is The Dimention: ");
    scanf("%d",&N);

    M = N;

    printf("Matrix A:\n");
    ReadMatrix(A,M);
    printf("Matrix B:\n");
    ReadMatrix(B,M);

    if(M > 1)
    {

        while(M>=2)
        {
            M/=2;
            Count++;
        }

        M = N;

        if(M != (pow(2.0,Count)))
        {
            N = pow(2.0,Count+1);

            for(i=0; i<N; i++)
            {
                for(j=0; j<N; j++)
                {
                    if((i>=M) || (j>=M))
                    {
                        A[i][j] = 0.0;
                        B[i][j] = 0.0;
                    }
                }
            }
        }
    }

    StrassenAlgorithm(A,B,C,N); // StrassenAlgorithm called here

    printf("Matrix A:\n\n");
    WriteMatrix(A,M);
    printf("Matrix B:\n\n");
    WriteMatrix(B,M);
    printf("The Product Of These Two Matrix:\n\n");
    WriteMatrix(C,M);

    return 0;

}
