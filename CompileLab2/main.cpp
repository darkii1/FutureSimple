#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <time.h>

using namespace std;
void addToDic(string);
void case1();
void case2();
bool correctStructure(string);
bool wordFromDic(string dicName, string word);
vector<string> divide(string text);
int manyAdj(string sentence, int);
int manyAdv(string sentence);

void addToDic(string DicName)
{
	cout << "Input a word you would like to add to " << DicName;
	string word;
	string nameWithQuotes = "\"";
	nameWithQuotes += DicName;
	nameWithQuotes += "\"";

	ofstream out(DicName, ios::app);
	if (out.is_open())
	{
		out << word << endl;
	}
	out.close();
}
void showDic(string dicName)
{
	cout << "Words in " << dicName << " are:\n";
	vector<string> AllWords;
	string line;
	ifstream in(dicName);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			AllWords.push_back(line);
		}
	}
	in.close();
	for (int i = 0; i < AllWords.size(); i++)
	{
		cout << AllWords[i] << endl;
	}
}
void case1()
{
	cout << "Which dictionary\n";
}
void case2()
{
	cout << "Input a sentence\n";
	string input;
	
	getline(cin, input);
	getline(cin, input);
	
	if (input.empty()) cout << "Sentence does not belong to Future Simple\n";
	else if (correctStructure(input)) cout << "Sentence belongs to Future Simple\n";
	else cout << "No, sentence does not belong to Future Simple\n";

}
bool correctStructure(string sentence)
{

	vector<string> words = divide(sentence);
	if (words.size() < 3) return false;
	int var = 0;
	if (wordFromDic("link.txt", words[0])) var = 1;
	if (wordFromDic("wh.txt", words[0])) var = 2;
	if (var == 0)
	{
		int start = manyAdj(sentence, var);
		
		if (words.size() < start + 2) return false;
		else {
			if (!wordFromDic("link.txt", words[start + 1])) return false;
			else {


				int advStart = start + 3; 
				if (words.size() == advStart)
				{
					if (wordFromDic("noun.txt", words[start]) && wordFromDic("link.txt", words[start + 1]) && wordFromDic("verb.txt", words[start + 2])) return true;
					return false;
				}
				else
					if (words.size() == advStart + 1) 
					{
						if ((wordFromDic("noun.txt", words[start]) && wordFromDic("link.txt", words[start + 1]) && wordFromDic("verb.txt", words[start + 2]) && wordFromDic("time.txt", words[advStart])))
							return true;
					}
				if (words.size() == advStart + 2) 
				{
					if ((wordFromDic("noun.txt", words[start]) && wordFromDic("link.txt", words[start + 1]) && wordFromDic("verb.txt", words[start + 2])
						&& wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]))
						|| ((wordFromDic("noun.txt", words[start]) && wordFromDic("link.txt", words[start + 1])
							&& wordFromDic("verb.txt", words[start + 2]) && (words[advStart] == "next")
							&& wordFromDic("day.txt", words[advStart + 1])))) return true;
				}
				if (words.size() == advStart + 3)
				{
					if (wordFromDic("noun.txt", words[start]) && wordFromDic("link.txt", words[start + 1]) && wordFromDic("verb.txt", words[start + 2]) && wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]) && wordFromDic("time.txt", words[advStart + 2])) return true;
				}
				if (words.size() == advStart + 4)
				{
					if (wordFromDic("noun.txt", words[start]) && wordFromDic("link.txt", words[start + 1]) && wordFromDic("verb.txt", words[start + 2]) && wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]) && (words[advStart + 2] == "next") && wordFromDic("day.txt", words[advStart + 3])) return true;
				}
				return false;
			}
		}
	}
	if (var == 1) //TODO add question here
	{
		int start = manyAdj(sentence, var);

		if (words.size() < start + 2) return false;
		else {
			


				int advStart = start + 2;
				if (words.size() == advStart)
				{
					if (wordFromDic("link.txt", words[0]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1])) return true;
					return false;
				}
				else
					if (words.size() == advStart + 1)
					{
						if ((wordFromDic("link.txt", words[0]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1]) && wordFromDic("time.txt", words[advStart])))
							return true;
					}
				if (words.size() == advStart + 2)
				{
					if ((wordFromDic("link.txt", words[0]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1])
						&& wordFromDic("prep.txt", words[start+2]) && wordFromDic("noun.txt", words[advStart + 1]))
						|| ((wordFromDic("link.txt", words[0]) && wordFromDic("noun.txt", words[start])
							&& wordFromDic("verb.txt", words[start + 1]) && (words[advStart] == "next")
							&& wordFromDic("day.txt", words[advStart + 1])))) return true;
				}
				if (words.size() == advStart + 3)
				{
					if (wordFromDic("link.txt", words[0]) && wordFromDic("noun.txt", words[start ]) && wordFromDic("verb.txt", words[start + 1]) && wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]) && wordFromDic("time.txt", words[advStart + 2])) return true;
				}
				if (words.size() == advStart + 4)
				{
					if (wordFromDic("link.txt", words[0]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1]) && wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]) && (words[advStart + 2] == "next") && wordFromDic("day.txt", words[advStart + 3])) return true;
				}
				return false;
			
		}
	}
	if (var == 2)
	{
		int start = manyAdj(sentence, var);

		if (words.size() < start + 2) return false;
		else {



			int advStart = start + 2;
			if (words.size() == advStart)
			{
				if (wordFromDic("wh.txt", words[0]) && wordFromDic("link.txt", words[1]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1])) return true;
				return false;
			}
			else
				if (words.size() == advStart + 1)
				{
					if ((wordFromDic("wh.txt", words[0]) && wordFromDic("link.txt", words[1]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1]) && wordFromDic("time.txt", words[advStart])))
						return true;
				}
			if (words.size() == advStart + 2)
			{
				if ((wordFromDic("wh.txt", words[0]) && wordFromDic("link.txt", words[1]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1])
					&& wordFromDic("prep.txt", words[start + 2]) && wordFromDic("noun.txt", words[advStart + 1]))
					|| ((wordFromDic("wh.txt", words[0]) && wordFromDic("link.txt", words[1]) && wordFromDic("noun.txt", words[start])
						&& wordFromDic("verb.txt", words[start + 1]) && (words[advStart] == "next")
						&& wordFromDic("day.txt", words[advStart + 1])))) return true;
			}
			if (words.size() == advStart + 3)
			{
				if (wordFromDic("wh.txt", words[0]) && wordFromDic("link.txt", words[1]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1]) && wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]) && wordFromDic("time.txt", words[advStart + 2])) return true;
			}
			if (words.size() == advStart + 4)
			{
				if (wordFromDic("wh.txt", words[0]) && wordFromDic("link.txt", words[1]) && wordFromDic("noun.txt", words[start]) && wordFromDic("verb.txt", words[start + 1]) && wordFromDic("prep.txt", words[advStart]) && wordFromDic("noun.txt", words[advStart + 1]) && (words[advStart + 2] == "next") && wordFromDic("day.txt", words[advStart + 3])) return true;
			}
			return false;
		}
	}

	
}
int manyAdj(string sentence, int var)
{
	vector<string> words = divide(sentence);
	int i = var;
	while ( wordFromDic("adj.txt", words[i]) )
	{
		i++;
		if (i == words.size()) return i;
	}
	return i;
	//return false
}
int manyAdv(string sentence)
{
	vector<string> words = divide(sentence);
	int i = manyAdj(sentence,0)+3;
	
		while (wordFromDic("adv.txt", words[i]))
		{
			i++;
		}
		return i;
	
	//return false
}

