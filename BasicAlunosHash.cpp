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
  cadastro[location] = aluno;
  length++;
}

void AlunosHash::deleteItem(Aluno aluno)
{
  int location = aluno.Hash();
  cadastro[location] = Aluno();
  length--; 
}


