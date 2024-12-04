#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPerfectMagicSquare(int n, int a[n + 1][n + 1])
{
    int freq[n * n + 1];
    for (int i = 1; i <= n * n; i++)
    {
        freq[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] < 1 || a[i][j] > n * n)
            {
                return false;
            }
            freq[a[i][j]]++;
        }
    }
    for (int i = 1; i <= n * n; i++)
    {
        if (freq[i] != 1)
        {
            return false;
        }
    }
    int desiredSum = n * (n * n + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        int rowSum = 0, colSum = 0;
        for (int j = 1; j <= n; j++)
        {
            rowSum += a[i][j];
            colSum += a[j][i];
        }
        if (rowSum != desiredSum || colSum != desiredSum)
        {
            return false;
        }
    }
    int mainDiagSum = 0, secDiagSum = 0;
    for (int i = 1; i <= n; i++)
    {
        mainDiagSum += a[i][i];
        secDiagSum += a[i][n - i + 1];
    }
    if (mainDiagSum != desiredSum || secDiagSum != desiredSum)
    {
        return false;
    }
    return true;
}
bool isPerfectMagicSquareDoubly(int n, int a[n][n])
{
    int freq[n * n + 1];
    for (int i = 1; i <= n * n; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 1 || a[i][j] > n * n)
            {
                return false;
            }
            freq[a[i][j]]++;
        }
    }
    for (int i = 1; i <= n * n; i++)
    {
        if (freq[i] != 1)
        {
            return false;
        }
    }
    int desiredSum = n * (n * n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++)
        {
            rowSum += a[i][j];
            colSum += a[j][i];
        }
        if (rowSum != desiredSum || colSum != desiredSum)
        {
            return false;
        }
    }
    int mainDiagSum = 0, secDiagSum = 0;
    for (int i = 0; i < n; i++)
    {
        mainDiagSum += a[i][i];
        secDiagSum += a[i][n - i - 1];
    }
    if (mainDiagSum != desiredSum || secDiagSum != desiredSum)
    {
        return false;
    }
    return true;
}
void doubly_even(int n)
{
    int a[n][n];
    int smallSquareSize = (n / 4);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < smallSquareSize; i++)
    {
        for (int j = 0; j < smallSquareSize; j++)
        {
            a[i][j] = -1;
        }
    }

    int LeftupperCorner = n - smallSquareSize;
    for (int i = 0; i < smallSquareSize; i++)
    {
        for (int j = LeftupperCorner; j < n; j++)
        {
            a[i][j] = -1;
        }
    }

    int downLeft = n - smallSquareSize;
    for (int i = downLeft; i < n; i++)
    {
        for (int j = 0; j < smallSquareSize; j++)
        {
            a[i][j] = -1;
        }
    }

    int rightDown = n - smallSquareSize;
    for (int i = rightDown; i < n; i++)
    {
        for (int j = rightDown; j < n; j++)
        {
            a[i][j] = -1;
        }
    }

    int middleFstIndx = smallSquareSize;
    for (int i = middleFstIndx; i < n - smallSquareSize; i++)
    {
        for (int j = middleFstIndx; j < n - smallSquareSize; j++)
        {
            a[i][j] = -1;
        }
    }
    int *v = (int *)malloc(n * n * sizeof(int));
    int v_size = 0;
    int InitialIndx = 1;
    int step = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                a[i][j] = InitialIndx++;

                int totalWidth = n * 5 + 2;
                int stepTextWidth = 8;
                int leftPadding = (totalWidth - stepTextWidth) / 2;
                for (int i = 0; i < leftPadding; i++) printf(" ");
                printf("Step :%d\n", step++);
                for (int k = 0; k < n * 5 + 2; k++) printf("_");
                printf("\n");

                for (int r = 0; r < n; r++)
                {
                    int rowSum = 0;
                    printf("|");
                    for (int c = 0; c < n; c++)
                    {
                        printf("%4d ", a[r][c]);
                        if (a[r][c] >= 0) rowSum += a[r][c];
                    }
                    if (rowSum < 0)
                        printf("|  %4d\n\n", 0);
                    else
                        printf("|  %4d\n\n", rowSum);
                }

                for (int k = 0; k < n * 5 + 2; k++) printf("-");
                printf("\n");

                printf("|");
                for (int c = 0; c < n; c++)
                {
                    int colSum = 0;
                    for (int r = 0; r < n; r++)
                    {
                        if (a[r][c] >= 0) colSum += a[r][c];
                    }
                    if (colSum < 0)
                        printf("%4d ", 0);
                    else
                        printf("%4d ", colSum);
                }
                printf("|\n");

                int mainDiagSum = 0, secDiagSum = 0;
                for (int d = 0; d < n; d++)
                {
                    if (a[d][d] >= 0) mainDiagSum += a[d][d];
                    if (a[d][n - d - 1] >= 0) secDiagSum += a[d][n - d - 1];
                }
                printf("\nMain diagonal sum: %d\n", mainDiagSum);
                printf("Secondary diagonal sum: %d\n", secDiagSum);
                if (isPerfectMagicSquareDoubly(n, a))
                {
                    printf("The current square is a perfect magic square.\n");
                }
                else
                {
                    printf("The current square is NOT a perfect magic square.\n");
                }
            }
            else
            {
                v[v_size++] = InitialIndx++;
            }
        }
    }

    int v_index = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i][j] == 0)
            {
                a[i][j] = v[v_index++];
                int totalWidth = n * 5 + 2;
                int stepTextWidth = 8;
                int leftPadding = (totalWidth - stepTextWidth) / 2;
                for (int i = 0; i < leftPadding; i++) printf(" ");
                printf("Step :%d\n", step++);
                for (int k = 0; k < n * 5 + 2; k++) printf("_");
                printf("\n");
                for (int r = 0; r < n; r++)
                {
                    int rowSum = 0;
                    printf("|");
                    for (int c = 0; c < n; c++)
                    {
                        printf("%4d ", a[r][c]);
                        if (a[r][c] >= 0) rowSum += a[r][c];
                    }
                    if (rowSum < 0)
                        printf("|  %4d\n\n", 0);
                    else
                        printf("|  %4d\n\n", rowSum);
                }
                for (int k = 0; k < n * 5 + 2; k++) printf("-");
                printf("\n");
                printf("|");
                for (int c = 0; c < n; c++)
                {
                    int colSum = 0;
                    for (int r = 0; r < n; r++)
                    {
                        if (a[r][c] >= 0) colSum += a[r][c];
                    }
                    if (colSum < 0)
                        printf("%4d ", 0);
                    else
                        printf("%4d ", colSum);
                }
                printf("|\n");

                int mainDiagSum = 0, secDiagSum = 0;
                for (int d = 0; d < n; d++)
                {
                    if (a[d][d] >= 0) mainDiagSum += a[d][d];
                    if (a[d][n - d - 1] >= 0) secDiagSum += a[d][n - d - 1];
                }
                printf("\nMain diagonal sum: %d\n", mainDiagSum);
                printf("Secondary diagonal sum: %d\n", secDiagSum);
                if (isPerfectMagicSquareDoubly(n, a))
                {
                    printf("The current square is a perfect magic square.\n");
                }
                else
                {
                    printf("The current square is NOT a perfect magic square.\n");
                }
            }
        }
    }
    free(v);
}
void single_even(int n)
{
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    int stp=1;
    int j = 1, k = ((n / 2) + 1) / 2, cnt = 1;
    for (int i = 1; i <= (n / 2) * (n / 2); i++)
    {
        int totalWidth = n * 5 + 2;
        int stepTextWidth = 8;
        int leftPadding = (totalWidth - stepTextWidth) / 2;
        for (int i = 0; i < leftPadding; i++) printf(" ");
        printf("Step %d", stp);
        stp++;
        a[j][k] = cnt;
        cnt++;

        j--, k++;

        if (j == 0 && k == (n / 2) + 1)
        {
            j += 2, k -= 1;
        }
        else if (j == 0)
        {
            j = n / 2;
        }
        else if (k == (n / 2) + 1)
        {
            k = 1;
        }
        else if (a[j][k] != 0)
        {
            j += 2, k -= 1;
        }
        printf("\n+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        for (int r = 1; r <= n; r++)
        {
            int rowSum = 0;
            printf("|");
            for (int c = 1; c <= n; c++)
            {
                printf("%4d ", a[r][c]);
                rowSum += a[r][c];
            }
            printf("|  %3d\n\n", rowSum);
        }

        printf("+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        printf("|");
        for (int c = 1; c <= n; c++)
        {
            int colSum = 0;
            for (int r = 1; r <= n; r++)
            {
                colSum += a[r][c];
            }
            printf("%4d ", colSum);
        }
        printf("|\n");
        int mainDiagSum = 0, secDiagSum = 0;
        for (int d = 1; d <= n; d++)
        {
            mainDiagSum += a[d][d];
            secDiagSum += a[d][n - d + 1];
        }

        printf("\n");
        printf("Main diagonal sum: %d\n", mainDiagSum);
        printf("Secondary diagonal sum: %d\n", secDiagSum);
        if (isPerfectMagicSquare(n, a))
        {
            printf("The current square is a perfect magic square.\n");
        }
        else
        {
            printf("The current square is NOT a perfect magic square.\n");
        }
        printf("\n");
    }
    j = (n / 2) + 1, k = ((n / 2) + 1) / 2 + (n / 2);
    for (int i = 1; i <= (n / 2) * (n / 2); i++)
    {
        int totalWidth = n * 5 + 2;
        int stepTextWidth = 8;
        int leftPadding = (totalWidth - stepTextWidth) / 2;
        for (int i = 0; i < leftPadding; i++) printf(" ");
        printf("Step %d", stp);
        stp++;
        a[j][k] = cnt;
        cnt++;
        j--, k++;

        if (j == n / 2 && k == n + 1)
        {
            j += 2, k -= 1;
        }
        else if (j == n / 2)
        {
            j = n;
        }
        else if (k == n + 1)
        {
            k = (n / 2) + 1;
        }
        else if (a[j][k] != 0)
        {
            j += 2, k -= 1;
        }

        printf("\n+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");

        for (int r = 1; r <= n; r++)
        {
            int rowSum = 0;
            printf("|");
            for (int c = 1; c <= n; c++)
            {
                printf("%4d ", a[r][c]);
                rowSum += a[r][c];
            }
            printf("|  %3d\n\n", rowSum);
        }

        printf("+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");

        printf("|");
        for (int c = 1; c <= n; c++)
        {
            int colSum = 0;
            for (int r = 1; r <= n; r++)
            {
                colSum += a[r][c];
            }
            printf("%4d ", colSum);
        }
        printf("|\n");

        int mainDiagSum = 0, secDiagSum = 0;
        for (int d = 1; d <= n; d++)
        {
            mainDiagSum += a[d][d];
            secDiagSum += a[d][n - d + 1];
        }

        printf("\n");
        printf("Main diagonal sum: %d\n", mainDiagSum);
        printf("Secondary diagonal sum: %d\n", secDiagSum);
        if (isPerfectMagicSquare(n, a))
        {
            printf("The current square is a perfect magic square.\n");
        }
        else
        {
            printf("The current square is NOT a perfect magic square.\n");
        }
        printf("\n");
    }
    j = 1, k = ((n / 2) + 1) / 2 + (n / 2);
    for (int i = 1; i <= (n / 2) * (n / 2); i++)
    {
        int totalWidth = n * 5 + 2;
        int stepTextWidth = 8;
        int leftPadding = (totalWidth - stepTextWidth) / 2;
        for (int i = 0; i < leftPadding; i++) printf(" ");
        printf("Step %d", stp);
        stp++;
        a[j][k] = cnt;
        cnt++;

        j--, k++;

        if (j == 0 && k == n + 1)
        {
            j += 2, k -= 1;
        }
        else if (j == 0)
        {
            j = n / 2;
        }
        else if (k == n + 1)
        {
            k = (n / 2) + 1;
        }
        else if (a[j][k] != 0)
        {
            j += 2, k -= 1;
        }
        printf("\n+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        for (int r = 1; r <= n; r++)
        {
            int rowSum = 0;
            printf("|");
            for (int c = 1; c <= n; c++)
            {
                printf("%4d ", a[r][c]);
                rowSum += a[r][c];
            }
            printf("|  %3d\n\n", rowSum);
        }
        printf("+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        printf("|");
        for (int c = 1; c <= n; c++)
        {
            int colSum = 0;
            for (int r = 1; r <= n; r++)
            {
                colSum += a[r][c];
            }
            printf("%4d ", colSum);
        }
        printf("|\n");
        int mainDiagSum = 0, secDiagSum = 0;
        for (int d = 1; d <= n; d++)
        {
            mainDiagSum += a[d][d];
            secDiagSum += a[d][n - d + 1];
        }

        printf("\n");
        printf("Main diagonal sum: %d\n", mainDiagSum);
        printf("Secondary diagonal sum: %d\n", secDiagSum);
        if (isPerfectMagicSquare(n, a))
        {
            printf("The current square is a perfect magic square.\n");
        }
        else
        {
            printf("The current square is NOT a perfect magic square.\n");
        }
        printf("\n");
    }
    j = (n / 2) + 1, k = ((n / 2) + 1) / 2;
    for (int i = 1; i <= (n / 2) * (n / 2); i++)
    {
        int totalWidth = n * 5 + 2;
        int stepTextWidth = 8;
        int leftPadding = (totalWidth - stepTextWidth) / 2;
        for (int i = 0; i < leftPadding; i++) printf(" ");
        printf("Step %d", stp);
        stp++;
        a[j][k] = cnt;
        cnt++;

        j--, k++;

        if (j == n / 2 && k == (n / 2) + 1)
        {
            j += 2, k -= 1;
        }
        else if (j == n / 2)
        {
            j = n;
        }
        else if (k == (n / 2) + 1)
        {
            k = 1;
        }
        else if (a[j][k] != 0)
        {
            j += 2, k -= 1;
        }
        printf("\n+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        for (int r = 1; r <= n; r++)
        {
            int rowSum = 0;
            printf("|");
            for (int c = 1; c <= n; c++)
            {
                printf("%4d ", a[r][c]);
                rowSum += a[r][c];
            }
            printf("|  %3d\n\n", rowSum);
        }

        printf("+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");

        printf("|");
        for (int c = 1; c <= n; c++)
        {
            int colSum = 0;
            for (int r = 1; r <= n; r++)
            {
                colSum += a[r][c];
            }
            printf("%4d ", colSum);
        }
        printf("|\n");
        int mainDiagSum = 0, secDiagSum = 0;
        for (int d = 1; d <= n; d++)
        {
            mainDiagSum += a[d][d];
            secDiagSum += a[d][n - d + 1];
        }

        printf("\n");
        printf("Main diagonal sum: %d\n", mainDiagSum);
        printf("Secondary diagonal sum: %d\n", secDiagSum);
        if (isPerfectMagicSquare(n, a))
        {
            printf("The current square is a perfect magic square.\n");
        }
        else
        {
            printf("The current square is NOT a perfect magic square.\n");
        }
        printf("\n");
    }
    for(int i=1; i<=(n/2-1)/2; i++)
    {
        for(int j=1; j<=(n/2-1)/2; j++)
        {
            int t=a[i][j];

            a[i][j]=a[i+n/2][j];

            a[i+n/2][j]=t;
        }
    }

    j=(n/2+1)/2,k=2;

    for(int i=1; i<=(n/2-1)/2; i++)
    {
        int t=a[j][k];

        a[j][k]=a[j+n/2][k];

        a[j+n/2][k]=t;
        k++;
    }
    k=(n/2)/2+2;

    for(int i=1; i<=(n/2-1)/2; i++)
    {
        for(int j=1; j<=(n/2-1)/2; j++)
        {
            int t=a[k][j];

            a[k][j]=a[k+n/2][j];

            a[k+n/2][j]=t;
        }
        k++;
    }
    for(int i=1; i<=n/2; i++)
    {
        for(int j=n-((n/2-1)/2)+2; j<=n; j++)
        {
            int t=a[i][j];
            a[i][j]=a[i+n/2][j];
            a[i+n/2][j]=t;
        }
    }
    int totalWidth = n * 5 + 2;
    int stepTextWidth = 8;
    int leftPadding = (totalWidth - stepTextWidth) / 2;
    for (int i = 0; i < leftPadding; i++) printf(" ");
    printf("Step %d", stp);
    stp++;
    printf("\n+");
    for (int i = 0; i < n * 5; i++) printf("-");
    printf("+\n");
    for (int r = 1; r <= n; r++)
    {
        int rowSum = 0;
        printf("|");
        for (int c = 1; c <= n; c++)
        {
            printf("%4d ", a[r][c]);
            rowSum += a[r][c];
        }
        printf("|  %3d\n\n", rowSum);
    }

    printf("+");
    for (int i = 0; i < n * 5; i++) printf("-");
    printf("+\n");
    printf("|");
    for (int c = 1; c <= n; c++)
    {
        int colSum = 0;
        for (int r = 1; r <= n; r++)
        {
            colSum += a[r][c];
        }
        printf("%4d ", colSum);
    }
    printf("|\n");
    int mainDiagSum = 0, secDiagSum = 0;
    for (int d = 1; d <= n; d++)
    {
        mainDiagSum += a[d][d];
        secDiagSum += a[d][n - d + 1];
    }
    printf("\n");
    printf("Main diagonal sum: %d\n", mainDiagSum);
    printf("Secondary diagonal sum: %d\n", secDiagSum);
    if (isPerfectMagicSquare(n, a))
    {
        printf("The current square is a perfect magic square.\n");
    }
    else
    {
        printf("The current square is NOT a perfect magic square.\n");
    }
    printf("\n");
}
void odd(int n)
{
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    int j = 1, k = (n + 1) / 2, cnt = 1;
    for (int step = 1; step <= n * n; step++)
    {
        int totalWidth = n * 5 + 2;
        int stepTextWidth = 8;
        int leftPadding = (totalWidth - stepTextWidth) / 2;
        for (int i = 0; i < leftPadding; i++) printf(" ");
        printf("Step %d\n", step);
        printf("+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        a[j][k] = cnt;
        cnt++;
        j--, k++;
        if (j == 0 && k == n + 1)
        {
            j += 2, k -= 1;
        }
        else if (j == 0)
        {
            j = n;
        }
        else if (k == n + 1)
        {
            k = 1;
        }
        else if (a[j][k] != 0)
        {
            j += 2, k -= 1;
        }
        for (int r = 1; r <= n; r++)
        {
            int rowSum = 0;
            printf("|");
            for (int c = 1; c <= n; c++)
            {
                printf("%4d ", a[r][c]);
                rowSum += a[r][c];
            }
            printf("|  %3d\n", rowSum);
            printf("\n");
        }
        printf("+");
        for (int i = 0; i < n * 5; i++) printf("-");
        printf("+\n");
        printf("|");
        for (int c = 1; c <= n; c++)
        {
            int colSum = 0;
            for (int r = 1; r <= n; r++)
            {
                colSum += a[r][c];
            }
            printf("%4d ", colSum);
        }
        printf("|\n");
        int mainDiagSum = 0, secDiagSum = 0;
        for (int d = 1; d <= n; d++)
        {
            mainDiagSum += a[d][d];
            secDiagSum += a[d][n - d + 1];
        }
        printf("\n");
        printf("Main diagonal sum: %d\n", mainDiagSum);
        printf("Secondary diagonal sum: %d\n", secDiagSum);
        if (isPerfectMagicSquare(n, a))
        {
            printf("The current square is a perfect magic square.\n");
        }
        else
        {
            printf("The current square is NOT a perfect magic square.\n");
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    printf("========================================\n");
    printf("       Welcome to the Magic Square!     \n");
    printf("========================================\n");
    printf("Press 1 to explore the magic of numbers: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nLet's create a Magic Square!\n");
        printf("========================================\n");
        printf("Select the type of Magic Square:\n");
        printf("  1. Odd Magic Square--->(Applicable for odd number of size)\n");
        printf("  2. Even Magic Square--->(Applicable for even number of size)\n");
        printf("========================================\n");
        printf("Enter your choice (1 or 2): ");
        int n;
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            printf("\nYou chose the Odd Magic Square.\n");
            printf("Enter the size of the Magic Square (odd number): ");
            scanf("%d", &n);
            odd(n);
        }
        else if (type == 2)
        {
            printf("\nYou chose the Even Magic Square.\n");
            printf("========================================\n");
            printf("Even Magic Squares are of two types:\n");
            printf("  1. Singly Even (e.g., 6x6, 10x10)  this square size is divisible by 2 but not divisible by 4\n");
            printf("  2. Doubly Even (e.g., 4x4, 8x8)   this square size is only divisible by 4\n");
            printf("========================================\n");
            printf("Enter your choice (1 or 2): ");
            int evenType;
            scanf("%d", &evenType);

            if (evenType == 1)
            {
                printf("\nYou chose the Singly Even Magic Square.\n");
                printf("Enter the size of the Magic Square (multiple of 2 and not multiple of 4): ");
                scanf("%d", &n);
                single_even(n);
            }
            else if (evenType == 2)
            {
                printf("\nYou chose the Doubly Even Magic Square.\n");
                printf("Enter the size of the Magic Square (multiple of 4): ");
                scanf("%d", &n);
                doubly_even(n);
            }
            else
            {
                printf("\nInvalid choice for Even Magic Square. Please try again.\n");
            }
        }
        else
        {
            printf("\nInvalid choice. Please restart the program and try again.\n");
        }
    }
    else
    {
        printf("\nGoodbye! Thank you for exploring Magic Squares.\n");
    }
    printf("\n========================================\n");
    printf("       Thank you for using the program! \n");
    printf("========================================\n");
    return 0;
}
