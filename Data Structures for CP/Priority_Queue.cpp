#include<iostream>
#include<queue>
#include<deque>
using namespace std;
deque<int> q;
void add_priority_queue_element(int new_element){
    while(!q.empty() && q.back() > new_element) q.pop_back();
    q.push_back(new_element);
}
void remove__element(int remove_element){
    if(!q.empty() && q.front() == remove_element) q.pop_front();
}
int main()
{
    
    return 0;
}