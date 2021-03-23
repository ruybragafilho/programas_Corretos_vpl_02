#include <iostream>


class IndiceNaoInicializado {};
class IndiceNegativo {};
class IndiceMaiorQueArranjo {};



template <class T, int N> class BoundedArray {

  public:

    void set(int index, T value) {
      if( index < 0 ) throw IndiceNegativo();
      if( index >= N ) throw IndiceMaiorQueArranjo();

      buf[index] = value;
      posicoesInicializadas[index] = true;
    }


    T get(int index) {
      if( index < 0 ) throw IndiceNegativo();
      if( index >= N ) throw IndiceMaiorQueArranjo();
      if( !posicoesInicializadas[index] ) throw IndiceNaoInicializado();
      
      return buf[index];
    }


  private:

    T buf[N];
    bool posicoesInicializadas[N]{};
};




template <class T> void testArray() {

  BoundedArray<T, 8> a;
  char action;
  
  while (std::cin >> action) {
  
    int index;
    std::cin >> index;
  
    try {

      if (action == 's') {
        T value;
        std::cin >> value;
        a.set(index, value);
      } else if (action == 'g') {
        std::cout << a.get(index) << std::endl;
      }

    } catch ( IndiceNegativo ) {
      
      std::cerr << "Erro: indice negativo." << std::endl;

    } catch ( IndiceMaiorQueArranjo ) {

      std::cerr << "Erro: indice maior que arranjo." << std::endl;

    } catch ( IndiceNaoInicializado ) {

      std::cerr << "Erro: indice nao inicializado." << std::endl;

    } catch (...) {

      std::cerr << "Erro desconhecido." << std::endl;
    }
  }
}



int main() {

  char type;
  
  std::cin >> type;
  
  switch(type) {
  
    case 'd':
      testArray<double>();
      break;

    case 'i':
      testArray<int>();
      break;

    case 's':
      testArray<std::string>();
      break;
  }
  
  return 0;
}