#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll data;
    node* next;
    node(ll val):data(val),next(nullptr){}
};
int main()
{   
    ll n;cin>>n;
    if(n==1){cout<<1;return 0;}
    node*root =  new node(1ll);
    node* curr = root;
    for(int i=2;i<=n;i++)
    {
        node* temp = new node(i);
        curr->next =temp;
        curr =  temp;
    }
    curr->next = root;
    node* prev = root;
    curr = root->next;

    while(curr!=nullptr)
    {
        cout<<curr->data<<" ";
        node* temp2 = curr->next;
        prev->next = temp2;
        curr->next = nullptr;
        node* used = curr;
        curr = temp2->next;
        prev  = temp2;
        delete(used);
    }
    return  0;
}