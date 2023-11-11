#include <iostream>
#include <string.h>

#include <assert.h>

#include "MyStrang.h"
using namespace std;

MyStrang mittNamn() { return "Ragnar"; }
void anropByValue(MyStrang str) { cout << str << endl; }
void anropByRef(const MyStrang &str) { cout << str << endl; }
bool arVersaler(const MyStrang &str) {
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != toupper(str[i]))
            return false;
    return true;
}
void konverteraTillVersaler(MyStrang &str) {
    for (int i = 0; i < str.size(); ++i)
        str[i] = toupper(str[i]);
}
MyStrang versalstrang(const MyStrang &str) {
    MyStrang kopia = str;
    konverteraTillVersaler(kopia);
    return kopia;
}
void testaStrang() {
    MyStrang str1;
    assert(str1 == "");
    MyStrang str2 = "Hej";
    assert(str2.size() == 3);
    str2 = "Sol";
    assert(str2.size() == 3);
    assert(str2[1] == 'o');
    str2 += "sken!";
    assert(str2.size() == 8);
    assert(str2 == "Solsken!");
    MyStrang str3 = mittNamn();
    anropByValue(str3);
    anropByRef(str3);
    assert(!arVersaler(str2));
    konverteraTillVersaler(str2);
    assert(arVersaler(str2));
    MyStrang str4 = versalstrang("hej");
    assert(arVersaler(str4));
    cout << "testaStrang lyckades" << endl;
}
int main() {
    testaStrang();
    cout << "Hello World!" << endl;
    return 0;
}
