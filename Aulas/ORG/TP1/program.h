#ifndef PROGRAM_H
#define PROGRAM_H

#include "instruction.h"
#include "cpu.h"
#include "ram.h"

#include <stdbool.h>

void sum(Cpu *cpu, Ram *ram, int add1, int add2);
void subtraction(Cpu *cpu, Ram *ram, int add1, int add2);
void setValue(Cpu *cpu, Ram *ram, int add, int value);
int getValue(Cpu *cpu, Ram *ram, int add);
int multiplication(Cpu *cpu, Ram *ram, int multiplier, int multiplicand);
int division(Cpu *cpu, Ram *ram, int dividend, int divisor);
int remainderOfDivision(Cpu *cpu, Ram *ram, int dividend, int divisor);
int fibonacci(Cpu *cpu, Ram *ram, int nesim);
int factorin(Cpu *cpu, Ram *ram, int factorial);
int exponentiation(Cpu *cpu, Ram *ram, int base, int exponent);
bool primeNumber(Ram *ram, Cpu *cpu, int x);
int squareRoot(Cpu *cpu, Ram *ram, int rooting);
int mdc(Cpu *cpu, Ram *ram, int a, int b);
int delta(Ram *ram, Cpu *cpu, int a, int b, int c);
int bhaskara(Cpu *cpu, Ram *ram, int a, int b, int c);
int pitagoras(Cpu *cpu, Ram *ram, int hypotenuse, int cathetusA, int cathetusB);
int pitagorasCathetus(Ram *ram, Cpu *cpu, int hypotenuse, int cathetus);
int pitagorasHypothenuse(Ram *ram, Cpu *cpu, int cathetusA, int cathetusB);

/*void random(Ram *ram, Cpu *cpu, int qtdInstruction){
    Instruction *instruction = createInstruction(qtdInstruction);
    int ramSize = 1000;
    ram = createRandomRam(ramSize);

    for(int i = 0; i < qtdInstruction-1; i++){
        setInstruction(instruction, i, rand()%1000, rand()%1000, rand()%1000, rand()%2);
    }

    setInstruction(instruction, qtdInstruction-1, 0, 0, 0, -1);

    cpu = createCpu();
    setProgram(cpu, instruction);
    initeCPU(cpu, ram);
    destroyCpu(cpu);
    destroyRam(ram);
    destroyInstruction(instruction);
}*/

void sum(Cpu *cpu, Ram *ram, int add1, int add2){
    Instruction *instruction = createInstruction(2);

    setInstruction(instruction, 0, add1, add2, add1, 0);
    setInstruction(instruction, 1, -1, -1, -1, -1);
    setProgram(cpu, instruction);
    initeCPU(cpu, ram);

    destroyInstruction(instruction);
}

void subtraction(Cpu *cpu, Ram *ram, int add1, int add2){
    Instruction *instruction = createInstruction(2);

    setInstruction(instruction, 0, add1, add2, add1, 1);
    setInstruction(instruction, 1, -1, -1, -1, -1);
    setProgram(cpu, instruction);
    initeCPU(cpu, ram);

    destroyInstruction(instruction);
}

void setValue(Cpu *cpu, Ram *ram, int add, int value){
    Instruction *instruction = createInstruction(2);
    setReg1(cpu, value);

    setInstruction(instruction, 0, 1, add, -1, 2);
    setInstruction(instruction, 1, -1, -1, -1, -1);
    setProgram(cpu, instruction);
    initeCPU(cpu, ram);

    destroyInstruction(instruction);
}

int getValue(Cpu *cpu, Ram *ram, int add){
    Instruction *instruction = createInstruction(2);

    setInstruction(instruction, 0, 1, add, -1, 3);
    setInstruction(instruction, 1, -1, -1, -1, -1);
    setProgram(cpu, instruction);
    initeCPU(cpu, ram);

    destroyInstruction(instruction);

    return getReg1(cpu);
}

int multiplication(Cpu *cpu, Ram *ram, int multiplier, int multiplicand){
    ram = createEmptyRam(4);
    cpu = createCpu();

    if(multiplier < 0 && multiplicand < 0){
        setValue(cpu, ram, 2, multiplicand);
        subtraction(cpu, ram, 1, 2);

        setValue(cpu, ram, 2, 0);
        setValue(cpu, ram, 3, multiplier);
        subtraction(cpu, ram, 2, 3);
    }
    else if(multiplier < 0 && multiplicand > 0){
        setValue(cpu, ram, 1, multiplier);
        setValue(cpu, ram, 2, multiplicand);
    }
    else{
        setValue(cpu, ram, 1, multiplicand);
        setValue(cpu, ram, 2, multiplier);
    }

    for(int i = 0; i < getValue(cpu, ram, 2); i++){
        sum(cpu, ram, 0, 1);
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);
    
    return aux;
}

