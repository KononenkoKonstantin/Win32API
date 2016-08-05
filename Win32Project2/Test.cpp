#include "Test.h"


Test::Test()
{	
	
}

Test::Test(Student &s, std::string path)
{		
	this->QuestionsCount = this->questions.size();
	this->student = s;
	this->path = path;
	this->id = s.getId();
	this->loadFromFile();
}

Test::~Test()
{
}

int Test::getTestWeight()const
{
	int s = 0;
	for (unsigned int i = 0; i < questions.size(); ++i)
	{
		s += this->questions[i].getWeight();
	}
	return s;
}

bool Test::loadFromFile()
{
	USES_CONVERSION;
	int pos = 0;
	
	std::string begin = "#";
	std::string buff;
	std::string ids;
	std::string quest;
	std::string weights;	
	std::string ans1;	
	std::string ans2;
	std::string ans3;
	std::string ans4;
	std::string ans5;
	std::string right_ans;
			
	std::ifstream fin;
	fin.open(this->path.c_str(), std::ios_base::in);
	if (!fin.is_open())
	{
		fin.close();
	}
	else
	{
		while (!fin.eof())
		{
			std::vector<Answer> ans;			
			ans.reserve(10);
			pos = 0;

			std::getline(fin, buff);
			if (buff.empty())
			{
				continue;
			}
			else
			{
				pos = buff.find(begin);
				ids = buff.substr(pos + 1, (buff.size() - pos));
			}
			
			std::getline(fin, quest);
			std::getline(fin, weights);
			std::getline(fin, ans1);			
			std::getline(fin, ans2);
			std::getline(fin, ans3);			
			std::getline(fin, ans4);			
			std::getline(fin, ans5);
			std::getline(fin, right_ans);
			
			int id = atoi(ids.c_str());
			int weight = atoi(weights.c_str());
			int rightAns = atoi(right_ans.c_str());	
			
			Answer a1(1, *A2T(ans1.c_str()));
			Answer a2(2, *A2T(ans2.c_str()));
			Answer a3(3, *A2T(ans3.c_str()));
			Answer a4(4, *A2T(ans4.c_str()));
			Answer a5(5, *A2T(ans5.c_str()));

			ans.push_back(a1);
			ans.push_back(a2);
			ans.push_back(a3);
			ans.push_back(a4);
			ans.push_back(a5);

			std::random_device random_deviced;
			std::mt19937 rand_function(random_deviced());
			std::shuffle(ans.begin(), ans.end(), rand_function);

			Question question(id, *A2T(quest.c_str()), weight, ans, rightAns);
			this->questions.push_back(question);
		}
		std::random_device random_deviced;
		std::mt19937 rand_function(random_deviced());
		std::shuffle(questions.begin(), questions.end(), rand_function);		
	}
	fin.close();
	
	return true;
}

int Test::getId() const
{
	return this->id;
}

std::vector<Question> Test::getAllQuestions() const
{
	return this->questions;
}

Question Test::getQuestion(unsigned int index) const
{
	Question q2;
	if (!this->questions.empty() && index < questions.size())
	{
		return questions[index];		
	}
	else
	{
		return q2;
	}
}

Answer Test::getAnswer(unsigned int index) const
{
	return this->questions[index].getAnswerByIndex(index);
}

int Test::getQuestionsCount() const
{
	return this->QuestionsCount;
}