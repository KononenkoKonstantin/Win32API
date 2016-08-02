#include "Answer.h"


Answer::Answer()
{
	this->id = 0;	
	this->text = nullptr;
}

Answer::~Answer()
{
}

Answer::Answer(int id, TCHAR& text)
{
	this->id = id;
	this->text = &text;
}

Answer::Answer(const Answer &ans)
{
	this->id = ans.id;
	this->text = ans.text;
}
int Answer::getId() const
{
	return id;
}
TCHAR& Answer::getText() const
{
	return *this->text;
}
void Answer::setId(int id)
{
	this->id = id;
}
void Answer::setText(TCHAR &text)
{
	this->text = &text;
}