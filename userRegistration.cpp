#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;
string loginUser, loginPass,nHolder,pHolder;
string choice();
string something();
int toDec();
int key1 = 11;
char key2 = 'L';
long long key3 = 999999000001;
int main() {
    choice();
}
string encryption(string n) { 
    int enc1n=0, enc2n=0, enc3n=0;
    for (int i = 0; i < n.length(); i++) {
        enc1n = (n[i] ^ key1) - enc1n;
    }
    enc2n = (enc1n ^ key2);
    enc3n = (enc2n ^ key3);
    string binary = std::bitset<32>(enc3n).to_string();
    return binary;
}
string comparison(string n) {
    int enc1=0, enc2=0, enc3=0;
    for (int i = 0; i < n.length(); i++) {
        enc1 = (n[i] ^ key1) - enc1;
    }
    enc2 = (enc1 ^ key2);
    enc3 = (enc2 ^ key3);
    string binary = std::bitset<32>(enc3).to_string();
    return binary;
}

string something(int k, string n, string p, string ph, string c) {
    // sign up
    string binaryP;
    while (true) {
        if (k == 1) {
                 cout << "Enter nickname:  ";
                 cin >> n;
                 cout << endl;

                 string binary = encryption(n);
                 ifstream readS(binary + ".txt");
            if (!readS.fail()) {
                 cout << "Username taken,try another one" << endl;
                 continue;
            }
            if (n.size() < 2) {
                cout << "Username must be at least 2 length" << endl;
                continue;
            }
                cout << "Password:  ";
                cin >> p;
                binaryP = encryption(p);
            if (p.size() < 4) {
                cout << "Password must be at least 4 length" << endl;
                continue;
            }
                cout << endl;
                cout << "Confirm password:  ";
                cin >> c;
                cout << endl;

            if (c != p) {
                cout << "Doesn't match" << endl;
                continue;
            }
            else {
                cout << "You successfuly created an account" << endl;
                ofstream myFile;
                myFile.open(binary + ".txt", ios::out);
                if (myFile.is_open()) {
                    myFile << binary << endl;
                    myFile << binaryP << endl;
                    myFile.close();
                }

            }
                choice();
                cout << endl;
        }
        // log in
        else if (k == 2) {
            while (true) {
                cout << "ENTER USERNAME: "; cin >> loginUser;
                cout << endl;
                string cBinary =  comparison(loginUser);
                ifstream read(cBinary + ".txt");
                string k, l;
                if (!read.fail()) {
                    getline(read, k);//retrieves username
                    getline(read, l);//retrieves password
                    cout << "ENTER PASSWORD : " << endl;
                    cin >> loginPass;     
                    if (comparison(loginPass) == l) {  //comparing passwords
                        cout << "Succeeded" << endl;
                        return choice();
                    }
                    else {
                        cout << "Password is incorrect" << endl;
                        int w;
                        cout << "Press 3 to Create account" << endl;
                        cout << "Press 0 to Continue" << endl;
                        cin >> w;
                        if (w == 3) {
                            return choice();
                        }
                        else if (w == 0) {
                            continue;
                        }
                    }
                }

                else {
                    cout << "Account doesn't exist" << endl;
                    int w;
                    cout << "Press 3 to Create account" << endl;
                    cout << "Press 0 to Continue" << endl;
                    cin >> w;
                    if (w == 3) {
                        return choice();
                    }
                    else if (w == 0) {

                        continue;
                    }
                }

            }
        }
    }
        return 0;
    }

    string choice(){
    string userName = "", userPassword = "", confirmation, passHolder;
    int choice;
    cout << "1.Sign Up" << "   " << "2.Log In" << endl;
    cout << "Your choice: ";  cin >> choice;
    return something(choice, userName, userPassword, passHolder, confirmation);
}
  