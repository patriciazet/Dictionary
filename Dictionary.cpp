/*Napisz prosty słownik który przetłumaczy słowo z języka anielskiego na polski (kilka testowych słów).*/

#include <iostream>
#include<map>

void translate(const std::map <std::string, std::string>& dictionary, const std::string& english) // nie chce nic zmieniac wiec przekazuje go przez stala referencje
{
	
	std::string polish{};
	try
	{
		polish = dictionary.at(english); // operacja, ktora jest ryzykowna
	}
	catch (const std::out_of_range& ex) // umieszczamy wyjatek, ktory chcemy zlapac // wyjatek lapiemy przez const reference
	{
		polish = "ERROR: not found";
	}
	std::cout << english << " means: " << polish << std::endl;
	

}


int main()
{
	std::map<std::string, std::string>dictionary;
	dictionary.insert(std::pair<std::string, std::string>("castle", "zamek")); // jako argument insert przekazujemy liste inicjalizacyjna
	dictionary.insert({ "pay", "placic" }); // lista inicjalizacyjna
	dictionary.insert({ "cat", "kot" });
	dictionary.insert({ "chat", "gawedzic" });
	dictionary.insert({ "like", "lubic" });
	dictionary.insert({ {"apple", "jablko"}, {"stay", "zostac"} })

		//at rzuca wyjątek, jeśli element jest nieznaleziony

	std::cout << dictionary.at("pay") << std::endl; // jezeli nie bedzie takiego slowa to wyrzuci wyjatek
	std::cout << dictionary["like"] << std::endl; // jezeli nie bedzie takiego slowa to nic nie wypisze

	translate(dictionary, "cat");
	translate(dictionary, "gawedzic");
	translate(dictionary, "listen");

} 

