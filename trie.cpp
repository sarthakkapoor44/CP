#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* link[26];
    bool flag;
};
class trie {
private:
    Node* root;
public:
    trie();
    void insert(string word);
    bool search(string word);
    bool prefix(string word);
};
trie::trie(){
root = new Node;
}
void trie::insert(string word){
    Node* node = root;
for(int i=0;i<word.length();i++){
if(node->link[word[i]-'a']==nullptr){
node->link[word[i]-'a']= new Node;
node = node->link[word[i]-'a'];
}
else{node = node->link[word[i]-'a'];}
}
node->flag= true;
}
bool trie::search(string word){
Node* node = root;
for(int i=0;i<word.length();i++){
if(node->link[word[i]-'a']==nullptr){return false;}
else{node = node->link[word[i]-'a'];}
}
if(node->flag==true){return true;}else{return false;}
}
bool trie::prefix(string word){
Node* node = root;
for(int i=0;i<word.length();i++){
if(node->link[word[i]-'a']==nullptr){return false;}
else{node = node->link[word[i]-'a'];}
}
return true;  
} 

int main(){
    trie obj;
    obj.insert("apple");
    obj.insert("apps");
    obj.insert("abc");
    cout<<obj.search("ab");
    cout<<endl;
    cout<<obj.prefix("ab");
    return 0;}