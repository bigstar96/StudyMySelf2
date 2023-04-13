#pragma once

#include <iostream>
#include <memory>

// x, y 좌표계 구조
struct treePoint
{
	int x;
	int y;

	treePoint() : x{ 0 }, y{ 0 }
	{}

	treePoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

struct Node
{
	treePoint position;
	int data;

	Node() : position{}, data{ 0 } {}
	Node(treePoint p, int data)
	{
		this->position = p;
		this->data = data;
	}
};

class QuadTree
{
	// 트리의 범위
	treePoint topLeft;
	treePoint bottomRight;

	// 현재 노드
	Node* node;

	// 하위 쿼드트리
	std::unique_ptr<QuadTree> nw;
	std::unique_ptr<QuadTree> ne;
	std::unique_ptr<QuadTree> sw;
	std::unique_ptr<QuadTree> se;

public:
	QuadTree();
	QuadTree(treePoint topleft, treePoint bottomright);
	void Insert(Node* node);
	Node* Search(treePoint pt);
	bool IsInBound(treePoint pt);
};

