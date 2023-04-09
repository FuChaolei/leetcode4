#include <iostream>
#include <queue>
#include <pthread.h>
#include <windows.h>
using namespace std;
queue<int> q;
pthread_mutex_t mu;
void *thread_func(void *arg)
{
    int n = *(int *)(arg);
    if (!q.empty())
    {
        pthread_mutex_lock(&mu);
        cout << q.front() << " " << n << endl;
        q.pop();
        pthread_mutex_unlock(&mu);
    }
    return 0;
}
int main()
{
    pthread_mutex_init(&mu, 0);
    pthread_t pid[5];
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
        a[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&pid[i], 0, thread_func, (void *)&(i));
        Sleep(1);
    }
    void *res;
    for (int i = 0; i < 5; i++)
    {
        if (pthread_join(pid[i], &res) != 0)
        {
            cout << i << "出错" << endl;
        }
    }
    pthread_mutex_destroy(&mu);
    return 0;
}
