#ifndef MYSTRANG_H
#define MYSTRANG_H


#include <ostream>
class MyStrang
{
public:
    ~MyStrang();
    MyStrang();
    MyStrang(const char *cstr);
    MyStrang(const MyStrang& otherString);
    MyStrang( MyStrang && stringToMove);

    const MyStrang& operator=(const MyStrang& otherString);
    const MyStrang& operator=(MyStrang&& stringToMove);
    const MyStrang& operator+=(const MyStrang& otherString);


    bool operator==(const MyStrang& otherString)  const;


    char& operator[](int ix);
    char& operator[](int ix) const;


    int size() const;
    const char* c_str() const;
private:
    char* m_cstr;
    int   m_size;
};

bool operator!= (const MyStrang& a, const MyStrang& b);
std::ostream& operator<<(std::ostream& out,const MyStrang& str);
#endif // MYSTRANG_H
