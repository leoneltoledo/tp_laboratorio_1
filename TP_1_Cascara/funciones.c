#ifndef FUNCIONES_C
#define FUNCIONES_C




#endif // FUNCIONES_C


int sumar(int A,int B) {
    int resp;
    resp = A + B;
    return resp;
}

int restar(int A,int B) {
    return (A - B);
}

int dividir(int A,int B) {
    return (A / B);
}

int multiplicar(int A,int B) {
    return (A * B);
}

int factorial(int A){
    int resultado;
    if (A>1){
        resultado = A*factorial(A-1);
    }
    else{
        resultado=1;
    }
    return resultado;
}
