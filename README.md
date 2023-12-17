# **Computação Gráfica**
#### As atividades foram feitas em um ambiente Linux, na linguagem C++ e na IDE Visual Studio Code.
> ### ***Instruções de compilação***
> 1. Dentro do diretório do projeto *AtividadeXX*, crie um novo diretório chamado *build*;
> 2. No interior do diretório *build* abra um terminal e insira os comandos abaixo;
>    ```
>    cmake ../
>    ```
>    ```
>    make
>    ```
> 3. Para executar o programa, use o comando abaixo, ajustando o caminho relativo do arquivo executável.
>    ```
>    ./src/main
>    ```

> ### ***Documentação***
> A documentação completa e detalhada do código está no arquivo ***Documentation.html*** dentro do diretório de sua respectiva atividade.

## - **Atividade 01 (I/O de Imagens)**
Aqui, foram feitas operações para **configurar o ambiente** que será utilizado para toda a disciplina, assim como a implementação do código para a **geração de imagens**. O código pertinente a esta atividade está no arquivo ***Generator.h*** e as chamadas das funções está em ***main.cpp***.

> ### ***Configurações*** 
> Foi usado o **CMake** para a compilação e a organização de dependências. Além disso, as bibliotecas **CImg** e **libpng** foram instaladas e, depois, conectadas pelo arquivo *CMakeLists.txt*. Elas servem para a criação e manipulação de imagens em formatos diferentes (como *PNG*). Note que a biblioteca **CImg** necessita apenas da inserção do arquivo ***CImg.h*** dentro do projeto para que ela funcione, enquanto a **libpng** necessita de instalação dentro do ambiente.

> ### ***Geração de imagens***
> Foram geradas 3 imagens, um gradiente, um quadrado e um círculo. Elas estão no diretório *images*.
> - ***Gradiente:*** feito de modo similar ao tutorial com adaptações ao uso da biblioteca **CImg**;
> - ***Quadrado:*** a imagem é gerada a partir do tamanho do lado do quadrado e o tamanho da imagem apenas. 
> - ***Círculo:*** ele é criado a partir da informação do tamanho de seu raio e usa uma fórmula matemática para reconhecer se um pixel pertence ao círculo ou não.

## - **Atividade 02 (Operações Matriciais)**
Nesta Atividade, foram implementadas classes para vetores e matrizes, além de operações referentes a elas. Também foi configurado um ambiente para testes unitários. Note que não há uma função *main* explícita neste projeto, uma vez que o código é executado pelo ambiente de testes.

> ### ***Vetores e Matrizes***
> - Dentro do diretório ***include*** estão os *headers* com as definições das classes e implementações de funções *inline* de utilidade (o corpo das funções *inline* precisam estar nestes arquivos). No diretório ***src***, há os arquivos *.cpp* com a implementação das classes definidas nos *headers*. Os arquivos são relacionados por seus nomes, por exemplo, *vec2.hpp* é header de *vec2.cpp*.
> - Para vetores com 2, 3 e 4 dimensões foram criadas classes denominadas: vec2, vec3 e vec4, respectivamente. Assim como para matrizes 2x2, 3x3 e 4x4, cujas classes foram chamadas de mat2, mat3 e mat4, respectivamente.
> - Encontra-se nesses arquivos, também, código para operações pertinentes à essas classes como produto escalar, produto vetorial, multiplicação de matrizes, multiplicação entre matrizes e vetores, entre outras. Mais detalhes estão presentes na documentação e no código em si.

