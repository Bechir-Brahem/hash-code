#include<bits/stdc++.h>
#include <string>
using namespace std;
int skLen=0;


map<int,map<int,int>>skill_to_pers;
map<string,int> skToInt;
map<int,string> intToSk;

class Person{
public:
    int id;
    string name;
    int nskills;
    //skill -> skill lvl
    map<int,int> initial_skill_lvl;
    map<int,int> curr_skill_lvl;
    void Read(int i){
        cin>>name;
        id=i;
        cin>>nskills;
        for(int i=0;i<nskills;i++){
            string a;
            int q;
            cin>>a;
            cin>>q;
            if(skToInt.find(a)==skToInt.end()){
                skToInt[a]=skLen++;   
                intToSk[skLen-1]=a;
            }
            skill_to_pers[skToInt[a]][q]=id;
            initial_skill_lvl[skToInt[a]]=q;
        }
        curr_skill_lvl=initial_skill_lvl;
    }

    void print(){
        cout<<name<<' '<<nskills<<endl;
        for (auto const& x : initial_skill_lvl)
        {
            cout<<intToSk[x.first]<<' '<<x.second<<endl;
        }
        cout<<endl;

    }

    void printName(){
        cout<<name<<' ';
    }
};
class Project{
    public:
    int id;
    string name;
    int bbefore,nRoles, nDays,score;
    map<int,int> roles;
    void read(int i){
        id=i;
        string tmp;
        int x;
        cin>>name>>nDays>>score>>bbefore>>nRoles;
        for(int i=0;i<nRoles;i++){
            cin>>tmp>>x;
            roles[skToInt[tmp]]=x;
        }

    }
     void print(){
        cout<<name<<' '<<nDays<<' '<<score<<' '<<bbefore<<' '<<nRoles<<endl;
        for (auto const& x : roles)
        {
            cout<<intToSk[x.first]<<' '<<x.second<<endl;
        }
        cout<<endl;

    }
};


vector<Person> vPer;
vector<Project> vPro;
int main(){


int nPer,nPro,tmp,q;
string a,b,c;
cin>>nPer>>nPro;
for(int i=0;i<nPer;i++){
    Person tmpPer =Person();
    tmpPer.Read(i);
    vPer.push_back(tmpPer);
}
for(int i=0;i<nPro;i++){
    Project tmpPro=Project();
    tmpPro.read(i);
    vPro.push_back(tmpPro);
}


for(Person g:vPer){
    g.print();
}
for(Project g:vPro){
    g.print();
}


return 0;
}
