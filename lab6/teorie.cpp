#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class A
{
    int x, y;

public:
    A(int x, int y) : x(x), y(y) {}

    friend std::ostream &operator<<(std::ostream &output, const A &p)
    {
        output << p.x << " " << p.y << " ";
        return output;
    }
    bool operator<(const A &p)
    {
        return this->x < p.x ? true : false;
    }
    friend bool compare_y(const A &a, const A &b);
};
bool compare_y(const A &a, const A &b)
{
    return a.y < b.y ? true : false;
}

// int main()
// {
//     // std::vector<A> as;
//     // as.push_back(A(3, 10)); // as[0]=3
//     // as.push_back(A(2, 2)); // as[1]=2
//     // as.push_back(A(1, 1)); // as[2]=1

//     // // metoda 1 - ai nevoie de indecsi
//     // for (int i = 0; i < as.size(); i++)
//     //     std::cout << as[i] << " ";
//     // std::cout << std::endl;

//     // // metoda 2 - nu ai nevoie de indecsi, ci doar de valori
//     // for (A a : as)
//     // {
//     //     std::cout << a << " ";
//     // }
//     // std::cout << std::endl;

//     // // metoda 3 - iterare cu iteratori
//     // std::vector<A>::iterator i;
//     // for (i = as.begin(); i != as.end(); i++)
//     //     std::cout << *i << " ";
//     // std::cout << std::endl;

//     // std::sort(as.begin(), as.end(), compare_y);
//     // for (A a : as)
//     // {
//     //     std::cout << a << " ";
//     // }
//     // std::cout << std::endl;

//     std::string s1 = "s1";
//     std::string s2 = "s2";
//     std::string s3 = s1 + s2;

//     return EXIT_SUCCESS;
// }