#include <stdio.h>

// Function to count positive numbers entered by the user
void count_positive_numbers(int num)
{
    static int count = 0; // Static variable to retain the count of positive numbers
    if (num > 0)
    {
        count++;
    }
    printf("Positive numbers entered so far: %d\n", count);
}

int main()
{
    int num;

    printf("Enter numbers (enter 0 or a negative number to stop):\n");

    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num > 0)
        {
            count_positive_numbers(num); // Call the function to count the positive number
        }
    } while (num > 0); // Keep asking for input until 0 or negative number is entered

    printf("Program ended. Total positive numbers entered: \n");
    count_positive_numbers(-1); // Final call to print the count

    return 0;
}
