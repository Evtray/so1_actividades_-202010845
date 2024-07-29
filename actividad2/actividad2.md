# Script
    # var para el usuario
    USER="evtray"

    # consultar la api
    RESPONSE=$(curl -s "https://api.github.com/users/${USER}")

    # Usando jq extraer id, user y fecha
    ID=$(echo "$RESPONSE" | jq -r '.id')
    CREATEDAT=$(echo "$RESPONSE" | jq -r '.created_at')

    # Mensaje a mostrar
    MESSAGE="Hola ${USER}. User ID: ${ID}. Cuenta fue creada el: ${CREATEDAT}."

    # Fecha de hoy
    FECHA=$(date +%F)

    # Crea el directorio /tmp/<fecha>
    DIR="/tmp/${FECHA}"
    mkdir -p "$DIR"
    echo "$DIR"

    # Guardar el archivo
    FILE="${DIR}/saludos.log"
    echo "$MESSAGE" > "$FILE"

    # Mostrar el mensaje
    echo "$MESSAGE"

# Ejemplo
    /tmp/2024-07-28
    Hola evtray. User ID: 68375021. Cuenta fue creada el: 2020-07-16T09:13:46Z.



# Configurar el cron job

    Ejecutar 
        crontab -e
    
    Agregar el cron job
        */5 * * * * edwin /home/Desktop/evtray.sh

    Guardar y salir
    Verificar cron
        crontab -l

