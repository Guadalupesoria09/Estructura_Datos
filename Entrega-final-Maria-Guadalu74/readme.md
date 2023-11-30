# Proyecto: Nombre de tu proyecto
La competencia del selectivo a olimpiada nacional es un evento que se hace cada año, es uno de los eventos más esperados del año y por ende el numero de atletas que participan para poder clasificar a juegos nacionales es un numero bastante amplio. Esta competencia es base para poder pasar a la siguiente fase de juegos nacionales, competencia donde unicamaente participan l@s mejores 12 atletas del país que lograron los mejores puntajes en el Selectivo Olimpiada Nacional. Posterior a esta etapa se registra el nombre de los atletas en un Ranking Nacional. Gracias a que es un evento grande, suele haber una falta de organización o el periodo para registras y sacar a los 12 atletas que participaran en Juego Nacionales se vuelve algo tedioso, sin mencionar que posiblemente pueda llagar a ver errores al registrar los puntajes de cada competidor. 

## Descripción del avance 1
**Se realizo un cambio de proyecto**
Este avance contiene algoritmos de ordenamiento (Quicksort) , que nos ayudaran a ordenar nuestros datos proporcionados por el usuario,  para asi identificar el mes en el que obtuvo una mayor perdida de peso. 
## Descripción del avance 2
El siguiente avance contiene algoritmos de ordenamiento (Quicksort), vectores, stacks y archivos de texto, que nos permiten registrar los puntajes de cada competidor asi como tambien su nombre, para posteriormente ordenar los puntajes y sacar las mejores puntajes en un ranking de 12.

## Descripción del avance 3
Contiene las mismas funcionalidades que el segundo avance, solo se agrego un menu donde se pudiera implementar mejor colsultas. Adicional a esto se agragaron otras funciones, como el buscar a un atleta por su nombre para saber su puntaje, tambien otra función para mostrar la lista de todos los atletas, y por ultimo una función que nos permita saber cuales son los atletas que estan en el pódium de la competencia.

### Cambios sobre el segundo avance
1. mostrarTodosLosAtletas: Muestra todos los atletas y sus puntajes en el vector.
2. buscarAtletaPorNombre: Busca un atleta por nombre en el vector e imprime su información si se encuentra.
3. mostrarPodio: Muestra el podium de los mejores atletas, tomando como entrada el número de atletas que se desea mostrar, en nuestro caso son 4 lugares (el primer lugar, el segundo lugar, y dos terceros lugares).
4. bucle do-while que presenta un menú al usuario y ejecuta la función correspondiente según la opción seleccionada. El bucle continuará hasta que el usuario elija salir (opcion == 4). Cada opción del menú invoca una función específica según la elección del usuario.
## Entrega final
En esta ultima entrega realizamos la implementación de metodos de busqueda, en este caso, agregamos BST para la busqueda por nombre de los atletas registrados por el usuario, de igual forma creamos una lista predeternimada de excel con nombres de atletas de cierta categoria, la función de esto es que el programa pueda leer dicha lista de nombres para que el usuario pueda manipular agregando sus puntajes correspondientes y estos se queden guardados en el sistema. 

### Cambios sobre el tercer avance avance
1. Se agregó a la estructura 'Atleta' un puntero al nodo correspondiente en el BST llamado 'AtletaNode*bstNode'
2. Se agrego la clase 'AtletaBST' representando un árbol de búsqueda binaria de los atletas. La funcionalidad de esta clase es insertar el nombre de los atletas en el arbol ('insert'), buscar el atleta por su nombre ('search') y asignar un puntero ('bstNode') después de la inserción ('asignarBstNode').
3. En lugar de buscar a los atletas directamente en el vector, se utiliza 'AtletaBST' para realizar una busqueda eficiente en el árbol. 
4. Se agrega documentos .xls con nombres de atletas de diferentes categorias para poder consultar y asignar puntajes, realizando lectura y escritura de archivos.

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
El usurio puede seleccionar una serie de funciones que requiera realizar, dichas funciones se muestran mediante un menu, antes de esto, le pide al usurio ingrresar el numero de atletas a registrar como tarea principal, posteriormente debera ingresar los nombres de l@s atletas y poner su puntaje correspondinete, una vez esto, puede seleccionar alguna opción dentro del menu, desde buscar un atleta por su nombre de acuerdo a los nombres recien registrados, o buscar desde archivos con atletas previamente registrados de rama femenil y varonil, puede ingresar a su información y asignar un puntaje, tambien puede ver el ranking de l@s 12 mejores atletas de la categoria y ver el podium de cada categoria. 

## Descripción de las salidas del avance de proyecto
Una vez que el usuario registre el numero de atletas, sus nombres y sus puntajes, lo que mostrara el programa sera el orden de l@s atletas que pasan a Juegos Nacionales, para asi poder publicar los nombres, posiciones y puntajes, comenzando con la que obtuvo el mejor puntaje y quedo en el primer puesto. 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utiliza un algoritmo de ordenamiento de QuickSort que es iterativa con pila. En el peor caso este método tiene una complejidad de tiempo de O(n^2), en donde "n" es el número de elementos en el arreglo. Esto ocurre cuando el pivote elegido siempre es el elemento más grande o más pequeño, lo que resulta en particiones desequilibradas y subarreglos extremadamente desiguales. En el peor caso, se asemeja al rendimiento de la versión recursiva de QuickSort.
En el mejor del caso este algoritmo tiene una complejidad de tiempo de O(n log n). Esto ocurre cuando el pivote se elige de manera que divide el arreglo en dos partes aproximadamente iguales en cada iteración. En este caso, el algoritmo funciona de manera eficiente.
El ordenamiento de l@s 12 mejores atletas tiene una complejidad constante, ya que el número de atletas que se muestran es fijo. La complejidad de espacio para QuickSort iterativo con pila es O(log n) en el peor caso debido al uso de la pila.


