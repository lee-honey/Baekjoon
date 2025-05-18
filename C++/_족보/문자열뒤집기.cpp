#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str)
{
    char* temp = new char[strlen(str) + 1];

    for(int i = 0; i < strlen(str); i++)
	    temp[i] = str[strlen(str) - i - 1];
    
    temp[strlen(str)] = '\0';

    strcpy(str, temp);

    delete temp;
}

int main(void)
{
    char str[] = "Zusin";
    reverse(str);
    cout << str << '\n';

    return 0;
}