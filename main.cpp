#include <iostream>
#include <assert.h>


using namespace std;

char nibble_to_hex(uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char symbols[]="0123456789abcdef";
    return symbols[i];
}

void print_in_hex(uint8_t byte)
{
    cout<<nibble_to_hex(byte>>4)
        <<nibble_to_hex(byte&0x0f);
}

const uint8_t* as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

char bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}

void print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 7; bit >= 0; bit--)
    {
        cout << bit_digit(byte, bit);
        if (bit==0)
            return;
    }
}

void print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

cale (uint16_t op1, char operat, uint16_t op2)
{
    if (operat=='&')
    {
        print_in_hex(&op1, sizeof(op1));
        cout<<operat;
        print_in_hex(&op2, sizeof(op2));
        cout<<"= ";
        uint16_t res;
        res=op1&op2;
        print_in_hex(&res, sizeof(res));
        cout<<'\n';


    }

        if (operat=='|')
    {
        print_in_hex(&op1, sizeof(op1));
        cout<<operat;
        print_in_hex(&op2, sizeof(op2));
        cout<<"= ";
        uint16_t res;
        res=op1|op2;
        print_in_hex(&res, sizeof(res));
    }

        if (operat=='^')
    {
        print_in_hex(&op1, sizeof(op1));
        cout<<operat;
        print_in_hex(&op2, sizeof(op2));
        cout<<"= ";
        uint16_t res;
        res=op1^op2;
        print_in_hex(&res, sizeof(res));
    }
}

struct Student
{
    char name[17];
    uint16_t year;
    float average;
    uint8_t gender:1;
    uint8_t coursere;
    Student* starosta;
};

int main()
{
    /*cout << "Vvedite chislo: ";
    uint8_t i;
    cin>>i;

    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');

    uint8_t u8 = 0x42;
    cout << " u8 bytes: ";
    print_in_hex(&u8, sizeof(u8));
    cout << '\n';

    uint16_t u16 = 0x42;
    cout << "u16 bytes: ";
    print_in_hex(&u16, sizeof(u16));
    cout << '\n';

    uint32_t u32 = 0x42;
    cout << "u32 bytes: ";
    print_in_hex(&u32, sizeof(u32));
    cout << '\n';

    uint8_t t=15;
    print_in_binary(t);

    char operat='|';
    cale(1025, operat, 127);*/

    Student students[3]={{"Nikolay", 2018, 2.4, 0, 1, nullptr}, {"Misha", 2018, 4.0, 1, 1, &students[0]}, {"Marina", 2018, 4.5, 0, 1, &students[0]}};

    cout<<"Addres of students:"<< '\n'
        <<&students<<'\n';
    cout<<"Size of students"<< '\n'
        <<sizeof(students)<< '\n';

    for (Student stud:students)
    {
        cout<<"Addres of student:"<< '\n'
        <<stud.name<<'\n';
        cout<<"Size of student"<< '\n'
        <<sizeof(stud)<< '\n';
    }

    cout<<"Addres of name of student 1: "<< '\n'
        <<students[1].name<< '\n';
    cout<<"Offset of name of student 1: "<< '\n'
        <<offsetof(Student, name)<< '\n';
    cout<<"Size of name of student 1: "<< '\n'
        <<sizeof(students[1].name)<< '\n';


    return 0;
}
