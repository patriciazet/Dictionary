/*Napisz prosty słownik który przetłumaczy słowo z języka anielskiego na polski (kilka testowych słów).*/

#include <iostream>
#include<map>

void translate(const std::map <std::string, std::string>& dictionary, const std::string& english) 
{
	
	std::string polish{};
	try
	{
		polish = dictionary.at(english);
	}
	catch (const std::out_of_range& ex) 
	{
		polish = "ERROR: not found";
	}
	std::cout << english << " means: " << polish << std::endl;
	

}


int main()
{
	std::map<std::string, std::string>dictionary;
	dictionary.insert(std::pair<std::string, std::string>("castle", "zamek"));
	dictionary.insert({ "pay", "placic" }); // lista inicjalizacyjna
	dictionary.insert({ "cat", "kot" });
	dictionary.insert({ "chat", "gawedzic" });
	dictionary.insert({ "like", "lubic" });
	dictionary.insert({ {"apple", "jablko"}, {"stay", "zostac"} })

		//at rzuca wyjątek, jeśli element jest nieznaleziony

	std::cout << dictionary.at("pay") << std::endl; 
	std::cout << dictionary["like"] << std::endl; 

	translate(dictionary, "cat");
	translate(dictionary, "gawedzic");
	translate(dictionary, "listen");

} 

