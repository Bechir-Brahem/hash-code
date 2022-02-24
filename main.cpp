#include<bits/stdc++.h>
#include <string>
using namespace std;
int skLen=0;

class Person{
    public:
    int id;
    string name;
    int nskills;
    map<int,int> mp;
    Person Read(){
 
    }

    void print(){
        cout<<name<<' '<<nskills<<endl;
        for (auto const& x : mp)
        {
            cout<<x.first<<' '<<x.second<<endl;
        }
        cout<<endl;

    }
    void printName(){
        cout<<name<<' ';
    }
};
vector<Person> vPer;

map<int,map<int,int>>skill_to_pers;
map<string,int> skToInt;
map<int,string> intToSk;


int main(){


int nPer,nPro,tmp,q;
string a,b,c;
cin>>nPer>>nPro;
for(int i=0;i<nPer;i++){
    Person tmpPer =Person();
    cin>>a;
    tmpPer.name=a;
    tmpPer.id=i;
    cin>>tmpPer.nskills;
    for(int i=0;i<tmpPer.nskills;i++){
        cin>>a;
        cin>>q;
        if(skToInt.find(a)==skToInt.end()){
            skToInt[a]=skLen++;   
            intToSk[skLen-1]=a;
        }
    
        tmpPer.mp[skToInt[a]]=q;
    }


    vPer.push_back(tmpPer);
}
for(Person g:vPer){
    g.print();
}

return 0;
}