int division(Cpu *cpu, Ram *ram, int dividend, int divisor){
    ram = createEmptyRam(4);
    cpu = createCpu();

    // divisao de um numero negativo e um positivo
    if(dividend > 0 && divisor < 0){
        setValue(cpu, ram, 0, dividend);
        setValue(cpu, ram, 2, divisor);
        subtraction(cpu, ram, 1, 2);
        setValue(cpu, ram, 2, 0);
    }
    if(dividend < 0 && divisor > 0){
        setValue(cpu, ram, 1, dividend);
        subtraction(cpu, ram, 0, 1);
        setValue(cpu, ram, 1, divisor);
    }

    // divisao de dois numeros negativos
    if(dividend < 0 && divisor < 0){
        setValue(cpu, ram, 1, dividend);
        subtraction(cpu, ram, 0, 1);
        setValue(cpu, ram, 1, 0);
        setValue(cpu, ram, 2, divisor);
        subtraction(cpu, ram, 1, 2);
        setValue(cpu, ram, 2, 0);
    }

    // divisao de dois numeros positivos
    if(dividend > 0 && divisor > 0){
        setValue(cpu, ram, 0, dividend);
        setValue(cpu, ram, 1, divisor);
    }

    setValue(cpu, ram, 3, 1);

    while(getValue(cpu, ram, 0) >= getValue(cpu, ram, 1)){
        subtraction(cpu, ram, 0, 1);
        sum(cpu, ram, 2, 3);
    }

    // correcao do sinal em divisao de um numero negativo e um positivo
    if((dividend < 0) ^ (divisor < 0)){
        setValue(cpu, ram, 1, 0);
        subtraction(cpu, ram, 1, 2);
    }

    int aux = getValue(cpu, ram, 2);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int remainderOfDivision(Cpu *cpu, Ram *ram, int dividend, int divisor){
    // essa funcao so funciona com a divisao de numeros positivos
    ram = createEmptyRam(3);
    cpu = createCpu();

    setValue(cpu, ram, 0, dividend);
    setValue(cpu, ram, 1, divisor);

    setValue(cpu, ram, 2, division(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    setValue(cpu, ram, 1, multiplication(NULL, NULL, getValue(cpu, ram, 1), getValue(cpu, ram, 2)));
    subtraction(cpu, ram, 0, 1);

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int fibonacci(Cpu *cpu, Ram *ram, int nesim){
    ram = createEmptyRam(3);
    cpu = createCpu();

    setValue(cpu, ram, 2, 1);
    for(int i = nesim; i >= 1; i--){
        setValue(cpu, ram, 0, getValue(cpu, ram, 1));
        setValue(cpu, ram, 1, getValue(cpu, ram, 2));
        sum(cpu, ram, 0, 1);
        setValue(cpu, ram, 2, getValue(cpu, ram, 0));
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int factorin(Cpu *cpu, Ram *ram, int factorial){
    ram = createEmptyRam(2);
    cpu = createCpu();

    setValue(cpu, ram, 0, 1);

    for(int i = 2; i <= factorial; i++){
        setValue(cpu, ram, 1, i);

        setValue(cpu, ram, 0, multiplication(cpu, ram, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int exponentiation(Cpu *cpu, Ram *ram, int base, int exponent){
    ram = createEmptyRam(3);
    cpu = createCpu();

    setValue(cpu, ram, 0, 1);
    setValue(cpu, ram, 1, base);
    setValue(cpu, ram, 2, exponent);

    for(int i = getValue(cpu, ram, 2); i > 0; i--){
        setValue(cpu, ram, 0, multiplication(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

bool primeNumber(Ram *ram, Cpu *cpu, int x){
    ram = NULL;
    cpu = createCpu();

    setReg1(cpu, x);

    if(getReg1(cpu) <= 2){
        destroyCpu(cpu);

        return false;
    }

    for(int i = 2; i < getReg1(cpu); i++){
        if(!division(NULL, NULL, getReg1(cpu), i)){
            destroyCpu(cpu);

            return false;
        }
    }

    destroyCpu(cpu);

    return true;
}

int squareRoot(Cpu *cpu, Ram *ram, int rooting){
    ram = createEmptyRam(3);
    cpu = createCpu();

    setValue(cpu, ram, 2, rooting);

    for(int i = 1; getValue(cpu, ram, 1) < getValue(cpu, ram, 2); i++){
        setValue(cpu, ram, 0, i);
        setValue(cpu, ram, 1, multiplication(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 0)));
    }

    if(remainderOfDivision(NULL, NULL, getValue(cpu, ram, 2), getValue(cpu, ram, 1))){
        destroyCpu(cpu);
        destroyRam(ram);

        return 0;
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int mdc(Cpu *cpu, Ram *ram, int a, int b){
    ram = createEmptyRam(3);
    cpu = createCpu();

    setValue(cpu, ram, 0, a);
    setValue(cpu, ram, 1, b);

    while(getValue(cpu, ram, 1) != 0){
        setValue(cpu, ram, 2, remainderOfDivision(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));

        setValue(cpu, ram, 0, getValue(cpu, ram, 1));
        setValue(cpu, ram, 1, getValue(cpu, ram, 2));
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int delta(Ram *ram, Cpu *cpu, int a, int b, int c){
    ram = createEmptyRam(3);
    cpu = createCpu();

    setValue(cpu, ram, 0, a);
    setValue(cpu, ram, 1, c);

    setValue(cpu, ram, 1, multiplication(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    setValue(cpu, ram, 1, multiplication(NULL, NULL, getValue(cpu, ram, 1), 4));

    setValue(cpu, ram, 0, b);
    setValue(cpu, ram, 0, exponentiation(NULL, NULL, getValue(cpu, ram, 0), 2));

    subtraction(cpu, ram, 0, 1);

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int bhaskara(Cpu *cpu, Ram *ram, int a, int b, int c){
    ram = createEmptyRam(4);
    cpu = createCpu();

    setValue(cpu, ram, 1, c);
    setValue(cpu, ram, 2, b);
    setValue(cpu, ram, 3, a);

    subtraction(cpu, ram, 0, 2);
    setValue(cpu, ram, 1, delta(ram, cpu, getValue(cpu, ram, 3), getValue(cpu, ram, 2), getValue(cpu, ram, 1)));
    setValue(cpu, ram, 2, multiplication(NULL, NULL, getValue(cpu, ram, 3), 2));

    if(getValue(cpu, ram, 1) < 0){
        printf("\nNão possui raiz");

        destroyCpu(cpu);
        destroyRam(ram);
        return 0;
    }
    else if(getValue(cpu, ram, 1) == 0){
        sum(cpu, ram, 0, 1);
        setValue(cpu, ram, 3, division(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 2)));
        printf("\nDuas raízes iguais: %d", getValue(cpu, ram, 3));
        
        destroyCpu(cpu);
        destroyRam(ram);
        return 1;
    }
    else{
        printf("\nDuas raizes diferentes:\n");

        setValue(cpu, ram, 3, getValue(cpu, ram, 2));
        setValue(cpu, ram, 2, getValue(cpu, ram, 1));
        setValue(cpu, ram, 1, getValue(cpu, ram, 0));

        sum(cpu, ram, 0, 2);
        setValue(cpu, ram, 0, division(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 3)));

        subtraction(cpu, ram, 1, 2);
        setValue(cpu,ram, 1, division(NULL, NULL, getValue(cpu, ram, 1), getValue(cpu, ram, 3)));
        
        printf("X1 = %d\n", getValue(cpu, ram, 0));
        printf("X2 = %d", getValue(cpu, ram, 1));

        destroyCpu(cpu);
        destroyRam(ram);
        return 1;
    }

    destroyCpu(cpu);
    destroyRam(ram);
    return 0;
}

int pitagoras(Cpu *cpu, Ram *ram, int hypotenuse, int cathetusA, int cathetusB){
    ram = createEmptyRam(2);
    cpu = createCpu();

    if(hypotenuse < 0){
        setValue(cpu, ram, 0, cathetusA);
        setValue(cpu, ram, 1, cathetusB);

        setValue(cpu, ram, 0, pitagorasHypothenuse(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    }
    if(cathetusA < 0){
        setValue(cpu, ram, 0, hypotenuse);
        setValue(cpu, ram, 1, cathetusB);

        setValue(cpu, ram, 0, pitagorasCathetus(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    }
    if(cathetusB < 0){
        setValue(cpu, ram, 0, hypotenuse);
        setValue(cpu, ram, 1, cathetusA);

        setValue(cpu, ram, 0, pitagorasCathetus(NULL, NULL, getValue(cpu, ram, 0), getValue(cpu, ram, 1)));
    }

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int pitagorasCathetus(Ram *ram, Cpu *cpu, int hypotenuse, int cathetus){
    ram = createEmptyRam(2);
    cpu = createCpu();

    setValue(cpu, ram, 0, hypotenuse);
    setValue(cpu, ram, 0, exponentiation(NULL, NULL, getValue(cpu, ram, 0), 2));
    setValue(cpu, ram, 1, cathetus);
    setValue(cpu, ram, 1, exponentiation(NULL, NULL, getValue(cpu, ram, 1), 2));

    subtraction(cpu, ram, 0, 1);

    setValue(cpu, ram, 0, squareRoot(NULL, NULL, getValue(cpu, ram, 0)));

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

int pitagorasHypothenuse(Ram *ram, Cpu *cpu, int cathetusA, int cathetusB){
    ram = createEmptyRam(2);
    cpu = createCpu();

    setValue(cpu, ram, 0, cathetusA);
    setValue(cpu, ram, 0, exponentiation(NULL, NULL, getValue(cpu, ram, 0), 2));
    setValue(cpu, ram, 1, cathetusB);
    setValue(cpu, ram, 1, exponentiation(NULL, NULL, getValue(cpu, ram, 1), 2));

    sum(cpu, ram, 0, 1);

    setValue(cpu, ram, 0, squareRoot(NULL, NULL, getValue(cpu, ram, 0)));

    int aux = getValue(cpu, ram, 0);

    destroyCpu(cpu);
    destroyRam(ram);

    return aux;
}

#endif