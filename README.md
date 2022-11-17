# material_classification_IA
Clasificación de materiales de distintas características, por medio de datos obtenidos de un sensor de color TCS3200 usando un Arduino UNO 

Se desarrollaron un conjunto de experimentos en donde se buscó clasificar o relacionar, a partir de
redes neuronales, tomando como entradas valores de los canales RGB obtenidos de un sensor de
color TCS3200, luego adquiriendo por medio de una placa Arduino Uno y finalmente entrenando las
redes neuronales en Jupyter Notebook con Python, particularmente, con la librería de Keras.
Se realizaron evaluaciones de:

## Proyecto 1: Clasificador de color y materiales
Se fabricaron cubos de 3.5x3.5x3.5cm de 16 Materiales (Acero quirúrgico, papel madera, piel mano,
algodón, lija fina, lija gruesa, plástico negro, Telgopor blanco, porcelana blanco, rojo, azul, verde,
cian, magenta, rojo y azul, verde y azul) se tomaron muestras cubriendo a su vez el sensor y el cubo
con una caja negra. Se colocaron los valores de cada canal en una red neuronal de 16 neuronas y
se entrenó el modelo, se realizó una optimización de parámetros de entrenamiento bach size y
epoch, a su vez se realizó una validación cruzada y se evaluó el entrenamiento por medio de las
gráficas del accuracy y el loss alrededor de los epoch, se estudió la matriz de confusión y los
estadísticos obtenidos de la misma.
Posteriormente se tomaron los pesos del modelo obtenido y se implementó el modelo en Arduino
para su detección, aquí se tomó como criterio al adquirir los datos la obtención de 10 valores
consecutivos, para posteriormente promediarlo y usar este para su clasificación y de esta forma
reduciendo el error de medición. Se muestra en pantalla el nombre del material detectado.
## Proyecto 2: Clasificador de manchas en tela
Se recortaron cuadrados de 9x9cm de una tela mitad plástica mitad algodón blanca, se las
sumergieron en aceite de girasol, alcohol, lavandina, polvo/tierra, humo, te y se dejó uno limpio. Se
tomaron muestras con el sensor, procurando hacerse en un espacio oscuro, se recorrió la tela en
toda su dimensión siempre a una altura entre el sensor y la tela de 1 cm. Se colocaron los valores de
cada canal en una red neuronal de 7 neuronas y se entrenó el modelo, se realizó una optimización
de parámetros de entrenamiento bach size y epoch, a su vez se realizó una validación cruzada y se
evaluó el entrenamiento por medio de las gráficas del accuracy y el loss alrededor de los epoch, se
estudió la matriz de confusión y los estadísticos obtenidos de la misma.
Posteriormente se tomaron los pesos del modelo obtenido y se implementó el modelo en Arduino
para su detección, aquí se tomó como criterio al adquirir los datos la obtención de 10 valores
consecutivos, para posteriormente promediarlo y usar este para su clasificación y de esta forma
reduciendo el error de medición. Se muestra en pantalla el nombre de la sustancia detectado.
## Proyecto 3: Medidor de distancia
Se fabricó un prisma de hoja blanca de dimensiones 4x4x20cm en donde desplazaremos el sensor
en su interior, tomamos muestras a una distancia de 5cm, 10cm, 15cm y 20cm del final del prisma.
Se Colocaron estos valores en una red neuronal de 1 neuronas y se entrenó un modelo de regresión
lineal, se evaluaron el P-valor y el R2.
Posteriormente se tomaron los parámetros obtenidos del modelo y se implementó el modelo en
Arduino para su uso, aquí se tomó como criterio al adquirir los datos la obtención de 10 valores
consecutivos, para posteriormente promediarlo y usar este para su clasificación y de esta forma
reduciendo el error de medición. Se muestra en pantalla la distancia calculada.
## Proyecto 4: Identificador de líquidos
En una taza semicircular de porcelana blanca de capacidad de 200mL, se colocan 100mL de
distintos líquidos y se fabricó una tapa blanca con el sensor encastrado. Los líquidos usados son
aceite, agua fría, agua caliente, alcohol, lavandina y no se coloca nada.
Se colocaron los valores de cada canal en una red neuronal de 6 neuronas y se entrenó el modelo,
se realizó una optimización de parámetros de entrenamiento bach size y epoch, a su vez se realizó
una validación cruzada y se evaluó el entrenamiento por medio de las gráficas del accuracy y el loss
alrededor de los epoch, se estudió la matriz de confusión y las estadísticas obtenidas de la misma.
Posteriormente se tomaron los pesos del modelo obtenido y se implementó el modelo en Arduino
para su detección, aquí se tomó como criterio al adquirir los datos la obtención de 10 valores
consecutivos, para posteriormente promediarlo y usar este para su clasificación y de esta forma
reduciendo el error de medición. Se muestra en pantalla el nombre del líquido detectado.
## Proyecto 5: Clasificador de cerveza y porcentaje de amargor y alcohol
En una taza semicircular de porcelana blanca de capacidad de 200mL, se colocan 100mL de
distintas cervezas y se fabricó una tapa blanca con el sensor encastrado, se utilizaron 6 variedades
distintas de cerveza de una misma marca, y se entrenaron 4 modelos distintos, dos modelos de
clasificación de tipo de cerveza, de color, y dos modelos de regresión de grado de alcohol y de
amargor.
Posteriormente se tomaron los pesos y parámetros del modelo obtenido y se implementó el modelo
en Arduino para su detección, aquí se tomó como criterio al adquirir los datos la obtención de 10
valores consecutivos, para posteriormente promediarlo y usar este para su clasificación y de esta
forma reduciendo el error de medición. Se muestra en pantalla el nombre del material detectado, su
porcentaje de alcohol y amargor en IBU

Nota: Se realizaron pruebas en fondos blancos para estudiar la capacidad de medición incluso en un
ambiente con ruido

Programa de recoleccion de datos, de autoria de https://www.gsampallo.com/2019/07/10/hojas-de-calculo-y-arduino/ , adaptado para recoleccion de datos de un sensor de color RGB
