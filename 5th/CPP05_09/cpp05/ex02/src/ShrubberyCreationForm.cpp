#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "ShrubberyCreationForm ";
	std::cout << getName();
	std::cout << " instance is initialized";
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) :
AForm(name, 145, 137)
{
	std::cout << "ShrubberyCreationForm ";
	std::cout << getName();
	std::cout << " instance is initialized";
	std::cout << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	if (this != &ref)
		setIsSigned(ref.getIsSigned());
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) :
AForm()
{
	setIsSigned(ref.getIsSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm instance ";
	std::cout << getName() << " is destroyed";
	std::cout << std::endl;
}

void ShrubberyCreationForm::createAsciiTree(void) const
{
	std::string asciiTree[] = {
		"                                 |\\    /|",
		"                              ___| \\,,/_/",
		"                           ---__/ \\/    \\",
		"                          __--/     (D)  \\",
		"                          _ -/    (_      \\",
		"   __-------_____--___--/           / \\_ O o)",
		"  /                                 /   \\__/",
		" /                                 /",
		"||          )                   \\_/\\",
		"||         /              _      /  |",
		"| |      /--______      ___\\    /\\  :",
		"| /   __-  - _/   ------    |  |   \\ \\",
		" |   -  -   /                | |     \\ )",
		" |  |   -  |                 | )     | |",
		"  | |    | |                 | |    | |",
		"  | |    < |                 | |   |_/",
		"  < |    /__\\                <  \\",
		"  /__\\                       /___\\"
	};
	size_t size = sizeof(asciiTree) / sizeof(asciiTree[0]);
	std::ofstream file(getName() + "_shrubbery");
	if (file.is_open())
	{
		for (size_t i = 0; i < size; i++)
			file << asciiTree[i] << std::endl;
		file.close();
	}
	else
		std::cout << "Failed to open file" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw IsNotSigned();
	if (executor.getGrade() > getGradeExe())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	createAsciiTree();
}
