#include <bits/stdc++.h>
using namespace std;

map<int,int> user;
map<int,int> balance;

bool userExsist(int user_id){
    if(user[user_id]==1){
        return 1;
    }
    return 0;
}

bool creatUser(int user_id){
    if(userExsist(user_id)){
        cout<<"User created\n";
        return 0;
    }
    user[user_id]=1;
    balance[user_id]=0;
    cout<<"User alreadey exsist\n";
    return 1;
}

bool isValidBalance(int user_id,int amount){
    if(userExsist(user_id) and balance[user_id]-amount>=0)return 1;
    return 0;
}

bool withdraw(int user_id,int amount){
    if(isValidBalance(user_id,amount)){
        balance[user_id]-=amount;
        cout<<amount<<" Is withdrawn \n";
        return 1;
    }
    cout<<"invalid balance or user dosent exsist\n";
    return 0;
}

bool deposit(int user_id,int amount){
    if(userExsist(user_id)){
        balance[user_id]+=amount;
        cout<<amount<<" Is Deposited \n";
        return 1;
    }
    cout<<"User dosent exsist\n";
    return 0;    
}

int main(){
    creatUser(1);
    withdraw(1,55);
    deposit(2,77);
    deposit(1,100);
    withdraw(1,34);
}