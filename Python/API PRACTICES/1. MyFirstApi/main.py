'''
Para ejecutar FLASK es recomendable ejecutarlo en un entorno virtual, aca les dejo el proceso par hacerlo:
1. En la misma carpeta escribes ''python3 -m venv mi_entorno'', en mi_entorno puedes poner otro nombre.
2. Luego para activar el entorno escribes "source mi_entorno/bin/activate", en el mi_entorno", reemplazas
    por el nombre que le pusiste al entorno de Flask.
3. Cuando vayas a correr la API, debes hacerlo desde la misma consola, si lo corres con el boton de VSCode
    puede que te de error. Recomendable hacer "python nombre_de_la_aplicacion.py"

EXTRA:
1. En VSCode Existe POSTMAN, puedes instalarlo mejor en VSCode si tu sistema operativo es linux y no quieres
    enrredarte.
2. Recuerda configurar bien la peticion POST en POSTMAN ya sea javascript, JSON, HTML, XML, etc.
pd: Elvis, estuviste 30 minutos viendo el error y te diste cuenta cuando maximisaste la pantalla.

Hasta aca llega el reporte del dia de hoy.
'''


#La cabezera importante
from flask import Flask, jsonify, request
app = Flask(__name__)

@app.route('/')
def root():
    return "Home"

'''
GET -> Obtener informacion
POST -> Crear informacion
PUT -> Actualizar infromacion
DELETE -> Borrar informacion
'''

@app.route("/users/<user_id>")
def get_user(user_id):
    user = {"id": user_id,
        "name": "test",
        "telefono": "999-666-333"}
        #/users/2654?query=query_test
    query = request.args.get('query')
    if query:
        user["query"] = query
    return jsonify(user), 200

@app.route('/users', methods=["POST"])
def create_user():
    data = request.get_json()
    #ata = ["status"] = "user created"
    return jsonify(data), 201

#SIEMPRE SE PONE AL FINAL
if __name__ == "__main__":
    app.run(debug=True)
