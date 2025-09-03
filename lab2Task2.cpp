#include <iostream>
using namespace std;

bool isUnique(int *resultArr, int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (*(resultArr + i) == val)
        {
            return false;
        }
    }

    return true;
}

int *findIntersection(int **arr1, int **arr2, int row1, int row2, int col1, int col2)
{
    int maxSize = row1 * col1, resultSize = 0, val = 0;
    int *resultArray = new int[maxSize];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {

            val = *(*(arr1 + i) + j);

            for (int k = 0; k < row2; k++)
            {
                for (int l = 0; l < col2; l++)
                {

                    if (val == *(*(arr2 + k) + l))
                    {
                        if (isUnique(resultArray, resultSize, val))
                        {
                            *(resultArray + resultSize) = val;
                            resultSize++;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < resultSize; i++)
    {
        cout << *(resultArray + i) << " ";
    }

    if (resultSize == 0)
    {
        return nullptr;
    }
    else
    {
        return resultArray;
    }
}

int main()
{
    int row1 = 3, col1 = 4, row2 = 5, col2 = 2;
    cout<<"24P-3077"<<endl;

    int **arr1 = new int *[row1];
    int **arr2 = new int *[row2];

    for (int i = 0; i < row1; i++)
    {
        *(arr1 + i) = new int[col1];
    }

    for (int i = 0; i < row2; i++)
    {
        *(arr2 + i) = new int[col2];
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            *(*(arr1 + i) + j) = i + j + 1;
        }
    }

    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            *(*(arr2 + i) + j) = i + j + 2;
        }
    }

    int *result = findIntersection(arr1, arr2, row1, row2, col1, col2);

    for (int i = 0; i < row1; i++)
    {
        delete[] *(arr1 + i);
    }

    for (int i = 0; i < row2; i++)
    {
        delete[] *(arr2 + i);
    }

    delete[] arr1;
    delete[] arr2;
    delete[] result;

    return 0;
}