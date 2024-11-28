#ifndef UTILS
#define UTILS

#include<map>
#include<iostream>
#include<cmath>
#include<algorithm>

std::string hex2bin(std::string s){
    std::map<char, std::string> mp;
    mp['0'] = "0000";
    mp['1'] = "0001";
    mp['2'] = "0010";
    mp['3'] = "0011";
    mp['4'] = "0100";
    mp['5'] = "0101";
    mp['6'] = "0110";
    mp['7'] = "0111";
    mp['8'] = "1000";
    mp['9'] = "1001";
    mp['A'] = "1010";
    mp['B'] = "1011";
    mp['C'] = "1100";
    mp['D'] = "1101";
    mp['E'] = "1110";
    mp['F'] = "1111";

    std::string bin = "";
    for(char &c : s){
        bin += mp[c];
    }
    return bin;
}

std::string bin2hex(std::string s){
    std::map<std::string, char> mp;
    mp["0000"] = '0';
    mp["0001"] = '1';
    mp["0010"] = '2';
    mp["0011"] = '3';
    mp["0100"] = '4';
    mp["0101"] = '5';
    mp["0110"] = '6';
    mp["0111"] = '7';
    mp["1000"] = '8';
    mp["1001"] = '9';
    mp["1010"] = 'A';
    mp["1011"] = 'B';
    mp["1100"] = 'C';
    mp["1101"] = 'D';
    mp["1110"] = 'E';
    mp["1111"] = 'F';

    std::string hex = "";
    for(int i=0;i<s.size();i += 4){
        std::string key = s.substr(i,4);
        hex += mp[key];
    }
    return hex;
}

int bin2dec(std::string s){
    int n = s.size();
    int decimal = 0;
    while(n--){
        if(s[s.size()-n-1] == '1') decimal += (int)pow(2, n);
    }
    return decimal;
}

std::string dec2bin(int n){
    std::string bin = "";
    do{
        bin += (n%2)?'1':'0';
        n = n>>1;
    }while(n);
    if(bin.size()%4){
        int div = bin.size()/4;
        int numZeros = 4*(div+1) - bin.size();
        for(int i=0;i<numZeros;i++){
            bin += '0';
        }
    }
    std::reverse(bin.begin(), bin.end());
    return bin;
}

std::string xorBits(std::string a, std::string b){
    std::string ans = "";
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i]) ans += '0';
        else ans += '1';
    }
    return ans;
}

std::string shiftLeft(std::string k, int n){
    std::string temp = "";
    for(int i=0;i<n;i++){
        for(int j=1;j<k.size();j++){
            temp += k[j];
        }
        temp += k[0];
        k = temp;
        temp = "";
    }
    return k;
}

#endif