bool wordFromDic(string dicName, string word)
{
	vector<string> AllWords;
	string line;
	ifstream in(dicName); 
	if (in.is_open())
	{
		while (getline(in, line))
		{
			AllWords.push_back(line);
		}
	}
	in.close();     
	for (int i = 0; i < AllWords.size(); i++)
	{
		if (word == AllWords[i]) return true;
	
	}
	return false;
}
bool mightBe(string dicName, string word)
{
	vector<string> AllWords;
	string line;
	ifstream in(dicName);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			AllWords.push_back(line);
		}
	}
	in.close();
	for (int i = 0; i < AllWords.size(); i++)
	{
		if (word == AllWords[i]) return true;

	}
	return true;
}
string pickWord(string dicName)
{
	vector<string> AllWords;
	string line;
	ifstream in(dicName);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			AllWords.push_back(line);
		}
	}
	in.close();
	//srand(time(NULL));
	int Random = rand() % AllWords.size();
	return AllWords[Random];
	
}

vector<string> divide(string text)
{
	std::istringstream iss(text);
	std::vector<std::string> results(istream_iterator<std::string>{iss}, istream_iterator<std::string>());
	return results;
}
void case3()
{
	int randN;
	
	randN = rand() % 3 + 6;
	if (randN == 3)
	{
		cout << pickWord("noun.txt") << " " << pickWord("link.txt") << " " << pickWord("verb.txt") << "\n";
	}
	if (randN == 4)
	{
		cout << pickWord("adj.txt") << " " <<pickWord("noun.txt") << " " << pickWord("link.txt") << " " << pickWord("verb.txt") << "\n";
	}
	if (randN == 5)
	{
		cout << pickWord("adj.txt") << " " << pickWord("adj.txt") << " " << pickWord("noun.txt") << " " << pickWord("link.txt") << " " << pickWord("verb.txt") << "\n";
	}
	if (randN == 6)
	{
		cout << pickWord("wh.txt") << " "<< pickWord("link.txt") << " "<<pickWord("adj.txt") << " " << pickWord("noun.txt")  << " " << pickWord("verb.txt") << " " <<pickWord("time.txt") << "\n";
	}
	if (randN == 7)
	{
		cout << pickWord("wh.txt") << " " << pickWord("link.txt") << " " << pickWord("adj.txt") << " " << pickWord("noun.txt") << " " << pickWord("verb.txt") << " " << "next " << pickWord("day.txt") << "\n";
	}
	if (randN == 8)
	{
		cout  << pickWord("adj.txt") << " " << pickWord("noun.txt") << " " << pickWord("link.txt") << " " << pickWord("verb.txt") << " " << pickWord("prep.txt") << " " << pickWord("noun.txt") << " " << pickWord("time.txt") << "\n";
	}
	if (randN == 9)
	{
		cout << pickWord("adj.txt") << " " << pickWord("noun.txt") << " " << pickWord("link.txt") << " " << pickWord("verb.txt") << " " << pickWord("prep.txt") << " " << pickWord("noun.txt") << " " << pickWord("time.txt") << "\n";
	}
}

