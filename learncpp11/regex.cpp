#include <regex>
#include <iostream>
#include <string>
#include <vector>

/*
 * sudo add-apt-repository ppa:ubuntu-toolchain-r/test
 * sudo apt-get update
 * sudo apt=get install gcc-4.9 g++-4.9 c++-4.9
 */

int main()
{
	std::cout<<"test regex simple usage:\n";
	std::string email_pattern("(\\w)+(\\.\\w+)*@(\\w)+((\\.\\w+)+)");
	try
	{
		std::regex email_regex(email_pattern);
		std::smatch results;
		std::string test_email_str = "My email is yubo1911@163.com";
		if(std::regex_search(test_email_str, results, email_regex))
		{
			std::cout<<results.str()<<std::endl;
		}
	}
	catch (std::regex_error e)
	{
		std::cout<<e.what()<<'\t'<<e.code()<<std::endl;
	}
	std::cout<<"test regex simple usage done.\n"<<std::endl;

	std::cout<<"test regex icase:\n";
	try
	{
		std::regex cpp_regex("(\\w)+\\.(cpp|hpp)$", std::regex::icase);
		std::vector<std::string> test_filenames = {"regex.cpp", "iostream.h", "template.CPP", "class.hPP", "Ah, regex.cpp", "regex.cpp Ah"};
		for(auto fn : test_filenames)
		{
			if(std::regex_match(fn, cpp_regex))
			{
				std::cout<<"cpp file: "<<fn<<'\n';
			}
		}
	}
	catch (std::regex_error e)
	{
		std::cout<<e.what()<<'\t'<<e.code()<<std::endl;
	}
	std::cout<<"test regex icase done.\n"<<std::endl;
	
	std::cout<<"test regex iterator usage:\n";
	try
	{
		std::regex email_regex(email_pattern);
		std::smatch results;
		std::string test_email_str = "I have three emails, yubo1911@163.com, yubo@gmail.com and guoyubo@gmail.com.";
		for(std::sregex_iterator it(std::begin(test_email_str), std::end(test_email_str), email_regex), end_it; it != end_it; it++)
		{
			std::cout<<it->str()<<std::endl;
		}
	}
	catch (std::regex_error e)
	{
		std::cout<<e.what()<<'\t'<<e.code()<<std::endl;
	}
	std::cout<<"test regex iterator usage done.\n"<<std::endl;
}