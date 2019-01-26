void quick(int a[], int n)
{
    int p;
    p = a[0];
    particion(a, p, n);
    if (n > 1)
    {
        quick(a, p);
        quick(a + p + 1, n - p - 1);
    }
}
void particion(int a[], int p, int n)
{
    int m, q;
    while (m < p)
    {
    }
}