#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int answer;
    int comCount; int lineCount;
    cin >> comCount;
    cin >> lineCount;
    bool isVisited[comCount + 1] = {false,};
    vector<int> graph[comCount + 1];
    queue<int> q;
    for(int i = 0; i < lineCount; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if(!isVisited[y])
            {
                q.push(y);
                isVisited[y] = true;
                if(y != 1)
                    answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main()
// {
//     int answer;
//     int comCount; int lineCount;
//     cin >> comCount;
//     bool isVisited[comCount + 1] = {false,};
//     vector<int> graph[comCount + 1];
//     cin >> lineCount;
//     for(int i = 0; i < lineCount; i++)
//     {
//         int a,b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     queue<int> q;
//     q.push(1);
//     while(!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         for(int i = 0; i < graph[x].size() ; i++)
//         {
//             int back = graph[x][i];
//             if(!isVisited[back]){
//                 q.push(back);
//                 isVisited[back] = true;
//                 if(back > 1)
//                 {
//                     answer++;   
//                 }
//             }
//         }
//     }
//     cout << answer << endl;
//     return 0;
// }