#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
La complejidad del algoritmo de ordenamiento (quickSort) tiene complejidad de O(n log n) y en el peor de los casos puede ser O(n^2), este es poco probable en situaciones prácticas. 

Las operaciones push y pop en la pila, tiene una complejidad de O(1), este se utiliza para mantener los índices de los límites de la partición,lo que hace que su rendimiento sea eficiente. 

La complejidad principal del programa viene de la ordenación del vector de atletas el cual utiliza el algoritmo QuickSort y su complejidad en el peor de los casos es O(n^2), pero en el caso promedio es O(n log n), esto ya que se limita la entrada a un máximo de 12 atletas en el ranking, por lo que el impacto práctico es mínimo. 

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Partiendo desde la complejidad descrita en el segundo avance, se agrega la complejidad de la función de búsqueda por nombre O(n) ya que se realiza una búsqueda lineal en el vector atletas, lo mismo para la función de 'mostrarTodosLosAtletas' ya que itera sobre todos los atletas, por último el 'mostrarPodio' tiene una complejidad O(k), en donde k es el número de atletas a mostrar (generalmente solo 4), esta itera sobre los primeros k atletas. En el menú principal depende la complejidad, esto varía de acuerdo con la opción seleccionada por el usuario, sin embargo, generalmente se tiene una complejidad lineal. La complejidad final del programa es O(n log n) dado a que la parte principal del programa es la ordenación rápida, generalmente dominada por la complejidad de quickSort. Las demás operaciones tienen un impacto menor en comparación con la ordenación. 

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El algoritmo de ordenamiento QuickSort es una elección adecuada para ordenar a los atletas por puntaje en función de su eficiencia en el promedio de casos y su capacidad para ordenar de manera descendente. La implementación del QuickSort iterativo con pila en el programa es una forma efectiva de abordar este problema de ordenamiento. Este algoritmo de ordenamiento es muy adaptable y funciona bien en muchos tipos de datos, lo que lo hace una elección buena elección para la solución a nuestra problematica. Cabe mencionar que además al iterar con pila utiliza una cantidad limitada de espacio adicional (O(log n)) para el almacenamiento de la pila, lo que es manejable incluso para conjuntos de datos grandes.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
El vector 'std::vector<Atleta> atletas' se comporta como un lista dinámica de atletas, esto ya que crece dinámicamente para acomodar nuevos atletas y proporciona un rápido acceso y aleatorio a los elementos.
La pila 'std::stack<int>pila' se utiliza para implementar una pila en el algoritmo iterativo de quickSort. Esta almacena los límites de la partición que se deben procesar, sigue un enfoque de último en entrar, primero en salir, esto evita la recursividad

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Implementamos un metodo de busqueda para consultar información 'AtletaBST' que representa un árbol binario de busqueda para los atletas.
En la función 'main', se crean atletas y se insertan en el BST utilizando la función 'atletaBST.insert(atleta)'. Esta función inserta un nodo nuevo en el árbol con el nombre del atleta que ingresa el usuario. En cada inserción se manda a llamar a 'atletaBST.asignarBstNode(atleta, atleta.bstNode)', por ultimo la función 'asignarBstNode' es el encargado de asignar el puntero 'bstNode' del atleta al nodo correspondiente en el árbol. Este metodo lo utilizamos para la función 'buscarAtletaPorNombre' mediante la función 'search' que busca un atleta por su nombre. La función 'search' devuelve un puntero al nodo del árbol que contiene al atleta, si es que existe y imprime su información (nombre y puntaje).

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Se crea la función de 'verListaFemenil()' y 'verListaVaronil()' en donde se utiliza un objeto 'ifstream'para poder abrir el archivo 'ListaF.txt' y 'ListaV.txt' en donde se encuentra todos los nombres de todos los atletas registrados tanto de la categoria femenil, como de la categoria varonil. Esta función lee cada linea del archivo correspondiente y muestra los nombres de estos atletas por la consola.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Se crea la función de 'registrarAtletaFemenil' y 'registrarAtletaVaronil' estas funciones utilizan el objeto 'std::ofstream' para abrir los archivos txt 'ListaF.txt' y 'ListaV.txt' en modo de escritura de anexado ('std::ios::app'), esto permite agragar nuevos nombres de atletas femeniles y varoniles al final del archivo correspondiente, sin borrar los datos ya existentes. Posteriormente se escribe el nombre del atleta femenil o varonil seguido de un salto de linea en el archivo. Se utilizan operadores de inserción ('<<')para escribir datos en los archivos, por ultimo se cierran estos despues de realizar las operaciones de escritura para liberar recursos y garantizar que los datos se hayan guardado correctamente.