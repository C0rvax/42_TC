/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:23:04 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/14 18:00:37 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation",
	   ShrubberyCreationForm::signGrade,
	   ShrubberyCreationForm::executeGrade)
{
	this->m_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("Shrubbery Creation",
	   ShrubberyCreationForm::signGrade,
	   ShrubberyCreationForm::executeGrade)
{
	this->m_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	AForm(src)
{
	this->m_target = src.m_target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
		this->m_target = rhs.m_target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm	(void)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	output;

	if (!this->getSigned())
		throw AForm::UnsignedException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	output.open((this->m_target + "_shrubbery").c_str(), std::ofstream::out);
	if (!output.good())
		throw std::exception();

    output << "   /\\   " << std::endl;
    output << "  /**\\  " << std::endl;
    output << " /****\\ " << std::endl;
    output << "/******\\" << std::endl;
    output << "   ||   " << std::endl;
    output << "   ||   " << std::endl;
	output << std::endl;
    output << "          &&& &&  & &&              " << std::endl;
    output << "      && &\\/&\\|& ()|/ @, &&          " << std::endl;
    output << "      &\\/(/&/&||/& /_/)_)&_&_&       " << std::endl;
    output << "   &() &\\/&|()|/&\\/ '%\" & ()         " << std::endl;
    output << "  &_\\_&&_\\ |& |&&/&__%_/_& &&        " << std::endl;
    output << "&&   && & &| &| /& & % ()& /&&       " << std::endl;
    output << " ()&_---()&\\&\\|&&-&&--%---()~        " << std::endl;
    output << "     &&     \\|||                    " << std::endl;
    output << "             |||                    " << std::endl;
    output << "             |||                    " << std::endl;
    output << "             |||                    " << std::endl;
    output << "       , -=-~  .-^- _               " << std::endl;
	output << std::endl;
    output << "                                                         .   " << std::endl;
    output << "                                              .         ;    " << std::endl;
    output << "                 .              .              ;%     ;;     " << std::endl;
    output << "                   ,           ,                :;%  %;      " << std::endl;
    output << "                    :         ;                   :;%;'     ., " << std::endl;
    output << "           ,.        %;     %;            ;        %;'    ,;   " << std::endl;
    output << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'    " << std::endl;
    output << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'     " << std::endl;
    output << "               ;%;      %;        ;%;        % ;%;  ,%;'       " << std::endl;
    output << "                `%;.     ;%;     %;'         `;%%;.%;'         " << std::endl;
    output << "                 `:;%.    ;%%. %@;        %; ;@%;%'            " << std::endl;
    output << "                    `:%;.  :;bd%;          %;@%;'              " << std::endl;
    output << "                      `@%:.  :;%.         ;@@%;'               " << std::endl;
    output << "                        `@%.  `;@%.      ;@@%;                 " << std::endl;
    output << "                          `@%%. `@%%    ;@@%;                  " << std::endl;
    output << "                            ;@%. :@%%  %@@%;                   " << std::endl;
    output << "                              %@bd%%%bd%%:;                    " << std::endl;
    output << "                                #@%%%%%:;;                     " << std::endl;
    output << "                                %@@%%%::;                      " << std::endl;
    output << "                                %@@@%(o);  . '                 " << std::endl;
    output << "                                %@@@o%;:(.,'                   " << std::endl;
    output << "                            `.. %@@@o%::;                      " << std::endl;
    output << "                               `)@@@o%::;                      " << std::endl;
    output << "                                %@@(o)::;                      " << std::endl;
    output << "                               .%@@@@%::;                      " << std::endl;
    output << "                               ;%@@@@%::;.                     " << std::endl;
    output << "                              ;%@@@@%%:;;;.                    " << std::endl;
    output << "                          ...;%@@@@@%%:;;;;,..                 " << std::endl;
	output.close();
}
