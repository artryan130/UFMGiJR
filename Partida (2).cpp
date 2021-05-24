#include "Partida.hpp"
#include "Jogador.hpp"

Partida::Partida(int num_jogadores)
{
	this->_jogadores = new Jogador[num_jogadores];
	this->_num_jogadores = num_jogadores;
	this->_atualSize = 0;
}

Partida::~Partida()
{
}

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe)
{
	bool encontrouJogador = false;
	if (this->_atualSize > 0)
	{
		for (int i = 0; i < this->_atualSize; i++)
		{
			if (this->_jogadores[i].getNomeJogador() == nomeJogador)
			{
				this->_jogadores[i].adicionaCarta(Carta(numero_pontos_carta, naipe));
				encontrouJogador = true;
			}
		}
	}
	if (!encontrouJogador)
	{
		Jogador jogador;
		jogador.setNomeJogador(nomeJogador);
		jogador.adicionaCarta(Carta(numero_pontos_carta, naipe));
		this->_jogadores[this->_atualSize] = jogador;
		this->_atualSize++;
	}
}

int Partida::getNumJogadores()
{
	return this->_num_jogadores;
}

int Partida::getNumAtualJogadores()
{
	return this->_atualSize;
}

void Partida::setJogadores(Jogador *jogadores)
{
	this->_jogadores = jogadores;
}

Jogador *Partida::getJogadores()
{
	return this->_jogadores;
}

Jogador Partida::getCampeao()
{
	Jogador *jogadores_ordenados = this->getJogadoresOrdenados();
	return jogadores_ordenados[this->_atualSize - 1];
}

Jogador *Partida::getJogadoresOrdenados()
{
	Jogador *jogadores = this->_jogadores;
	// bubblesort
	int i, j;
	for (i = 0; i < this->_atualSize - 1; i++)
	{
		for (j = 0; j < this->_atualSize - i - 1; j++)
		{
			if (jogadores[j].calcularPontuacao() > jogadores[j + 1].calcularPontuacao())
			{
				Jogador aux = jogadores[j];
				jogadores[j] = jogadores[j + 1];
				jogadores[j + 1] = aux;
			}
		}
	}
	return jogadores;
}

void Partida::imprimeJogadoresOrdenados()
{
	Jogador *jogadores_ordenados = this->getJogadoresOrdenados();
	for (int i = 0; i < this->_atualSize; i++)
	{
		cout << jogadores_ordenados[i].getNomeJogador() << " " << jogadores_ordenados[i].calcularPontuacao() << endl;
	}
}
//oi