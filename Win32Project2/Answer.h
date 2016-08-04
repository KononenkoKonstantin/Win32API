#pragma once
#include "Header.h"
class Answer
{
	int id;
	TCHAR* text;
public:
	Answer();	
	Answer(int id, TCHAR& text);
	Answer(const Answer &ans);
	~Answer();

	int getId() const;
	TCHAR& getText() const;
	void setId(int id);
	void setText(TCHAR& text);
};

