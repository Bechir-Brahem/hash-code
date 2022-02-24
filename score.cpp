#include <bits/stdc++.h>
#include <string>
using namespace std;
int skLen = 0;

map<int, map<int, int>> skill_to_pers;
map<string, int> skToInt;
map<int, string> intToSk;

class Person
{
public:
    int id;
    string name;
    int nskills;
    //skill -> skill lvl
    map<int, int> mp;
    void Read(int i)
    {
        cin >> name;
        id = i;
        cin >> nskills;
        for (int i = 0; i < nskills; i++)
        {
            string a;
            int q;
            cin >> a;
            cin >> q;
            if (skToInt.find(a) == skToInt.end())
            {
                skToInt[a] = skLen++;
                intToSk[skLen - 1] = a;
            }
            skill_to_pers[skToInt[a]][q] = id;
            mp[skToInt[a]] = q;
        }
    }

    void print()
    {
        cout << name << ' ' << nskills << endl;
        for (auto const &x : mp)
        {
            cout << intToSk[x.first] << ' ' << x.second << endl;
        }
        cout << endl;
    }

    void printName()
    {
        cout << name << ' ';
    }
};
class Project
{
public:
    int id;
    string name;
    int bbefore, nRoles, nDays, score;
    map<int, int> roles;
    vector<int> orderOfRoles;
    void read(int i)
    {
        id = i;
        string tmp;
        int x;
        cin >> name >> nDays >> score >> bbefore >> nRoles;
        for (int i = 0; i < nRoles; i++)
        {
            cin >> tmp >> x;
            roles[skToInt[tmp]] = x;
            orderOfRoles.push_back(skToInt[tmp]);

        }
    }
    void print()
    {
        cout << name << ' ' << nDays << ' ' << score << ' ' << bbefore << ' ' << nRoles << endl;
        for (auto const &x : roles)
        {
            cout << intToSk[x.first] << ' ' << x.second << endl;
        }
        cout << endl;
    }
    bool operator<(const Project &p) const
    {
        return nDays < p.nDays;
    }
};
// ma t7awalch 
vector<Person> vPer;
vector<Project> vPro;



int main()
{

    int nPer, nPro, tmp, q;
    string a, b, c;
    cin >> nPer >> nPro;
    for (int i = 0; i < nPer; i++)
    {
        Person tmpPer = Person();
        tmpPer.Read(i);
        vPer.push_back(tmpPer);
    }
    for (int i = 0; i < nPro; i++)
    {
        Project tmpPro = Project();
        tmpPro.read(i);
        vPro.push_back(tmpPro);
    }

    sort(vPro.begin(),vPro.end());
    string finalRet="";
    int id=0;
    bool found=false;
    for(Project p:vPro){
       string ret=p.name+'\n';
        found=false;
         for (int role:p.orderOfRoles){
             for(Person per:vPer){
                 if(per.mp.find(role)==per.mp.end()){
                     continue;
                 }
                 //person with role found
                 if(per.mp[role]>=p.roles[role]){
                     //cout<<per.mp[role]<<' '<<p.roles[role]<<endl;
                     ret+=per.name+' ';
                     found=true;
                     break;
                 }      
             }
             if(found){
                 continue;
             }else{
                 break;
             }

         }
         if(found){
             id++;
             finalRet+=ret+'\n';
         }
        //omi ba7theya hetha aleh msaker manajamch nahki
    }
    
    

  cout<<id<<endl<<finalRet;

    return 0;
}
