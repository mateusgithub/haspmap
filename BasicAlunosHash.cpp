#include "AlunosHash.h" 

AlunosHash::AlunosHash() {
  length = 0;
}

bool AlunosHash::isFull() const
{
  return (length == MAX_ITEMS);
}

int AlunosHash::getLength() const
{
  return length;
}

void AlunosHash::retrieveItem(Aluno& aluno, bool& found)
{
  int location = aluno.Hash();
  Aluno aux    = cadastro[location];
  if (aux.getRa() == -1) {
    found      = false;
  } else {
    found      = true;
    aluno      = aux;
  }
}

void AlunosHash::insertItem(Aluno aluno)
{
  int location = aluno.Hash();
  bool isColision = cadastro[location].getRa() != -1 && cadastro[location].getNome() != "";

  if(!isColision){
    cadastro[location] = aluno;
    length++;
  }else{
    while(isColision){
      location++;
      if(cadastro[location].getRa() == -1 && cadastro[location].getNome() == ""){
        cadastro[location] = aluno;
        length++;
        isColision = false;
      }
    }
  }
}

void AlunosHash::deleteItem(Aluno aluno)
{
  int location = aluno.Hash();
  cadastro[location] = Aluno();
  length--; 
}


