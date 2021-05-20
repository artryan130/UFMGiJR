#include "No.hpp"
#include "FilaPrioridade.hpp"

FilaPrioridade::FilaPrioridade()
{
	this->tamanho = 0;
	this->cabeca = nullptr;
}

void FilaPrioridade::inserir(int prioridade, int dado)
{
	No *aux = this->cabeca;
	No *novo_no = new No(prioridade, dado, nullptr);
	if (tamanho == 0)
	{
		this->cabeca = novo_no;
	}
	else
	{
		if (this->cabeca->getPrioridade() > prioridade)
		{
			novo_no->setProximo(this->cabeca);
			this->cabeca = novo_no;
		}
		else
		{
			while (aux->getProximo() != nullptr && aux->getProximo()->getPrioridade() <= prioridade)
			{
				aux = aux->getProximo();
			}
			novo_no->setProximo(aux->getProximo());
			aux->setProximo(novo_no);
		}
	}
	this->tamanho++;
}

int FilaPrioridade::remover()
{
	int valor = this->cabeca->getDado();
	this->cabeca = this->cabeca->getProximo();
	this->tamanho -= 1;
	return valor;
}

int FilaPrioridade::estaVazio()
{
	return 0;
}

unsigned FilaPrioridade::getTamanho()
{
	return this->tamanho;
}

int FilaPrioridade::getMeio()
{
	No *aux = this->cabeca;
	int n = this->tamanho / 2;
	int cont = 0;
	while (aux && cont < n)
	{
		aux = aux->getProximo();
		cont++;
	}
	return aux->getDado();
}

int FilaPrioridade::getUltimo()
{
	No *aux = this->cabeca;
	while (aux->getProximo())
	{
		aux = aux->getProximo();
	}
	return aux->getDado();
}

void FilaPrioridade::furaFila(int dado)
{
	this->inserir(this->cabeca->getPrioridade() - 1, dado);
}

void FilaPrioridade::print()
{
	No *aux = this->cabeca;
	while (aux)
	{
		cout << aux->getDado() << " ";
		aux = aux->getProximo();
	}
	cout << endl;
}