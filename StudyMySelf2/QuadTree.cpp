#include "QuadTree.h"
#include <cmath>

QuadTree::QuadTree() :
	topLeft{ treePoint() },
	bottomRight{ treePoint() },
	node{ nullptr },
	nw{ nullptr },
	ne{ nullptr },
	sw{ nullptr },
	se{ nullptr }
{
}

QuadTree::QuadTree(treePoint topleft, treePoint bottomright) : QuadTree()
{
	this->topLeft = topleft;
	this->bottomRight = bottomright;
}

void QuadTree::Insert(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	// 현재 영역이 아니면 무시
	if (!IsInBound(node->position))
	{
		return;
	}

	// 현재 영역이 단위 영역 ( 1 x 1 )이라면 더 이상 분할 불가능
	if (std::abs(topLeft.x - bottomRight.x) <= 1 &&
		std::abs(topLeft.y - bottomRight.y) <= 1)
	{
		if (this->node == nullptr)
		{
			this->node = node;
		}
		return;
	}

	// 서쪽
	if ((topLeft.x + bottomRight.x) / 2 >= node->position.x)
	{
		if ((topLeft.y + bottomRight.y) / 2 >= node->position.y)
		{
			// 북서
			if (nw == nullptr)
			{
				nw = std::make_unique<QuadTree>(
					treePoint(topLeft.x, topLeft.y),
					treePoint((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2)
				);
			}
			nw->Insert(node);
		}
		else
		{
			// 남서
			if (sw == nullptr)
			{
				sw = std::make_unique<QuadTree>(
					treePoint(topLeft.x, (topLeft.y + bottomRight.y) / 2),
					treePoint((topLeft.x + bottomRight.x) / 2, bottomRight.y)
				);
			}
			sw->Insert(node);
		}
	}
	// 동쪽
	else
	{
		if ((topLeft.y + bottomRight.y) / 2 >= node->position.y)
		{
			// 북동
			if (ne == nullptr)
			{
				ne = std::make_unique<QuadTree>(
					treePoint((topLeft.x + bottomRight.x) / 2, topLeft.y),
					treePoint(bottomRight.x, (topLeft.y + bottomRight.y) / 2)
				);
			}
			ne->Insert(node);
		}
		else
		{
			// 남동
			if (se == nullptr)
			{
				se = std::make_unique<QuadTree>(
					treePoint((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2),
					treePoint(bottomRight.x, bottomRight.y)
				);
			}
			se->Insert(node);
		}
	}
}

Node* QuadTree::Search(treePoint pt)
{
	// 현재 영역이 아니면 무시
	if (!IsInBound(pt))
	{
		return nullptr;
	}

	// node에 값이 있으면 더이상 분할 불가능한 단위 영역
	if (node != nullptr)
	{
		return node;
	}

	// 서쪽
	if ((topLeft.x + bottomRight.x) / 2 >= pt.x)
	{
		// 북서
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{
			if (nw == nullptr)
			{
				return nullptr;
			}
			return nw->Search(pt);
		}
		// 남서
		else
		{
			if (sw == nullptr)
			{
				return nullptr;
			}
			return sw->Search(pt);
		}
	}
	// 동쪽
	else
	{
		// 북동
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{
			if (ne == nullptr)
			{
				return nullptr;
			}
			return ne->Search(pt);
		}
		// 남동
		else
		{
			if (se == nullptr)
			{
				return nullptr;
			}
			return se->Search(pt);
		}
	}
}

bool QuadTree::IsInBound(treePoint pt)
{
	return (pt.x >= topLeft.x && pt.x <= bottomRight.x && pt.y >= topLeft.y && pt.y <= bottomRight.y);
}
