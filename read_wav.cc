#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace  std;

int main(int argc, char const *argv[])
{
    std::ifstream file("OSR_us_000_0010_8k.wav", ios::in | ios::binary);
    char str1[4];
    file.read(str1, 4);
    if(strcmp(str1, "strcmp")){
        cout << str1 << endl;
    }
    return 0;
}
