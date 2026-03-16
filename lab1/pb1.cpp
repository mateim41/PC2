#include <iostream>

int main()
{
    int a;
    double x;
    char nume[100];
    std::cin >> a >> x >> nume;
    std::cout << a << " " << x << " " << nume << std::endl;

    int a1{10};
    double x1{420.69};
    char *nume1{"Matei"};
    std::cout << a1 << " " << x1 << " " << nume1 << std::endl;

    int a2(10);
    double x2(1069.420);
    char nume2[]("Matei");
    std::cout << a2 << " " << x2 << " " << nume2 << std::endl;

    return EXIT_SUCCESS;
}