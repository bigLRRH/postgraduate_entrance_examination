#include <iostream>
#include <cstdio>
#define MAXSIZE 100
typedef int ElemType;
typedef struct SeqList
{
    ElemType data[MAXSIZE];
    int length;
};

// 二.综合应用题
// 1
bool del_min(SeqList &L, ElemType &value)
{
    if (L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 2
void reverse(SeqList &L)
{
    for (int i = 0; i < L.length / 2; i++)
    {
        ElemType temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

// 3
void del_x(SeqList &L, ElemType x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 4
void del_s_t(SeqList &L, ElemType s, ElemType t)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

// 5
void del_same(SeqList &L)
{
    int k = 1;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] != L.data[i - 1])
        {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}

// 6
void merge_sortedSeqList(SeqList &A, SeqList &B, SeqList &C)
{
    int index_A = 0, index_B = 0, index_C = 0;
    while (index_A < A.length && index_B < B.length)
    {
        if (A.data[index_A] <= B.data[index_B])
        {
            C.data[index_C++] = A.data[index_A++];
        }
        else
        {
            C.data[index_C++] = B.data[index_B++];
        }
    }
    while (index_A < A.length)
    {
        C.data[index_C++] = A.data[index_A++];
    }
    while (index_B <= B.length)
    {
        C.data[index_C++] = B.data[index_B++];
    }
    C.length = index_C;
}

// 7
void reverse(SeqList &L, int left, int right)
{
    while (left < right)
    {
        ElemType temp = L.data[left];
        L.data[left] = L.data[right];
        L.data[right] = temp;
        ++left;
        --right;
    }
}
void exchange(SeqList &L, int m, int n)
{
    reverse(L, 0, m - 1);
    reverse(L, m, m + n - 1);
    reverse(L, 0, m + n - 1);
}

// 8
void searchInsert(SeqList &L, ElemType x)
{
    int left = 0, right = L.length - 1, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (L.data[mid] < x)
        {
            left = mid + 1;
        }
        else if (L.data[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            break;
        }
    }
    if (L.data[mid] == x)
    {
        ElemType temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }
    else
    {
        for (int i = L.length; i > mid; i--)
        {
            L.data[i] = L.data[i - 1];
        }
        L.data[mid] = x;
    }
}

// 9
void print_same(SeqList &A, SeqList &B, SeqList &C, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n)
    {
        if (A.data[i] == B.data[j] && B.data[j] == C.data[k])
        {
            std::cout << A.data[i] << std::endl;
            ++i;
            ++j;
            ++k;
        }
        else
        {
            int max = A.data[i];
            if (max < B.data[j])
                max = B.data[j];
            if (max < C.data[k])
                max = C.data[k];

            if (A.data[i] < max)
                i++;
            if (B.data[j] < max)
                j++;
            if (C.data[k] < max)
                k++;
        }
    }
}

// 10
void reverse(int r[], int from, int to)
{
    for (int i = 0; i < (from - to) / 2; ++i)
    {
        int temp = r[from + i];
        r[from + i] = r[to - i];
        r[to - i] = temp;
    }
}
void cycle_left(int r[], int n, int p)
{
    reverse(r, 0, p - 1);
    reverse(r, p, n - 1);
    reverse(r, 0, n - 1);
}

// 11
int get_median(ElemType s1[], ElemType s2[], int length)
{
    int s1_index = 0, s2_index = 0;
    int cnt = 0;
    int median1 = 0, median2 = 0;
    while (cnt < length)
    {
        if (s1[s1_index] <= s2[s2_index])
        {
            median1 = s1[s1_index++];
        }
        else
        {
            median1 = s2[s2_index++];
        }
    }
    if (s1[s1_index] <= s2[s2_index])
    {
        median2 = s1[s1_index];
    }
    else
    {
        median2 = s1[s1_index];
    }
    return (median1 + median2) / 2;
}

// 12
int get_main_element(int A[], int n)
{
    int e = A[0], count = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == e)
        {
            ++count;
        }
        else
        {
            if (count > 0)
            {
                --count;
            }
            else
            {
                e = A[i];
                count = 1;
            }
        }
    }
    if (count > 0)
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == e)
                count++;
        }
    }
    if (count > n / 2)
        return e;
    else
        return -1;
}

// 13
int find_miss_min(int a[], int n)
{
    int result = 0;
    int *is_included = new int[n + 2];
    for (int i = 0; i < n; i++)
        is_included[i] = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0 && a[i] <= n + 1)
            ++is_included[a[i]];
    for (int i = 0; i <= n + 2; i++)
        if (is_included[i] == 0)
            result = i;
    delete is_included;
    return result;
}

// 14
int abs(int a)
{
    return a < 0 ? -a : a;
}
bool is_min(int a, int b, int c)
{
    return a <= b && a <= c ? true : false;
}
int findMinDistance(int A[], int n, int B[], int m, int C[], int p)
{
    int i = 0, j = 0, k = 0, d_min = 0x7fffffff;
    while (i < n && j < m && k < p && d_min > 0)
    {
        int d = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
        if (d < d_min)
            d_min = d;
        if (is_min(A[i], B[j], C[k]))
            i++;
        else if (is_min(B[j], A[i], C[k]))
            j++;
        else
            k++;
    }
    return d_min;
}

int main()
{
    SeqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 5;
    L.data[4] = 5;
    L.data[5] = 6;
    L.length = 6;
    return 0;
}