int main()
{
	srand(time(NULL));
	int choice;
	bool gameOn = true;
	while (gameOn != false) {
		cout << "Welcome to Future Simple!\n";
	//	cout << " 1 - Show dictionary.\n";
		cout << " 1 - Check your own sentence.\n";
		cout << " 2 - Generate random Future Simple sentence.\n";
		cout << " 3 - Exit.\n";

		cout << "Enter your choice and press return: ";
		while (!(cin >> choice))
		{
			cin.clear();
			while (cin.get() != '\n') continue;
			cout << "Wrong input, must be a number!" << endl;
		}

		switch (choice)
		{
		/*case 1:
			int choiceCase1;
			bool on = true;
			while (on != false) {
				cout << "Which dictionary you would like to see?\n";
				cout << " 1 - Qustion words\n";
				cout << " 2 - Nouns\n";
				cout << " 3 - Verbs\n";
				cout << " 4 - Link verbs\n";
				cout << " 5 - Adverbs\n";
				cout << " 6 - Adjectives\n";
				cout << " 7 - Go back\n";

				cout << "Enter your choice and press return: ";
				while (!(cin >> choiceCase1))
				{
					cin.clear();
					while (cin.get() != '\n') continue;
					cout << "Wrong input, must be a number!" << endl;
				}

				switch (choiceCase1)
				{
				case 1:
					showDic("wh.txt");
					// rest of code here
					break;
				default:
					cout << "mmm";
					break;
				}
			} 
			// rest of code here
			break;*/
		case 1:
			case2();
			// rest of code here
			break;
		case 2:
			//cout << "Ahahah, you really think I will help you?\n";
			case3();

			break;
		case 3:
			cout << "End of Program.\n";
			gameOn = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}

	}
	
	

}

