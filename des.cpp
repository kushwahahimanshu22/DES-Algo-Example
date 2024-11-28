#include<iostream>
#include<chrono>
#include "desStd.hpp"

using namespace std;

int main(int argc, char **argv){
    if(argc < 2){
        cout << "USAGE ./des ROUNDS" << endl;
        exit(1);
    }
    int rounds = stoi(argv[1]);
    string pt = "123456ABCD132536", key = "AABB09182736CCDD"; //Plaintext in 64 bit HEX and Key in 64 bit HEX
    cout << "PT = " << pt << endl << endl;
    cout << "Key = " << key << endl << endl;
    auto start = chrono::high_resolution_clock::now();
    vector<string> rk = roundKeys(key, rounds);
    auto end = chrono::high_resolution_clock::now();

    cout << "Round Key generation time : " << chrono::duration_cast<chrono::microseconds>(end-start).count() << " ms\n" << endl;

    start = chrono::high_resolution_clock::now();
    cout << "ENCRYPTION--------------------------------------------------------\n" << endl;
    string cipher =  bin2hex(encrypt(pt, rk));
    cout << "\nENCRYPT : " << cipher << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time taken to encrypt: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << " ms\n" << endl;

    reverse(rk.begin(), rk.end());

    start = chrono::high_resolution_clock::now();
    cout << "DECRYPTION--------------------------------------------------------\n" << endl;
    string deciper = bin2hex(encrypt(cipher, rk));
    cout << "\nDECRYPT : " << deciper << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time taken to decrypt: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << " ms" << endl;

    return 0;
}
