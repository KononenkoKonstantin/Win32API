#pragma once
#include "Header.h"
#include "Question.h"
#include "Student.h"

class Test
{
	int id;
	TCHAR Caption[512];
	std::vector<Question> questions;
	std::vector<Question>::iterator itr;
	int QuestionsCount;
	Student student;
	std::string path;
			
	bool loadFromFile();
	
public:
	Test();	
	Test(Student &s, std::string path);
	~Test();

	int getId() const;
	std::vector<Question> getAllQuestions() const;
	Question getQuestion(unsigned int index) const;
	Answer getAnswer(unsigned int index) const;
	int getQuestionsCount()const;	
	int getTestWeight()const;	
};

