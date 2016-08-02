#include "Question.h"


Question::Question()
{
	this->id = 0;	
	this->text = nullptr;
	this->weight = 0;
	this->ans.reserve(5);
	this->rightAns = 0;
}

Question::~Question()
{	
}

Question::Question(int id, TCHAR& text, int weight, std::vector<Answer> ans, int rightAns)
{
	this->id = id;
	this->text = &text;
	this->weight = weight;
	this->ans = ans;
	this->rightAns = rightAns;
}

Question::Question(const Question &q)
{
	this->id = q.id;
	this->text = q.text;
	this->weight = q.weight;
	this->ans = q.ans;
	this->rightAns = q.rightAns;
}

void Question::setQuestion(const Question &q)
{
	this->id = q.id;
	this->text = q.text;
	this->weight = q.weight;
	this->ans = q.ans;
	this->rightAns = q.rightAns;
}

int Question::getId() const
{
	return id;
}
TCHAR& Question::getText() const
{
	return *this->text;
}

int Question::getWeight() const
{
	return this->weight;
}

std::vector<Answer> Question::getAnswers() const
{
	return this->ans;
}

Answer Question::getAnswerByIndex(int index) const
{
	return this->ans[index];
}

int Question::getRightAnswerNum() const
{
	return this->rightAns;
}

void Question::setId(int id)
{
	this->id = id;
}
void Question::setText(TCHAR &text)
{
	this->text =  &text;
}
void Question::setWeight(int weight)
{
	this->weight = weight;
}

void Question::setRightAnsNum(int index)
{
	this->rightAns = index;
}