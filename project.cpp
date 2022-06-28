// Autores: Rodrigo Rebelo e Guilherme Pontes

#include <iostream>
using namespace std;

#define MAX 999

int resposta;

struct Fila
{
  float nos[MAX + 1];
  int ini;
  int fim;
};

Fila *init()
{
  Fila *f = new Fila;
  f->ini = 0;
  f->fim = 0;
  return f;
}

int incrementa(int i)
{
  int ret;
  if (i == MAX)
  {
    ret = 0;
  }
  else
  {
    ret = i + 1;
  }
  return ret;
}

int isEmpty(Fila *f)
{
  return (f->ini == f->fim);
}

int count(Fila *f)
{
  int qtde = 0;
  int i = f->ini;
  while (i != f->fim)
  {
    qtde++;
    i = incrementa(i);
  }
  return qtde;
}

void print(Fila *f)
{
  int i = f->ini;
  cout << "---------" << endl;
  while (i != f->fim)
  {
    cout << f->nos[i] << endl;
    i = incrementa(i);
  }
  cout << "---------" << endl;
}

int enqueue(Fila *f, float v)
{
  int podeEnfileirar = (incrementa(f->fim) != f->ini);
  if (podeEnfileirar)
  {
    f->nos[f->fim] = v;
    f->fim = incrementa(f->fim);
  }
  return podeEnfileirar;
}

float dequeue(Fila *f)
{
  float ret;
  if (isEmpty(f))
  {
    ret = -1;
  }
  else
  {
    ret = f->nos[f->ini];
    f->ini = incrementa(f->ini);
  }
  return ret;
}

void verify(Fila *f)
{
  if (isEmpty(f))
  {
    cout << "Fila de senhas vazia!" << endl;
    exit(0);
  }
  else
  {
    cout << "A fila de senhas possui elementos." << endl;
  }
}

int main()
{
  int SG = 1;
  int SA = 1;

  Fila *senhasGeradas;
  senhasGeradas = init();

  Fila *senhasAtendidas;
  senhasAtendidas = init();

  while (true)
  {
    cout << "\n0 - Sair\n1- Gerar senha\n2- Realizar atendimento";
    cin >> resposta;

    switch (resposta)
    {
    case 0:

      return 0;

    case 1:
      system("clear");

      cout << "Enfileirou: " << enqueue(senhasGeradas, SG) << endl;
      cout << "Qtde de senhas na fila: " << count(senhasGeradas) << endl;
      verify(senhasGeradas);

      SG++;

      print(senhasGeradas);

      break;

    case 2:
      system("clear");

      cout << "Desenfileirou: " << dequeue(senhasGeradas) << endl;
      print(senhasGeradas);

      cout << "Enfileirou: " << enqueue(senhasAtendidas, SA) << endl;
      cout << "Total de senhas atendidas: " << count(senhasAtendidas) << endl;

      verify(senhasGeradas);
      print(senhasAtendidas);

      SA++;

      break;

    default:
      break;
    }
  }
}