#include <iostream>
#define ll long long
using namespace std;
long long modulo = 998244353;

//class to store and work on 2d matrices
class two_d_matrix
{
    public:
    long long **entities;
    int dimensions;
    //constructor
    two_d_matrix(int size)
    {
        dimensions = size;
        entities = new ll *[size];
        for (int i = 0; i < size; i++)
        {
            entities[i] = new long long[size];
            for (int j = size-1; j >=0; j--)
            {
                entities[i][j] = 0;
            }
        }
    }
    // to fill the matrix
    two_d_matrix(const two_d_matrix &b)
    {
        entities = new ll *[b.dimensions];
        for (int i = 0; i < b.dimensions; i++)
        {
            entities[i] = new ll[b.dimensions];
            for (int j = b.dimensions-1; j >=0; j--)
            {
                entities[i][j] = b.entities[i][j]%modulo;
            }
        }
    }

    ~two_d_matrix() //destructor
    {
        for (int i = 0; i < dimensions; i++)
        {
            delete[] entities[i];
        }
        delete[] entities;
    }

    void operator=(const two_d_matrix &b)
    {
        for (int i = 0; i < b.dimensions; i++)
        {
            for (int j = 0; j < dimensions; j++)
            {
                entities[i][j] = b.entities[i][j]%modulo;
            }
        }
    }
};
void poduct(const two_d_matrix &a,const two_d_matrix &b, two_d_matrix &res);

void exponent(const two_d_matrix &a, long long n, two_d_matrix &res)
{
    if (n == 1)
    {
        res = a;
        return ;
    }
    two_d_matrix temp(a.dimensions);

    exponent(a, n / 2, temp);

    poduct(temp, temp, temp);

    if (n % 2 == 1)
    {
        poduct(temp, a, temp);
    }
    res = temp;
}

void poduct(const two_d_matrix &a,const two_d_matrix &b, two_d_matrix &res)
{
    two_d_matrix temp(a.dimensions);
    for (int i = 0; i < a.dimensions; i++)
    {
        for (int j = 0; j < b.dimensions; j++)
        {
            for (int k = 0; k < b.dimensions; k++)
            {
                temp.entities[i][j] += a.entities[i][k] * b.entities[k][j];
                temp.entities[i][j] %= modulo;
            }
        }
    }
    res = temp;
}

void take_input(two_d_matrix &A)
{
    int k = A.dimensions;
    for(int i = 0; i<k; i++)
    {
        A.entities[0][i] = 1;
    }
    for(int i = 1; i<k; i++)
    {
        for(int j = 0; j<k; j++)
        {
            if(i-1 == j)
            {
                A.entities[i][j] = 1;
            }
        }
    }
}

long long solve(long long n, int k)
{
    two_d_matrix A(k);
    take_input(A);
    exponent(A, n, A);
    return A.entities[0][0];
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        long long n;
        int k;
        cin >> n >> k;
        long long x=solve(n, k);
        cout << x <<endl;
    }
    return 0;
}