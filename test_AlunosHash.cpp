#include <iostream>
#include "AlunosHash.h" 

using namespace std;


ostream& operator<<(ostream& os, const AlunosHash& array){
  for (int i = 0; i < 100; i++) {
    os << i << ":" << array.cadastro[i].getRa() <<", "  <<array.cadastro[i].getNome() << endl;
  }
  os << endl;
  return os;
}

int main(){
  AlunosHash alunosHash;

   int   ras[7]   = {12704  , 31300 , 1234  , 49001   , 52202  , 65606  , 91234    };
  string nomes[7] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta"}; 
	    
  for (int i = 0; i < 7; i++) {
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunosHash.insertItem(aluno);
  }

  cout << alunosHash;
  
  cout << "------------------------------" <<  endl;
  
  Aluno aluno(12704,"");
  bool     found = false;

  alunosHash.retrieveItem(aluno, found);
  cout << aluno.getNome() << " -> " << found << endl;

  cout << "------------------------------" <<  endl;

  alunosHash.deleteItem(aluno);

  cout << "------------------------------" <<  endl;

  cout << alunosHash;
  cout << "Fim" << endl;  
}
