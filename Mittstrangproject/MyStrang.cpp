#include "MyStrang.h"
#include <iostream>

MyStrang::~MyStrang()
{
    delete[] m_cstr;   // Frigör dynamiskt allokerat minne
    m_cstr = nullptr;

    //delete [] this; här om vi ska deleta this det betyder att vi deleta pekare som pekar på den hela objektet
    //men vi vill att den deleta pekare som finns inne på den här class.
}

MyStrang::MyStrang()
{
    ////m_cstr= new char[1];  är det rätt eller ska man låta en tom char som ner..
    m_size = 0;
    m_cstr = nullptr;
    //    m_cstr =   new char;
    //    m_cstr[m_size] = '\0';
}

MyStrang::MyStrang(const char *cstr)
{
    if(cstr == nullptr){
        //        m_cstr= new char [1];
        //        *m_cstr=   '\0';
        m_cstr= nullptr;
        m_size=       0;

    }
    if(cstr != nullptr){

        m_size = 0;/// här behöver vi ger värdet noll till m_size för att den metoden själv anropas
        // och kompailer läser inte m_size =0; som finns öppe om vi anropar bara den här metod
        // Beräkna storleken på strängen "h'e'j'0"
        for(int i =0; cstr[i]!= 0; i++){
            m_size +=1;
        }
        m_cstr = new char [m_size +1];
        for(int i=0; i<m_size ; i++){
            m_cstr[i]= cstr[i];
        }
        // nuull terminert the string
        m_cstr[m_size]='\0';
        // *m_cstr = '\0'; fel
        ///m_size =0;  fel
    }


    //    if (cstr==nullptr){
    //       std:: string tomStrang =0;
    //       char *b=nullptr;
    //       tomStrang=b;
    //       b=m_cstr;

    //    }


}

MyStrang::MyStrang(const MyStrang &otherString): MyStrang(){
    //  otherString.m_size= m_size;
    m_size = otherString.m_size;
    m_cstr = new char[m_size +1];
    for (int i = 0; i < m_size; i++){
        m_cstr[i] = otherString[i];
    }
    //m_cstr[m_size] = '\0';
    m_size = 0;
}

MyStrang::MyStrang(MyStrang &&stringToMove){
    //  this->m_cstr = stringToMove.m_cstr; den här uttryckt är rätt den ersättar rader 64/65
    m_cstr = stringToMove.m_cstr;
    m_size=stringToMove.m_size;
    stringToMove.m_cstr = nullptr;
    stringToMove.m_size = 0;
}

const MyStrang &MyStrang::operator=(const MyStrang &otherString)
{
    //    Sträng str = ....
    //    Sträng other = ...
    //    str = other;
    if (this == &otherString)
        return *this;

    //    MyStrang(otherString.m_cstr);
    //    return *this;

    delete [] m_cstr;// vad är skilnaden mellan att cleana första konstroktorn och allokeera en byte ??
    ///*m_cstr= '\0'; här kan vi inte använda den för att den betyder att vi nollställat första index i
    /// arrayen som pekare pekar på.
    m_size = otherString.m_size;
    m_cstr = new char[m_size +1];
    for (int i = 0; i < m_size; i++){
        m_cstr[i] = otherString[i];
    }
    m_cstr[m_size] = '\0';
    //m_cstr = otherString.m_cstr;
    //return otherString.m_cstr;

    //    this; // MyString*
    //    *this; // MyString

    return *this;
}


const MyStrang &MyStrang:: operator=(MyStrang&& stringToMove)
{
    m_cstr = stringToMove.m_cstr;
    m_size=stringToMove.m_size;
    stringToMove.m_cstr = nullptr;
    stringToMove.m_size = 0;
    return *this;
}

const MyStrang &MyStrang::operator+=(const MyStrang &otherString)
{
    //    Operatorn += skall förlänga den aktuella strängen med högerledet.
    //    Räkna ut den totala längden. Allokera ny sträng av denna storlek.
    //    Kopiera in data till den nya strängen, och delete:a den gamla.
    //    (Om du vill kan du istället allokera en sträng som är längre än vad
    //     som behövs.
    
    
    
    
    
    
    int new_size = m_size + otherString.m_size;

    // this->m_size = new_size;
    //char *new_strang = new char[new_size+1];
    char *new_strang= new char [new_size+1];
    for (int i = 0; i < m_size; i++) {
        new_strang[i] = m_cstr[i];
    }
    for (int i = 0; i < otherString.m_size; i++) {
        new_strang[m_size + i] = otherString.m_cstr[i];
    }
    new_strang[new_size] = '\0';//// här betyder att jag dlagt i sista index den här
    //karaktär betyder det slutet av strängen.....
    //new_strang = nullptr;
    delete[] m_cstr;
    m_cstr = new_strang;
    m_size = new_size;
    return *this;
    //    const MyStrang b= this->m_cstr + otherString.m_cstr;
    /// här ersätter den här raden alla kod som jag skriivit tidigare..



    //    //*this = otherString.m_size +m_size;
    //    return otherString + this;
}

bool MyStrang::operator==(const MyStrang &otherString) const
{
    if (m_size!= otherString.m_size)
        return false;
    for(int i=0 ; i < m_size ;i++)
        if((*this)[i] != otherString[i])
            return false;
    return true;


    //    int i=0;
    //    while ((*this)[i] != 0  &&  otherString[i] == (*this)[i]){
    //        i++;

    //    }

    //    if((*this)[i]== otherString[i])
    //        return true;
    //    return false;
}


char &MyStrang::operator[](int ix) {
    return m_cstr[ix];
}

char &MyStrang::operator[](int ix) const
{
    return m_cstr[ix];
}



int MyStrang::size() const
{
    return m_size;
}

const char *MyStrang::c_str() const
{
    return m_cstr;
}

bool operator!=(const MyStrang &a, const MyStrang &b)
{
    return !(a==b);
}

std::ostream &operator<<(std::ostream &out, const MyStrang &str)
{
    return out << str.c_str();
}
