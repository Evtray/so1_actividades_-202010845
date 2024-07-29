USER="evtray"


RESPONSE=$(curl -s "https://api.github.com/users/${USER}")


ID=$(echo "$RESPONSE" | jq -r '.id')
CREATEDAT=$(echo "$RESPONSE" | jq -r '.created_at')


MESSAGE="Hola ${USER}. User ID: ${ID}. Cuenta fue creada el: ${CREATEDAT}."


FECHA=$(date +%F)


DIR="/tmp/${FECHA}"
mkdir -p "$DIR"
echo "$DIR"

FILE="${DIR}/saludos.log"
echo "$MESSAGE" > "$FILE"


echo "$MESSAGE"
