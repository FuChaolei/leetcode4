#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;
queue<int> q;
mutex mu;
void thread_func(int n)
{
    if (!q.empty())
    {
        mu.lock();
        cout << q.front() << " " << n << endl;
        q.pop();
        mu.unlock();
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        thread t(thread_func, i);
        t.join();
    }
    return 0;
}
