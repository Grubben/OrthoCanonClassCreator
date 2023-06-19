/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthodox_creator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amc <amc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:19:01 by akliek            #+#    #+#             */
/*   Updated: 2023/06/19 15:58:51 by amc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <algorithm>

void	createSrcFile(std::string file, std::string name)
{
	std::ofstream	fout;

	fout.open(file);
	if (!fout)
	{
		std::cerr << "Error: can't open " << file << std::endl;
		return ;
	}

	fout << "#include \"" << name << ".hpp\"\n" << std::endl;
	
	fout << name << "::" << name << "(void)\n{" << std::endl;
	fout << "\tstd::cout << \"" << name << " constructor called\" << std::endl;\n}\n" << std::endl;
	
	fout << name << "::" << name << "(const " << name << "& copy)\n{" << std::endl;
	fout << "\tstd::cout << \"" << name << " copy constructor called\" << std::endl;\n\t*this = copy;\n}\n" << std::endl;
	
	fout << name << "::~" << name << "(void)\n{" << std::endl;
	fout << "\tstd::cout << \"" << name << " destructor called\" << std::endl;\n}\n" << std::endl;
	
	fout << name << "&\t" << name << "::" << "operator= (const " << name << "& copy)\n{" << std::endl;
	fout << "\tstd::cout << \"" << name << " assignment operator called\" << std::endl;\n\tif (this != &copy)\n\t{}\n\treturn (*this);\n}" << std::endl;

	fout.close();
}

void	createHeaderFile(std::string file, std::string name)
{
	std::string		upper;
	std::ofstream	fout;

	fout.open(file);
	if (!fout)
	{
		std::cerr << "Error: can't open " << file << std::endl;
		return ;
	}

	upper = name;
	std::transform(upper.begin(), upper.end(),upper.begin(), ::toupper);

	// fout << "#ifndef " << upper << "_HPP" << std::endl;
	// fout << "# define " << upper << "_HPP\n" << std::endl;
	fout << "#pragma once" << std::endl;
	fout << "#include <iostream>\n" << std::endl;
	fout << "class " << name << "\n{"<< std::endl;
	fout << "private:\n\t\t/*private members*/\npublic:" << std::endl;
	fout << "\t" << name << "(void);" << std::endl;
	fout << "\t" << name << "(const " << name << "& copy);" << std::endl;
	fout << "\t~" << name << "(void);" << std::endl;
	fout << std::endl;
	fout << "\t" << name << "&\toperator= (const " << name << "& copy);" << std::endl;
	fout << "};" << std::endl;
	// fout << "#endif" << std::endl;

	fout.close();
}


int	main(int argc, char **argv)
{
	std::string		src_file;
	std::string		header_file;

	if (argc != 2)
	{
		std::cout << "Usage: ./orthodox <class name>" << std::endl;
		return (1);
	}

	src_file = argv[1];
	src_file += ".cpp";
	header_file = argv[1];
	header_file += ".hpp";

	createHeaderFile(header_file, argv[1]);
	createSrcFile(src_file, argv[1]);

	return (0);
}
