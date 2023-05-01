#include <iostream>
#include <thread>

void func()
{
    std::cout << "Hola, soy un thread!" << std::endl;
}

int main()
{
    std::thread t(func); // Crea un nuevo thread y lo ejecuta
    t.join(); // Espera a que el thread termine
    return 0;
}
