/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:45:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/28 12:36:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>  // for std::strerror(errno)

#define PROG_NAME "./stringreplaced"

int printErrorMsgReturn(std::string msg)
{
	std::cout << msg << std::endl;
	return (1);
}

int	printErrorReturn(std::string str)
{
	std::cout << "File error : \"" << str << "\" : " << std::strerror(errno) << std::endl;
	return (1);
}

int	replaceString(std::ifstream& srcFile, std::ofstream& dstFile, std::string str1, std::string str2)
{
	std::string				tmpStr;
	std::string::size_type	foundPos;
	std::string::size_type	str1Len;
	std::string::size_type	str2Len;
	
	if (str1.empty())
		return (printErrorMsgReturn("Error : OldString is empty"));
	if (std::getline(srcFile, tmpStr, '\0') != '\0')
	{
		str1Len = str1.length();
		str2Len = str2.length();
		foundPos = tmpStr.find(str1);
		if (foundPos != std::string::npos)
		{
			while (foundPos != std::string::npos)
			{
				tmpStr.erase(foundPos, str1Len);
				tmpStr.insert(foundPos, str2);
				foundPos = tmpStr.find(str1, foundPos + str2Len);
			}
		}
		dstFile << tmpStr;
		return (0);
	}
	else
		return (printErrorMsgReturn("Error : intput FileName is empty"));
}

int	openCheckFiles(std::ifstream& srcFile, std::ofstream& dstFile, std::string srcFilename)
{
	std::string		dstFilename;

	srcFile.open(srcFilename.c_str());
	if (srcFile.fail())
		return (printErrorReturn(srcFilename));
	dstFilename = srcFilename + ".replace";
	dstFile.open(dstFilename.c_str());
	if (dstFile.fail())
		return (printErrorReturn(dstFilename));
	return (0);
}

int main( int argc , char *argv[])
{
	std::ifstream	srcFile;
	std::ofstream	dstFile;
	int				returnStatus;
	
	if (argc != 4)
	{
		std::cerr << "Usage: " << PROG_NAME << " FileName OldString NewString" << std::endl;
		return (1);
	}
	returnStatus = openCheckFiles(srcFile, dstFile, argv[1]);
	if (returnStatus == 0)
	{
		returnStatus = replaceString(srcFile, dstFile, argv[2], argv[3]);
		srcFile.close();
		dstFile.close();
	}
	return (returnStatus);
}
