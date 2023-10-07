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
>    ./main
>    ```

## - **Atividade 01:**
Aqui, foram feitas operações para **configurar o ambiente** que será utilizado para toda a disciplina, assim como tutoriais iniciais de **geração de imagens**.

> ### ***Configurações*** 
> Foi usado o **CMake** para a compilação e a organização de dependências. Além disso, as bibliotecas **CImg** e **libpng** foram instaladas e, depois, conectadas pelo arquivo *CMakeLists.txt*. Elas servem para a criação e manipulação de imagens em formatos diferentes (como *PNG*).

> ### ***Geração de imagens***
> Foram geradas 3 imagens, um gradiente, um quadrado e um círculo. Elas estão no diretório *images*.
> - ***Gradiente:*** feito de modo similar ao tutorial com adaptações ao uso da biblioteca **CImg**;
> - ***Quadrado:*** a imagem é gerada a partir do tamanho do lado do quadrado e o tamanho da imagem apenas. 
> - ***Círculo:*** ele é criado a partir da informação do tamanho de seu raio e usa uma fórmula matemática para reconhecer se um pixel pertence ao círculo ou não.