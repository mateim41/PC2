#include <iostream>
#include <string>
#include "jocvideo.hpp"
#include <algorithm>


JocVideo::JocVideo(std::string title, unsigned int launch_date, float reviewScore) :titlu(title), anLansare(launch_date), scorRecenzii(reviewScore)
{
}

bool JocVideo::operator<(const JocVideo& j1)
{
	return this->scorRecenzii < j1.scorRecenzii ? true : false;
}

std::istream& operator>>(std::istream& input, JocVideo& j)
{
	input >> j.titlu >> j.anLansare >> j.scorRecenzii;
	return input;
}

std::ostream& operator<<(std::ostream& output, const JocVideo& j)
{
	output << "Titlu joc: " << j.titlu << ", an lansare: " << j.anLansare << ", scor recenzii: " << j.scorRecenzii << std::endl;
	return output;
}

bool compare_an(const JocVideo& j1, const JocVideo& j2)
{
	return j1.Get_AnLansare() < j2.Get_AnLansare() ? true : false;
}

Jucator::Jucator(std::string name, int level) :nume(name), nivelExperienta(level)
{
}

Jucator::Jucator(const Jucator& j) :nume(j.nume), nivelExperienta(j.nivelExperienta)
{
}

Jucator::Jucator(Jucator&& j) noexcept :nume(std::move(j.nume)), nivelExperienta(j.nivelExperienta)
{
	j.nivelExperienta = 0;
}

Jucator::~Jucator()
{
	std::cout << "destructor Jucator" << std::endl;
}

std::ostream& operator<<(std::ostream& output, const Jucator& j)
{
	output << "Nume jucator: " << j.nume << ", experienta: " << j.nivelExperienta << std::endl;
	return output;
}

EchipaEsports::EchipaEsports(int nb_players) :nrJucatori(nb_players), echipa(new Jucator* [nb_players])
{
	for (int i = 0; i < nrJucatori; i++)
		echipa[i] = nullptr;
}

EchipaEsports::~EchipaEsports()
{
	std::cout << "destructor esports" << std::endl;
	delete[] echipa;
}

void EchipaEsports::addJucator(Jucator* j, int poz)
{
	echipa[poz] = j;
}

std::ostream& operator<<(std::ostream& output, const EchipaEsports& e)
{
	for (int i = 0; i < e.nrJucatori; i++)
	{
		if (e.echipa[i] != nullptr)
			output << *e.echipa[i];
	}
	output << std::endl;
	return output;
}