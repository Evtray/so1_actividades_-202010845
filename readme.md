### Pregunta 1: ¿Cuántos procesos únicos son creados?

```c
pid_t pid;
pid = fork();
if (pid == 0) { 
    fork(); 
    thread_create(...);
}
fork();
```

- Al inicio tenemos 1 proceso (el proceso padre).
- Con el primer `fork()`, se crean 2 procesos (el proceso padre y el hijo).
- El segundo `fork()` solo ocurre en el hijo del primer `fork()`, por lo que después de este segundo `fork()` hay 3 procesos en total.
- El tercer `fork()` se ejecuta en ambos procesos que existen hasta ese punto (padre y descendientes), lo que dobla la cantidad de procesos de 3 a 6.

**Resultado: Se crean 6 procesos únicos en total.**

### Pregunta 2: ¿Cuántos hilos únicos son creados?

```c
if (pid == 0) {
    thread_create(...);
}
```

Esto indica que el hilo solo se crea en el segundo proceso (el hijo del primer `fork()`).

**Resultado: Se crea 1 hilo único.**

### Pregunta 3: ¿Cuántos hilos únicos son creados?

```c
pid_t pid;

pid = fork();
if (pid == 0) {
    fork();
    thread_create(...);
}
fork();
```

#### Procesos creados:

- Inicialmente, tenemos 1 proceso principal.
- El primer `fork()` crea un nuevo proceso. Ahora hay 2 procesos (el proceso padre y el proceso hijo).
- Si `pid == 0`, si estamos en el proceso hijo, se ejecuta otro `fork()` lo que genera otro proceso
- El segundo `fork()` fuera del `if` se ejecuta tanto en el proceso padre como en todos los procesos existentes hasta este punto.

**Total de procesos creados: 5 procesos únicos**.

#### Hilos creados:

1. La función `thread_create(...)` se llama únicamente dentro del bloque `if (pid == 0)`, dentro del segundo proceso que se crea
2. Solo se ejecuta una vez en el proceso hijo del primer `fork()`, se crea un solo hilo único.

**Total de hilos creados: 1 hilo único.**