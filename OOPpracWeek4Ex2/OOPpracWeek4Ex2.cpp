#include "People.cpp"
int main() {
    Member* mem[1000],rand;
    Basic bas[1000];
    Premium pre[1000];
    NonMember nmem[1000];

    cout << "== Import data of customers ==" << endl;
    int n; cout << "Number of customers: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "1. Basic member" << endl << "2. Premium member" << endl << "3. Non-member" << endl;
        int role; cin >> role;
        if (role == 1) {
            mem[i] = &bas[i];
        }
        else if (role == 2) {
            mem[i] = &pre[i];
        }
        else if (role == 3) {
            mem[i] = &nmem[i];
        }
        mem[i]->Input();
    }

    cout << "== Imported data ==" << endl;
    cout << "Number of basic members: " << Basic::nBasic << endl;
    cout << "Number of premium members: " << Premium::nPremium << endl;
    cout << "Number of non-members: " << NonMember::nNonMember << endl;


    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << endl;
        mem[i]->Display();
    }

    cout << "== The highest payment ==" << endl;
    int j = 0;
    mem[rand.Sort(*mem,n,j)]->Display();
    cout << "Recommended type: ";
    mem[j]->Recommend(); 
    return 0;
}