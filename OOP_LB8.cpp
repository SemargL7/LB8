#include <iostream>
#include <string>

std::string to_binary_string(int n)
{
    std::string result;
    do
    {
        result += (char)('0' + (n % 2));
        n = n / 2;
    } while (n > 0);
    return result;
}

template <typename T>
class JustClass
{
    T* v;
    int size;
public:
    template <typename T> friend class JustClassIter;
    JustClass() {}
    JustClass(T* v, int size) {
        this->v = v;
        this->size = size;
    }
    ~JustClass() {}

    void Input(T* v[], int size) {
        this->v = *v;
        this->size = size;
    }


    void DataTypeSize() {
        int a = 0;
        for (int i = 0; i < size; i++) {
            a += (int)v[i];
        }
        std::cout << to_binary_string(a) << " mirrored" << std::endl;

    }
    void Output() {
        for (int i = 0; i < size; i++) {
            std::cout << v[i] << "\t";
        }
        std::cout << std::endl;
    }
    T Output(JustClass<T>& stk, int i) {
        return stk.v[i];
    }
};

template <typename T>
class JustClassIter
{
    const JustClass<T>& stk;
    int index;
public:
    JustClassIter(const JustClass<T>& s) : stk(s)
    {
        index = 0;
    }
    void operator++()
    {
        index++;
    }
    bool operator()()
    {
        return index != stk.size;
    }
    int operator *()
    {
        return stk.v[index];
    }
};

template <typename T>
bool operator == (const JustClass<T>& l, const JustClass<T>& r)
{
    JustClassIter<T> itl(l);
    JustClassIter<T> itr(r);
    for (; itl(); ++itl, ++itr)
        if (*itl != *itr)
            break;
    return !itl() && !itr();
}


int main()
{
    char arrays_char[] = "132132123";
    char arrays_char2[] = "132832123";
    int arrays_int[] = { 15,15,35,15,50 };
    int arrays_int2[] = { 15,15,35,15,50 };
    double arrays_double[] = { 100.05,105.150,10551.9,10.9 };
    double arrays_double2[] = { 88.05,105.150,1.9,10.9 };

    JustClass<char> e_ch(arrays_char, *(&arrays_char + 1) - arrays_char);
    JustClass<int> e_in(arrays_int, *(&arrays_int + 1) - arrays_int);
    JustClass<double> e_db(arrays_double, *(&arrays_double + 1) - arrays_double);

    JustClass<char> e_ch2(arrays_char2, *(&arrays_char2 + 1) - arrays_char2);
    JustClass<int> e_in2(arrays_int2, *(&arrays_int2 + 1) - arrays_int2);
    JustClass<double> e_db2(arrays_double2, *(&arrays_double2 + 1) - arrays_double2);

    std::cout << "Sum:" << std::endl;
    e_ch.DataTypeSize(); e_in.DataTypeSize(); e_db.DataTypeSize();
    e_ch2.DataTypeSize(); e_in2.DataTypeSize(); e_db2.DataTypeSize();
    std::cout << "Output:" << std::endl;
    e_ch.Output(); e_in.Output(); e_db.Output();
    e_ch2.Output(); e_in2.Output(); e_db2.Output();

    std::cout << "1 == 2 is " << (e_ch == e_ch2) << std::endl;

    std::cout << std::endl;
    std::cout << "1 == 2 is " << (e_in == e_in2) << std::endl;

    std::cout << std::endl;
    std::cout << "1 == 2 is " << (e_db == e_db2) << std::endl;


    getchar(); getchar();
}