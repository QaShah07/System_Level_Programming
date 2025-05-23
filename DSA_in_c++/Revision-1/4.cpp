#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
 
int main()
{
    std::queue<int> q;
 
    q.push(0); // back pushes 0
    q.push(1); // q = 0 1
    q.push(2); // q = 0 1 2
    q.push(3); // q = 0 1 2 3
 
    assert(q.front() == 0);
    assert(q.back() == 3);
    assert(q.size() == 4);
 
    q.pop(); // removes the front element, 0
    assert(q.size() == 3);
 
    // Print and remove all elements. Note that std::queue does not
    // support begin()/end(), so a range-for-loop cannot be used.
    cout << "q: ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
        cout<<endl;
        cout<<q.size()<< " ";
    }
    cout << '\n';
}