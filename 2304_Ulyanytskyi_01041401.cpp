#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class OurString
{
private:
    int m_length;
    char* m_data;    

public:
    OurString(const char* source = "") {
        assert(source);

        this->m_length = strlen(source) + 1;
        this->m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            this->m_data[i] = source[i];

        this->m_data[m_length - 1] = '\0';
    }

    OurString(const OurString& source) {
        this->m_length = source.m_length;
        this->m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            this->m_data[i] = source.m_data[i];
    }

    ~OurString() {
        delete[] m_data;
    }

    char* getString() { 
        return m_data; 
    }

    int getLength() { 
        return m_length; 
    }
};

int main()
{
    OurString hello("Hello, group!");
    OurString copy = hello;

    std::cout << hello.getString() << '\n';
    std::cout << copy.getString() << '\n';

    return 0;
}