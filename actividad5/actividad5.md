# Conceptos de Sistemas Operativos

## 1. Tipos de Kernel y sus diferencias

### Monolítico

- **Descripción**: Un kernel monolítico es un tipo de sistema operativo donde todo el software de nivel de sistema se ejecuta en el modo supervisor (kernel mode). Este incluye no solo el núcleo del sistema operativo, sino también los drivers de dispositivos, el sistema de archivos, y el stack de red.
- **Ventajas**: Alta eficiencia y rendimiento, debido a que todas las operaciones se ejecutan en el mismo espacio de memoria.
- **Desventajas**: Menor seguridad y estabilidad, ya que un fallo en un componente puede afectar todo el sistema.

### Microkernel

- **Descripción**: En un sistema operativo con microkernel, solo las funciones esenciales del núcleo se ejecutan en modo kernel, como la comunicación entre procesos y la gestión de memoria. Los servicios como drivers de dispositivos y sistemas de archivos se ejecutan en espacio de usuario.
- **Ventajas**: Mayor seguridad y estabilidad, ya que los servicios están aislados unos de otros.
- **Desventajas**: Puede tener menor rendimiento debido al overhead de comunicación entre el espacio de usuario y el espacio de kernel.

### Híbrido

- **Descripción**: Un kernel híbrido intenta combinar aspectos de kernels monolíticos y microkernels. Ejecuta algunos servicios en modo kernel mientras mantiene otros en modo usuario.
- **Ventajas**: Balance entre rendimiento y seguridad.
- **Desventajas**: La complejidad de su diseño puede llevar a dificultades en la depuración y mantenimiento.

## 2. User vs Kernel Mode

- **User Mode**: Modo en el que se ejecutan las aplicaciones del usuario. Tiene restricciones de acceso a la memoria y a los recursos del hardware para proteger la integridad del sistema operativo.
- **Kernel Mode**: Modo en el que el kernel del sistema operativo tiene acceso completo al hardware y a toda la memoria. Es necesario para realizar tareas de bajo nivel que requieren un control total del sistema.

### Transiciones entre modos:

- **System Call**: Los programas en user mode hacen solicitudes al sistema operativo (llamadas al sistema) para realizar tareas que requieren privilegios de kernel mode.

## 3. Interruptions vs Traps

### Interruptions (Interrupciones)

- **Descripción**: Una interrupción es una señal generada por el hardware o el software que interrumpe el flujo normal de ejecución del procesador.
- **Propósito**: Manejar eventos como entrada/salida o temporizadores. Permiten al sistema operativo responder de manera eficiente a los eventos externos.

### Traps (Excepciones)

- **Descripción**: Una trampa es un tipo de interrupción generada internamente por el software (por ejemplo, errores o llamadas al sistema).
- **Propósito**: Proporcionar una manera segura de cambiar al modo kernel para ejecutar código de sistema operativo, como manejar errores o ejecutar una llamada al sistema.