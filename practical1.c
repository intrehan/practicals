
#include <stdio.h>

int main()
{
    int a[50], n=0, i, j, pos, temp;
    int key, ch, low, high, mid, found;

    do
    {
        printf("\n----- ARRAY OPERATIONS MENU -----\n");
        printf("1. Insert Marks\n");
        printf("2. Delete Marks\n");
        printf("3. Display Marks\n");
        printf("4. Linear Search\n");
        printf("5. Bubble Sort\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                if(n == 50)
                {
                    printf("Array is full!\n");
                    break;
                }

                printf("Enter number of students: ");
                scanf("%d", &n);

                if(n < 1 || n > 50)
                {
                    printf("Invalid number!\n");
                    n = 0;
                    break;
                }

                printf("Enter marks:\n");

                for(i = 0; i < n; i++)
                {
                    scanf("%d", &a[i]);
                }
                break;

            case 2:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter position to delete: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for(i = pos-1; i < n-1; i++)
                    {
                        a[i] = a[i+1];
                    }

                    n--;
                    printf("Mark deleted successfully!\n");
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Student Marks: ");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;

            case 4:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter mark to search: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(a[i] == key)
                    {
                        printf("Mark found at position %d\n", i+1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Mark not found!\n");
                }
                break;

            case 5:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                for(i = 0; i < n-1; i++)
                {
                    for(j = 0; j < n-1-i; j++)
                    {
                        if(a[j] > a[j+1])
                        {
                            temp = a[j];
                            a[j] = a[j+1];
                            a[j+1] = temp;
                        }
                    }
                }

                printf("Sorted Marks: ");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;

            case 6:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                // Sort array before Binary Search
                for(i = 0; i < n-1; i++)
                {
                    for(j = 0; j < n-1-i; j++)
                    {
                        if(a[j] > a[j+1])
                        {
                            temp = a[j];
                            a[j] = a[j+1];
                            a[j+1] = temp;
                        }
                    }
                }

                printf("Sorted Marks: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }

                printf("\nEnter mark to search: ");
                scanf("%d", &key);

                low = 0;
                high = n-1;
                found = 0;

                while(low <= high)
                {
                    mid = (low+high)/2;

                    if(a[mid] == key)
                    {
                        printf("Mark found at position %d\n", mid+1);
                        found = 1;
                        break;
                    }
                    else if(key < a[mid])
                    {
                        high = mid-1;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }

                if(found == 0)
                {
                    printf("Mark not found!\n");
                }
                break;

            case 7:
                printf("Program exited successfully!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(ch != 7);

    return 0;
}
