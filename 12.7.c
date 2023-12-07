#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr1[10000] = { '\0' };
void merge(int* arr, int start, int mid, int end)
{
    int a = 0, b = 0, c = mid, d = start, e;
    e = sizeof(arr) / sizeof(arr[0]);
    for (a = 0; a < e; a++)
    {
        arr1[a] = arr[a];
    }
    for (a = 0; a < end - start; a++)
    {
        if (arr1[d] < arr1[c])
        {
            arr[a] = arr1[d];
            d++;
        }
        else
        {
            arr[a] = arr1[c];
            c++;
        }
        while (d == mid && end > c)
        {
            arr[a++] = arr1[c++];
        }
        while (c == end && mid > d)
        {
            arr[a++] == arr1[d++];
        }
    }

}
void mergeSort(int* arr, int start, int end)
{

    int mid = 0;
    if (start == end)
        arr[start] = arr[end];
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return;
}
int main() {
    // length of array
    int n;
    scanf("%d", &n);

    // initial array
    int* arr = (int*)malloc(sizeof(int) * (n));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    // sorting
    mergeSort(arr, 0, n - 1);

    // print array
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    free(arr);
    return 0;
}
//#define ROW 3
//#define COL 3
//
//void matrixInput(int(*mat)[COL]);
//void matrixPrint(int* mat[ROW]);
//void matrixAddT(int* mat);
//
//
//void matrixInput(int(*mat)[COL])
//{
//    int a = 0, b = 0;
//    for (a = 0; a < 3; a++)
//    {
//        for (b = 0; b < 3; b++)
//        {
//            scanf("%d", &(*(*(mat+a)+b)));//*(mat+a)[b]
//        }
//    }
//}
//void matrixPrint(int* mat[ROW])
//{
//    for (int a = 0; a < 3; a++)
//    {
//        for (int b = 0; b < 3; b++)
//        {
//            printf("%-3d", mat[a][b]);
//        }
//        printf("\n");
//    }
//}
//void matrixAddT(int* mat)
//{
//    for (int a = 0; a < 9; a++)
//    {
//        if (a != 0 && a != 4 && a != 8)
//        {
//            if (a == 1)
//                mat[1] = mat[1] + mat[3];
//            else if (a == 2)
//                mat[2] = mat[2] + mat[6];
//            else if (a == 3)
//                mat[3] = mat[3] + mat[1];
//            else if (a == 5)
//                mat[5] = mat[5] + mat[7];
//            else if (a == 6)
//                mat[6] = mat[6] + mat[2];
//            else if (a == 7)
//                mat[7] = mat[7] + mat[5];
//        }
//        else
//            mat[a] *= 2;
//    }
//}
//int main()
//{
//    int mat[ROW][COL];
//
//    // printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
//    matrixInput(mat);
//
//    // call function to add mat with mat.T
//    matrixAddT(mat);
//
//    int* p[ROW] = { NULL, NULL, NULL };
//    for (int row = 0; row < ROW; row++)
//        *(p + row) = *(mat + row);
//
//    // print result
//    matrixPrint(p);
//
//    return 0;
//}