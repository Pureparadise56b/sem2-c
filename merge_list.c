/* Q. Merge two input sorted lists into a single sorted list.
Here lists are stored in the respective one-dimensional array.
*/

#include <stdio.h>
#include <stdlib.h>

/* ReadList() function is used to read a list of elements from user.*/
void ReadList(float *A, int n)
{
  int i;
  if (n <= 0)
  {
    printf("\nInvalid List Size");
    return;
  }
  for (i = 0; i < n; i++)
  {
    printf("Element#%d=", i);
    scanf("%f", &A[i]);
  }
}
/* PrintList() function is used to print / display
the elements of the list */
void PrintList(float *A, int n)
{
  int i;
  if (n <= 0)
  {
    printf("\nInvalid List Size");
    return;
  }
  printf("[");
  for (i = 0; i < n; i++)
    printf("%.2f ", A[i]);
  printf("]");
}

/* IsSorted() function is used to check whether the input list is
sorted in ascending order or not. */
int IsSorted(float *L, int n)
{
  int i;
  if (n <= 0)
  {
    printf("\nInvalid List Size");
    return 0;
  }
  for (i = 0; i < (n - 1); i++)
  {
    if (L[i] > L[i + 1])
      return 0;
  }
  return 1;
}
/* A & B - are input sorted lists
n & m - are the sizes of the lists.
Merge() - merges these two sorted lists into a single sorted list.*/
float *Merge(float *A, int m, float *B, int n)
{
  int p = 0, q = 0, r = 0;
  float *C;
  if (m <= 0 || n <= 0)
  {
    printf("\nInvalid List Size");
    return NULL;
  }
  C = (float *)malloc((m + n) * sizeof(float));
  /*Starting from the beginning of both the lists A and B take the smaller data in the
  output list until any of the list is becoming exhausted. Then copy the rest part of
  the other list into the output list. */
  while (p < m && q < n)
  {
    if (A[p] < B[q])
    {
      C[r] = A[p];
      p++;
    }
    else
    {
      C[r] = B[q];
      q++;
    }
    r++;
  }
  // copy the unmerged part
  while (p < m)
  {
    C[r] = A[p];
    r++;
    p++;
  }
  while (q < n)
  {
    C[r] = B[q];
    r++;
    q++;
  }
  return C;
}

int main()
{
  float *L1, *L2, *L;
  int m, n;
  printf("\nEnter the size of the first list (m):");
  scanf("%d", &m);
  L1 = (float *)malloc(m * sizeof(float));
Lbl1:
  printf("\nEnter elements of the 1st Sorted List(L1):\n");
  ReadList(L1, m);
  if (!IsSorted(L1, m))
  {
    printf("\nEntered List is not sorted.");
    goto Lbl1;
  }
  printf("\nEnter the size of the 2nd list (n):");
  scanf("%d", &n);
  L2 = (float *)malloc(n * sizeof(float));
Lbl2:
  printf("\nEnter elements of the 2nd Sorted List(L2):\n");
  ReadList(L2, n);
  if (!IsSorted(L2, n))
  {
    printf("\nEntered List is not sorted.");
    goto Lbl2;
  }
  printf("\n\nInput Lists\n");
  printf("L1=");
  PrintList(L1, m);
  printf("\nL2=");
  PrintList(L2, n);
  L = Merge(L1, m, L2, n);
  printf("\n\nOutput Sorted List:\nL=");
  PrintList(L, m + n);
  printf("\n\n");
}