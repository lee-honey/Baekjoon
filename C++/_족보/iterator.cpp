#include <iostream>
#include <vector>

using namespace std;

void deleteVector(vector<int> aa)
{ 
    for(vector<int>::iterator iter = aa.begin(); iter != aa.end(); ++iter)
    { 
    if(*iter)
        delete *iter;
    aa.erase(iter);
    }
}

int main(void)
{
    return 0;
}