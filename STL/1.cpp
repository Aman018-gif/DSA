#include<bits/stdc++.h>
using namespace std;

void explainpair(){
    pair<int,int> p={1,3};
    cout<< p.first <<" " <<p.second <<endl;

    pair <int,pair<int,int>> p1={5,{6,7}};
    cout<< p1.first <<" " <<p1.second.second <<" " <<p1.second.first <<endl;

    pair<int,int> arr[] = {{1,2},{3,4},{5,6},{7,8}};
    cout<<arr[1].first;
}

void explainvector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.emplace_back(4);
    v.push_back(9);
    //cout<<v[1] <<endl;
    vector<pair<int,int>>v1;
    v1.push_back({1,2});
    v1.emplace_back(3,4);
    //cout<<v1[1].first <<endl;
    vector<int> v2(5,100);
    //cout<<v2[4]<<endl;
    vector<int> v3(v2);
    //cout<<v3[4]<<endl;
    // for(vector<int>::iterator it =v.begin();it !=v.end();it++){
    // cout<< *(it) <<" ";
    // }
//     for(auto it =v.begin();it !=v.end();it++){
//     cout<< *(it) <<" ";
//     }
    for(auto it: v){
    cout<< it <<" ";
    }
    cout<<endl;

    vector<int> v4({1,2,3,4,5,6});
    //v4.erase(v4.begin()+1);
    //v4.erase(v4.begin()+2,v4.begin()+4);
    //v4.insert(v4.begin()+1,2,300);
    vector<int> copy(2,50);
    v4.insert(v4.begin(),copy.begin(),copy.end()); //singly list list maintained
    cout<<endl;
    v4.pop_back();
    for(auto it1:v4){
        cout<<it1 <<" ";
    }
    cout<<endl;
    cout<< "size"<<v4.size();
    //v4.swap(v5);
    //v.clear();
    cout<<v4.empty();
}

void explainlist(){
    list<int> l;
    l.push_back(2);
    l.emplace_back(3);
    l.push_front(1); // chepaer then insert in vector as uses doubly linked list
    l.emplace_front(0);
    for(auto it:l){
        cout<<it << " ";
    }
}

void Stack(){
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.emplace(5);
    cout<< s1.top()<<endl;
    cout<<"size is "<<s1.size()<<endl;   
    s1.pop();
    cout<< s1.top()<<endl;
    cout<<"size is "<<s1.size()<<endl;   
    s1.pop();
    cout<<"size is "<<s1.size()<<endl;   
    cout<< s1.top()<<endl; 
    cout<< "is empty "<<s1.empty();
    //stack1.swap(stack2);
}

void Queue(){
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.emplace(5);
    q1.back()+=10;
    cout<< "queue front is "<<q1.front() << " queue back is " << q1.back() <<endl;
    q1.pop();
    cout<< "queue front after one pop is "<<q1.front();
}

void Priority_Queue(){
    // priority_queue<int>q1;
    // q1.push(1);
    // q1.push(20);
    // q1.push(30);
    // q1.push(4);
    // q1.emplace(500);
    // cout<< "priority_queue top is "<<q1.top()<<endl;
    // q1.pop();
    // cout<< "queue top after one pop is "<<q1.top();

    //min heap
    priority_queue<int, vector<int>,greater<int>> q1;
    q1.push(1);
    q1.push(20);
    q1.push(30);
    q1.push(4);
    q1.emplace(500);
    cout<< "priority_queue top is "<<q1.top()<<endl;
    q1.pop();
    cout<< "queue top after one pop is "<<q1.top();
}

void set(){
    // insert and emplace to insert sotre in sorted order and unique also;
    // find erase and count also works
    // auto it = set.find(element) if the element exists inside the set return an iterator pointing towards it and if it does not return an iterator pointing towards end;
    // set.count(element) since every element is unique so if exists return 1 else 0
    //set.erase(either put an element or an iterator or give a range)
}

void Map(){
    map <int,int> mpp;
    //map<pair<int,int>,int> mpp;
    //map[{2,3}] =10;
    //key value pair where key are unquie and sorted
    mpp[1]=2;
    //mpp.emplace({3,1});
    mpp.insert({3,1});
    mpp.insert({2,4});
    for(auto it:mpp){
        cout<< it.first <<" " <<it.second <<endl;
    }
    cout<<mpp[2]<<endl;
    cout<<mpp[5] <<endl;
    auto it1 = mpp.find(3);
    cout<< (*it1).second;
    

}

bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    if(p1.first>p2.first)return true;
    return false;
}

void sort(){
    vector<int> v4({1,6,4,2,3,9});
   //sort(v4.begin(),v4.end());
   //sort(v4.begin()+2,v4.end());
   sort(v4.begin(),v4.end(),greater<int>());
    for(auto it:v4){
        cout<<it <<" ";
    }
    cout<<endl;
    pair<int,int> a[]= {{1,2},{2,1},{4,1}};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n,comp);
    for(auto it1:a){
        cout<< it1.first << " " <<it1.second << endl;
    }
}

int main(){
    int a;
    // cin >> a;
    // cout << "hello " << a;
    //explainpair();
    //explainvector();
    //explainlist();
    //deques also same as list and vector
   //Stack();
   //Queue();
   //Priority_Queue();
   //Set();
   //Multiset(); bas not unquie 
   //UnorderedSet(); bas not ordered
   //Map();
   //Multimap(); bas not unquie for keys 
   //Unorderedmap(); bas not ordered for keys 
   //sort();
    //int num = 7;
    //int cnt = __builtinpopcount();
    //cout<< cnt; gives total one's in binary
    string s="123";
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    // int maxi = *max_element(a,a+n);
}