> ### ***Testes Unitários***
> A biblioteca escolhida foi o **GoogleTest**. A integração desse ambiente com o projeto foi feita através do *CMakeLists.txt*. Todos os testes estão no diretório ***tests*** e há um arquivo de teste para cada classe feita, ou seja, *vec2_tests.cpp* é referente à classe vec2, *vec3_tests.cpp* à classe vec3, e assim por diante. Por fim, o projeto é compilado do mesmo modo de como foi descrito [nas instruções de compilação](#instruções-de-compilação), contudo, para executar os testes, deve-se utilizar o comando ***./run_tests*** sob o diretório *build*.

## - **Atividade 03 (I/O de Malhas)**
Nesta Atividade, foi implementada a classe obj referente à leitura e ao armazenamento de malhas à partir de um arquivo em formato *.obj*. 

> ### ***Malhas***
> O *header* dessa classe está no diretório *include*, no arquivo *obj.hpp*, e a sua respectiva implementação está em *obj.cpp* dentro da pasta *src*. A classe obj tem apenas seu construtor, que recebe como parâmetro o nome do arquivo a ser armazenado, e alguns métodos auxiliares (usados na fase de teste) para a conversão dos dados armazenados de volta para *string*. Mais detalhes estão na documentação e no código em si.

> ### ***Testes Unitários***
> - Os testes seguem o mesmo padrão da [Atividade 02](#testes-unitários), porém há apenas um arquivo de teste *obj_tests.cpp*, onde são testadas as estrutura de dados (vértices geométricos, coordenadas de texturas, vértices normais e elementos de faces) utilizadas pela classe.
> - Foram feitos testes através da criação de um objeto da classe obj com os arquivos *.obj* do diretório *tests/mock_inputs*, e a posterior comparação entre os dados que foram armazenados no objeto e o que estava na sua entrada. 
> - Cada teste tem um nome e um arquivo de *mock_input* relacionado, por exemplo, *mock_inputs/v_test.obj* é atribuído ao teste *v_test* que é o teste para vértices geométricos. Mais detalhes estão na documentação e no código de teste em si.
> - Todos os arquivos de *mock_inputs* foram gerados com base em um arquivo *.obj* real chamado *cat.obj*, baixado do site [free3d](https://free3d.com/). Ele está dentro do diretório *input*.

## - **Atividade 04 (Visualização Inicial)**
Nesta Atividade, foram implementadas a visualização de esferas, a de triângulos e a de objetos formados por faces triangulares. Algumas classes foram adicionadas, enquanto outras classes, como vec3, foram reutilizadas de atividades anteriores.

> ### ***Esferas***
> - Nessa seção, o [tutorial 1](https://raytracing.github.io/books/RayTracingInOneWeekend.html#rays,asimplecamera,andbackground) foi seguido para a criação da classe **ray** e a visualização de uma imagem de uma esfera. Para a organização do código, foi criada uma classe base **hittable** que é herdada pela classe **sphere**. Na classe **sphere**, temos a implementação da lógica por trás da checagem de que um ray está atravessando a esfera ou não. 
> - Além disso, foi criada uma classe **renderer** que irá traçar os rays referentes a cada pixel e desenhar sua cor, considerando se o ray acerta ou não a esfera. Mais detalhes estão na documentação e no código em si.
> - A organização dos arquivos segue assim como na atividade anterior, por exemplo, o *header* da classe renderer está no arquivo *renderer.hpp* no diretório *include* e o corpo do código está no arquivo *renderer.cpp* sob o diretório *src*. Contudo, algumas classes foram implementadas totalmente em seus *headers* por serem simples, o que pode ser visto na classe sphere que tem apenas seu *header* *sphere.hpp*.

> ### ***Triângulos***
> - Nessa parte, o [tutorial 2](https://raytracing.github.io/books/RayTracingTheNextWeek.html#quadrilaterals/ray-planeintersection) foi usado de inspiração para a criação da classe **triangle** que representa um triângulo no espaço tridimensional. A implementação do código e a distribuição dos arquivos segue o mesmo padrão utilizado para a classe sphere.

> ### ***Renderer***
> - A classe **renderer** é a responsável por renderizar as imagens e é chamada diretamente pela *main*. Ela possui métodos para cada tipo de imagem vista nesta atividade. Para mais detalhes, veja a documentação e o código.

> ### ***Objetos***
> - Por fim, 2 arquivos do formato *.obj* foram baixados da internet para servirem de teste na visualização de objetos reais. Um se chama [cat.obj](https://free3d.com/pt/3d-model/low-poly-cat-46138.html) e outro [icosahedron.obj](https://github.com/angerangel/LCR3D/blob/master/3D-models/icosahedron.obj) e estão no diretório *input*. Ambos possuem apenas faces triangulares, uma vez que não foi implementado suporte para quadriláteros. Foram escolhidos dois objetos para testes, pois um deles (icosahedron) é mais fácil de observar, e o outro (cat) possui geometria mais complexa e mais difícil de visualizar sem o uso de normais.

> ### ***Execução do programa e saídas***
> A compilação e execução do programa segue exatamente igual à [atividade 01](#instruções-de-compilação) e as saídas estão no diretório *images*, sendo que cada imagem é referente a um dos objetos feitos nesta atividade (veja o arquivo *main.cpp* para mais detalhes).

## - **Atividade 05 (Materiais Difusos)**
Nesta Atividade, foi implemetada a representação de normais na superfície dos objetos, o possibilidade de se ter múltiplos objetos em uma mesma cena, a refatoração do código da camera para uma classe separada com suporte para múltiplas cameras, a adição de antialiasing e de materiais difusos. Para a organização do código, também foi adicionado um arquivo chamado *include/commons.hpp* que possui definições de constantes, métodos, e *headers* comuns entre diversos arquivos.

> ### ***Normais***
> - Agora, os objetos possuem normais que controlam sua cor, permitindo superfícies suaves e com profundidade. O exemplo deixado no diretório *images* é de um icosaedro renderizado a partir do arquivo *input/icosahedron_with_normals.obj*, sua superfície suave fica difícil de enxegar por conta da adição do material difuso.
> - Caso deseje renderizar novamente com cores mais destacadas, descomente a linha 134 do código em *include/camera.hpp*. Ou, troque o nome do arquivo na linha 15 do código em *src/main.cpp* para *../input/icosahedron.obj*, a fim de observar o icosaedro com faces planas (utilizar a normal da própria face triangular).
> - Como a interpolação das cores das faces utiliza normais que são dos vértices (não da face), foi criada uma classe **vertex** que representa um vértice. Nela, há apenas as coordenadas do vértice e sua normal. 

> ### ***Camera***
> - O código referente à camera foi separado em uma classe chamada **camera** e agora é possível criar mais de uma camera para se ter diferentes pontos de vista de uma mesma cena. As imagens em *images/output_cam1.png* e *images/output_cam2.png* representam os pontos de vistas das duas cameras instanciadas em *src/main.cpp*. Diversos parâmetros foram adicionados à camera para suportar a customização de sua posição (**look_from**), em qual ponto ela olha (**look_at**), de qual é a direção do norte relativo à camera (**v_up**), e de seu campo de visão vertical (**vfov**). Existem outros parâmetros que serão discutidos posteriormente.

> ### ***Antialiasing***
> - Para a incorporação do antialiasing nesse código, foram acrescentados métodos auxiliares para a geração de números reais aleatórios, esses métodos estão em *include/commons.hpp*.
> - Também foi incluída uma nova classe chamada **interval** que representa um intervalo e possui métodos pertinentes a esse intervalo, permitindo uma melhor organização do código.
> - A ideia geral por trás da versão de antialiasing implementada é de pegar um feixe aleatório de raios ao redor do raio original, ao em vez de um único raio para cada pixel. Em seguida, é feita a média das cores desses raios para o pixel, o que deixa a transição de cor entre os pixels mais suave.
> - Na classe **camera**, é possível controlar a quantidade de raios aleatórios utilizados no cálculo da média através do atributo **samples_per_pixel**. Um número maior estende o tempo de processamento exponencialmente, porém aumenta a suavidade das bordas dos objetos da imagem.

> ### ***Materiais Difusos***
> - Os raios refletidos de materiais difusos têm sua direção randomizada, com uma chance do raio ser absorvido pelo objeto.
> - Para aliviar a recursividade de raios sendo refletidos em superfícies, foi adicionado um atributo **max_depth** na classe **camera** para limitar o número de reflexões que um raio pode ter. 
> - Além disso, para uma representação mais realística de luz, as superfícies dos objetos seguem a Lei do Cosseno de Lambert. Ou seja, os raios aleatórios gerados pelas reflexões tendem a ser mais próximos da normal da superfície.
> - Por fim, foi adicionada a correção de gamma na imagem para que o nível iluminação siga o espaço gamma 2, ao em vez do espaço linear. É possível modificar o nível de iluminação do objeto (refletância) através do atributo **gamma** na classe **camera**.

> ### ***Execução do programa e saídas***
> A compilação e a execução do programa seguem exatamente como na [atividade 01](#instruções-de-compilação), as imagens geradas estão no diretório *images* e os objetos de entrada estão no diretório *input*. Veja a documentação e o código fonte para mais detalhes sobre as implementações.

## - **Atividade 06 (Metal e Vidro)**
Nessa atividade, foram implementados os materiais metálicos e dielétricos (vidros).

> ### ***Metal***
> - Foi criada uma classe abstrata para materiais em geral chamada **material**. Agora, a classe **hit_record** e as classes herdadas de **hittable** armazenam uma instância da classe material, ou seja, elas sabem qual o material decidido para o objeto.
> - Cada tipo de material é herdado a partir da classe **material**. O material de classe **lambertian** é o material difuso, implementado na [atividade 05](#materiais-difusos).
> - O material de classe **metal** é o metálico, responsável por refletir os raios de maneira organizada. Essa reflexão segue uma fórmula que foi implementada pelo método **reflect** na classe **vec3**.
> - Note que o método **ray_color** que decide as cores dos pixels atingidos pelos raios, foi generalizado para aceitar os métodos sobrescritos dos diferentes materiais.
> - Também foi adicionado um parâmetro ("*fuzziness*") para alterar o nível de difusão da reflexão do material metálico.

> ### ***Vidro***
> - Adicionalmente, foi criada a classe **dielectric** para materiais dielétricos (vidros). Ela é baseada na Lei de Snell e simula tanto situações de refração como de reflexão (quando o raio não consegue ser refratado).
> - Para simular um vidro mais realisticamente, foi utilizada a aproximação de Schlick, pois o nível de reflexão do vidro varia de acordo com o ângulo da visão.

> ### ***Execução do programa e saídas***
> A compilação e a execução do programa seguem exatamente como na [atividade 01](#instruções-de-compilação), as imagens geradas estão no diretório *images* e os objetos de entrada estão no diretório *input*. Veja a documentação e o código fonte para mais detalhes sobre as implementações.
