from flask import Flask, jsonify, request, render_template
import json

from sklearn.naive_bayes import MultinomialNB
from sklearn.naive_bayes import GaussianNB
from sklearn.externals import joblib

app = Flask(__name__)


@app.route('/' , methods = ["GET"])
def index():
    return render_template("formulario.html")


@app.route('/classificar', methods = ["POST"])
def calssificador():
    
    cor = request.form.get('cor')
    tamanho = request.form.get('tamanho')
    tipo = request.form.get('tipo')
    pessoa =  request.form.get('pessoa')
   
  
   
  

    modelo_NB = GaussianNB()
    #Carrega o modelo gerado
    modelo_NB = joblib.load('../modelo_baloes.pkl')

    #Executa a classificação
    res = modelo_NB.predict([[int(cor), int(tamanho), int(tipo), int(pessoa)]])
    result = res[0]
    print(result)

    #Encontra o valor da confidência
    probabilidade = modelo_NB.predict_proba([[int(cor), int(tamanho), int(tipo), int(pessoa)]])
    prob = probabilidade[0][0]
    print(prob)
    
    return render_template('formulario.html',  classificacao = res, probabilidade = prob)

if __name__ == '__main__':
    app.run(debug=True)