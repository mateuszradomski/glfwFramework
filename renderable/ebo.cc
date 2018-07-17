#include "renderable/ebo.h"

EBO::EBO(unsigned int indices[], unsigned int size) :
	count(size / sizeof(indices[0]))
{
	glGenBuffers(1, &EBOId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

EBO::~EBO()
{
	glDeleteBuffers(1, &EBOId);
}

void EBO::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOId);
}

void EBO::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int EBO::getId() const { return EBOId; }
unsigned int EBO::getCount() const { return count; }
