#ifndef JOCVIDEO_HPP
#define JOCVIDEO_HPP

#include <iostream>
#include <string>

class Jucator
{
private:
	std::string nume;
	int nivelExperienta;
public:
	Jucator(std::string name = "Undefined", int level = 0);
	Jucator(const Jucator& j);
	Jucator(Jucator&& j) noexcept;
	~Jucator();

	friend std::ostream& operator<<(std::ostream& output, const Jucator& j);
};

class JocVideo
{
private:
	std::string titlu;
	unsigned int anLansare;
	float scorRecenzii;

public:
	JocVideo(std::string title = "Undefined", unsigned int launch_date = 0, float reviewScore = 0);

	bool operator<(const JocVideo& j1);
	friend std::istream& operator>>(std::istream& input, JocVideo& j);
	friend std::ostream& operator<<(std::ostream& output, const JocVideo& j);
	float Get_Recenzii() const { return scorRecenzii; };
	void Set_Recenzii(float new_recenzii) { scorRecenzii = new_recenzii; };
	unsigned int Get_AnLansare() const { return anLansare; };
};
bool compare_an(const JocVideo& j1, const JocVideo& j2);

class EchipaEsports
{
private:
	int nrJucatori;
	Jucator** echipa;
public:
	EchipaEsports(int nb_players);
	~EchipaEsports();

	void addJucator(Jucator* j, int poz);
	friend std::ostream& operator<<(std::ostream& output, const EchipaEsports& e);
};

#endif // !JOCVIDEO_HPP
