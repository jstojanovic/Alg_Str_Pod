#include <iostream>
#include <fstream>
#include <string>
#include <stack>

int main() {
    std::fstream file;
    file.open("test.txt", std::ios::out);
//otvorio OUT
    std::stack<std::string> STEK;
    STEK.push("1\n");
    STEK.push("22\n");
    STEK.push("333\n");
    while(!STEK.empty()){
        file << STEK.top();
        STEK.pop();
    }
    file.close();
//otvorio IN
    std::fstream file_in;
    file_in.open("test.txt", std::ios::in);
    std::string redak;
    while(getline(file_in, redak)){
        STEK.push( redak );//pisem redak u stog
        std::cout<<redak<<"\n";
    }
    file_in.close();

    while(!STEK.empty()){
        std::cout << STEK.top() <<"\n";//ispisujem stack
        STEK.pop();
    }
}
