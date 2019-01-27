#include<bits/stdc++.h>
using namespace std;
 
class Person
{
public:
    string name,DOB;
    Person(string a,string b)
    {
        name=a;
        DOB=b;
    }
    void show_Per()
    {
        cout<<name<<endl;
    }
};
class Customer : public Person
{
public:
    string cus_id,sex;
    int catagory;   /** 1 for kids ; 2 for male ; 3 for female **/
    Customer(string a,string b,string c,string d,int x) : Person(a,b)
    {
        cus_id=c;
        sex=d;
        catagory=x;
    }
    void show_Cus()
    {
        if(catagory == 1)
            cout<<"Hey champ , ";
        else if(catagory == 2)
            cout<<"Hello sir , ";
        else if(catagory == 3)
            cout<<"Hello mem , ";
        cout<<"Customer ID : "<<cus_id<<endl;
    }
};
 
class Product;
 
class SuperShop
{
public:
    string pro_Name,pro_Cat;
    int quantity;
    void getInfo(string a,string x,int b)
    {
        pro_Name=a;
        pro_Cat=x;
        quantity=b;
    }
    friend bool Process(SuperShop,Product);
};
 
class Product : SuperShop
{
public:
    double price;
    void getData(string a,string x,int b,double c)
    {
        getInfo(a,x,b);
        price=c;
    }
    friend bool Process(SuperShop,Product);
};
 
bool Process(SuperShop s,Product p)
{
    if(s.pro_Cat==p.pro_Cat && s.pro_Name==p.pro_Name && s.quantity<=p.quantity)
    {
        cout<<"Total Cost: "<<s.quantity*p.price<<endl;
        cout<<"Thank You for shopping with us.\n";
        cout<<"Your shopping is successfully done! Thank u.\n\n";
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Product obj[5];
    obj[0].getData("Body lotion","Cosmetics",5,270.00);
    obj[1].getData("Pen","Stationary",5,12.50);
    obj[2].getData("T-Shirt","Garments",5,485.75);
    obj[3].getData("Hijab","Garments",5,279.50);
    obj[4].getData("Body Spray","Cosmetics",5,295.00);
 
    Customer c1("Arman","30/12/1996","12345","Male",2);
 
    SuperShop t1;
    t1.getInfo("Body lotion","Cosmetics",6);
    bool fg=false;
    for(int i=0; i<4; i++)
    {
        if(Process(t1,obj[i]))
        {
            fg=true;
        }
    }
    if(!fg)
    {
        c1.show_Cus();
        cout<<"Sorry! We don't have this product sufficiently. Please try again later.\n\n";
    }
    return 0;
}
