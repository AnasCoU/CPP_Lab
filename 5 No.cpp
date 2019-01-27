#include<bits/stdc++.h>
 
using namespace std;
 
class Date {
    public:
 
        int day, month, year;
};
 
istream& operator >> (istream &in,Date &d) {
 
    cin >> d.day >> d.month >>  d.year;
 
    return cin ;
}
 
class Watch {
 
    public:
        Date d;
        int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
        int countLeapYears(Date d) {
            int years = d.year;
            if (d.month <= 2)
                years--;
            return years/4 - years/100 + years/400;
        }
 
        Date current(){
            time_t t = time(0);
            tm* now = localtime(&t);
            Date y;
            y.year = now->tm_year + 1900 ;
            y.month = now->tm_mon + 1 ;
            y.day = now->tm_mday ;
            return y;
        }
 
        int ageCalculator() {
            Date y=current();
            Date x=d;
            int n1 = x.year*365 + x.day;
            for(int i=0; i<x.month - 1; i++)
                n1 += monthDays[i];
            n1 += countLeapYears(x);
            int n2 = y.year*365 + y.day;
            for (int i=0; i<y.month-1; i++)
                n2 += monthDays[i];
            n2 += countLeapYears(y);
            return (n2-n1)/365;
        }
};
 
class Biodata: public Watch{
 
    public:
        string name ;
        int match ;
        int innings ;
        int notOut ;
        int wicket ;
        int run ;
        double BowlingAVG ;
        double BattingAVG ;
        string speciality ;
        int age ;
};
 
bool f (Biodata p,Biodata q){
 
    return p.BattingAVG>=q.BattingAVG;
}
 
bool g (Biodata p,Biodata q){
 
    return p.BowlingAVG>=q.BowlingAVG;
}
 
void selection (Biodata player[],vector<Biodata> &x,vector<Biodata> &y,int n,int &tfive,string a,string b,bool omg(Biodata p,Biodata q)){
 
    sort(player,player+n,omg);
 
    for(int i=0; i<n; i++) {
        if( (player[i].age>=20 && player[i].age<25) && player[i].speciality==a ){
            x.push_back(player[i]);
        }
        else if( (player[i].age>=25 && player[i].age<=30) && player[i].speciality==a && tfive<=4 ){
            x.push_back(player[i]);
            tfive++;
        }
        else if( (player[i].age>=20 && player[i].age<25) && player[i].speciality==b ){
            y.push_back(player[i]);
        }
        else if( (player[i].age>=25 && player[i].age<=30) && player[i].speciality==b && tfive<=4 ){
            y.push_back(player[i]);
            tfive++;
        }
    }
}
 
void print(vector<Biodata> v){
 
    for(int i=0; i<v.size(); i++){
 
        cout<<v[i].name<<" "<<v[i].speciality<<"\n";
    }
    cout<<"\n";
}
 
int main()
{
 
    int n, tfive=0 ;
    cin >> n ;
    Biodata player[ n ];
    vector<Biodata> batsman, pacer, spinner, wicketkeeper;
 
    cout<<"Enter Player name, date of birth, match, innings, notOut, wicket, run, speciality\n";
    for(int i=0; i<n; i++) {
        cin >> player[i].name >> player[i].d >> player[i].match >> player[i].innings >> player[i].notOut >> player[i].wicket >> player[i].run >> player[i].speciality ;
        player[i].BattingAVG = player[i].run/(player[i].innings-player[i].notOut);
        player[i].BowlingAVG = player[i].wicket/player[i].innings;
        player[i].age=player[i].ageCalculator();
    }
 
    selection(player,batsman,wicketkeeper,n,tfive,"batsman","wicketkeeper",f);
 
    selection(player,pacer,spinner,n,tfive,"pacer","spinner",g);
 
    print(batsman);
    print(wicketkeeper);
    print(pacer);
 
    return 0;
}
