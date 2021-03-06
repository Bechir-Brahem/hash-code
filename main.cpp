#include <bits/stdc++.h>
#include <string>
using namespace std;
int skLen = 0;

//role + skill lvl => id l3bed eli y3rfou
map<pair<int,int>, vector <int>> skill_to_pers;
//role => id l3bed eli y3rfou
map<int , vector <int> > skil_to_perss ;
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
    map<int, int> curr_mp;
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
            skill_to_pers[{skToInt[a],q}].push_back(id);
            skil_to_perss[skToInt[a]].push_back(id);
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
    vector<int> idOfRoles;
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
            idOfRoles.push_back(skToInt[tmp]);
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
        
        return score-nDays > p.score-p.nDays;
    }
};
// ma t7awalch 
vector<Person> vPer;
vector<Project> vPro;

class Assign
{
public:
    Project proj;
    //role=> pers
    map<int, int> role_to_pers;
    void print(){
        cout<<proj.name<<endl;
        for(int i=0;i<proj.nRoles;i++){
            cout<<vPer[role_to_pers[proj.idOfRoles[i]] ].name<<' ';
        }
        cout<<endl;
    }
};

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
    vector<Assign> assigns;
    for(auto proj:vPro){
        Assign tmpAssign;
        set<int> usedPers;
        set<int> last_usedPers;

        for(auto idRole:proj.idOfRoles){
            auto list_of_potential_colab=skil_to_perss[idRole];
            random_shuffle(list_of_potential_colab.begin(),list_of_potential_colab.end());
            for(auto potential_colab:list_of_potential_colab){
                if(vPer[potential_colab].mp[idRole]>=proj.roles[idRole]){
                    if(usedPers.find(potential_colab)==usedPers.end()&&last_usedPers.find(potential_colab)==last_usedPers.end()){
                        tmpAssign.role_to_pers[idRole]=potential_colab;
                        usedPers.insert(potential_colab);
                        break;
                    }else{//saha khalil wa7chhh ????????
                        for(int i=0;i<min(150,nPer);i++){   
                            auto choose_rand=max(0,rand()%nPer);
                            if(usedPers.find(choose_rand)==usedPers.end()&&vPer[choose_rand].mp[idRole]>=proj.roles[idRole]-1&&last_usedPers.find(potential_colab)==last_usedPers.end()){
                                tmpAssign.role_to_pers[idRole]=choose_rand;
                                usedPers.insert(choose_rand);
                                goto here;
                            }
                        }
                    }
                }
                here:;
            }
        }
        //zid Assign
        if(tmpAssign.role_to_pers.size()==proj.nRoles){
            last_usedPers=usedPers;
            usedPers.clear();
            for(auto i:tmpAssign.role_to_pers){
                if(vPer[i.second].mp[i.first]<=proj.roles[i.first]){
                    vPer[i.second].mp[i.first]++;
                }
            }
            tmpAssign.proj=proj;
            assigns.push_back(tmpAssign);
        }
    }
    
    cout<<assigns.size()<<endl;
    for(auto assign: assigns){
        assign.print();
    }
  

    return 0;
}
