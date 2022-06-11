#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>



using namespace std;

class JogoDaForca {
  static const int nMaxChances = 6;
  int nChances;
  vector<string> palavras;
  vector<char> chutesErrados;
  string palavraDaRodada, palavraInvestigada;
public:
  JogoDaForca(vector<string> palavras):  
    palavras(palavras), nChances(nMaxChances), palavraDaRodada(""), palavraInvestigada("") {
  }
  ~JogoDaForca(){
  }
  bool iniciar() {
    ostringstream codificada;
    vector<string>::iterator elem_to_remove = palavras.begin();

    if(palavras.empty()) { return false;}
    palavraDaRodada = palavras[0];
    palavras.erase(elem_to_remove);
    nChances = nMaxChances;
    for(int i=0; i < palavraDaRodada.length(); i++)
      codificada << "_ ";
    palavraInvestigada = codificada.str();
    chutesErrados = {};
    return true;
  }
  void mostrar() {
    cout << endl;
    cout << palavraInvestigada << endl;
    cout << "\n| Vidas: " << nChances << endl;
    cout << "| Chutes Errados: ";
    for(int i=0; i < chutesErrados.size(); i++) {
      cout << chutesErrados[i];
      if((i+1) < chutesErrados.size())
        cout << " - ";
    }
    cout << "\n" << endl;
  }
  void jogar() {
    char chute;
    bool correto = false;
    vector<char>::iterator it;
    cout << "Chute uma letra: ";
    cin >> chute;
    if(chute >= 'a' && chute <= 'z')
      chute += ('A' - 'a');
    it = find(chutesErrados.begin(), chutesErrados.end(), chute);
    if(it != chutesErrados.end()) {
      cout << "******* Essa letra ja foi chutada *******" << endl;
      jogar();
    }
    for(int i=0; i<palavraDaRodada.length(); i++) {
      if(chute == palavraDaRodada[i]) {
        palavraInvestigada[2*i] = chute;
        correto = true;
      }
    }
    if(!correto) {
      chutesErrados.push_back(chute);
      nChances--;
    }
    mostrar();
    if(!testeFimdeJogo()) {
      jogar();
    }
  }
  bool testeFimdeJogo() {
    int opcao;
    bool fim = false;

    if(nChances <=0) {
      cout << "****** Enforcado ******\n" << endl;
      fim = true;
    }
    else {
      fim = true;
      for(int i=0; i < palavraInvestigada.length(); i++) {
        if(palavraInvestigada[i] == '_')
          fim = false;
      }
      if(fim) {
        cout << "****** Vitoria ******\n" << endl;
      }
    }
    if(fim){
      cout << "\n 1- Jogar Novamente" << endl;
      cout << " 2- Sair" << endl;
      cout << "----------------------" << endl;
      cout << "Selecione uma opcao: ";
      cin >> opcao;
      cout << endl;
      switch (opcao) {
        case 1: {
          if(iniciar())
            jogar();
          break;
        }
        case 2: {
          break; 
        }
          
        default: {
          cout << "Opcao invalida" << endl;
        }
          break;
      }
      return true;
    }
    else {
      return false;
    }
  }
};

int main() {

  vector<string> palavras = {"ABACAXI", "MELANCIA", "MACA"};

  JogoDaForca jg1(palavras);

  jg1.iniciar();

  jg1.jogar();


  return 0;
}