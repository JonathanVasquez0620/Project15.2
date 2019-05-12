//count of often a word occurs in a text file
//use and unordered _map<string, int>

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_multiset<string> read_words(string filename)
{
	ifstream in(filename);
	unordered_multiset<string>	result;
	string input;
	while (in >> input)
	{
		string word;
		for (int i = 0; i < input.length(); i++)
		{
			if ('a' <= input[i] && input[i] <= 'z')
			{
				word.push_back(input[i]);
			}
			else if ('A' <= input[i] && input[i] <= 'Z')
			{
				word.push_back(input[i] + 'a' - 'A');
			}
			else
			{
				word = " ";
				result.insert(word);
			}
		}
		result.insert(word);
	}
	result.erase(" ");
	return result;
}
unordered_map<string, int> mappedd_words(unordered_multiset<string> wrds)
{
	unordered_map<string, int> map;
	for (int i = 0; i < wrds.size(); i++)
	{
		auto  pos = wrds.begin();
		map.at(wrds) = wrds.count(wrds);
		pos++;
	}
}
int main()
{
	unordered_multiset<string> words = read_words("words.txt");
	mappedd_words(words);
	cout << "Enter a word to see how often it appers in the document(lower case only):     ";
	string word_in;
	cout << word_in << " occurs " << words.count(word_in) << " times in the text file.";

	return 0;
}