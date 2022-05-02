#pragma once
#include <iostream>
#include <string>

using namespace std;

class Member {
private:
    string name;
    int time, id;
public:
    int baseFee, classFee, steamFee, ptSupport, total;
    string type;
    Member();
    void BaseInput();
    virtual void Input() {}
    int TotalFee();
    void BaseDisplay();
    virtual void Display() {}
    void Swap(Member& a, Member& b);
    int Sort(Member mem[], int n,int x);
    virtual void Recommend() {};
    int CountMoney();
};
class Basic : public Member {
private:
    int nClass;
public:
    static int nBasic;
    static int GetNumBer() {
        return nBasic;
    }
    Basic();
    void Input();
    void Display();
    void Recommend();
};

int Basic::nBasic = 0;
class NonMember : public Member {
public:
    static int nNonMember;
    static int GetNumber() {
        return nNonMember;
    }
    NonMember();
    void Input();
    void Display();
    void Recommend();
};

int NonMember::nNonMember = 0;
class Premium : public Member {
public:
    static int nPremium;
    static int GetNumber() {
        return nPremium;
    }
    Premium();
    void Input();
    void Display();
    void Recommend();
};

int Premium::nPremium = 0;