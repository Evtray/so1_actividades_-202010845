# Systemd Unit

Este servicio de `systemd` imprime un saludo junto con la fecha y hora actual cada segundo.

## Instalación

1. **Crear el Script:**

   Crea un script Bash en `/usr/local/bin/saludo.sh`:

   ```bash

   while true
   do
       echo "Hola, la fecha actual es: $(date)"
       sleep 1
   done
    ```
    Ejecutar
    ```bash
    sudo chmod +x /usr/local/bin/saludo.sh
    ```



2. **Crear el Script:**

    Crea un archivo de servicio en `/etc/systemd/system/saludo.service`:

    ```bash

    [Unit]
    Description=Greeting Service that prints a greeting and the current date every second

    [Service]
    ExecStart=/usr/local/bin/greeting.sh
    Restart=always

    [Install]
    WantedBy=multi-user.target
    ```
    Habilitar el servicio para que se inicie automáticamente al arrancar 
    el sistema y luego inícialo manualmente.

    ```bash
    sudo systemctl enable saludo.service
    sudo systemctl start saludo.service
    ```

