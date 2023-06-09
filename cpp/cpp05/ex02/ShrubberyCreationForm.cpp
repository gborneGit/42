#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

void	drawTree(std::string const filename, int widthBase, char c) {
	std::ofstream	o;
	o.open(filename);
	if (!(widthBase % 2))
		widthBase++;
	int indexMiddle = widthBase / 2;
	int	nbLeaf = 1;
	for (int i = 0; i < indexMiddle + 1; i++) {
		int sideWidth = (widthBase - nbLeaf) / 2;
		for (int j = 0; j < sideWidth; j++) {
			o << " ";
		}
		for (int j = 0; j < nbLeaf; j++) {
			o << c;
		}
		for (int j = 0; j < sideWidth; j++) {
			o << " ";
		}
		nbLeaf += 2;
		o << std::endl;
	}
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < indexMiddle; i++) {
			o << " ";
		}
		o << "|";
		for (int i = indexMiddle + 1; i < widthBase; i++) {
			o << " ";
		}
		o << std::endl;
	}
	o.close();
}

class Bureaucrat;

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Shrubbery", 145, 137),
	target("???") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	Form("Shrubbery", 145, 137),
	target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	Form(src.getName(), src.getGradeReqToSign(), src.getGradeReqToExec()),
	target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned()) {
		throw std::runtime_error(this->getName() + " is not signed");
	} else if (executor.getGrade() > this->getGradeReqToExec()) {
		throw (Form::GradeTooLowException());
	} else {
		drawTree(this->target + "_shrubbery", 99, '*');
	}
}
