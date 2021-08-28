#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<math.h>
long long power(long long a, long long b) {
	long long result = 1;
	for (int i = 1; i <= b; i++) {
		result *= a;
	}
	return result;
}
struct node
{
	int data;
	node* next;
};
node* creatNode(int data)
{
	node* p = new node;
	p->data = data;
	p->next = NULL;
	return p;
}
struct stack
{
	node* top;
};
void creat_stack(stack& s)
{
	s.top = NULL;
}
void push(stack& s, node* p)
{
	if (s.top == NULL)
		s.top = p;
	else
	{
		p->next = s.top;
		s.top = p;
	}
}
node* pop(stack& s)
{
	if (s.top == NULL)
		return NULL;
	node* p = new node;
	p->data = s.top->data;
	p->next = NULL;
	s.top = s.top->next;
	return p;
}