#include "program.h"
#include "ram.h"
#include "instruction.h"
#include "cpu.h"

#include <stdbool.h>
#include <string.h>

int main(){
    Cpu *cpu = NULL;
    Ram *ram = NULL;

    //int x = multiplication(cpu, ram, -10, 15);
    //int x = division(cpu, ram, 11, 2);
    //int x = remainderOfDivision(cpu, ram, 11, 2);
    //int x = fibonacci(cpu, ram, 5);
    //int x = factorin(cpu, ram, 10);
    //int x = exponentiation(cpu, ram, 4, 2);
    //bool x = primeNumber(ram, cpu, 3);
    //int x = squareRoot(cpu, ram, 2);
    //int x = mdc(cpu, ram, 12, 18);
    //int x = delta(ram, cpu, 1, 2, 5);
    //int x = bhaskara(cpu, ram, 1, -5, 6);
    int x = pitagoras(cpu, ram, 5, 3, -1);
    printf("\nRESULTADO: %d\n", x);

    return 0;
}