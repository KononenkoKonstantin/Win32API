#pragma once
#include "Header.h"
#include "Answer.h"

class Question
{
	int id;
	TCHAR *text;
	int weight;
	std::vector<Answer> ans;
	std::vector<Answer>::const_iterator itr;
	int rightAns;
	
public:
	Question();
	~Question();
	Question(int id, TCHAR& text, int weight, std::vector<Answer> ans, int rightAns);
	Question(const Question &q);
	void setQuestion(const Question &q);

	int getId() const;
	TCHAR& getText() const;
	int getWeight() const;
	std::vector<Answer> getAnswers() const;
	Answer getAnswerByIndex(int index) const;
	int getRightAnswerNum() const;

	void setId(int id);
	void setText(TCHAR &text);
	void setWeight(int weight);
	void setRightAnsNum(int index);
};

