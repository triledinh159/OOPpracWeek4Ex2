#include "People.h"

Member::Member() {
    baseFee = classFee = steamFee = ptSupport = id = time = total = 0;
    name = "None";
}

void Member::BaseInput() {
    cout << "Name: ";
    cin.ignore(); getline(cin, name);
    cout << "ID: "; cin >> id;
    cout << "Time to join (month): "; cin >> time;
}
int Member::TotalFee() {
    total = baseFee;
    if (classFee != -1)
        total += classFee;
    if (steamFee != -1)
        total += steamFee;
    total += ptSupport;
    return (total * time);
}
void Member::BaseDisplay() {
    cout << "Name of customer: " << name << endl;
    cout << "ID of customer: " << id << endl;
    cout << "Registered " << time << " months" << endl;
    cout << "Detail of payment: " << endl;
    cout << "Basic fee: " << baseFee << endl;

    if (classFee == 0)
        cout << "Class fee: free" << endl;
    else if (classFee == -1)
        cout << "Class fee: none" << endl;
    else
        cout << "Class fee: " << classFee << endl;

    if (steamFee == 0)
        cout << "Fee for steaming: free" << endl;
    else
        cout << "Fee for steaming: none" << endl;

    if (ptSupport == 0)
        cout << "PT support: free" << endl;
    else
        cout << "PT support: " << ptSupport << endl;

    cout << "Total paymemt for " << time << " month is " << TotalFee() << endl;
}
void Member::Swap(Member & a, Member & b) {
    Member tmp = a;
    a = b;
    b = tmp;
}
int Member::Sort(Member mem[], int n,int x) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            if (mem[i].TotalFee() < mem[j].TotalFee())
                x = j;
            else x = i;
        }
    return x;
}
Basic::Basic() {
    type = "Basic";
    baseFee = 500;
    classFee = ptSupport = 100;
    nClass = 0;
    steamFee = -1;
}
void Basic::Input() {
    Basic::nBasic++;
    BaseInput();
    cout << "Number of class: "; cin >> nClass;
    classFee = nClass * classFee;
}
void Basic::Display() {
    BaseDisplay();
    cout << "Registered class: " << nClass << endl;
    
}
void Basic::Recommend() {
    if (Member::total >= 900) cout << "Premium" << endl;
    if (Member::total >= 600 && Member::total < 900) cout << "Basic" << endl;
    if (Member::total < 600) cout << "Non-basic" << endl;
}
NonMember::NonMember() {
    type = "Non-member";
    baseFee = 200;
    classFee = steamFee = -1;
    ptSupport = 200;
}
void NonMember::Input() {
    NonMember::nNonMember++;
    BaseInput();
}
void NonMember::Display() {
    BaseDisplay();
}
void NonMember::Recommend() {
    if (Member::total >= 900) cout << "Premium" << endl;
    if (Member::total >= 600 && Member::total < 900) cout << "Basic" << endl;
    if (Member::total < 600) cout << "Non-basic" << endl;
}
Premium::Premium() {
    type = "Premium";
    baseFee = 1000;
    classFee = steamFee = ptSupport = 0;
}
void Premium::Input() {
    Premium::nPremium++;
    BaseInput();
}
void Premium::Display() {
    BaseDisplay();
}
void Premium::Recommend() {
    if (Member::total >= 900) cout << "Premium" << endl;
    if (Member::total >= 600 && Member::total < 900) cout << "Basic" << endl;
    if (Member::total < 600) cout << "Non-basic" << endl;
}