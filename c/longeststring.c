#include <stdio.h>
#include <string.h>

void userInput(char Arr[]);
int space(int i, char Arr[]);
void max(int len, char Arr[], char max[]);

int main()
{
    int i = 0;
    char Arr[1000];
    char max[1000] = "";
    int maxLength = 0;

    userInput(Arr);

    while (i < strlen(Arr))
    {
        int segmentStart = i;
        i = space(i, Arr);
        int segmentLength = i - segmentStart - 1; 

        if (segmentLength > maxLength)
        {
            maxLength = segmentLength;
            strncpy(max, Arr + segmentStart, segmentLength);
            max[segmentLength] = '\0';
        }
    }

    printf("Longest segment: %s\n", max);
    printf("Original string: %s\n", Arr);

    return 0;
}

int space(int i, char Arr[])
{
    for (; i < strlen(Arr); i++)
    {
        if (Arr[i] == ' ')
        {
            return i + 1;
        }
    }
    return strlen(Arr);
}

void userInput(char Arr[])
{
    printf("Enter your string:\n");
    fgets(Arr, 1000, stdin);
    Arr[strcspn(Arr, "\n")] = '\0';
}

