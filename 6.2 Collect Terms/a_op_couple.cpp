#include "stdafx.h"
#include "a_op_couple.h"
#include "cos.h"

bool a_op_couple::operator==(const a_op_couple sec) const
{
	if (names[0] != sec.names[0])
		return false;
	if (names[1] != sec.names[1])
		return false;
	if (dx != sec.dx)
		return false;
	if (dy != sec.dy)
		return false;
	return true;
}

void a_op_couple::check()
{
	if (dx < 0)
	{
		dx = -dx;
		dy = -dy;
	}
}

bool a_op_couple::operator<(const a_op_couple sec) const
{
	
	for (int i = 0; i < 2; i++)	{
		if (names[i] < sec.names[i]) return true;
		else if (names[i] > sec.names[i]) return false;
	}
	
	if (dx < sec.dx) return true;
	else if (dx > sec.dx) return false;

	if (dy < sec.dy) return true;
	else  return false;
}

void a_op_couple::printAterm(std::ofstream &F, int **m, int size, bool if_print_coeff)const
{
	
	if (if_print_coeff)
		F << coeff << "*";
	if (names[0] != names[1])
		F << "G";
	else if (names[0] == 'm')
		F << "F";
	else if (names[0] == 'p')
		F << "Fp";
	else
		F << "\n\n Strange ops \n\n";
	if (dx != 0 || dy != 0)
	{
		//if (node[0]!=0)
		//	F << "\n\n Strange nodes \n\n";
		F << "*Cos[";
		switch (dx){
		case 0: break;
		case 1: F << "ka"; break;
		default: F << "ka*" << dx;
		}
		switch (dy){
		case 0: break;
		case -1: F << "-kb"; break;
		case 1: F << "+kb"; break;
		default: F << "+kb*" << (dy);
		}
		F << "]";
	}
	
}

void a_op_couple::clear()
{
	double coeff = 0;
	int order = 0;
}