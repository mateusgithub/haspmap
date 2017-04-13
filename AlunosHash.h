#include <iostream>
#include <string>


const int MAX_ITEMS = 100;

class Aluno{
 public:

  Aluno(){
    this->ra   = -1;
    this->nome = "";
  };
  
  Aluno(int ra, std::string nome){
    this->ra    = ra;
    this->nome  = nome;
  }

  std::string getNome() const {
    return nome;
  }
  
  int getRa() const{
    return ra;
  }

  int Hash(){
    return (ra % MAX_ITEMS);
  }

 private :
  int         ra;
  std::string nome;
};


class AlunosHash {
 public:


  // Constructor
  AlunosHash(); 

  /*
    Verifica se a hash estah cheia.
   */
  bool isFull() const;

  /*
    Retorna o numero de elementos preenchidos.
   */
  int getLength() const;

  /* Recebe um ponteiro para um elemento do tipo Aluno. Esse
  // elemento Aluno que recebemos por parametro tem uma
  // chave. Usamos essa chave para buscar um elemento em nossa lista e
  // retornar esse elemento na mesma regiao de memoria, caso ele exista.

  // Se o elemento nao estiver na lista, entao nao precisa alterar o
  // parametro aluno, basta avisar na variavel found que o elemento nao
  // foi achado.
  */
  void retrieveItem(Aluno& aluno, bool& found);

  
  // Insere o elemento na lista na posicao indicada pelo metodo Hash.
  void insertItem(Aluno aluno); 

  // Remove uma ocorrencia do aluno na lista.
  void deleteItem(Aluno aluno);  

  friend std::ostream& operator<<(std::ostream& os, const AlunosHash& st);

 private:
  int   length;
  Aluno cadastro[MAX_ITEMS];
};


